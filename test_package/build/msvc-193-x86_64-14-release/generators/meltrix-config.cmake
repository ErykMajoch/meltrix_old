########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(meltrix_FIND_QUIETLY)
    set(meltrix_MESSAGE_MODE VERBOSE)
else()
    set(meltrix_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/meltrixTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${meltrix_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(meltrix_VERSION_STRING "0.0")
set(meltrix_INCLUDE_DIRS ${meltrix_INCLUDE_DIRS_RELEASE} )
set(meltrix_INCLUDE_DIR ${meltrix_INCLUDE_DIRS_RELEASE} )
set(meltrix_LIBRARIES ${meltrix_LIBRARIES_RELEASE} )
set(meltrix_DEFINITIONS ${meltrix_DEFINITIONS_RELEASE} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${meltrix_BUILD_MODULES_PATHS_RELEASE} )
    message(${meltrix_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


