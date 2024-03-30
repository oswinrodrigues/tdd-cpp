cmake_minimum_required(VERSION 3.25)
project(tdd-cpp)

# define required C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# enable debugging
add_compile_options(-g)

# map source to executable
add_executable(
  soundex_test
  src/soundex_test.cpp
)

# setup testing functionality
enable_testing()
add_test(
  SoundexEncoding
  soundex_test
)

# define required C++ libraries
find_package(GTest
  CONFIG
  REQUIRED
)
find_package(CppUTest
  CONFIG
  REQUIRED
)
find_package(jsoncpp
  CONFIG
  REQUIRED
)
set(Boost_NO_WARN_NEW_VERSIONS 1) # suppresses version warnings (optional)
find_package(Boost
  REQUIRED
  COMPONENTS
  date_time
  filesystem
  # 'algorithm' and 'assign' are header-only and already included within Boost
)

# link libraries to executable
target_link_libraries(
  soundex_test
  PRIVATE
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main
  CppUTest
  CppUTestExt
  JsonCpp::JsonCpp
  Boost::boost
  Boost::date_time
  Boost::filesystem
  # 'algorithm' and 'assign' are header-only and already included within Boost::boost
)
