#include <QtTest>
#include <QCoreApplication>


// add necessary includes here
#include <voiture.h>
#include<exception>

class TestVoiture : public QObject
{
    Q_OBJECT

public:
    TestVoiture();
    ~TestVoiture();

private slots:
    void test_constructorDefault();
    void test_constructorComplet();
    void test_constructorModele();
    void test_rouler();
    void test_rouler_Impossible();


};

TestVoiture::TestVoiture()
{

}

TestVoiture::~TestVoiture()
{

}

void TestVoiture::test_constructorDefault()
{
    //given: pas de given prsk on a construit la voiture a partir de rien
    //when
    Voiture voiture;
    //then
    QCOMPARE(voiture.modele(), "");
    QCOMPARE(voiture.kilometrage(), 0);
    QCOMPARE(voiture.jaugeCarburant(), 0);
}

void TestVoiture::test_constructorComplet()
{
    //given
    QString modele = "Renault Scenic";
    int kilometrage = 192000;
    int jaugeCarburant = 2000; //en cl
    //when
    Voiture voiture(modele, kilometrage, jaugeCarburant);
    //then
    QCOMPARE(voiture.modele(), modele);
    QCOMPARE(voiture.kilometrage(), kilometrage);
    QCOMPARE(voiture.jaugeCarburant(), jaugeCarburant);
}

void TestVoiture::test_constructorModele()
{
    //given
    QString modele = "Renault Scenic";

    //when
    Voiture voiture(modele);
    //then
    QCOMPARE(voiture.modele(), modele);

}

void TestVoiture::test_rouler()
{
    //old car: kilometrage: >= 150000 et consomme 5 l/100km

    //given: an old car

    int kmStart = 160000;
    int jaugeStart = 1500;

    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100;
    //when
    voiture.rouler(distance);
    //then
    QCOMPARE(voiture.kilometrage() , kmStart + distance);
    QCOMPARE(voiture.jaugeCarburant() ,jaugeStart - distance * 10);
}

void TestVoiture::test_rouler_Impossible()
{
    //scenario pour verifier que le code est protege
    //on verifie en provoquant une erreur et on s'att a ce que le test echoue
    //given: an old car

    int kmStart = 160000;
    int jaugeStart = 1500;

    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 200; //trop de km par rapport a la jauge
    //when
    voiture.rouler(distance);
    //then
    QVERIFY_EXCEPTION_THROWN(voiture.rouler(distance), std::invalid_argument());
    QCOMPARE(voiture.kilometrage(), kmStart);
    QCOMPARE(voiture.jaugeCarburant(), jaugeStart);
}

QTEST_MAIN(TestVoiture)

#include "tst_testvoiture.moc"
