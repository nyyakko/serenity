#include "TaskbarSettingsWidget.h"
#include "Defaults.h"
#include <LibGUI/IconView.h>
#include <LibConfig/Client.h>
#include <LibGUI/ComboBox.h>
#include <LibGUI/JsonArrayModel.h>
#include <LibGUI/TextBox.h>
#include <LibGUI/Widget.h>

namespace TaskbarSettings {

ErrorOr<NonnullRefPtr<TaskbarSettingsWidget>> TaskbarSettingsWidget::create()
{
    auto widget = TRY(try_create());
    TRY(widget->setup());
    return widget;
}

void TaskbarSettingsWidget::apply_settings()
{
}

void TaskbarSettingsWidget::reset_default_values()
{
}

ErrorOr<void> TaskbarSettingsWidget::setup()
{
    return {};
}

}
