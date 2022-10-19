#include "gtest/gtest.h"
//#include "colony.h"
#include "antlogic.h"

class antSpy: public antLogic
{
public:
    float* get_mRot() {return mRot;}
    float* get_mxPos() {return mxPos;}
    float* get_myPos() {return myPos;}
    float get_mRot_value() {return *mRot;}
    float get_mxPos_value() {return *mxPos;}
    float get_myPos_value() {return *myPos;}
};

class antTester: public antLogic, public ::testing::Test
{
protected:
    antSpy bob;
};

TEST_F(antTester, GivenAnAntClass_WhenCallingANewAnt_ExpectNoErrorsThrown)
{
    ASSERT_NO_THROW(antLogic jerald);
}

TEST_F(antTester, GivenAnAntClass_WhenCallingNewAnt_ExpectNonNullPointerRotation)
{
    ASSERT_TRUE(bob.get_mRot() != nullptr);
}

TEST_F(antTester, GivenAnAntClass_WhenCallingNewAnt_ExpectNonNullPointerPositions)
{
    ASSERT_TRUE(bob.get_mxPos() != nullptr);
    ASSERT_TRUE(bob.get_myPos() != nullptr);
}

TEST_F(antTester, GivenAnAnt_WhenSettingPositions_ExpectValuesToMatch)
{
    bob.SetPos(100,150);
    EXPECT_EQ(100, bob.get_mxPos_value());
    EXPECT_EQ(150, bob.get_myPos_value());
    bob.SetPos(-100,-150);
    EXPECT_EQ(-100, bob.get_mxPos_value());
    EXPECT_EQ(-150, bob.get_myPos_value());
}

TEST_F(antTester, GivenAnAnt_WhenSettingRotation_ExpectValueToMatch)
{
    bob.SetRot(100);
    EXPECT_EQ(100, bob.get_mRot_value());
}

TEST_F(antTester, GivenAnAnt_WhenSettingRotationHigherThan360_ExpectValueToBeReducedToProperAngle)
{
    bob.SetRot(460);
    EXPECT_EQ(100, bob.get_mRot_value());
    bob.SetRot(1180);
    EXPECT_EQ(100, bob.get_mRot_value());
}

TEST_F(antTester, GivenanAntWithRotation_WhenCallingForwardFunction_ExpectCorrectVectorBack)
{

}
