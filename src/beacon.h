#pragma once

#include <stddef.h>
#include <stdint.h>

void beacon_setup(void);
void beacon_update_manufacturer_data(uint8_t *data, size_t size);