# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(meltrix_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(meltrix_FRAMEWORKS_FOUND_RELEASE "${meltrix_FRAMEWORKS_RELEASE}" "${meltrix_FRAMEWORK_DIRS_RELEASE}")

set(meltrix_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET meltrix_DEPS_TARGET)
    add_library(meltrix_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET meltrix_DEPS_TARGET
             PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${meltrix_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${meltrix_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:>
             APPEND)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### meltrix_DEPS_TARGET to all of them
conan_package_library_targets("${meltrix_LIBS_RELEASE}"    # libraries
                              "${meltrix_LIB_DIRS_RELEASE}" # package_libdir
                              "${meltrix_BIN_DIRS_RELEASE}" # package_bindir
                              "${meltrix_LIBRARY_TYPE_RELEASE}"
                              "${meltrix_IS_HOST_WINDOWS_RELEASE}"
                              meltrix_DEPS_TARGET
                              meltrix_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "meltrix"    # package_name
                              "${meltrix_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${meltrix_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Release ########################################
    set_property(TARGET meltrix::meltrix
                 PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Release>:${meltrix_OBJECTS_RELEASE}>
                 $<$<CONFIG:Release>:${meltrix_LIBRARIES_TARGETS}>
                 APPEND)

    if("${meltrix_LIBS_RELEASE}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET meltrix::meltrix
                     PROPERTY INTERFACE_LINK_LIBRARIES
                     meltrix_DEPS_TARGET
                     APPEND)
    endif()

    set_property(TARGET meltrix::meltrix
                 PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Release>:${meltrix_LINKER_FLAGS_RELEASE}> APPEND)
    set_property(TARGET meltrix::meltrix
                 PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Release>:${meltrix_INCLUDE_DIRS_RELEASE}> APPEND)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET meltrix::meltrix
                 PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Release>:${meltrix_LIB_DIRS_RELEASE}> APPEND)
    set_property(TARGET meltrix::meltrix
                 PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Release>:${meltrix_COMPILE_DEFINITIONS_RELEASE}> APPEND)
    set_property(TARGET meltrix::meltrix
                 PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Release>:${meltrix_COMPILE_OPTIONS_RELEASE}> APPEND)

########## For the modules (FindXXX)
set(meltrix_LIBRARIES_RELEASE meltrix::meltrix)
