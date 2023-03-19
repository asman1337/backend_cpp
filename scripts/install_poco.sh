DIRECTORY="source/third_party/poco/build"
if [ ! -d "$DIRECTORY" ]; then
  mkdir $DIRECTORY
fi

cd $DIRECTORY &&
cmake .. && cmake --build . &&
sudo cmake --build . --target install