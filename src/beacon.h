#pragma once

#include "defs.h"
#include <stddef.h>
#include <stdint.h>
#include <string>

const std::string beacon_setup(void);
void beacon_update_manufacturer_data(uint8_t *data, size_t size);