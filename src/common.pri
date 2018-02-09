CONFIG(debug, debug|release) {
    BIN_DIR = $$OUTPUT_DIR/bin/debug
    LIB_DIR = $$OUTPUT_DIR/lib/debug
} else {
    BIN_DIR = $$OUTPUT_DIR/bin/release
    LIB_DIR = $$OUTPUT_DIR/lib/release
}

contains(TEMPLATE, "lib") {
    DLLDESTDIR = $$BIN_DIR
    DESTDIR = $$LIB_DIR
} else {
    DESTDIR = $$BIN_DIR
}
