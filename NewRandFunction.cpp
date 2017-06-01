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

void BernoulliFunction()
{
	//Calculate the probability
	cout << "BernoulliFunction" << endl;
	std::default_random_engine engine(time(nullptr));
	std::bernoulli_distribution bernoulli(0.1);
	auto bResult = std::bind(bernoulli, engine);
	for (int i = 0; i < 100; i++)
	{
		if (bResult())
		{
			cout << "good" << endl;
		}
	}
}

int main()
{
	OldRandFunction();
	NewRandFunction();
	BernoulliFunction();
}