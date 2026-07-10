#pragma once

#include <QColor>
#include <QFileSystemWatcher>
#include <QMutex>
#include <QObject>

#include "lingmo-base/singleton.h"
#include "lingmo-base/stdafx.h"
#include "lingmoaccentcolor.h"
#include "export.h"

namespace Lingmo::Appearance {

enum class DarkMode {
    System = 0x0000,
    Light = 0x0001,
    Dark = 0x0002,
};

class LINGMO_APPEARANCE_EXPORT LingmoTheme : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool dark READ dark NOTIFY darkChanged)
    Q_PROPERTY_AUTO_P(LingmoAccentColor*, accentColor)
    Q_PROPERTY_AUTO(QColor, primaryColor)
    Q_PROPERTY_AUTO(QColor, backgroundColor)
    Q_PROPERTY_AUTO(QColor, dividerColor)
    Q_PROPERTY_AUTO(QColor, windowBackgroundColor)
    Q_PROPERTY_AUTO(QColor, windowActiveBackgroundColor)
    Q_PROPERTY_AUTO(QColor, fontPrimaryColor)
    Q_PROPERTY_AUTO(QColor, fontSecondaryColor)
    Q_PROPERTY_AUTO(QColor, fontTertiaryColor)
    Q_PROPERTY_AUTO(QColor, itemNormalColor)
    Q_PROPERTY_AUTO(QColor, frameColor)
    Q_PROPERTY_AUTO(QColor, frameActiveColor)
    Q_PROPERTY_AUTO(QColor, itemHoverColor)
    Q_PROPERTY_AUTO(QColor, itemPressColor)
    Q_PROPERTY_AUTO(QColor, itemCheckColor)
    Q_PROPERTY_AUTO(QString, desktopImagePath)
    Q_PROPERTY_AUTO(int, darkMode)
    Q_PROPERTY_AUTO(bool, nativeText)
    Q_PROPERTY_AUTO(bool, animationEnabled)
    Q_PROPERTY_AUTO(bool, blurBehindWindowEnabled)

private:
    explicit LingmoTheme(QObject* parent = nullptr);

    bool eventFilter(QObject* obj, QEvent* event) override;
    void refreshColors();

protected:
    void timerEvent(QTimerEvent* event) override;
    void checkUpdateDesktopImage();

public:
    SINGLETON(LingmoTheme)

    Q_SIGNAL void darkChanged();
    bool dark() const;

private:
    bool _systemDark;
    QFileSystemWatcher _watcher;
    QMutex _mutex;
};

} // namespace Lingmo::Appearance
