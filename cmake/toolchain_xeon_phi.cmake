#src: https://software.intel.com/en-us/articles/cross-compilation-for-intel-xeon-phi-coprocessor-with-cmake

SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR k1om)
SET(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
SET(CMAKE_C_COMPILER   icc)
SET(CMAKE_CXX_COMPILER icpc)
SET(MPI_C_COMPILER mpiicc)
SET(_CMAKE_TOOLCHAIN_PREFIX  x86_64-k1om-linux-)

# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH /usr/linux-k1om-4.7)

