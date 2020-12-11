add_executable(main
    Shader.cpp
    Main.cpp)

target_link_libraries(main
    glfw
    glad
    stb)

configure_file(shaders/vert.glsl vert.glsl COPYONLY)
configure_file(shaders/frag.glsl frag.glsl COPYONLY)
configure_file(res/container.jpg container.jpg COPYONLY)
configure_file(res/awesomeface.png awesomeface.png COPYONLY)
