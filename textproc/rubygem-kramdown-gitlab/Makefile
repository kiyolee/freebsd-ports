PORTNAME=	kramdown
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Yet-another-markdown-parser but fast, pure Ruby
WWW=		https://kramdown.gettalong.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-rexml-gitlab>=0:textproc/rubygem-rexml-gitlab

USES=		cpe gem

CPE_VENDOR=	kramdown_project

NO_ARCH=	yes

PLIST_FILES=	bin/kramdown

.include <bsd.port.mk>
