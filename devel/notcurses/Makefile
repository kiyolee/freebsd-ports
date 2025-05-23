PORTNAME=	notcurses
DISTVERSIONPREFIX=	v
DISTVERSION=	${ABIVERSION}.0.16
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/:docs
DISTFILES=	${PORTNAME}-doc-${DISTVERSION}.tar.gz:docs

MAINTAINER=	nickblack@linux.com
COMMENT=	TUI library for modern terminal emulators
WWW=		https://nick-black.com/dankwiki/index.php/Notcurses

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libdeflate.so:archivers/libdeflate \
		libqrcodegen.so:graphics/qr-code-generator \
		libunistring.so:devel/libunistring

USES=		cmake:noninja compiler:c++17-lang localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dankamongmen
USE_LDCONFIG=	yes

CMAKE_ON=	USE_QRCODEGEN
# we leave USE_POC=on (and BUILD_TESTING=on) so that we can run some basic
# tests, if not the full notcurses-tester suite.
CMAKE_OFF=	USE_DOCTEST USE_PANDOC

TEST_TARGET=	test

PLIST_SUB=	ABI_VER=${ABIVERSION} \
		REL_VER=${DISTVERSION}

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

ABIVERSION=	3

.include <bsd.port.options.mk>

# ncursesw and tinfo >= 6.1 seem to be needed (see CMakeLists.txt:l104)
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400035
USES+=ncurses:port
.else
USES+=ncurses
.endif

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|install(FILES $${MARKDOWN} DESTINATION $${CMAKE_INSTALL_DOCDIR})|#install(FILES $${MARKDOWN} DESTINATION $${CMAKE_INSTALL_DOCDIR})|' \
		${WRKSRC}/CMakeLists.txt

post-install-MANPAGES-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1 ${STAGEDIR}${PREFIX}/share/man/man3
	# we don't want to install e.g. "notcurses-x.x.1"
	${FIND} ${WRKDIR} -maxdepth 1 -type f -iname \*.1 -execdir ${INSTALL_MAN} {} ${STAGEDIR}${PREFIX}/share/man/man1 \;
	${FIND} ${WRKDIR} -maxdepth 1 -type f -iname \*.3 -execdir ${INSTALL_MAN} {} ${STAGEDIR}${PREFIX}/share/man/man3 \;

.include <bsd.port.mk>
