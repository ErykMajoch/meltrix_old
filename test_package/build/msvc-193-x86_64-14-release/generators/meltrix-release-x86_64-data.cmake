########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(meltrix_COMPONENT_NAMES "")
set(meltrix_FIND_DEPENDENCY_NAMES "")

########### VARIABLES #######################################################################
#############################################################################################
set(meltrix_PACKAGE_FOLDER_RELEASE "C:/Users/erykm/.conan2/p/b/meltr1a44dc54c7a20/p")
set(meltrix_BUILD_MODULES_PATHS_RELEASE )


set(meltrix_INCLUDE_DIRS_RELEASE "${meltrix_PACKAGE_FOLDER_RELEASE}/include")
set(meltrix_RES_DIRS_RELEASE )
set(meltrix_DEFINITIONS_RELEASE )
set(meltrix_SHARED_LINK_FLAGS_RELEASE )
set(meltrix_EXE_LINK_FLAGS_RELEASE )
set(meltrix_OBJECTS_RELEASE )
set(meltrix_COMPILE_DEFINITIONS_RELEASE )
set(meltrix_COMPILE_OPTIONS_C_RELEASE )
set(meltrix_COMPILE_OPTIONS_CXX_RELEASE )
set(meltrix_LIB_DIRS_RELEASE "${meltrix_PACKAGE_FOLDER_RELEASE}/lib")
set(meltrix_BIN_DIRS_RELEASE )
set(meltrix_LIBRARY_TYPE_RELEASE STATIC)
set(meltrix_IS_HOST_WINDOWS_RELEASE 1)
set(meltrix_LIBS_RELEASE meltrix)
set(meltrix_SYSTEM_LIBS_RELEASE )
set(meltrix_FRAMEWORK_DIRS_RELEASE )
set(meltrix_FRAMEWORKS_RELEASE )
set(meltrix_BUILD_DIRS_RELEASE )
set(meltrix_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(meltrix_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${meltrix_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${meltrix_COMPILE_OPTIONS_C_RELEASE}>")
set(meltrix_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${meltrix_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${meltrix_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${meltrix_EXE_LINK_FLAGS_RELEASE}>")


set(meltrix_COMPONENTS_RELEASE )