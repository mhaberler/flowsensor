# https://github.com/espressif/esp-idf/blob/4fc2e5cb95abb1e7339f11929bc9e916a9c3d15a/docs/en/api-guides/build-system.rst#adding-conditional-configuration


# set(COMPONENT_SRCS 	".")

# set(COMPONENT_ADD_INCLUDEDIRS "include")

idf_component_register(SRCS "my-header.c" 
INCLUDE_DIRS "include")

# register_component(SRCS "my-header.c" 
# INCLUDE_DIRS "include")

# minimal
# idf_component_register(SRCS "foo.c" "bar.c"
#                        INCLUDE_DIRS "include"
#                        REQUIRES mbedtls)