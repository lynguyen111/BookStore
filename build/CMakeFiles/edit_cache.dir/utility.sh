set -e

cd /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build
/opt/homebrew/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
