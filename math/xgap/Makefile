PORTNAME=	xgap
DISTVERSIONPREFIX=	v
DISTVERSION=	4.32
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical user interface for GAP
WWW=		https://gap-packages.github.io/xgap/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	cannot find sources (xgap.c) in ../../src.x11
BROKEN_armv7=	cannot find sources (xgap.c) in ../../src.x11

BUILD_DEPENDS=	gap:math/gap
LIB_DEPENDS=	libXaw.so:x11-toolkits/libXaw
RUN_DEPENDS=	gap:math/gap

USES=		autoreconf gmake xorg
USE_XORG=	ice sm x11 xext xmu xt

USE_GITHUB=	yes
GH_ACCOUNT=	gap-packages

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gaproot=${LOCALBASE}/lib/gap

ALL_TARGET=	default

PLIST_FILES=	bin/xgap \
		bin/xgap-bin

pre-build:
	@cd ${WRKSRC} && ./autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/*/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${REINPLACE_CMD} -i '' -e " \
		s,^XGAP=.*,XGAP=${PREFIX}/bin/${PORTNAME}-bin,; \
		s,^GAP=.*,GAP=${PREFIX}/bin/gap,; \
		" ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
