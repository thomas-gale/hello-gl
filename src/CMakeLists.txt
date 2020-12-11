add_executable(main
    Shader.cpp
    Main.cpp)

target_link_libraries(main
    glfw
    glad)

configure_file(vert.glsl vert.glsl COPYONLY)
configure_file(frag.glsl frag.glsl COPYONLY)
