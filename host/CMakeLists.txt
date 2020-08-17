cmake_minimum_required(VERSION 3.7)
project(rack++host)

set(dir_rack ${CMAKE_CURRENT_LIST_DIR}/../rack)

find_package(Boost REQUIRED)

list(APPEND HEADERS
	./include/rack++/host/channel.h
	./include/rack++/host/dll.h
	./include/rack++/host/module.h
	./include/rack++/host/param.h
	./include/rack++/host/unit.h
)

list(APPEND SRC
	./src/channel.cpp
	./src/dll.cpp
	./src/module.cpp
	./src/param.cpp
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
	${Boost_INCLUDE_DIRS}
)