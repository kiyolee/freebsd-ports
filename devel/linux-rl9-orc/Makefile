PORTNAME=	orc
PORTVERSION=	0.4.31
DISTVERSIONSUFFIX=	-8.el9
PORTREVISION=	4
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library and toolset to operate arrays of data (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://gstreamer.freedesktop.org/projects/orc.html

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libgcrypt
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

BIN_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-compiler-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
