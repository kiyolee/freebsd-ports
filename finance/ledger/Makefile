PORTNAME=	ledger
PORTVERSION=	3.2.1
PORTREVISION=	8
DISTVERSIONPREFIX=	v
CATEGORIES=	finance

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program
WWW=		https://ledger-cli.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	utf8cpp>=0:devel/utf8cpp
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lib cpe libedit
CPE_VENDOR=	${PORTNAME}-cli
USE_GITHUB=	yes
USE_LDCONFIG=	yes

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
