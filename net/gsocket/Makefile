PORTNAME=	gsocket
PORTVERSION=	1.4.28
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://github.com/hackerschoice/gsocket/releases/download/v${PORTVERSION}/

MAINTAINER=	arr@watson.org
COMMENT=	Connect two users behind NAT/firewall via TCP/IP
WWW=		https://github.com/hackerschoice/gsocket

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix ssl

SHEBANG_FILES=	tools/blitz \
		tools/gsocket \
		tools/gs_funcs \
		tools/gs-mount \
		tools/gs-sftp

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
