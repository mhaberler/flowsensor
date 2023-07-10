#pragma once

#include <stddef.h>
#include <stdint.h>
#include <string>
#include "defs.h"



const std::string beacon_setup(void);
void beacon_update_manufacturer_data(uint8_t *data, size_t size);