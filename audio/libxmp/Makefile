PORTNAME=	libxmp
PORTVERSION=	4.6.3
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module rendering library for xmp
WWW=		https://xmp.sourceforge.net/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=		cmake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxmp.so.${PORTVERSION}

.include <bsd.port.mk>
