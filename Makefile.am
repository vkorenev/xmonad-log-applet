bin_PROGRAMS = xmonad-log-applet

xmonad_log_applet_SOURCES = main.c

xmonad_log_applet_CPPFLAGS = \
	$(GLIB_CFLAGS) \
	$(DBUS_GLIB_CFLAGS) \
	$(LIBPANEL_CFLAGS) \
	$(GCONF_CFLAGS)

xmonad_log_applet_LDADD = \
	$(GLIB_LIBS) \
	$(DBUS_GLIB_LIBS) \
	$(LIBPANEL_LIBS) \
	$(GCONF_LIBS)