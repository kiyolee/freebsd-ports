PORTNAME=	cargo-deny
DISTVERSION=	0.16.4
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust: Cargo plugin for linting dependencies
WWW=		http://embark.rs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	EmbarkStudios

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

CARGO_CRATES=	addr2line-0.24.2 \
		adler2-2.0.0 \
		ahash-0.8.11 \
		aho-corasick-1.1.3 \
		allocator-api2-0.2.21 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.7 \
		anyhow-1.0.95 \
		arc-swap-1.7.1 \
		askalono-0.5.0 \
		async-compression-0.4.18 \
		atomic-waker-1.1.2 \
		autocfg-1.4.0 \
		backtrace-0.3.74 \
		base64-0.22.1 \
		bitflags-2.8.0 \
		bitvec-1.0.1 \
		block-buffer-0.10.4 \
		borsh-1.5.5 \
		bstr-1.11.3 \
		bumpalo-3.16.0 \
		byteorder-1.5.0 \
		bytes-1.9.0 \
		camino-1.1.9 \
		cargo-lock-10.1.0 \
		cc-1.2.10 \
		cfg-expr-0.17.2 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		clap-4.5.26 \
		clap_builder-4.5.26 \
		clap_derive-4.5.24 \
		clap_lex-0.7.4 \
		clru-0.6.2 \
		codespan-0.11.1 \
		codespan-reporting-0.11.1 \
		colorchoice-1.0.3 \
		console-0.15.10 \
		core-foundation-0.9.4 \
		core-foundation-0.10.0 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.16 \
		crc32fast-1.4.2 \
		crossbeam-0.8.4 \
		crossbeam-channel-0.5.14 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-queue-0.3.12 \
		crossbeam-utils-0.8.21 \
		crypto-common-0.1.6 \
		cvss-2.0.0 \
		deranged-0.3.11 \
		digest-0.10.7 \
		displaydoc-0.2.5 \
		dunce-1.0.5 \
		either-1.13.0 \
		encode_unicode-1.0.0 \
		encoding_rs-0.8.35 \
		equivalent-1.0.1 \
		errno-0.3.10 \
		faster-hex-0.9.0 \
		fastrand-2.3.0 \
		fern-0.7.1 \
		filetime-0.2.25 \
		fixedbitset-0.4.2 \
		flate2-1.0.35 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		fs-err-2.11.0 \
		fs_extra-1.3.0 \
		funty-2.0.0 \
		futures-channel-0.3.31 \
		futures-core-0.3.31 \
		futures-io-0.3.31 \
		futures-sink-0.3.31 \
		futures-task-0.3.31 \
		futures-util-0.3.31 \
		generic-array-0.14.7 \
		getrandom-0.2.15 \
		gimli-0.31.1 \
		gix-0.70.0 \
		gix-actor-0.33.2 \
		gix-attributes-0.24.0 \
		gix-bitmap-0.2.14 \
		gix-chunk-0.4.11 \
		gix-command-0.4.1 \
		gix-commitgraph-0.26.0 \
		gix-config-0.43.0 \
		gix-config-value-0.14.11 \
		gix-credentials-0.27.0 \
		gix-date-0.9.3 \
		gix-diff-0.50.0 \
		gix-discover-0.38.0 \
		gix-features-0.40.0 \
		gix-filter-0.17.0 \
		gix-fs-0.13.0 \
		gix-glob-0.18.0 \
		gix-hash-0.16.0 \
		gix-hashtable-0.7.0 \
		gix-ignore-0.13.0 \
		gix-index-0.38.0 \
		gix-lock-16.0.0 \
		gix-negotiate-0.18.0 \
		gix-object-0.47.0 \
		gix-odb-0.67.0 \
		gix-pack-0.57.0 \
		gix-packetline-0.18.3 \
		gix-packetline-blocking-0.18.2 \
		gix-path-0.10.14 \
		gix-pathspec-0.9.0 \
		gix-prompt-0.9.1 \
		gix-protocol-0.48.0 \
		gix-quote-0.4.15 \
		gix-ref-0.50.0 \
		gix-refspec-0.28.0 \
		gix-revision-0.32.0 \
		gix-revwalk-0.18.0 \
		gix-sec-0.10.11 \
		gix-shallow-0.2.0 \
		gix-submodule-0.17.0 \
		gix-tempfile-16.0.0 \
		gix-trace-0.1.12 \
		gix-transport-0.45.0 \
		gix-traverse-0.44.0 \
		gix-url-0.29.0 \
		gix-utils-0.1.14 \
		gix-validate-0.9.3 \
		gix-worktree-0.39.0 \
		gix-worktree-state-0.17.0 \
		globset-0.4.15 \
		goblin-0.9.3 \
		h2-0.4.7 \
		hashbrown-0.14.5 \
		hashbrown-0.15.2 \
		heck-0.5.0 \
		home-0.5.11 \
		http-1.2.0 \
		http-body-1.0.1 \
		http-body-util-0.1.2 \
		httparse-1.9.5 \
		hyper-1.5.2 \
		hyper-rustls-0.27.5 \
		hyper-util-0.1.10 \
		icu_collections-1.5.0 \
		icu_locid-1.5.0 \
		icu_locid_transform-1.5.0 \
		icu_locid_transform_data-1.5.0 \
		icu_normalizer-1.5.0 \
		icu_normalizer_data-1.5.0 \
		icu_properties-1.5.1 \
		icu_properties_data-1.5.0 \
		icu_provider-1.5.0 \
		icu_provider_macros-1.5.0 \
		idna-1.0.3 \
		idna_adapter-1.2.0 \
		indexmap-2.7.0 \
		insta-1.42.0 \
		io-close-0.3.7 \
		ipnet-2.10.1 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.14 \
		jiff-0.1.24 \
		jiff-tzdb-0.1.2 \
		jiff-tzdb-platform-0.1.2 \
		jobserver-0.1.32 \
		js-sys-0.3.77 \
		krates-0.17.5 \
		kstring-2.0.2 \
		lazy_static-1.5.0 \
		libc-0.2.169 \
		libredox-0.1.3 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.4.15 \
		litemap-0.7.4 \
		lock_api-0.4.12 \
		log-0.4.25 \
		maybe-async-0.2.10 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		mime-0.3.17 \
		miniz_oxide-0.8.3 \
		mio-1.0.3 \
		nu-ansi-term-0.50.1 \
		num-conv-0.1.0 \
		num-traits-0.2.19 \
		object-0.36.7 \
		once_cell-1.20.2 \
		openssl-probe-0.1.5 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		paste-1.0.15 \
		percent-encoding-2.3.1 \
		petgraph-0.6.5 \
		pin-project-lite-0.2.16 \
		pin-utils-0.1.0 \
		pkg-config-0.3.31 \
		plain-0.2.3 \
		platforms-3.5.0 \
		portable-atomic-1.10.0 \
		portable-atomic-util-0.2.4 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.20 \
		proc-macro2-1.0.93 \
		prodash-29.0.0 \
		quinn-0.11.6 \
		quinn-proto-0.11.9 \
		quinn-udp-0.5.9 \
		quote-1.0.38 \
		radium-0.7.0 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.5.8 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		reqwest-0.12.12 \
		ring-0.17.8 \
		rmp-0.8.14 \
		rmp-serde-1.3.0 \
		rustc-demangle-0.1.24 \
		rustc-hash-2.1.0 \
		rustix-0.38.43 \
		rustls-0.23.21 \
		rustls-native-certs-0.8.1 \
		rustls-pemfile-2.2.0 \
		rustls-pki-types-1.10.1 \
		rustls-webpki-0.102.8 \
		rustsec-0.30.1 \
		rustversion-1.0.19 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		schannel-0.1.27 \
		scopeguard-1.2.0 \
		scroll-0.12.0 \
		scroll_derive-0.12.0 \
		security-framework-3.2.0 \
		security-framework-sys-2.14.0 \
		semver-1.0.24 \
		serde-1.0.217 \
		serde_derive-1.0.217 \
		serde_json-1.0.136 \
		serde_spanned-0.6.8 \
		serde_urlencoded-0.7.1 \
		sha1_smol-1.0.1 \
		sha2-0.10.8 \
		shell-words-1.1.0 \
		shlex-1.3.0 \
		signal-hook-0.3.17 \
		signal-hook-registry-1.4.2 \
		similar-2.6.0 \
		slab-0.4.9 \
		smallvec-1.13.2 \
		smol_str-0.3.2 \
		socket2-0.5.8 \
		spdx-0.10.8 \
		spin-0.9.8 \
		stable_deref_trait-1.2.0 \
		static_assertions-1.1.0 \
		strsim-0.11.1 \
		strum-0.26.3 \
		strum_macros-0.26.4 \
		subtle-2.6.1 \
		syn-2.0.96 \
		sync_wrapper-1.0.2 \
		synstructure-0.13.1 \
		system-configuration-0.6.1 \
		system-configuration-sys-0.6.0 \
		tame-index-0.17.0 \
		tap-1.0.1 \
		target-lexicon-0.12.16 \
		tempfile-3.15.0 \
		termcolor-1.4.1 \
		thiserror-1.0.69 \
		thiserror-2.0.11 \
		thiserror-impl-1.0.69 \
		thiserror-impl-2.0.11 \
		time-0.3.37 \
		time-core-0.1.2 \
		time-macros-0.2.19 \
		tinystr-0.7.6 \
		tinyvec-1.8.1 \
		tinyvec_macros-0.1.1 \
		tokio-1.43.0 \
		tokio-rustls-0.26.1 \
		tokio-util-0.7.13 \
		toml-0.8.19 \
		toml-span-0.4.1 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.22 \
		tower-0.5.2 \
		tower-layer-0.3.3 \
		tower-service-0.3.3 \
		tracing-0.1.41 \
		tracing-core-0.1.33 \
		try-lock-0.2.5 \
		twox-hash-2.1.0 \
		typenum-1.17.0 \
		unicode-bom-2.0.3 \
		unicode-ident-1.0.14 \
		unicode-normalization-0.1.24 \
		unicode-width-0.1.14 \
		untrusted-0.9.0 \
		url-2.5.4 \
		utf16_iter-1.0.5 \
		utf8_iter-1.0.4 \
		utf8parse-0.2.2 \
		version_check-0.9.5 \
		walkdir-2.5.0 \
		want-0.3.1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-futures-0.4.50 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		web-sys-0.3.77 \
		web-time-1.1.0 \
		webpki-roots-0.26.7 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.9 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-registry-0.2.0 \
		windows-result-0.2.0 \
		windows-strings-0.1.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.24 \
		write16-1.0.0 \
		writeable-0.5.5 \
		wyz-0.5.1 \
		yoke-0.7.5 \
		yoke-derive-0.7.5 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35 \
		zerofrom-0.1.5 \
		zerofrom-derive-0.1.5 \
		zeroize-1.8.1 \
		zerovec-0.10.4 \
		zerovec-derive-0.10.3 \
		zstd-0.13.2 \
		zstd-safe-7.2.1 \
		zstd-sys-2.0.13+zstd.1.5.6

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
