serenity_component(
    TaskbarSettings
    RECOMMENDED
    TARGETS TaskbarSettings
)

compile_gml(TaskbarSettingsWidget.gml TaskbarSettingsWidgetGML.cpp)

set(SOURCES
    main.cpp
    TaskbarSettingsWidgetGML.cpp
    TaskbarSettingsWidget.cpp
)

serenity_app(TaskbarSettings ICON app-taskbar)
target_link_libraries(TaskbarSettings PRIVATE LibConfig LibCore LibGfx LibGUI LibMain)
