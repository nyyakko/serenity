#pragma once

#include <LibGUI/SettingsWindow.h>

namespace TaskbarSettings {

class TaskbarSettingsWidget final : public GUI::SettingsWindow::Tab {
    C_OBJECT_ABSTRACT(TaskbarSettingsWidget)

public:
    static ErrorOr<NonnullRefPtr<TaskbarSettingsWidget>> create();

    virtual void apply_settings() override;
    virtual void reset_default_values() override;

private:
    TaskbarSettingsWidget() = default;
    static ErrorOr<NonnullRefPtr<TaskbarSettingsWidget>> try_create();

    ErrorOr<void> setup();
};

}
