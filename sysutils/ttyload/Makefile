PORTNAME=	ttyload
PORTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daveltd.com/src/util/ttyload/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Give a color-coded graph of load averages over time
WWW=		https://www.daveltd.com/src/util/ttyload/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

ALL_TARGET=	default

USES=		tar:bzip2
PLIST_FILES=	bin/ttyload share/man/man1/ttyload.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttyload.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
