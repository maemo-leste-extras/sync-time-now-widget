AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

hildondesktoplib_LTLIBRARIES = lib-sync-time-now-menu-widget.la

lib_sync_time_now_menu_widget_la_SOURCES = sync-time-now-menu-widget.c

lib_sync_time_now_menu_widget_la_CFLAGS = \
	$(LIBHILDON_CFLAGS) $(LIBHILDONDESKTOP_CFLAGS) $(LIBTIME_CFLAGS)

lib_sync_time_now_menu_widget_la_LIBADD = \
	$(LIBHILDON_LIBS) $(LIBHILDONDESKTOP_LIBS) $(LIBTIME_LDFLAGS)

lib_sync_time_now_menu_widget_la_LDFLAGS = -Wl,--as-needed -module -avoid-version

sudoersdir = $(sysconfdir)/sudoers.d/
sudoers_DATA = sync-time-now-menu-widget.sudoers

hildonstatusmenudesktopentry_DATA = sync-time-now-menu-widget.desktop
EXTRA_DIST = $(hildonstatusmenudesktopentry_DATA)

install-data-hook:
	@(cd $(DESTDIR)$(hildondesktoplibdir) && $(RM) \
		$(hildondesktoplib_LTLIBRARIES))
