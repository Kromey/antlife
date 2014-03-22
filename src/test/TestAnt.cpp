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
	int minAgeLimit, maxAgeLimit;
	bool ageVaries = false;
	minAgeLimit = (1.0 - Ant::AGE_VARIANCE) * Ant::MAX_AGE;
	maxAgeLimit = (1.0 + Ant::AGE_VARIANCE) * Ant::MAX_AGE;
	for(int i=0; i < 1000; ++i)
	{
		Ant a1;
		while(a1.update())
		{
			if(a1.getAge() > maxAgeLimit)
			{
				break;
			}
		}
		EXPECT_FALSE(a1.isAlive());
		EXPECT_TRUE(a1.getAge() >= minAgeLimit);
		EXPECT_TRUE(a1.getAge() <= maxAgeLimit);
		ageVaries = a1.getAge() != Ant::MAX_AGE;
	}
	EXPECT_TRUE(ageVaries);
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
