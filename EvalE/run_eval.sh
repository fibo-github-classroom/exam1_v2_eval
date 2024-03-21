rm -rf build
rm q1.out
rm q2.out
mkdir build
cmake -S . -B build
cmake --build build
./build/test/q1_test >> q1.out
./build/test/q2_test >> q2.out
