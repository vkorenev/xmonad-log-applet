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
	for p in $(schemas_DATA) ; do \
		GCONF_CONFIG_SOURCE=$(GCONF_SCHEMA_CONFIG_SOURCE) \
		gconftool-2 --makefile-install-rule $(srcdir)/$$p ; \
	done ;
endif

# TODO: use libpanel_applet_dir in GNOME3
appletdir = $(datadir)/gnome-panel/applets
applet_files = org.xmonad.Log.panel-applet
applet_DATA = $(applet_files)

$(applet_files): $(applet_files:.panel-applet=.panel-applet.in)
	$(SED) -e "s|\@LIBEXECDIR\@|$(libexecdir)|"	\
		-e "s|\@DATADIR\@|$(datadir)|" < $< > $@

DISTCLEANFILES = \
	$(applet_DATA)

EXTRA_DIST = \
	xmonad48.png \
	xmonad-log-applet.schema \
	org.xmonad.Log.panel-applet.in

gtk_update_icon_cache = gtk-update-icon-cache -f -t

update-icon-cache:
	@-if test -z "$(DESTDIR)"; then \
		echo "Updating Gtk icon cache."; \
		$(gtk_update_icon_cache) $(datadir)/icons/hicolor; \
	else \
		echo "*** Icon cache not updated.  After (un)install, run this:"; \
		echo "*** $(gtk_update_icon_cache) $(datadir)/icons/hicolor"; \
	fi

install-icons:
	mkdir -p $(DESTDIR)$(datadir)/icons/hicolor/48x48/apps; \
	$(INSTALL_DATA) $(srcdir)/xmonad48.png $(DESTDIR)$(datadir)/icons/hicolor/48x48/apps/xmonad.png;

uninstall-icons:
	rm -f $(DESTDIR)$(datadir)/icons/hicolor/48x48/apps/xmonad.png;

install-data-local: install-icons update-icon-cache

uninstall-local: uninstall-icons update-icon-cache
