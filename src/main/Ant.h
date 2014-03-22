#ifndef ANTLIFE_ANT_H_
#define ANTLIFE_ANT_H_

class Ant
{
	public:
		Ant();
		bool isAlive();
		int getAge();
		void update();
	private:
		int age;
};

#endif //ANTLIFE_ANT_H_
