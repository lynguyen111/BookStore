set -e

cd /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build
/opt/homebrew/bin/cmake -E cmake_autogen /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/pbl2_generate_reports_autogen.dir/AutogenInfo.json Debug
/opt/homebrew/bin/cmake -E touch /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/pbl2_generate_reports_autogen/timestamp
/opt/homebrew/bin/cmake -E cmake_transform_depfile Ninja gccdepfile /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/pbl2_generate_reports_autogen/deps /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/d/f823e45c75ecd218a7bef4d98d79062796b0282c11c314ec5226907872d92134.d
