add_subdirectory(glfw)
add_subdirectory(glad)

# stb
add_library(stb stb/stb_include.h) # Arbitary source file to make cmake happy.
target_include_directories(stb PUBLIC stb) # Include all the header files.
set_target_properties(stb PROPERTIES LINKER_LANGUAGE CXX)
