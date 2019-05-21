#include <QString>
#include <QtTest>
#include <QCoreApplication>

class SampleTest;
#define QTTEST_OBJECT friend class SampleTest;

#include "BaseWindow.h"
#include "ui_BaseWindow.h"
#include "common.h"

class SampleTest : public QObject
{
    Q_OBJECT

public:
    SampleTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1_data();
    void testCase1();

private:
    BaseWindow* mTargetWindow;
};

SampleTest::SampleTest()
{
}

void SampleTest::initTestCase()
{
    mTargetWindow = new BaseWindow();
}

void SampleTest::cleanupTestCase()
{
}

void SampleTest::testCase1_data()
{
    QTest::addColumn<QString>("data");
    QTest::addColumn<QString>("result");
    QTest::newRow("input test")<< QString("test") << QString("test");
    QTest::newRow("input hello")<< QString("hello") << QString("hello");
    QTest::newRow("input てすと")<< QString("てすと") << QString("てすと");
}

void SampleTest::testCase1()
{
    QFETCH(QString, data);
    //QFETCH(QString, result);

    QTest::keyClicks(mTargetWindow->ui->inputText, data);
    QTest::mouseClick(mTargetWindow->ui->sendButton, Qt::LeftButton);


    QCOMPARE(mTargetWindow->ui->outputText->text(), data);

    mTargetWindow->ui->inputText->clear();
}

QTEST_MAIN(SampleTest)

#include "tst_SampleTest.moc"
