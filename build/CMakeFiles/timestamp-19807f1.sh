set -e

cd /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build
/opt/homebrew/bin/cmake -E cmake_autogen /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/pbl2_seed_data_autogen.dir/AutogenInfo.json Debug
/opt/homebrew/bin/cmake -E touch /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/pbl2_seed_data_autogen/timestamp
/opt/homebrew/bin/cmake -E cmake_transform_depfile Ninja gccdepfile /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/pbl2_seed_data_autogen/deps /Users/nguyenly/eclipse-workspace/Pbl2_book_patched_binaware/Pbl2_book/build/CMakeFiles/d/5aa04c013885b4797e9b6c7cb7e0dc95475314b37e3b8df473a123129447c609.d
