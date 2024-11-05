#include <iostream>
using namespace std;

template <typename T>

class Array {

private:
	T* data;
	size_t size;

public:
	Array(size_t s) : size(s) {
		if (s == 0) {
			cout << "Size < 0" << endl;
		}

		data = new T[size];
	}

	~Array() {
		delete[] data;
	}

	void setElement(size_t index, T value) {
		if (index >= size) {
			cout << "Index out of range" << endl;
		}

		data[index] = value;
	}

	T getElement(size_t index) const {
		if (index >= size) {
			cout << "Index out of range" << endl;
		}

		return data[index];
	}

	size_t getSize() const {
		return size;
	}
};

int main()
{
	Array<int> intArray(3);
	intArray.setElement(0, 10);
	intArray.setElement(1, 15);
	intArray.setElement(2, 20);

	cout << "intArray[0]: " << intArray.getElement(0) << endl; // 10
	cout << "intArray[1]: " << intArray.getElement(1) << endl; // 15
	cout << "intArray[2]: " << intArray.getElement(2) << endl; // 20

	Array<double> doubleArray(3);
	doubleArray.setElement(0, 3.14);
	doubleArray.setElement(1, 10.3);
	doubleArray.setElement(2, 465.2);

	cout << "doubleArray[0]: " << doubleArray.getElement(0) << endl; // 3.14
	cout << "doubleArray[1]: " << doubleArray.getElement(1) << endl; // 10.3
	cout << "doubleArray[2]: " << doubleArray.getElement(2) << endl; // 465.2

	Array<string> stringArray(1);
	stringArray.setElement(0,"C++");
	cout << "stringArray[0]: " << stringArray.getElement(0) << endl;

}