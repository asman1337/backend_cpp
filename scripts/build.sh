#Check for build folder and doesn't exist then create it.
DIRECTORY="../build"
if [ ! -d "$DIRECTORY" ]; then
  mkdir $DIRECTORY
fi

cmake -B ../build -S . -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPES=RELEASE -G Ninja &&
cmake --build ../build --target codingveda_backend_cpp