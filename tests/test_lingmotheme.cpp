#include <QtTest/QtTest>
#include <QCoreApplication>

#include "lingmo-appearance/lingmotheme.h"
#include "lingmo-appearance/lingmocolor.h"

class TestLingmoAppearance : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testThemeSingleton();
    void testColorSingleton();
    void testDarkMode();
    void testAccentColors();
    void testColorPalette();

private:
    Lingmo::Appearance::LingmoTheme* theme;
    Lingmo::Appearance::LingmoColor* color;
};

void TestLingmoAppearance::initTestCase()
{
    theme = Lingmo::Appearance::LingmoTheme::getInstance();
    color = Lingmo::Appearance::LingmoColor::getInstance();
    QVERIFY(theme != nullptr);
    QVERIFY(color != nullptr);
}

void TestLingmoAppearance::cleanupTestCase()
{
}

void TestLingmoAppearance::testThemeSingleton()
{
    auto* t1 = Lingmo::Appearance::LingmoTheme::getInstance();
    auto* t2 = Lingmo::Appearance::LingmoTheme::getInstance();
    QCOMPARE(t1, t2);
}

void TestLingmoAppearance::testColorSingleton()
{
    auto* c1 = Lingmo::Appearance::LingmoColor::getInstance();
    auto* c2 = Lingmo::Appearance::LingmoColor::getInstance();
    QCOMPARE(c1, c2);
}

void TestLingmoAppearance::testDarkMode()
{
    theme->darkMode(static_cast<int>(Lingmo::Appearance::DarkMode::Light));
    QVERIFY(!theme->dark());

    theme->darkMode(static_cast<int>(Lingmo::Appearance::DarkMode::Dark));
    QVERIFY(theme->dark());
}

void TestLingmoAppearance::testAccentColors()
{
    QVERIFY(color->Yellow() != nullptr);
    QVERIFY(color->Orange() != nullptr);
    QVERIFY(color->Red() != nullptr);
    QVERIFY(color->Magenta() != nullptr);
    QVERIFY(color->Purple() != nullptr);
    QVERIFY(color->Blue() != nullptr);
    QVERIFY(color->Teal() != nullptr);
    QVERIFY(color->Green() != nullptr);

    QVERIFY(color->Blue()->normal().isValid());
}

void TestLingmoAppearance::testColorPalette()
{
    QVERIFY(color->Black().isValid());
    QVERIFY(color->White().isValid());
    QVERIFY(color->Grey10().isValid());
    QVERIFY(color->Grey220().isValid());
    QCOMPARE(color->Transparent().alpha(), 0);
}

QTEST_MAIN(TestLingmoAppearance)
#include "test_lingmotheme.moc"
