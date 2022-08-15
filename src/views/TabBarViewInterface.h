/*
  This file is part of KDDockWidgets.

  SPDX-FileCopyrightText: 2020-2022 Klarälvdalens Datakonsult AB, a KDAB Group company
  <info@kdab.com> Author: Sérgio Martins <sergio.martins@kdab.com>

  SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#pragma once

#include "kddockwidgets/docks_export.h"

QT_BEGIN_NAMESPACE
class QPoint;
class QRect;
class QIcon;
class QString;
QT_END_NAMESPACE

namespace KDDockWidgets {

namespace Controllers {
class DockWidget;
class TabBar;
}

namespace Views {

/// @brief The interface that TabBar views should implement
class DOCKS_EXPORT TabBarViewInterface
{
public:
    explicit TabBarViewInterface(Controllers::TabBar *);
    virtual ~TabBarViewInterface();
    virtual bool tabsAreMovable() const = 0;
    virtual int tabAt(QPoint localPt) const = 0;
    virtual void moveTabTo(int from, int to) = 0;
    virtual QRect rectForTab(int index) const = 0;
    virtual void setCurrentIndex(int index) = 0;
    virtual int numDockWidgets() const = 0;

    virtual void renameTab(int index, const QString &) = 0;
    virtual void changeTabIcon(int index, const QIcon &icon) = 0;

    virtual void removeDockWidget(Controllers::DockWidget *dw) = 0;
    virtual bool insertDockWidget(int index, Controllers::DockWidget *dw, const QIcon &icon,
                                  const QString &title) = 0;

    virtual QString text(int index) const = 0;

protected:
    Controllers::TabBar *const m_tabBar;
};

}

}
