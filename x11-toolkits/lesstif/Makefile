PORTNAME=	lesstif
PORTVERSION=	0.95.2
PORTREVISION=	8
PORTEPOCH=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	API compatible clone of the Motif toolkit
WWW=		https://lesstif.sourceforge.net/

LICENSE=	LGPL20+

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

CONFLICTS?=	open-motif

USES=		cpe tar:bzip2 libtool xorg
USE_XORG=	sm ice xt x11 xext xorgproto xrender xft
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	lt_cv_libxp=no
CONFIGURE_ARGS=	--enable-static --enable-shared --enable-production \
		--disable-maintainer-mode \
		--with-fontconfig-lib=${LOCALBASE}/lib \
		--with-freetype-lib=${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's,freetype/freetype.h,freetype.h,' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/scripts/autoconf/ac_find_motif.m4 \
		${STAGEDIR}${PREFIX}/share/aclocal

.include <bsd.port.mk>
