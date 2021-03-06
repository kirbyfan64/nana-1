# CMake configuration for Nana
# Author: ierofant(https://github.com/ierofant)

project(nana)
cmake_minimum_required(VERSION 2.8)

string(REGEX REPLACE "/[^/]*$" "" CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})
string(REGEX REPLACE "/[^/]*$" "" CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})

set(NANA_SOURCE_DIR ${CMAKE_SOURCE_DIR}/source)
set(NANA_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
endif(CMAKE_COMPILER_IS_GNUCXX)

include_directories(${NANA_INCLUDE_DIR})
aux_source_directory(${NANA_SOURCE_DIR} NANA_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/detail NANA_DETAIL_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/filesystem NANA_FILESYSTEM_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/audio NANA_AUDIO_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/audio/detail NANA_AUDIO_DETAIL_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/gui NANA_GUI_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/gui/detail NANA_GUI_DETAIL_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/gui/widgets NANA_GUI_WIDGETS_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/gui/widgets/skeletons NANA_GUI_WIDGETS_SKELETONS_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/paint NANA_PAINT_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/paint/detail NANA_PAINT_DETAIL_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/system NANA_SYSTEM_SOURCE)
aux_source_directory(${NANA_SOURCE_DIR}/threads NANA_THREADS_SOURCE)

add_library(${PROJECT_NAME} ${NANA_SOURCE}
							${NANA_DETAIL_SOURCE}
							${NANA_FILESYSTEM_SOURCE}
							${NANA_AUDIO_SOURCE}
							${NANA_AUDIO_DETAIL_SOURCE}
							${NANA_GUI_SOURCE}
							${NANA_GUI_DETAIL_SOURCE}
							${NANA_GUI_WIDGETS_SOURCE}
							${NANA_GUI_WIDGETS_SKELETONS_SOURCE}
							${NANA_PAINT_SOURCE}
							${NANA_PAINT_DETAIL_SOURCE}
							${NANA_SYSTEM_SOURCE}
							${NANA_THREADS_SOURCE})


install(TARGETS ${PROJECT_NAME}
			ARCHIVE DESTINATION lib
			LIBRARY DESTINATION lib)
install(DIRECTORY ${NANA_INCLUDE_DIR}/nana DESTINATION include)