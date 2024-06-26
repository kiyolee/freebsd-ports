PORTNAME=	cppzmq
PORTVERSION=	4.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ bindings for 0MQ
WWW=		https://github.com/zeromq/cppzmq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzmq.so:net/libzmq4
TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake:testing pkgconfig

NO_ARCH=	yes

CMAKE_ARGS=	--no-warn-unused-cli \
		-DCPPZMQ_CMAKECONFIG_INSTALL_DIR:PATH="lib/cmake/${PORTNAME}" \
		-Wno-dev

CMAKE_OFF=	CPPZMQ_BUILD_TESTS
CMAKE_TESTING_ON=	CPPZMQ_BUILD_TESTS # some tests fail intermittently, for example https://github.com/zeromq/cppzmq/issues/574

# cppzmq is included in libzmq2
CONFLICTS_INSTALL=	libzmq2

USE_GITHUB=	yes
GH_ACCOUNT=	zeromq

NO_ARCH=	yes

PLIST_FILES=	\
	include/zmq.hpp \
	include/zmq_addon.hpp \
	lib/cmake/${PORTNAME}/cppzmqConfig.cmake \
	lib/cmake/${PORTNAME}/cppzmqConfigVersion.cmake \
	lib/cmake/${PORTNAME}/cppzmqTargets.cmake \
	lib/cmake/${PORTNAME}/libzmq-pkg-config/FindZeroMQ.cmake \
	libdata/pkgconfig/cppzmq.pc

post-patch:
	${SED} -i '.orig' \
		-e 's|ZeroMQ_LIBRARY AND ZeroMQ_STATIC_LIBRARY|ZeroMQ_LIBRARY|' \
		${WRKSRC}/libzmq-pkg-config/FindZeroMQ.cmake

.include <bsd.port.mk>
