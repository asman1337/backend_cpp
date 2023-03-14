#Check for build folder and doesn't exist then create it.
DIRECTORY="build"
if [ ! -d "$DIRECTORY" ]; then
  mkdir $DIRECTORY
else
  rm -frd $DIRECTORY
fi

cmake -B $DIRECTORY -S . -DCMAKE_CXX_COMPILER=g++-12 -DCMAKE_BUILD_TYPE=Release &&
  cmake --build $DIRECTORY --target codingveda_backend_cpp
