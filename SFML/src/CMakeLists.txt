set(SOURCE_FILES 
	test.cpp
	Pad.cpp 
	Ball.cpp 
	WindowAplication.cpp
	EventManager.cpp
	Wall.cpp
	FrameHandler.cpp
)

project(pad)

add_definitions(-DSFML_STATIC)

# for SFML library
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SFML/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SFML/include)

# pad files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(pad ${SOURCE_FILES})

target_link_libraries(pad sfml-graphics-s sfml-window-s sfml-system-s opengl32 winmm gdi32 freetype jpeg)



