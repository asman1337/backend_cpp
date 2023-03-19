DIRECTORY="source/third_party/drogon/build"
if [ ! -d "$DIRECTORY" ]; then
  mkdir $DIRECTORY
fi

cd $DIRECTORY &&
cmake .. &&
make &&
sudo make install