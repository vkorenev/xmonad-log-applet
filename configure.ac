AC_INIT([Xmonad Log Applet], [2.0.0])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign])

AM_MAINTAINER_MODE

AC_PROG_CC
AC_PROG_SED
AC_PROG_INSTALL
AC_HEADER_STDC

PKG_PROG_PKG_CONFIG

PKG_CHECK_MODULES(GLIB, glib-2.0 >= 2.20.0)
PKG_CHECK_MODULES(DBUS_GLIB, dbus-glib-1 >= 0.80)

AM_PATH_GTK_2_0([2.10.0],,AC_MSG_ERROR([Gtk+ 2.10.0 or higher required.]))

SESSION_BUS_SERVICES_DIR=`$PKG_CONFIG --variable=session_bus_services_dir dbus-1`
AC_SUBST([SESSION_BUS_SERVICES_DIR])

AC_ARG_WITH(
    [panel],
    [AS_HELP_STRING([--with-panel], [target gnome2 (default), mate,  gnome3 or xfce4 panel])],
    [panel=$withval],
    [panel=gnome2]
)
AS_IF(
    [test "x$panel" = xgnome2],
        [PKG_CHECK_MODULES(LIBPANEL, libpanelapplet-3.0 >= 2.32.0)]
        LIBPANEL_APPLET_DIR=`$PKG_CONFIG --variable=prefix libpanelapplet-3.0`/share/gnome-panel/applets
        PLUGIN_DIR=`$PKG_CONFIG --variable=prefix libpanelapplet-3.0`/libexec
        [AC_DEFINE(PANEL_GNOME2, 1, [panel version])]
        ,
    [test "x$panel" = xmate],
        [PKG_CHECK_MODULES(LIBMATEPANEL, libmatepanelapplet-2.0 >= 1.4.0)]
        LIBPANEL_APPLET_DIR=`$PKG_CONFIG --variable=prefix libmatepanelapplet-2.0`/share/mate-panel/applets
        PLUGIN_DIR=`$PKG_CONFIG --variable=prefix libmatepanelapplet-2.0`/libexec
        [AC_DEFINE(PANEL_MATE, 1, [panel version])]
        ,
    [test "x$panel" = xgnome3],
        [PKG_CHECK_MODULES(LIBPANEL, libpanelapplet-4.0 >= 3.0.0)]
        LIBPANEL_APPLET_DIR=`$PKG_CONFIG --variable=libpanel_applet_dir libpanelapplet-4.0`
        PLUGIN_DIR=`$PKG_CONFIG --variable=prefix libpanelapplet-4.0`/libexec
        [AC_DEFINE(PANEL_GNOME3, 1, [panel version])]
        ,
    [test "x$panel" = xxfce4],
        [PKG_CHECK_MODULES(LIBPANEL, libxfce4panel-1.0 >= 4.6.0)]
        LIBPANEL_APPLET_DIR=`$PKG_CONFIG --variable=prefix libxfce4panel-1.0`/share/xfce4/panel-plugins
        PLUGIN_DIR=`$PKG_CONFIG --variable=libdir libxfce4panel-1.0`/xfce4/panel/plugins
        [AC_DEFINE(PANEL_XFCE4, 1, [panel version])]
        ,
    [AC_MSG_ERROR([Unknown panel type, use gnome2, gnome3 or xfce4])]
)
AC_SUBST([LIBPANEL_APPLET_DIR])
AC_SUBST([PLUGIN_DIR])

AM_CONDITIONAL([PANEL_GNOME2], [test "x$panel" = xgnome2])
AM_CONDITIONAL([PANEL_MATE], [test "x$panel" = xmate])
AM_CONDITIONAL([PANEL_GNOME3], [test "x$panel" = xgnome3])
AM_CONDITIONAL([PANEL_XFCE4], [test "x$panel" = xxfce4])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
