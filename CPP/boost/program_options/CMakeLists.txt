cmake_minimum_required(VERSION 3.10)
project(boost)

# 下边这句一定要有COMPONENTS
find_package(Boost REQUIRED COMPONENTS system program_options)
include_directories(${Boost_INCLUDE_DIR})

# add_executable(program_options_demo program_options_demo.cpp)
# target_link_libraries(program_options_demo ${Boost_LIBRARIES})

add_executable(program_options_cmdline program_options_cmdline.cpp)
target_link_libraries(program_options_cmdline ${Boost_LIBRARIES})

# add_executable(program_options_cmdfile program_options_cfgfile.cpp)
# target_link_libraries(program_options_cmdfile ${Boost_LIBRARIES})