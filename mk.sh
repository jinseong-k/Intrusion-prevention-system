BUILD_DIR="build"
RUN_DIR=`pwd`
BIN_DIR='bin'
EXEC_FILE='run'

if [ "clear" == "$1" ]; then
  if [ -d "build" ]; then
    rm -rf build
  fi
  echo "Clear build files"
  exit 0
fi

# compile submodule
if [ ! -f "lib/libcommon.a" ]; then
  cd lib/gotouniverse/clang/src/
  ./mk.sh
  cd $RUN_DIR
  cp lib/gotouniverse/clang/src/libcommon/build/libcommon.a lib/
fi

if [ ! -d "build" ]; then
  mkdir ${BUILD_DIR}
fi

if [ ! -d "bin" ]; then
  mkdir ${BIN_DIR}
fi

cd ${BUILD_DIR}
cmake ..
make

cp ${EXEC_FILE} ../${BIN_DIR}
cp ${EXEC_FILE} ../
