cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu99")
set(CMAKE_BUILD_TYPE Debug)

# We use pkgconfig to find other packages
find_package(PkgConfig REQUIRED)
pkg_search_module(DRM REQUIRED libdrm)
pkg_search_module(GLIB REQUIRED glib-2.0)
pkg_search_module(GEOCLUE REQUIRED libgeoclue-2.0)

# Set library sources
project(redshift)
set(REDSHIFT_SRC
  src/colorramp.c
  src/config-ini.c
  src/gamma-drm.c
  src/gamma-dummy.c
  # src/gamma-quartz.c  # Mac shit
  # src/gamma-w32gdi.c  # Windows shit
  src/gamma-randr.c
  src/gamma-vidmode.c
  src/hooks.c
  src/location-geoclue2.c
  src/location-manual.c
  src/redshift.c
  src/signals.c
  src/solar.c
  src/systemtime.c)

# Define core library characteristics
add_library(redshift SHARED ${REDSHIFT_SRC})
target_include_directories(redshift PRIVATE "src")
target_include_directories(redshift PUBLIC "include")
target_link_libraries(redshift DRM_LIBRARY gdi32 glib)

# Include DRM dependencies
target_include_directories(redshift PUBLIC ${DRM_INCLUDE_DIRS})
target_compile_options(redshift PUBLIC ${DRM_CFLAGS_OTHER})
target_link_libraries(redshift ${DRM_LIBRARIES})

# Include GLIB dependencies
target_include_directories(redshift PUBLIC ${GLIB_INCLUDE_DIRS})
target_compile_options(redshift PUBLIC ${GLIB_CFLAGS_OTHER})
target_link_libraries(redshift ${GLIB_LIBRARIES})

# Include GEOCLUE dependencies
target_include_directories(redshift PUBLIC ${GEOCLUE_INCLUDE_DIRS})
target_compile_options(redshift PUBLIC ${GEOCLUE_CFLAGS_OTHER})
target_link_libraries(redshift ${GEOCLUE_LIBRARIES})
