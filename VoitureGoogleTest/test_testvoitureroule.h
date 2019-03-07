#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h> //simulation proche des conditions reelles
#include "voiture.h"

#include<QDebug>

using namespace testing;

TEST(TestVoitureRouler, oldCar)
{

    int kmStart = 160000;
    int jaugeStart = 1500;

    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100; //trop de km par rapport a la jauge
    //when
    voiture.rouler(distance);
    //then


    EXPECT_EQ(voiture.jaugeCarburant(), jaugeStart - distance*10) << "km incorrect";//s'affiche si fail
    EXPECT_EQ(voiture.kilometrage(), kmStart + distance)<<"jauge incorrect";

    //ASSERT_THAT(0, Eq(0));
}

TEST(TestVoitureRouler, recentCar)
{

    int kmStart = 10000;
    int jaugeStart = 1500;

    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100; //trop de km par rapport a la jauge

    //when
    voiture.rouler(distance);
    //then

    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jaugeStart - distance*5)) << "km incorrect";//s'affiche si fail
    EXPECT_THAT(voiture.kilometrage(), Eq(kmStart + distance))<<"jauge incorrect";


}

TEST(TestVoitureRouler, oldCarNoGaz)
{

    int kmStart = 160000;
    int jaugeStart = 1500;

    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 300; //trop de km par rapport a la jauge

    //faut pas faire le when ici sinon il va pas marcher prsk sinon
    //il va se rendre compte que la voiture ne roule pas et fait un fatal et arrete les tests
    //voiture.rouler(distance);
    //then

    EXPECT_THROW(voiture.rouler(distance), std::invalid_argument);
}

//pour jouer sur les parametres et tester plusieurs cas: Test_P
//il faut declarer une classe de ce type test et on l'a fait heriter
//de

class TestVoitureRecenteRouler : public TestWithParam<int>{

};
TEST_P(TestVoitureRecenteRouler, Range)
{
    //le parametre a parametrer est int d'ou l'heritage de testwithparam int
    int kmStart = GetParam();
    int jaugeStart = 1500;

    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100; //trop de km par rapport a la jauge

    //when
    voiture.rouler(distance);
    //then

    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jaugeStart - distance*5)) << "km incorrect";//s'affiche si fail
    EXPECT_THAT(voiture.kilometrage(), Eq(kmStart + distance))<<"jauge incorrect";


}
//test fixture
class TestOldVoitureRouler : public Test {
protected:
    int kmStart ;
    int jaugeStart;
    Voiture oldCar;

    void SetUp() override{
        kmStart = 160000;
        jaugeStart = 1500;
        oldCar.setKilometrage(kmStart);
        oldCar.setJaugeCarburant(jaugeStart);
        oldCar.setModele("Ford Mustang 1967");
    }
    //un nettoyage si ona fait de l'alloc dynamiq
    void TearDown() override{
        qDebug() << "Do some cleaning";
    }
};

//class filles qui herite de test old voiture rouler
TEST_F(TestOldVoitureRouler, ok)
{

    int distance = 100; //trop de km par rapport a la jauge
    //when
    oldCar.rouler(distance);
    //then

    EXPECT_EQ( oldCar.kilometrage(), kmStart + distance)<<"kilometrage incorrect";
    EXPECT_EQ( oldCar.jaugeCarburant(), jaugeStart - distance*10) << "jauge carburant incorrect";//s'affiche si fail

    //ASSERT_THAT(0, Eq(0));
}

TEST_F(TestOldVoitureRouler, NoGaz)
{

    //given
    int distance = 300; //trop de km par rapport a la jauge

    //when/then
    EXPECT_THROW( oldCar.rouler(distance), std::invalid_argument);
}

//INSTANTIATE_TEST_SUITE_P(GroupVoitureRecente,TestVoitureRecenteRouler(nom du test), (valeur pour param) values(0, 10000, 149999))
INSTANTIATE_TEST_SUITE_P(GroupVoitureRecente,TestVoitureRecenteRouler,
                         //Values(0, 10000, 149999, 150000, 150001)
                         Range(0,150000,10000));


//#ifndef TEST_TESTVOITUREROULE_H
//#define TEST_TESTVOITUREROULE_H

//#endif // TEST_TESTVOITUREROULE_H
