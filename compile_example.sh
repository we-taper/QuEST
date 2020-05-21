# Since I might use gcc which is too new
export CC=/usr/bin/gcc-8
export CXX=/usr/bin/g++-8
rm -rf build
mkdir build
cd build
cmake ..
make
./demo
