#include <iostream>

class Multiplier {
	public:
		Multiplier(int m): multiplier(m) {}
		int operator()(int x, bool b)
		{
			if (b)
				return multiplier * x;
			else
				return 0;
		}
	private:
		int multiplier;
};

int main ()
{

	Multiplier m(5);
	std::cout << m(4, true) << std::endl;
	std::cout << m(4, false) << std::endl;

	return 0;

}
