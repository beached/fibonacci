cmake_minimum_required( VERSION 2.8.12 )

project( fibonacci_prj )

include( ExternalProject )

find_package( Boost 1.61.0 COMPONENTS system date_time iostreams program_options filesystem regex unit_test_framework REQUIRED )

enable_testing( )
add_definitions( -DBOOST_TEST_DYN_LINK ) 

if( ${CMAKE_CXX_COMPILER_ID} STREQUAL 'MSVC' )
	add_compile_options( -D_WIN32_WINNT=0x0601 /std:c++latest ) 
else( )
	if( ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" )
		add_compile_options(-std=c++14 -O3 -Weverything -pthread -Wno-c++98-compat -g -Wno-covered-switch-default -Wno-padded -Wno-exit-time-destructors -Wno-c++98-compat-pedantic -Wno-unused-parameter -Wno-missing-noreturn -Wno-missing-prototypes -Wno-disabled-macro-expansion -Wno-c99-compat)
	elseif( ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
		add_compile_options(-std=c++14 -O3 -ggdb -Wall -pthread -Wno-deprecated-declarations -march=native )
	endif( )
endif( )

include_directories( ${HEADER_FOLDER} )
include_directories( SYSTEM ${Boost_INCLUDE_DIRS} )

link_directories( ${Boost_LIBRARY_DIRS} )

add_executable( fibonacchi_bin fibonacci.cpp )
target_link_libraries( fibonacchi_bin ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )
