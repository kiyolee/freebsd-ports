PORTNAME=	brial
PORTVERSION=	1.2.12
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python implementation of BRiAl
WWW=		https://github.com/BRiAl/BRiAl

LICENSE=	GPLv2

LIB_DEPENDS=	libbrial.so:math/brial

USE_GITHUB=	yes
GH_ACCOUNT=	BRiAl
GH_PROJECT=	${GH_ACCOUNT}

USES=		python

WRKSRC_SUBDIR=	sage-brial
USE_PYTHON=	distutils

NO_ARCH=	yes

.include <bsd.port.mk>
