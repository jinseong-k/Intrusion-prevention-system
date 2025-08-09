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
