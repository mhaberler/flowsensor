// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Main_screen_init(void)
{
ui_Main = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Main, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_flex_flow(ui_Main,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Main, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

ui_Top = lv_obj_create(ui_Main);
lv_obj_set_width( ui_Top, lv_pct(90));
lv_obj_set_height( ui_Top, lv_pct(40));
lv_obj_set_align( ui_Top, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Top,LV_FLEX_FLOW_ROW);
lv_obj_set_flex_align(ui_Top, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_clear_flag( ui_Top, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Values = lv_obj_create(ui_Top);
lv_obj_set_width( ui_Values, 100);
lv_obj_set_height( ui_Values, 50);
lv_obj_set_align( ui_Values, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Values,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Values, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_clear_flag( ui_Values, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Rate = lv_label_create(ui_Values);
lv_obj_set_width( ui_Rate, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Rate, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Rate, LV_ALIGN_CENTER );

ui_Count = lv_label_create(ui_Values);
lv_obj_set_width( ui_Count, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Count, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Count, LV_ALIGN_CENTER );

ui_Buttons = lv_obj_create(ui_Top);
lv_obj_set_width( ui_Buttons, 100);
lv_obj_set_height( ui_Buttons, 50);
lv_obj_set_align( ui_Buttons, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Buttons, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_ClearCount = lv_btn_create(ui_Buttons);
lv_obj_set_width( ui_ClearCount, 100);
lv_obj_set_height( ui_ClearCount, 50);
lv_obj_set_align( ui_ClearCount, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_ClearCount, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_ClearCount, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Bottom = lv_obj_create(ui_Main);
lv_obj_set_width( ui_Bottom, lv_pct(90));
lv_obj_set_height( ui_Bottom, lv_pct(40));
lv_obj_set_align( ui_Bottom, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_Bottom,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_Bottom, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_clear_flag( ui_Bottom, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_FlowRate = lv_bar_create(ui_Bottom);
lv_bar_set_value(ui_FlowRate,25,LV_ANIM_OFF);
lv_obj_set_width( ui_FlowRate, lv_pct(100));
lv_obj_set_height( ui_FlowRate, lv_pct(40));
lv_obj_set_align( ui_FlowRate, LV_ALIGN_CENTER );

ui_Battery = lv_bar_create(ui_Bottom);
lv_bar_set_value(ui_Battery,25,LV_ANIM_OFF);
lv_obj_set_width( ui_Battery, lv_pct(100));
lv_obj_set_height( ui_Battery, lv_pct(40));
lv_obj_set_align( ui_Battery, LV_ALIGN_CENTER );

}
