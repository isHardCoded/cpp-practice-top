#include <iostream>

// Шаблоны классов
template <typename T1, typename T2, typename T3>

class Pair {
private:
	T1 first;
	T2 second;
	T3 test;

public:
	Pair(T1 f, T2 s, T3 t) : first(f), second(s), test(t) {}

	T1 getFirst() const {
		return first;
	}

	T2 getSecond() const {
		return second;
	}

	T3 getTest() const {
		return test;
	}
};

int main()
{
	// Создать разные пары значений с разными типами данных
	// для разных объектов

	Pair<std::string, double, int> intPair("Hello", 1.3, 3);
	Pair<char, double, int> intPair(9, 1.3, 3);

}