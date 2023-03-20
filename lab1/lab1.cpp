#include <iostream>

class Grade
{
private:
	double acquired;
	double maxpoints;
public:
	Grade()
	{
		std::cout << "Grade exist" << std::endl;
	}
	Grade(double acquired, double maxpoints) : acquired(acquired), maxpoints(maxpoints)
	{
		std::cout << "Student acquired " << acquired << " out of " << maxpoints << " possible points" << std::endl;
	}
	double getacquired() const
	{
		return this->acquired;
	}
	double getmax() const
	{
		return this->maxpoints;
	}
	/*
	void reset()
	{
		this->acquired = nullptr;

	}
	*/
	
	Grade(Grade&& other)
	{
		this->acquired = other.acquired;
		this->maxpoints = other.maxpoints;
		//other.reset()

		std::cout << "MOVE" << std::endl;
	}
};
class Gradebook
{
private:
	Grade* g1;
	Grade* g2;
	Grade* g3;
	Grade* g4;
public:
	Gradebook() : g1(nullptr), g2(nullptr), g3(nullptr), g4(nullptr) {}
	Gradebook(const Gradebook& other) : g1(g1), g2(g2), g3(g3), g4(g4) {}
	Grade *getg1()
	{
		return this->g1;
	}
	Grade* getg2()
	{
		return this->g2;
	}
	Grade* getg3()
	{
		return this->g3;
	}
	Grade* getg4()
	{
		return this->g4;
	}
};

int main()
{
	Grade grade1(1, 4);
	Grade grade1(2, 4);
	Grade grade1(3, 4);
	Grade grade1(4, 4);
	return 0;
}