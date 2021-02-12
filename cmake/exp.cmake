# Compile exp file
find_package(OpenCV QUIET)
add_executable(exp source/exp/exp.cpp ${EXT_SOURCE})
target_link_libraries(exp ${PNG_LIBRARY} zhp-shared ${OpenCV_LIBS})