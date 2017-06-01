#include <iostream>
#include <random>
#include <functional>
#include <time.h>
using namespace std;

void OldRandFunction()
{
	srand(time(nullptr));
	for (int i = 0; i < 5; i++)
	{
		cout << rand() % 100 << endl;
	}
}

void NewRandFunction()
{
	std::uniform_int_distribution<int> distribution(0, 99);
	std::mt19937 engine(time(nullptr));
	auto generator = std::bind(distribution, engine);
	for (int i = 0; i < 5; i++)
	{
		cout << generator() << endl;
	}
}

int main()
{
	OldRandFunction();
	NewRandFunction();
}