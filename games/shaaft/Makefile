PORTNAME=	shaaft
PORTVERSION=	0.5.0
PORTREVISION=	27
CATEGORIES=	games
MASTER_SITES=	SF/criticalmass/OldFiles
DISTNAME=	Shaaft-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL 3D falling block game similar to Blockout

DEPRECATED=	Unmaintained upstream for ages, breaks with modern toolchains
EXPIRATION_DATE=2025-03-02

LIB_DEPENDS=	libpng.so:graphics/png

CONFLICTS=	criticalmass

USES=		gl sdl tar:bzip2
USE_SDL=	mixer image sdl
USE_GL=		gl
USE_GCC=	yes
USE_CXXSTD=	gnu++98
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-optimize

CFLAGS+=	-fpermissive
CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --L_opts)

DATADIR=	${PREFIX}/share/Shaaft

PLIST_FILES=	bin/Packer bin/shaaft %%DATADIR%%/resource.dat \
		share/man/man6/shaaft.6.gz

DESKTOP_ENTRIES="Shaaft" "" "" "${PORTNAME}" "" ""

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG:T}|g ; \
		s|^CXXFLAGS|#CXXFLAGS|g ; \
		s|/usr/X11R6|${LOCALBASE}|g ; \
		s|-lSDL | |g ; \
		s|-lpng12|-lpng|g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|== 3|>= 3|' ${WRKSRC}/utils/hashMap.hpp

.include <bsd.port.mk>
