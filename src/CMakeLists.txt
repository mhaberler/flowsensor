# see esp/esp-idf-lib/examples/tsl2591/default/CMakeLists.txt
# https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/build-system.html#example-project

# set(EXTRA_COMPONENT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../esp/esp-idf-lib/components)
# set(EXTRA_COMPONENT_DIRS ${PROJECT_DIR}/esp/esp-idf-lib/components)

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

idf_component_register(SRCS ${app_sources}
        REQUIRES custom-header tsl2591 )
