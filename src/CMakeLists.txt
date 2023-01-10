list(APPEND LD_PLUGIN_SRC 
     "log_debugger.cpp"
     "log_debugger_db.cpp"
)

if (ENABLE_SOURCE_CONTROL)
    list(APPEND LD_PLUGIN_SRC  "log_debugger_git.cpp")
endif()

add_library(ld_plugin STATIC ${LD_PLUGIN_SRC})

if (ENABLE_SOURCE_CONTROL)
    target_compile_definitions(ld_plugin PUBLIC LD_ENABLE_SOURCE_CONTROL)
endif()
if (ENABLE_PROCESS_CONTROL)
    target_compile_definitions(ld_plugin PUBLIC LD_ENABLE_PROCESS_CONTROL)
    if (ENABLE_THREAD_CONTROL)
        target_compile_definitions(ld_plugin PUBLIC LD_ENABLE_THREAD_CONTROL)
    endif()
endif()

target_include_directories(ld_plugin PRIVATE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include/log_debugger>)

install(TARGETS ld_plugin LIBRARY DESTINATION lib)
