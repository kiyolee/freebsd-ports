PORTNAME=	minicom
DISTVERSION=	2.10
CATEGORIES=	comms

MAINTAINER=	jailbird@fdf.net
COMMENT=	MS-DOS Telix serial communication program "workalike"
WWW=		https://salsa.debian.org/minicom-team/minicom/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	lrz:comms/lrzsz

USES=		cpe iconv localbase ncurses
CPE_VENDOR=	minicom_project
USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org/
GL_ACCOUNT=	minicom-team
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dfl-baud=57600 \
		--enable-dfl-port=/dev/cuau0 \
		--enable-lock-dir=/var/spool/lock \
		--sysconfdir=${PREFIX}/etc/minicom
LIBS+=		${ICONV_LIB} -lncurses

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} -E 's,"([rs][bxz] ),"l\1,' ${WRKSRC}/src/rwconf.c

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}/
	(umask 022 && cd ${WRKSRC} && ${TAR} --exclude '*/Makefile*' \
		 --exclude '*.orig' -chf - extras doc | ${TAR}  -xf - -C \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
