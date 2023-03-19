#Check for third_party folder and doesn't exist then create it.
DIRECTORY="source/third_party"
if [ ! -d "$DIRECTORY" ]; then
  mkdir $DIRECTORY
fi

cd source/third_party &&
git clone --recurse-submodules https://github.com/drogonframework/drogon &&
git clone --recurse-submodules https://github.com/open-source-parsers/jsoncpp &&
git clone --recurse-submodules https://github.com/Thalhammer/jwt-cpp &&
git clone --recurse-submodules https://github.com/trusch/libbcrypt &&
git clone -b master https://github.com/pocoproject/poco.git
