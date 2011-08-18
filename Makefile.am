libexec_PROGRAMS = xmonad-log-applet

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

schemasdir = @GCONF_SCHEMA_FILE_DIR@
schemas_files = xmonad-log-applet.schema
schemas_DATA = $(schemas_files)

if GCONF_SCHEMAS_INSTALL
install-data-local:
	GCONF_CONFIG_SOURCE=$(GCONF_SCHEMA_CONFIG_SOURCE) \
	gconftool-2 --makefile-install-rule $(schemas_DATA)
endif

serverdir = $(libdir)/bonobo/servers
server_files = xmonad-log-applet.server
server_DATA = $(server_files)

$(server_files): $(server_files:.server=.server.in)
	$(SED) -e "s|\@LIBEXECDIR\@|$(libexecdir)|"	\
		-e "s|\@DATADIR\@|$(datadir)|" < $< > $@

DISTCLEANFILES = \
	$(server_DATA)

EXTRA_DIST = \
	xmonad-log-applet.schema \
	xmonad-log-applet.server.in