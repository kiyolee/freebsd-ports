PORTNAME=	PollyReports
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Band-oriented PDF report generation from database query
WWW=		https://newcenturycomputers.net/projects/pollyreports.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	REPORTLAB

REPORTLAB_DESC=	Install Reportlab
REPORTLAB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab>=3.0:print/py-reportlab@${PY_FLAVOR}

.include <bsd.port.mk>
