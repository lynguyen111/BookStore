set -e

cd /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build
/opt/homebrew/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
