AC_INIT([Xmonad Log Applet], [1.0.4])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign])

AM_MAINTAINER_MODE

AC_PROG_CC
AC_PROG_SED
AC_PROG_INSTALL
AC_HEADER_STDC

PKG_CHECK_MODULES(GLIB, glib-2.0 >= 2.20.0)
PKG_CHECK_MODULES(DBUS_GLIB, dbus-glib-1 >= 0.80)

AC_ARG_WITH(
    [panel],
    [AS_HELP_STRING([--with-panel], [target gnome2 (default) or gnome3 panel])],
    [panel=$withval],
    [panel=gnome2]
)
AS_IF(
    [test "x$panel" = xgnome2],
          AC_DEFINE(PANEL_GNOME2, 1, [panel version])
          panel_applets=/gnome-panel/applets
          [PKG_CHECK_MODULES(LIBPANEL, libpanelapplet-3.0 >= 2.32.0)],
    [test "x$panel" = xgnome3],
          AC_DEFINE(PANEL_GNOME3, 1, [panel version])
          panel_applets=/gnome-panel/4.0/applets
          [PKG_CHECK_MODULES(LIBPANEL, libpanelapplet-4.0 >= 3.0.0)],
    [AC_ERROR([Unknown panel type, use gnome2 or gnome3])]
)
AC_SUBST([panel_applets])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
