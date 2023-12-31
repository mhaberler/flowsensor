

#include <Arduino.h>
#ifdef M5UNIFIED
#include <M5Unified.h>
#endif
#include "Esp.h"
#include "FlowSensor.h"
#include "QuadratureDecoder.h"
#include "defs.h"

#ifdef LVGL_UI
#include "lv_setup.h"
#include "ui/ui.h"

void ui_set_inital_values() {
  lv_obj_set_style_bg_color(ui_Battery, lv_color_hex(0xFADD18),
                            LV_PART_INDICATOR);
  lv_bar_set_value(ui_FlowRate, 0, LV_ANIM_OFF);
}

void ui_update_values(const mfdReport_t &mfd, float maxRate) {

#ifdef LVGL_UI
  switch (mfd.flags & CHARGE_MASK) {
  case FLAG_DISCHARGING:
    lv_obj_set_style_bg_color(ui_Battery, lv_color_hex(0x12EEEC),
                              LV_PART_INDICATOR);
    break;
  case FLAG_CHARGING:
    lv_obj_set_style_bg_color(ui_Battery, lv_color_hex(0x09CE46),
                              LV_PART_INDICATOR);
    break;
  case FLAG_CHARGE_UNKNOWN:
    lv_obj_set_style_bg_color(ui_Battery, lv_color_hex(0xFADD18),
                              LV_PART_INDICATOR);
    break;
  }

  char buf[30];
  sprintf(buf, "count: %d", mfd.count);
  lv_label_set_text(ui_Count, buf);

  sprintf(buf, "rate: %u", (uint32_t)(mfd.rate / 10.0f));
  lv_label_set_text(ui_Rate, buf);
#ifdef PRESSURE_WORKAROUND
  sprintf(buf, "Bar: %.2f", mfd.pressure_mBar/1000.0);
  lv_label_set_text(ui_MaxRate, buf);
#else
  sprintf(buf, "max: %u", (uint32_t)maxRate);
  lv_label_set_text(ui_MaxRate, buf);
#endif
  uint32_t pct = 0;
  if (maxRate > 0.0f) {
    pct = 100 * (mfd.rate / 10.0f) / maxRate;
  }
  lv_bar_set_value(ui_FlowRate, pct, LV_ANIM_OFF);

  lv_bar_set_value(ui_Battery, mfd.batteryLevel, LV_ANIM_OFF);
#endif
}
#else
void ui_update_values(const mfdReport_t &mfd, float maxRate) {}
void ui_set_inital_values() {}
#endif
