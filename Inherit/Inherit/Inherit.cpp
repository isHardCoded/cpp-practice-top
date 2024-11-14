#include <iostream>
using namespace std;

const int MAX_CHARACTERS = 20;

class Character {
protected:
    string name;
    int health;
    int weapon;
    int attackPower;

public:
    Character(string name, int health, int attackPower) : name(name), health(health), attackPower(attackPower) {}

    virtual void attack(Character& target) {
        cout << name << " атакует " << target.name << " на " << attackPower << " урона!" << endl;
        target.takeDamage(attackPower);
    }

    void takeDamage(int damage) {
        health -= damage;
        cout << name << " получает " << damage << " урона! Осталось здоровья: " << health << endl;
    }
};

class Warrior : public Character {
public:
    Warrior (string name) : Character(name, 100, 15) {}
};

class Knight : public Warrior {
public:
    Knight(string name) : Warrior(name) {}

    void attack(Character& target) override {
        cout << name << " (Рыцарь) использует щит для защиты!" << endl;
        Warrior::attack(target);
    }
};

class Berserker : public Warrior {
public:
    Berserker(string name) : Warrior(name) {}

    void attack(Character& target) override {
        cout << name << " (Берсеркер) в ярости! Урон увеличен!" << endl;
        int increasedAttack = attackPower * 2;
        target.takeDamage(increasedAttack);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Character* characters[MAX_CHARACTERS];
    int characterCount = 0;

    // Создание персонажа
    characters[characterCount++] = new Knight("Biba");
    characters[characterCount++] = new Berserker("Boba");

    characters[0]->attack(*characters[1]); // biba -> boba
    characters[1]->attack(*characters[0]);

    for (int i = 0; i < characterCount; i++) {
        delete characters[i];
    }

    // Задание: реализовать еще 2 класса персонажа и дополнить существующие
}
