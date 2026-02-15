cmake_minimum_required(VERSION 3.2)
project(cross_platform_game_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(EXE_FILE cross_platform_game_engine)

option(BROWSER_BUILD "Building for browser or not" OFF)

#sources
set(SOURCES
    main.cpp
    platform/Platform.hpp
    gl_backend.hpp
    Image.cpp
    Image.hpp
    Shader.cpp
    Shader.hpp
    platform/Window.hpp
    platform/GlfwWindow.cpp
    platform/GlfwWindow.hpp
        Mesh.cpp
        Mesh.hpp
        Camera.hpp
        Camera.cpp
)



#dependencies
include(FetchContent)
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb.git
    GIT_TAG master
)
FetchContent_GetProperties(stb)
if (NOT stb_POPULATED)
    FetchContent_MakeAvailable(stb)
    add_library(stb INTERFACE)
    target_include_directories(stb INTERFACE ${stb_SOURCE_DIR})
endif()

FetchContent_Declare(
    tinygltf
    GIT_REPOSITORY https://github.com/syoyo/tinygltf
    GIT_TAG release
)
FetchContent_MakeAvailable(tinygltf)

add_library(tinygltf_external_stb_image INTERFACE)
target_include_directories(tinygltf_external_stb_image INTERFACE ${tinygltf_SOURCE_DIR} ${stb_SOURCE_DIR})
target_compile_definitions(tinygltf_external_stb_image INTERFACE TINYGLTF_NO_INCLUDE_STB_IMAGE TINYGLTF_NO_INCLUDE_STB_IMAGE_WRITE)


FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG master
)
FetchContent_MakeAvailable(glm)


set(DEPENDENCIES
    stb
    tinygltf_external_stb_image
    glm
)


if(BROWSER_BUILD)
    #sources
    list(APPEND SOURCES
            platform/browser/PlatformBrowser.cpp
            platform/browser/PlatformBrowser.hpp
    )
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    configure_file(${CMAKE_SOURCE_DIR}/platform/browser/index.html ${CMAKE_BINARY_DIR}/index.html COPYONLY)
    configure_file(${CMAKE_SOURCE_DIR}/platform/browser/favicon.ico ${CMAKE_BINARY_DIR}/favicon.ico COPYONLY)
    #Dependencies
    list(APPEND DEPENDENCIES
    )
else()
    #sources
    list(APPEND SOURCES
            platform/desktop/PlatformDesktop.cpp
            platform/desktop/PlatformDesktop.hpp
    )
    # Dependencies
    FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(glad)
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(glfw)


    list(APPEND DEPENDENCIES
        glad
        glfw
    )
endif()





add_executable(${EXE_FILE} ${SOURCES} )
target_link_libraries(${EXE_FILE} PRIVATE ${DEPENDENCIES})

target_compile_definitions(${EXE_FILE} PRIVATE
        #STB_IMAGE_IMPLEMENTATION
        #STB_IMAGE_WRITE_IMPLEMENTATION
        #TINYGLTF_IMPLEMENTATION
)


if(BROWSER_BUILD)
    # linker flags
    target_compile_options(${EXE_FILE} PRIVATE
        "-sUSE_WEBGL2=1"
        "-sFULL_ES3=1"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sASSERTIONS=1"
        "-sUSE_GLFW=3"
    )
    target_link_options(${EXE_FILE} PRIVATE
        "-sUSE_WEBGL2=1"
        "-sUSE_GLFW=3"
         "--preload-file"
         "${CMAKE_CURRENT_SOURCE_DIR}/assets/@/assets"
    )
    # build target
    add_custom_target(run_browser
        DEPENDS ${EXE_FILE}
    )
else()
    # build target
    add_custom_target(default
        DEPENDS ${EXE_FILE}
    )

endif()

# asset copying
#add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${EXE_FILE}>/assets )
#add_dependencies(${EXE_FILE} copy_assets)

add_custom_command(TARGET ${EXE_FILE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${EXE_FILE}>/assets
)

