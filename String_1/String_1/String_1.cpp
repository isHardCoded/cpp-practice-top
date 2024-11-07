#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string firstName;
	string lastName;
	string studentID;
	int age;

public:
	Student(string fName, string lName, string id, int a) {
		firstName = fName;
		lastName = lName;
		studentID = id;
		age = a;
	}

	string getFullName() const {
		return lastName + ", " + firstName;
	}

	string getInfo() const {
		return "Имя: " + firstName + "\nФамилия: " + lastName + "\nВозраст: " + to_string(age) + "\nНомер зачетной книжки: " + studentID + "\n";
	}
};

class StudentList {
private:
	Student** students;
	int size;
	int c;

	void newArray() {

		c *= 2;
		Student** newStudents = new Student * [c];

		for (int i = 0; i < size; ++i) {
			newStudents[i] = students[i];
		}

		delete[] students;
		students = newStudents;
	}

public:
	StudentList() : students(new Student* [2]), size(0), c(2) {}

	void addStudent(const Student& student) {
		if (size == c) {
			newArray();
		}

		students[size++] = new Student(student);
	}

	void displayAllStudents() const {
		for (int i = 0; i < size; ++i) {
			cout << students[i]->getInfo() << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "RU");

	StudentList list;

	list.addStudent(Student("Boba", "Bibovich", "100", 20));
	list.addStudent(Student("Biba", "Bobovich", "110", 18));

	cout << "All students: " << endl;
	list.displayAllStudents();

}
