set -e

cd /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build
/opt/homebrew/bin/cmake -E cmake_autogen /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/pbl2_book_autogen.dir/AutogenInfo.json Debug
/opt/homebrew/bin/cmake -E touch /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/pbl2_book_autogen/timestamp
/opt/homebrew/bin/cmake -E cmake_transform_depfile Ninja gccdepfile /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/pbl2_book_autogen/deps /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/d/2727afc7615a5d225b0f0122de853ee2e4312df0f6f1cf89c0249e2da3a4c079.d
