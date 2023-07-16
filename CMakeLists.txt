cmake_minimum_required(VERSION 3.16.0)

list(APPEND EXTRA_COMPONENT_DIRS "components" "esp/esp-idf-lib/components")

message(STATUS "extra components dirs = ${EXTRA_COMPONENT_DIRS}")

#set(COMPONENT_DIRS $ENV{IDF_PATH}/components $ENV{PROJECT_DIR}/components$ENV{PROJECT_DIR}/esp/esp-idf-lib/components)

# https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/build-system.html#optional-project-variables
# set(COMPONENTS  "flowsensor")

#set(COMPONENTS src)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# https://github.com/platformio/platform-espressif32/issues/330
project(flowsensor)
