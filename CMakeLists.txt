cmake_minimum_required(VERSION 3.9)

project("CPP-PROJECT-TEMPLATE" CXX)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(
                        # REQUIRES fmt/6.1.2
                      GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

# conan_cmake_install(PATH_OR_REFERENCE .
#                     BUILD missing
#                     REMOTE conancenter
#                     SETTINGS ${settings})

# target_link_libraries(main )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(apps)
message(test=${LIBRARY_NAME})

set(MSVC True)
if(MSVC)
    message("Building for windows")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
    endif()
    
if (ENABLE_TESTS)
    add_subdirectory(tests)
    enable_testing()
endif()