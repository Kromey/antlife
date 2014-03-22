#include "gtest/gtest.h"
#include "Ant.h"

TEST(AntTest, NewAntIsAlive)
{
	Ant a1;
	EXPECT_EQ(true, a1.isAlive());
}

TEST(AntTest, NewAntIsAgeZero)
{
	Ant a1;
	EXPECT_EQ(0, a1.getAge());
}

TEST(AntTest, AntAgesAfterUpdate)
{
	Ant a1;
	a1.update();
	EXPECT_EQ(1, a1.getAge());
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
