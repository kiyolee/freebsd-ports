PORTNAME=	zfs-snapshot-mgmt
PORTVERSION=	20090201
PORTREVISION=	4
CATEGORIES=	filesystems sysutils
MASTER_SITES=	http://marcin.studio4plus.com/files/

MAINTAINER=	johntdarrah@gmail.com
COMMENT=	Automatic ZFS snapshot management tool
WWW=		http://marcin.studio4plus.com/en/zfs-file-history/howto.html

USES=		ruby:run shebangfix
SHEBANG_FILES=	zfs-snapshot-mgmt

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

post-patch:	.SILENT
	${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} \
		-e 's|/usr/local|${PREFIX}|g' {} +

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
