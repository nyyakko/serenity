/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "WindowIdentifier.h"
#include <LibGUI/Button.h>

class TaskbarButton final : public GUI::Button {
    C_OBJECT(TaskbarButton)
public:
    virtual ~TaskbarButton() override = default;

    void update_taskbar_rect();
    void clear_taskbar_rect();

    static ErrorOr<NonnullRefPtr<TaskbarButton>> create(WindowIdentifier const& identifier)
    {
        auto button = TaskbarButton::construct(identifier);
        button->m_instances_show_timer = TRY(Core::Timer::create_single_shot(700, [] {
            dbgln("hello!");
        }));
        return button;
    }

private:
    explicit TaskbarButton(WindowIdentifier const&);

    virtual void context_menu_event(GUI::ContextMenuEvent&) override;
    virtual void resize_event(GUI::ResizeEvent&) override;
    virtual void paint_event(GUI::PaintEvent&) override;

    inline virtual void enter_event(Core::Event&) override
    {
        m_instances_show_timer->restart();
    }

    inline virtual void leave_event(Core::Event&) override
    {
        m_instances_show_timer->stop();
    }

    WindowIdentifier m_identifier;
    RefPtr<Core::Timer> m_instances_show_timer;
};
