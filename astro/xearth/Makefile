PORTNAME=	xearth
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	astro geography
MASTER_SITES=	LOCAL/madpilot/xearth

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Set the root window to the image of earth
WWW=		https://xearth.org/

LICENSE=	Xearth
LICENSE_NAME=	Xearth license
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		tar:xz xorg
USE_XORG=	x11 xext sm ice xt

PLIST_FILES=	bin/xearth \
		share/man/man1/xearth.1.gz \
		lib/X11/xearth/freebsd.committers.markers \
		lib/X11/xearth/freebsd.ftp.markers
PLIST_DIRS=	lib/X11/xearth

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xearth ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xearth.man ${STAGEDIR}${PREFIX}/share/man/man1/xearth.1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xearth
# Copy the list of FreeBSD sites & committers locations
.for marker in freebsd.committers.markers freebsd.ftp.markers
	${INSTALL_DATA} ${FILESDIR}/${marker} ${STAGEDIR}${PREFIX}/lib/X11/xearth
.endfor

.include <bsd.port.mk>
