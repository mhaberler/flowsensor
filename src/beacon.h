#pragma once

#include <stddef.h>
#include <stdint.h>
#include "defs.h"

const uint8_t *beacon_setup(void);
void beacon_update_manufacturer_data(uint8_t *data, size_t size);