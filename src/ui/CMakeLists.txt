SET(SOURCES screens/ui_Main.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    fonts/ui_font_Font1.c
    fonts/ui_font_Font2.c)

add_library(ui ${SOURCES})
