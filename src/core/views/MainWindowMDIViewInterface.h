/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2019-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/


#ifndef KD_MAINWINDOW_MDI_INTERFACE_H
#define KD_MAINWINDOW_MDI_INTERFACE_H
#pragma once

#include "kddockwidgets/KDDockWidgets.h"

namespace KDDockWidgets {

namespace Core {

class DockWidget;
class MDILayout;
class DockWidgetViewInterface;

/// @brief Interface for MainWindowMDI views
class DOCKS_EXPORT MainWindowMDIViewInterface
{
public:
    explicit MainWindowMDIViewInterface(MDILayout *);

    ///@brief Docks @p dockWidget
    /// The widget will be placed at the specified position
    void addDockWidget(DockWidgetViewInterface *dockWidget, Point localPos,
                       InitialOption addingOption = {});

    ///@brief Convenience overload
    void addDockWidget(DockWidgetViewInterface *dockWidget, PointF localPos,
                       InitialOption addingOption = {});

private:
    MDILayout *const m_mdiLayout;
};

}

}

#endif
