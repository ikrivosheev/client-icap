set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED system)

add_executable(c-icap main.cpp)

set_target_properties(c-icap PROPERTIES
   CXX_STANDARD 14
   CXX_STANDARD_REQUIRED ON
   COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(c-icap icap ${Boost_SYSTEM_LIBRARY} Threads::Threads)
target_include_directories(c-icap INTERFACE ${Boost_INCLUDE_DIR})
