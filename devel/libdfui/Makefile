PORTNAME=	libdfui
PORTVERSION=	4.1.20060122
CATEGORIES=	devel
MASTER_SITES=	LOCAL/philip

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Abstract user interface protocol library

LICENSE=	BSD3CLAUSE

DEPRECATED=	Depends on deprecated port devel/libaura
EXPIRATION_DATE=2025-06-30

LIB_DEPENDS=	libaura3.so:devel/libaura

USES=		tar:bzip2
USE_LDCONFIG=	yes

MAKE_ENV=	SONAME=${SONAME} SOLINK=${SOLINK}

SONAME=		${SOLINK}.4
SOLINK=		${PORTNAME}4.so

PLIST_FILES=	lib/${SONAME} \
		lib/${SOLINK} \
		include/dfui4/conn_caps.h \
		include/dfui4/conn_npipe.h \
		include/dfui4/conn_tcp.h \
		include/dfui4/dfui.h \
		include/dfui4/dump.h \
		include/dfui4/encoding.h \
		include/dfui4/lang.h \
		include/dfui4/system.h
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${SONAME} ${STAGEDIR}${PREFIX}/lib
	${LN} -s ${SONAME} ${STAGEDIR}${PREFIX}/lib/${SOLINK}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/dfui4
	${INSTALL_DATA} ${WRKSRC}/conn_caps.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/conn_npipe.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/conn_tcp.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/dfui.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/dump.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/encoding.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/lang.h ${STAGEDIR}${PREFIX}/include/dfui4/
	${INSTALL_DATA} ${WRKSRC}/system.h ${STAGEDIR}${PREFIX}/include/dfui4/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
