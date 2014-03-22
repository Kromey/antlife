#ifndef ANTLIFE_ANT_H_
#define ANTLIFE_ANT_H_

class Ant
{
	public:
		static const int MAX_AGE;
		Ant();
		bool isAlive();
		int getAge();
		void update();
	private:
		int age;
};

#endif //ANTLIFE_ANT_H_
