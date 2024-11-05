#include <iostream>


class Student {
private:
    std::string name;
    std::string group;
    int age;

public:

    Student(std::string n, int a, std::string g) : name(n), age(a), group(g) {}

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Group: " << group << std::endl;
    }
};

template <typename T>

class Database {
private:
    T* array;
    int size;
    int index;

public:
    Database() {};

    Database(int s) : size(s), index(0) {
        array = new T[size];
    }

    ~Database() {
        delete[] array;
    }

    void addStudent(const T& element) {
        array[index++] = element;
    }

    T get(int i) const {
        return array[i];
    }

    void displayAll() const {
        for (int i = 0; i < index; ++i) {
            array[i].display();
        }
    }
};

int main()
{
    Database<Student> db(5);

    db.addStudent(Student("Иван", 18, "Программист"));
    db.addStudent(Student("Boba", 20, "Programmer"));
    db.addStudent(Student("Biba", 20, "Programmer"));

    std::cout << "Info: " << std::endl;
    db.displayAll();

    


}
