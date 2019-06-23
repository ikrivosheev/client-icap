set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 

add_library(icap 
    url.cpp
)

set_target_properties(icap PROPERTIES
   CXX_STANDARD 14
   CXX_STANDARD_REQUIRED ON
   COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_include_directories(icap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
