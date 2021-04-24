AC_INIT([Sync Time Now status widget],
        [0.5],
        [parazyd@dyne.org], [sync-time-now-widget])

AM_INIT_AUTOMAKE
LT_INIT([shared disable-static])
AC_CONFIG_FILES([Makefile])

AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_LIBTOOL

PKG_CHECK_MODULES(LIBHILDON, hildon-1)
AC_SUBST(LIBHILDON_CFLAGS)
AC_SUBST(LIBHILDON_LIBS)

PKG_CHECK_MODULES(LIBHILDONDESKTOP, libhildondesktop-1)
AC_SUBST(LIBHILDONDESKTOP_CFLAGS)
AC_SUBST(LIBHILDONDESKTOP_LIBS)

PKG_CHECK_MODULES(LIBTIME, libtime)
AC_SUBST(LIBTIME_CFLAGS)
AC_SUBST(LIBTIME_LIBS)

hildonstatusmenudesktopentrydir="`$PKG_CONFIG --variable=hildonstatusmenudesktopentrydir libhildondesktop-1`"
AC_SUBST(hildonstatusmenudesktopentrydir)

hildondesktoplibdir="`$PKG_CONFIG --variable=hildondesktoplibdir osso-af-settings`"
AC_SUBST(hildondesktoplibdir)

AC_OUTPUT
