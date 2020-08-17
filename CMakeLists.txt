cmake_minimum_required(VERSION 3.7)
project(rack++)

set(dir_rack ${CMAKE_CURRENT_LIST_DIR}/../rack)

find_package(Boost REQUIRED)

list(APPEND PUBLIC_HEADERS
	./include/rack++/host/channel.h
	./include/rack++/host/dll.h
	./include/rack++/host/module.h
	./include/rack++/host/param.h
	./include/rack++/host/unit.h
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

list(APPEND HEADERS
)

list(APPEND SRC
	./src/host/channel.cpp
	./src/host/dll.cpp
	./src/host/module.cpp
	./src/host/param.cpp
	./src/host/unit.cpp
	./src/module/basic_stereo_effect.cpp
	./src/module/channel.cpp
	./src/module/param.cpp
	./src/module/trigger.cpp
	./src/module/unit.cpp
)

source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/include/rack++ PREFIX public_headers FILES ${PUBLIC_HEADERS})
source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/src PREFIX headers FILES ${HEADERS})
source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/src PREFIX src FILES ${SRC})

add_library(${PROJECT_NAME} STATIC ${SRC} ${HEADERS} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC
	${dir_rack}/include
)

target_include_directories(${PROJECT_NAME} PRIVATE
	./include/rack++
	./src
	${Boost_INCLUDE_DIRS}
)