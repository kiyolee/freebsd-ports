PORTNAME=	kmplayer
PORTVERSION=	0.12.0b
PORTREVISION=	8
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE frontend to Phonon / KDE5
WWW=		https://kmplayer.kde.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	prcpucfg.h:764:2: error: "Unknown CPU architecture"

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext-runtime \
		gnome kde:5 pkgconfig qt:5 tar:bz2 xorg
USE_GNOME=	cairo gdkpixbuf gtk20
USE_QT=		concurrent core dbus gui network printsupport \
		svg widgets x11extras xml \
		buildtools:build qmake:build
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm guiaddons i18n iconthemes init itemviews \
		jobwidgets mediaplayer notifications parts phonon service \
		textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui kdelibs4support kio solid sonnet \
		doctools:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
