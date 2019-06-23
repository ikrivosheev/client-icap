set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 

add_library(icap 
    client.cpp
    request.cpp
    response.cpp
    connection.cpp
    url.cpp
)

set_target_properties(icap PROPERTIES
   CXX_STANDARD 14
   CXX_STANDARD_REQUIRED ON
   COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_include_directories(icap PUBLIC ${CMAKE_SOURCE_DIR})
