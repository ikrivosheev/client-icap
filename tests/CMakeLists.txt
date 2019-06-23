set(CURL_LIBRARY "-lcurl") 
find_package (Threads)
find_package(CURL REQUIRED) 

add_executable(test_url test_url.cpp)

set_target_properties(test_url gtest PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(test_url
    gtest
    icap 
    ${CMAKE_THREAD_LIBS_INIT}
    ${CURL_LIBRARIES}
)

target_include_directories(gtest PRIVATE ${GTEST_INCLUDE_DIRS})

add_test(test_url test_url)

