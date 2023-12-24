cmake_minimum_required(VERSION 3.14)
project(vscode_setting_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
  include
)




add_executable(
  example
  example.cpp
  src/bank_system.cpp
  src/atm_machine.cpp
)



include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_card
  test/test_card.cpp
)
target_link_libraries(
  test_card
  GTest::gtest_main
)

add_executable(
  test_account
  test/test_account.cpp
)
target_link_libraries(
  test_account
  GTest::gtest_main
)


add_executable(
  test_user_info
  test/test_user_info.cpp
)
target_link_libraries(
  test_user_info
  GTest::gtest_main
)



add_executable(
  test_bank_system
  test/test_bank_system.cpp
  src/bank_system.cpp
)
target_link_libraries(
  test_bank_system
  GTest::gtest_main
)



add_executable(
  test_atm_machine
  test/test_atm_machine.cpp
  src/bank_system.cpp
  src/atm_machine.cpp
)
target_link_libraries(
  test_atm_machine
  GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(test_card)
gtest_discover_tests(test_account)
gtest_discover_tests(test_user_info)
gtest_discover_tests(test_bank_system)
gtest_discover_tests(test_atm_machine)