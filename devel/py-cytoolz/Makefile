PORTNAME=	cytoolz
DISTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython implementation of Toolz: High performance functional utilities
WWW=		https://github.com/pytoolz/cytoolz

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}toolz>=0.8.0:devel/py-toolz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/cytoolz/tests

# 3 tests fail, see https://github.com/pytoolz/cytoolz/issues/200

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*.so

.include <bsd.port.mk>
