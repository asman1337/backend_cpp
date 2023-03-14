#!/bin/bash
# Created by asman on 12-03-2023.

# Run the script as root
if [ "$EUID" -ne 0 ]
 then echo "Please run the script as root i.g: sudo ./ubuntu_setup.sh"
 exit
fi

#Check for build folder and doesn't exist then create it.
DIRECTORY="../build"
if [ ! -d "$DIRECTORY" ]; then
  mkdir $DIRECTORY
fi

#Install vcpkg
#cd ~
#git clone https://github.com/Microsoft/vcpkg.git
#~/vcpkg/bootstrap-vcpkg.sh

#Update system dependencies
sudo add-apt-repository --update -y ppa:ubuntu-toolchain-r/test &&
sudo apt update && sudo apt --fix-broken upgrade -y &&
#Install build system
sudo apt-get install build-essential gcc-12 make libssl-dev pkg-config clang curl zip unzip tar git -y &&
#For Drogon [default-libmysqlclient-dev]
sudo apt install libjsoncpp-dev uuid-dev openssl libssl-dev zlib1g-dev libhiredis-dev libmariadb-dev -y

#Install cmake
if ! command -v cmake &> /dev/null
then
  cd /opt
  sudo wget https://github.com/Kitware/CMake/releases/download/v3.25.3/cmake-3.25.3-linux-x86_64.sh &&
  sudo chmod +x cmake-3.25.3-linux-x86_64.sh &&
  sudo ./cmake-3.25.3-linux-x86_64.sh &&
  sudo ln -s /opt/cmake-3.25.3-linux-x86_64/bin/* /usr/bin &&
  cd ~
fi

# Install nginx (Optional)
if ! command -v nginx &> /dev/null
then
  sudo apt install nginx &&
  sudo ufw allow 'Nginx Full' &&
  sudo systemctl restart nginx
fi