#include <iostream>
#include <ctime>
using namespace std;

const int MAX_CHARACTERS = 20;

class Character {
protected:
    string name;
    string weapon;
    int health;
    int attackPower;

public:
    Character(string n, int h, int ap) : name(n), health(h), attackPower(ap) {}

    virtual void attack(Character& target) {
        if (health <= 0) {
            cout << name << " не может атаковать, так как здоровье равно нулю." << endl;
            return;
        }
        cout << name << " атакует " << target.name << " на " << attackPower << " урона." << endl;
        target.takeDamage(attackPower);
    }

    void takeDamage(int damage) {
        health -= damage;
        cout << name << " осталось здоровья: " << health << endl;
    }

    virtual void heal() {
        health += 20;
        cout << name << " вылечился до " << health << " здоровья." << endl;
    }

    void displayStatus() const {
        cout << "Имя: " << name << ", Здоровье: " << health << ", Урон: " << attackPower << endl;
    }

    int getAttackPower() {
        return attackPower;
    }

    void setAttackPower(int ap) {
        attackPower = ap;
    }

    string getName() {
        return name;
    }

    bool isAlive() const {
        return health > 0;
    }
};

class Warrior : public Character {
public:
    Warrior(string n) : Character(n, 100, 15) {}

    void boostPower(int a) {
        setAttackPower(getAttackPower() + a);
        cout << name << " получил бафф на силу атаки на " << a << "." << endl;
    }

    void boostHealth(int b) {
        health += b;
        cout << name << " получил броню, здоровье теперь: " << health << "." << endl;
    }
};

class Knight : public Warrior {
public:
    Knight(string n) : Warrior(n) {}

    void attack(Character& target) override {
        if (health <= 0) {
            cout << name << " не может атаковать, так как здоровье равно нулю." << endl;
            return;
        }
        cout << name << " Рыцарь использует щит для защиты." << endl;
        Warrior::attack(target);
    }
};

class Berserker : public Warrior {
public:
    Berserker(string n) : Warrior(n) {}

    void attack(Character& target) override {
        if (health <= 0) {
            cout << name << " не может атаковать, так как здоровье равно нулю." << endl;
            return;
        }
        cout << name << " Берсерк использует силу для увеличения урона." << endl;
        int increasedAttack = getAttackPower() * 2;
        target.takeDamage(increasedAttack);
    }
};

class Archer : public Warrior {
public:
    Archer(string n) : Warrior(n) {}

    void attack(Character& target) override {
        if (health <= 0) {
            cout << name << " не может атаковать, так как здоровье равно нулю." << endl;
            return;
        }
        cout << name << " Лучник использует 2 стрелы для увеличения урона." << endl;
        int increasedAttack = getAttackPower() * 10;
        target.takeDamage(increasedAttack);
    }

    void heal() override {
        health += 100;
        cout << name << " вылечился до " << health << " здоровья." << endl;
    }

    void buff(Character& target) {
        int buffAttack = 10;
        target.setAttackPower(target.getAttackPower() + buffAttack);
        cout << getName() << " наложил смертельный бафф на " << target.getName() << " на: " << buffAttack << endl;

    }
};

void randomAction(Character* characters[], int characterCount) {
    int action = rand() % 2; // 0 - attack, 1 - heal
    int attackerIndex = rand() % characterCount;
    int targetIndex = rand() % characterCount;

    while (targetIndex == attackerIndex) {
        targetIndex = rand() % characterCount;
    }

    if (action == 0) {
        if (characters[attackerIndex]->isAlive() && characters[targetIndex]->isAlive()) {
            characters[attackerIndex]->attack(*characters[targetIndex]);
        }
    }

    else {
        if (characters[attackerIndex]->isAlive()) {
            characters[attackerIndex]->heal();
        }
    }

}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    Character* characters[MAX_CHARACTERS];
    int characterCount = 0;

    characters[characterCount++] = new Knight("Биба");
    characters[characterCount++] = new Berserker("Боба");
    characters[characterCount++] = new Archer("Лучник");

    while (true) {

        int aliveCount = 0;

        for (int i = 0; i < characterCount; ++i) {
            if (characters[i]->isAlive()) {
                aliveCount++;
            }
        }

        if (aliveCount <= 1) {
            cout << "Игра окончена!" << endl;
            break;
        }

        randomAction(characters, characterCount);

        cout << "\nСтатус персонажей: " << endl;
        for (int i = 0; i < characterCount; ++i) {
            characters[i]->displayStatus();
        }

        cout << "-------------------------------------------" << endl;

        system("pause");
    }

    for (int i = 0; i < characterCount; ++i) {
        delete characters[i];
    }

    return 0;
}