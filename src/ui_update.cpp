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
#endif

void ui_set_inital_values() {
  lv_obj_set_style_bg_color(ui_Battery, lv_color_hex(0xFADD18),
                            LV_PART_INDICATOR);
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
  sprintf(buf, "count: %u", mfd.count);
  lv_label_set_text(ui_Count, buf);

  sprintf(buf, "rate: %u", (uint32_t)(mfd.rate / 10.0f));
  lv_label_set_text(ui_Rate, buf);

  sprintf(buf, "max: %u", (uint32_t)maxRate);
  lv_label_set_text(ui_MaxRate, buf);

  uint32_t pct = 0;
  if (maxRate > 0.0f) {
    pct = 100 * (mfd.rate / 10.0f) / maxRate;
  }
  lv_bar_set_value(ui_FlowRate, pct, LV_ANIM_OFF);

  lv_bar_set_value(ui_Battery, mfd.batteryLevel, LV_ANIM_OFF);
#endif
}
