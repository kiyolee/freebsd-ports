PORTNAME=	libdbusmenu
PORTVERSION=	16.04.0
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/243440794/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	vishwin@vishwin.info
COMMENT=	GLib and Gtk Implementation of the DBusMenu protocol
WWW=		https://launchpad.net/libdbusmenu

LICENSE=	GPLv3 LGPL21 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING-GPL3
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.2.1

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libharfbuzz.so:print/harfbuzz

GNU_CONFIGURE=	yes
USES=		compiler gettext-tools gmake gnome libtool pathfix pkgconfig python:run \
		shebangfix vala:build
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 intltool intlhack libxslt \
		introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	tools/dbusmenu-bench

PLIST_SUB=	VERSION="0.4"

CONFIGURE_ARGS=	--disable-static \
	--disable-static \
	--disable-dumper \
	--disable-tests \
	--disable-massivedebugging \
	--enable-introspection=yes \
	--disable-nls \
	--enable-vala \
	--with-gtk=3

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=	gtk-doc
DOCSDIR=		${PREFIX}/share/gtk-doc/html/

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CFLAGS+=	-Wno-unused-value
.endif

.include <bsd.port.post.mk>
