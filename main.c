/* main.c
 *
 * Copyright (c) 2009 Adam Wick
 * Copyright (c) 2011 Alexander Kojevnikov
 *
 * See LICENSE for licensing information
 */

#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>
#include <panel-applet.h>
#include <dbus/dbus-glib.h>

static void signal_handler(DBusGProxy *obj, const char *msg, GtkWidget *widget)
{
    gtk_label_set_markup(GTK_LABEL(widget), msg);
}

static void set_up_dbus_transfer(GtkWidget *buf)
{
    DBusGConnection *connection;
    DBusGProxy *proxy;
    GError *error= NULL;

    connection = dbus_g_bus_get(DBUS_BUS_SESSION, &error);
    if(connection == NULL) {
        g_printerr("Failed to open connection: %s\n", error->message);
        g_error_free(error);
        exit(1);
    }

    proxy = dbus_g_proxy_new_for_name(
        connection, "org.xmonad.Log", "/org/xmonad/Log", "org.xmonad.Log");
    error = NULL;

    dbus_g_proxy_add_signal(proxy, "Update", G_TYPE_STRING, G_TYPE_INVALID);
    dbus_g_proxy_connect_signal(
        proxy, "Update", (GCallback)signal_handler, buf, NULL);
}

static gboolean xmonad_log_applet_fill(PanelApplet *applet)
{
	panel_applet_set_flags(
        applet,
        PANEL_APPLET_EXPAND_MAJOR |
        PANEL_APPLET_EXPAND_MINOR |
        PANEL_APPLET_HAS_HANDLE);

    panel_applet_set_background_widget(applet, GTK_WIDGET(applet));

    GtkWidget *label = gtk_label_new("Waiting for Xmonad...");
    gtk_label_set_ellipsize(GTK_LABEL(label), PANGO_ELLIPSIZE_END);

    gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    set_up_dbus_transfer(label);

    gtk_container_add(GTK_CONTAINER(applet), label);
    gtk_widget_show_all(GTK_WIDGET(applet));

    return TRUE;
}

static gboolean xmonad_log_applet_factory(
    PanelApplet *applet, const gchar *iid, gpointer data)
{
    gboolean retval = FALSE;

    if(!strcmp(iid, "XmonadLogApplet"))
        retval = xmonad_log_applet_fill(applet);

    if(retval == FALSE) {
        printf("Wrong applet!\n");
        exit(-1);
    }

    return retval;
}

PANEL_APPLET_OUT_PROCESS_FACTORY(
    "XmonadLogAppletFactory",
    PANEL_TYPE_APPLET,
    "XmonadLogApplet",
    xmonad_log_applet_factory,
    NULL);
