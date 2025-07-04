PORTNAME=	drill
DISTVERSION=	0.8.3
PORTREVISION=	18
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HTTP load testing application written in Rust
WWW=		https://github.com/fcsonline/drill

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	fcsonline

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.20 \
		ansi_term-0.12.1 \
		async-trait-0.1.60 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.1 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.11.1 \
		byteorder-1.4.3 \
		bytes-1.3.0 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		colored-2.0.0 \
		cookie-0.16.2 \
		cookie_store-0.16.1 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.3 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.6 \
		crossbeam-utils-0.8.14 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		data-encoding-2.3.3 \
		encoding_rs-0.8.31 \
		enum-as-inner-0.5.1 \
		fastrand-1.8.0 \
		flate2-1.0.25 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.1.0 \
		futures-0.3.25 \
		futures-channel-0.3.25 \
		futures-core-0.3.25 \
		futures-executor-0.3.25 \
		futures-io-0.3.25 \
		futures-macro-0.3.25 \
		futures-sink-0.3.25 \
		futures-task-0.3.25 \
		futures-util-0.3.25 \
		getrandom-0.2.8 \
		h2-0.3.15 \
		hashbrown-0.12.3 \
		hdrhistogram-7.5.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hostname-0.3.1 \
		http-0.2.8 \
		http-body-0.4.5 \
		httparse-1.8.0 \
		httpdate-1.0.2 \
		hyper-0.14.23 \
		hyper-tls-0.5.0 \
		idna-0.2.3 \
		idna-0.3.0 \
		indexmap-1.9.2 \
		instant-0.1.12 \
		ipconfig-0.3.1 \
		ipnet-2.7.0 \
		itoa-0.4.8 \
		itoa-1.0.5 \
		js-sys-0.3.60 \
		lazy_static-1.4.0 \
		libc-0.2.138 \
		linked-hash-map-0.5.6 \
		lock_api-0.4.9 \
		log-0.4.17 \
		lru-cache-0.1.2 \
		match_cfg-0.1.0 \
		matches-0.1.9 \
		memchr-2.5.0 \
		mime-0.3.16 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.6.2 \
		mio-0.8.5 \
		native-tls-0.2.11 \
		nom-7.1.1 \
		num-traits-0.2.15 \
		num_cpus-1.14.0 \
		once_cell-1.16.0 \
		openssl-0.10.44 \
		openssl-macros-0.1.0 \
		openssl-probe-0.1.5 \
		openssl-src-111.24.0+1.1.1s \
		openssl-sys-0.9.79 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.5 \
		percent-encoding-2.2.0 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.26 \
		ppv-lite86-0.2.17 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.48 \
		psl-types-2.0.11 \
		publicsuffix-2.2.3 \
		quick-error-1.2.3 \
		quote-1.0.22 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.2.16 \
		regex-1.7.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.13 \
		resolv-conf-0.7.0 \
		ryu-1.0.12 \
		schannel-0.1.20 \
		scopeguard-1.1.0 \
		security-framework-2.7.0 \
		security-framework-sys-2.6.1 \
		serde-1.0.151 \
		serde_derive-1.0.151 \
		serde_json-1.0.90 \
		serde_urlencoded-0.7.1 \
		slab-0.4.7 \
		smallvec-1.10.0 \
		socket2-0.4.7 \
		strsim-0.8.0 \
		syn-1.0.106 \
		tempfile-3.3.0 \
		textwrap-0.11.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		time-0.3.17 \
		time-core-0.1.0 \
		time-macros-0.2.6 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		tokio-1.23.0 \
		tokio-native-tls-0.3.0 \
		tokio-util-0.7.4 \
		tower-service-0.3.2 \
		tracing-0.1.37 \
		tracing-attributes-0.1.23 \
		tracing-core-0.1.30 \
		trust-dns-proto-0.22.0 \
		trust-dns-resolver-0.22.0 \
		try-lock-0.2.3 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.6 \
		unicode-normalization-0.1.22 \
		unicode-width-0.1.10 \
		url-2.3.1 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		want-0.3.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-futures-0.4.33 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		web-sys-0.3.60 \
		widestring-0.5.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.36.1 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.36.1 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.36.1 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.36.1 \
		windows_x86_64_msvc-0.42.0 \
		winreg-0.10.1 \
		yaml-rust-0.4.5

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
