#ifndef ANTLIFE_ANT_H_
#define ANTLIFE_ANT_H_

class Ant
{
	public:
		static const int MAX_AGE;
		static const float AGE_VARIANCE;
		Ant();
		bool isAlive();
		int getAge();
		bool update();
	private:
		int age;
		int ageLimit;
};

#endif //ANTLIFE_ANT_H_
