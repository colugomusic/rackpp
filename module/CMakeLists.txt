cmake_minimum_required(VERSION 3.7)
project(rack++module)

set(dir_rack ${CMAKE_CURRENT_LIST_DIR}/../rack)

list(APPEND HEADERS
	./include/rack++/module/basic_stereo_effect.h
	./include/rack++/module/channel.h
	./include/rack++/module/channel_listener.h
	./include/rack++/module/listenable.h
	./include/rack++/module/param.h
	./include/rack++/module/param_listener.h
	./include/rack++/module/trigger.h
	./include/rack++/module/trigger_listener.h
	./include/rack++/module/unit.h
)

list(APPEND SRC
	./src/basic_stereo_effect.cpp
	./src/channel.cpp
	./src/param.cpp
	./src/trigger.cpp
	./src/unit.cpp
)

source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/include/rack++ PREFIX headers FILES ${HEADERS})
source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/src PREFIX src FILES ${SRC})

add_library(${PROJECT_NAME} STATIC ${SRC} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC
	${dir_rack}/include
)

target_include_directories(${PROJECT_NAME} PRIVATE
	./include/rack++
	./src
)