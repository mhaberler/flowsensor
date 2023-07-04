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

void ui_update_values(const mfdReport_t &mfd, float maxRate) {
#ifdef LVGL_UI

  char buf[30];
  sprintf(buf, "count: %u", mfd.count);
  lv_label_set_text(ui_Count, buf);

  sprintf(buf, "rate: %.1f", (float)mfd.rate / 10.0f);
  lv_label_set_text(ui_Rate, buf);

  sprintf(buf, "max rate: %.1f", maxRate);
  lv_label_set_text(ui_MaxRate, buf);

  uint32_t pct = 0;
  if (maxRate > 0.0f) {
    pct = 100 * (mfd.rate / 10.0f) / maxRate;
  }
  lv_bar_set_value(ui_FlowRate, pct, LV_ANIM_OFF);

  lv_bar_set_value(ui_Battery, mfd.batteryLevel, LV_ANIM_OFF);
#endif
}
