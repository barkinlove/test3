How to build:

Prerequesities:

- cmake 3.28 or higher [link](https://cmake.org/download/)
- ninja (optionally on linux)
- MSVC 2019 or higher
- gcc or clang with stdc++20 support

1. Clone the repo
```
git clone https://github.com/barkinlove/test3.git
```
2. Initialize submodules
```
git submodule update --init
```
3. Create build folder and generate build files (on linux you can use convenience script)

windows:
```
mkdir build
cd build
cmake ..
cmake --build .
```
linux:
```
./swift_build
```
or if you have ninja installed
```
./swift_build -n
```
4. Binary will be located in `build` folder
