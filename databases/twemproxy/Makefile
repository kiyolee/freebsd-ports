PORTNAME=	twemproxy
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Fast, light-weight proxy for memcached and redis
WWW=		https://github.com/twitter/twemproxy

LICENSE=	APACHE20

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	twitter

LDFLAGS+=	-lexecinfo

PLIST_FILES=	sbin/nutcracker \
		share/man/man8/nutcracker.8.gz \
		etc/nutcracker.yml.sample

HAS_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nutcracker ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/nutcracker.8 ${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_DATA} ${WRKSRC}/conf/nutcracker.yml ${STAGEDIR}${PREFIX}/etc/nutcracker.yml.sample

.include <bsd.port.mk>
