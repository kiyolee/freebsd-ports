PORTNAME=	openjdk
DISTVERSIONPREFIX=	jdk-
DISTVERSION=	${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION}
CATEGORIES=	java devel
PKGNAMESUFFIX?=	${JDK_MAJOR_VERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VERSION}
WWW=		https://openjdk.java.net/projects/jdk/24/

LICENSE=	GPLv2

# i386 is deprecated, and will be removed in the next JDK
ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	zip:archivers/zip \
		${LOCALBASE}/include/cups/cups.h:print/cups \
		bash:shells/bash \
		gsed:textproc/gsed
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libharfbuzz.so:print/harfbuzz \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png
RUN_DEPENDS=	javavm:java/javavmwrapper \
		xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype

USES=	autoreconf:build compiler:features cpe gmake iconv jpeg pkgconfig xorg
USE_XORG=	x11 xext xi xrandr xrender xt xtst

CPE_VENDOR=	oracle

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	openjdk
GH_TAGNAME=	jdk-24.0.2-ga-freebsd-1

NO_CCACHE=	yes

MAKE_ENV=	CLASSPATH="" \
		JAVA_HOME="" \
		LD_LIBRARY_PATH="" \
		MAKEFLAGS=""

MAKE_JOBS_UNSAFE=	yes

JDK_ARCH=	${ARCH:S/amd64/x86_64/:S/i386/x86/:S/powerpc64/ppc64/}
JDK_OSARCH=	bsd-${JDK_ARCH}
JDK_BUILDDIR=	${WRKSRC}/build/${JDK_OSARCH}-${JDK_BUILD_JVM}-${JDK_BUILD_TYPE}
.if defined(BUILD_JRE)
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/jre
.else
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/jdk
.endif
INSTALLDIR=	${PREFIX}/${PKGBASE}

NOPRECIOUSMAKEVARS=	yes

JDK_MAJOR_VERSION=	24
JDK_MINOR_VERSION=	0
JDK_PATCH_VERSION=	2
JDK_BUILD_NUMBER=	12
BSD_JDK_VERSION=	1

JDK_BUG_URL=	https://bugs.freebsd.org/bugzilla/enter_bug.cgi?product=Ports%20%26%20Packages&component=Individual%20Port(s)&short_desc=java/${PORTNAME}${JDK_MAJOR_VERSION}%3A%20

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=${JDK_ARCH}-portbld-${OPSYS:tl}${OSREL}
CONFIGURE_ENV=	ac_cv_path_SED=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	--with-boot-jdk=${BOOTSTRAPJDKDIR} \
		--disable-ccache \
		--disable-javac-server \
		--with-alsa=${LOCALBASE} \
		--with-cups=${LOCALBASE} \
		--with-fontconfig=${LOCALBASE} \
		--with-freetype=system \
		--with-libjpeg=system \
		--with-giflib=system \
		--with-giflib-include=${LOCALBASE}/include \
		--with-giflib-lib=${LOCALBASE}/lib \
		--with-harfbuzz=system \
		--with-libpng=system \
		--with-zlib=system \
		--with-lcms=system \
		--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--with-version-string=${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION} \
		--with-native-debug-symbols=none \
		--with-debug-level=release \
		--with-vendor-name="OpenJDK BSD Porting Team" \
		--with-vendor-url="https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/" \
		--with-vendor-bug-url="${JDK_BUG_URL}" \
		--with-vendor-vm-bug-url="${JDK_BUG_URL}"

JAVAVMS_COMMENT=	OpenJDK${JDK_MAJOR_VERSION}

.if defined(BUILD_JRE)
ALL_TARGET=		legacy-images
.else
ALL_TARGET=		images
.endif
JDK_BUILD_TYPE=		release

.include <bsd.port.pre.mk>

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk24 ${LOCALBASE}/openjdk23

# do we have valid native jdk installed?
.for BJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${BJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${BJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/openjdk23
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:java/openjdk23
.endif

JDK_BUILD_JVM=	server

MAKE_ENV+=		--with-toolchain-type=${COMPILER_TYPE}
CONFIGURE_ARGS+=	--with-toolchain-type=${COMPILER_TYPE}
CONFIGURE_ARGS+=	--disable-warnings-as-errors

.if ${COMPILER_TYPE} == gcc
USE_GCC=	yes
CONFIGURE_ARGS+=	--with-extra-ldflags="-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT} -L${LOCALBASE}/lib/gcc${GCC_DEFAULT}" \
			--with-extra-cflags="-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT}" \
			--with-extra-cxxflags="-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT}"
.else
MAKE_ENV+=	USE_CLANG=true
EXTRA_CFLAGS+=		-Wno-unused-but-set-parameter
EXTRA_CFLAGS+=		-Wno-bitwise-instead-of-logical
EXTRA_CFLAGS+=		-Wno-error=deprecated-non-prototype
CONFIGURE_ARGS+=	--with-extra-cflags="${EXTRA_CFLAGS}"
CONFIGURE_ARGS+=	--with-extra-cxxflags="${EXTRA_CFLAGS}"
.endif

.if ${ARCH} == aarch64
CONFIGURE_ARGS+=	--disable-dtrace
.endif

.if empty(ICONV_LIB)
ICONV_CFLAGS=	-DLIBICONV_PLUG
.else
ICONV_CFLAGS=	-I${LOCALBASE}/include
ICONV_LDFLAGS=	-L${LOCALBASE}/lib
ICONV_LIBS=	${ICONV_LIB}
.endif

post-patch:
	@${RM} ${WRKSRC}/src/hotspot/os_cpu/bsd_ppc/thread_bsd_ppc.cpp
	@${MV} ${WRKSRC}/src/hotspot/os_cpu/bsd_ppc/thread_bsd_ppc.hpp \
		${WRKSRC}/src/hotspot/os_cpu/bsd_ppc/javaThread_bsd_ppc.hpp

	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${CHMOD} 755 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/configure \
		${WRKSRC}/src/hotspot/os/bsd/os_bsd.cpp
	@${REINPLACE_CMD} -e 's|%%ICONV_CFLAGS%%|${ICONV_CFLAGS}|' \
		-e 's|%%ICONV_LDFLAGS%%|${ICONV_LDFLAGS}|' \
		-e 's|%%ICONV_LIBS%%|${ICONV_LIBS}|' \
		${WRKSRC}/make/autoconf/libraries.m4

post-build:
.if defined(OPENJDK_SYMLINK_CACERTS)
	@${RM} ${JDK_IMAGEDIR}/lib/security/cacerts
	@${LN} -sf ${OPENJDK_SYMLINK_CACERTS} ${JDK_IMAGEDIR}/lib/security/cacerts
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	@cd ${JDK_IMAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}
	@cd ${STAGEDIR}${INSTALLDIR} && \
		${FIND} bin -type f -exec ${CHMOD} ${BINMODE} {} \;
	@${CHMOD} ${BINMODE} ${STAGEDIR}${INSTALLDIR}/lib/jspawnhelper
	@${ECHO} "@javavm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${INSTALLDIR} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.post.mk>
