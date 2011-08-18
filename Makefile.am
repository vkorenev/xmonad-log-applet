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

serverdir = $(libdir)/bonobo/servers
server_files = xmonad-log-applet.server
server_DATA = $(server_files)

$(server_files): $(server_files:.server=.server.in)
	$(SED) -e "s|\@LIBEXECDIR\@|$(libexecdir)|"	\
		-e "s|\@DATADIR\@|$(datadir)|" < $< > $@

DISTCLEANFILES = \
	$(server_DATA)

EXTRA_DIST = \
	xmonad-log-applet.server.in