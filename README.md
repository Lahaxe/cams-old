# cams
Collection Archiving and Managment System

## Linux compilation

sudo apt-get install git git-gui

sudo apt-get install cmake build-essential ninja-build libboost1.65-all-dev qtbase5-dev qtcreator

git config --global user.name "<your name>"
  
git config --global user.email "<your email>"

git clone https://github.com/lahaxe/cams-old.git

cd cams-old

mkdir build

cd build

cmake -GNinja ..

ninja

## si besoin, installer Qt5

wget http://download.qt.io/official_releases/qt/5.14/5.14.1/qt-opensource-linux-x64-5.14.1.run
chmod +x qt-opensource-linux-x64-5.14.1.run
./qt-opensource-linux-x64-5.14.1.run

## Generer un GUID

echo _`uuidgen -r | tr - _`


## Compiler et exécuter les tests

cd build
cmake -GNinja -DBUILD_TESTS=ON ..
ninja
../run_tests.sh

