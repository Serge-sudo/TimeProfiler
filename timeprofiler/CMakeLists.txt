add_library(timeprofiler timeprofiler.cpp)
set_property(TARGET timeprofiler PROPERTY CXX_STANDARD 20)
target_include_directories(timeprofiler PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
install(TARGETS timeprofiler)
