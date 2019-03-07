#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h> //simulation proche des conditions reelles
#include "voiture.h"

using namespace testing;

/*TEST(TestVoitureConstructor, Default)
{

    //si assert n'est pas verifié il s'arrete
    //alors que except il note les erreurs et continue qd mm

    Voiture voiture;
    EXPECT_EQ(voiture.kilometrage(), 0); //basé sur des == se mefier alors des string
    //ASSERT_THAT(0, Eq(0));
}*/

TEST(TestVoitureConstructor, Complet)
{

    //si assert n'est pas verifié il s'arrete
    //alors que except il note les erreurs et continue qd mm
    QString modele ="Ferrari F40";
    int km = 20000;
    int jauge = 5000;
    Voiture voiture(modele, km, jauge);
    EXPECT_EQ(voiture.modele(), modele);
    EXPECT_EQ(voiture.jaugeCarburant(), jauge);
    EXPECT_EQ(voiture.kilometrage(), km);

    //ASSERT_THAT(0, Eq(0));
}
