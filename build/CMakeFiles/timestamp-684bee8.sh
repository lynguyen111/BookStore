set -e

cd /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build
/opt/homebrew/bin/cmake -E cmake_autogen /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/convert_legacy_bin_autogen.dir/AutogenInfo.json Debug
/opt/homebrew/bin/cmake -E touch /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/convert_legacy_bin_autogen/timestamp
/opt/homebrew/bin/cmake -E cmake_transform_depfile Ninja gccdepfile /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/convert_legacy_bin_autogen/deps /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/d/a6839cdc5764d5fddf5bfff91f22b1e39ab7883807593994773d943d5cb1e995.d
