cmake_minimum_required(VERSION 3.10)
project(ATh_FHE_Middleware)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenFHE package installed globally in the container
find_package(OpenFHE REQUIRED)

include_directories(${OPENFHE_INCLUDE_DIRS})
include_directories(/usr/local/include/openfhe)
include_directories(/usr/local/include/openfhe/pke)
include_directories(/usr/local/include/openfhe/core)
include_directories(/usr/local/include/openfhe/binfhe)
include_directories(/usr/local/include/openfhe/lattice)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(ath_middleware
    src/main.cpp
    src/CryptoManager.cpp
    src/MiddlewareCore.cpp
    src/CloudSimulator.cpp
)

# Link all OpenFHE components explicitly
target_link_libraries(ath_middleware 
    OPENFHEpke
    OPENFHEcore
    OPENFHEbinfhe
)