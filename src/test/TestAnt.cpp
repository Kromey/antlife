#include "gtest/gtest.h"
#include "Ant.h"

TEST(AntTest, NewAntIsAlive)
{
	Ant a1;
	EXPECT_TRUE(a1.isAlive());
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

TEST(AntTest, AntDiesOfOldAge)
{
	int minAge, maxAge;
	minAge = 0.8 * Ant::MAX_AGE;
	maxAge = 1.2 * Ant::MAX_AGE;
	for(int i=0; i < 10; ++i)
	{
		Ant a1;
		while(a1.update())
		{
			if(a1.getAge() > maxAge)
			{
				break;
			}
		}
		EXPECT_FALSE(a1.isAlive());
		EXPECT_TRUE(a1.getAge() >= minAge);
		EXPECT_TRUE(a1.getAge() <= maxAge);
	}
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
