#include <iostream>

// Оператор присваивания =

class Point {
private:
    int x;
    int y;

public:
    Point(int xv, int yv) : x(xv), y(yv) {};

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Перегрузка оператора присваивания
    Point& operator=(const Point& other) {
        // 1. Проверка на самоприсваивание
        if (this == &other) {
            return *this;
        }
        // 2. Копирование данных (присваивание)
        x = other.x;
        y = other.y;

        // 3. Возврат ссылки на текущий объект
        return *this;
    }
};

int main()
{
    Point pt1(2, 5);
    Point pt2 = pt1; // конструктор копирования
}
