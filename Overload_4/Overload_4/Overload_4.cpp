#include <iostream>

class Circle {
private:
	double radius;
	double pi = 3.14;

public:
	Circle(double r) : radius(r) {
		if (radius < 0) {
			radius = 0;
		}
	}

	// Перегрузка операторов сравнения
	bool operator>(const Circle& other) const {
		return getLengthCircle() > other.getLengthCircle();
	}

	bool operator<(const Circle& other) const {
		return getLengthCircle() < other.getLengthCircle();
	}

	// Перегрузка оператора равенства
	bool operator==(const Circle& other) const {
		return radius == other.radius;
	}

	// Перегрузка инкремента (++) и декемента (--)
	Circle& operator+=(double value) {
		radius += value;

		if (radius < 0) {
			radius = 0;
		}

		return *this;
	}

	Circle& operator-=(double value) {
		radius -= value;

		if (radius < 0) {
			radius = 0;
		}

		return *this;
	}


	double getLengthCircle() const {
		return 2 * pi * radius;
	}

	double getRadius() const {
		return radius;
	}
};

int main()
{
	Circle c1(12.0);
	Circle c2(10.0);

	std::cout << "c1 radius: " << c1.getRadius() << std::endl;
	std::cout << "c1 radius was ++ 10.0" << std::endl;
	c1 += 10.0;
	std::cout << "c1 radius: " << c1.getRadius() << std::endl;
	std::cout << "c1 radius was -- 5.0" << std::endl;
	c1 -= 5.0;
	std::cout << "c1 radius: " << c1.getRadius() << std::endl;
}
