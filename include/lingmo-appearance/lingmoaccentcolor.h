#pragma once

#include <QColor>
#include <QObject>

#include "lingmo-base/stdafx.h"
#include "export.h"

namespace Lingmo::Appearance {

class LINGMO_APPEARANCE_EXPORT LingmoAccentColor : public QObject {
    Q_OBJECT

    Q_PROPERTY_AUTO(QColor, darkest)
    Q_PROPERTY_AUTO(QColor, darker)
    Q_PROPERTY_AUTO(QColor, dark)
    Q_PROPERTY_AUTO(QColor, normal)
    Q_PROPERTY_AUTO(QColor, light)
    Q_PROPERTY_AUTO(QColor, lighter)
    Q_PROPERTY_AUTO(QColor, lightest)

public:
    explicit LingmoAccentColor(QObject* parent = nullptr);
};

} // namespace Lingmo::Appearance
