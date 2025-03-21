#include <iostream>
#include <string>

using namespace std;

class BattleUnit 
{
private:
    int health;
    int damage;
    string type;

    static int totalHealth; 
    static int totalDamage;  

public:
    BattleUnit(int health, int damage, const string& type) {
        this->health = health;
        this->damage = damage;
        this->type = type;

        totalHealth += this->health;
        totalDamage += this->damage;
    }

    ~BattleUnit() 
    {
        totalHealth -= this->health;
        totalDamage -= this->damage;
    }

    int getHealth() const { return this->health; }
    int getDamage() const { return this->damage; }
    string getType() const { return this->type; }

    static int getTotalHealth() { return totalHealth; }
    static int getTotalDamage() { return totalDamage; }

    void setHealth(int newHealth) 
    {
        totalHealth -= this->health;  
        this->health = newHealth;     
        totalHealth += this->health;  
    }

    void setDamage(int newDamage) 
    {
        totalDamage -= this->damage;  
        this->damage = newDamage;     
        totalDamage += this->damage;  
    }

    void increaseHealth(int amount) 
    {
        this->health += amount;
        totalHealth += amount;
    }

    void decreaseHealth(int amount) 
    {
        if (amount > this->health) 
        {
            totalHealth -= this->health;
            this->health = 0;
        }
        else 
        {
            totalHealth -= amount;
            this->health -= amount;
        }
    }

    void increaseDamage(int amount) 
    {
        this->damage += amount;
        totalDamage += amount;
    }

    void decreaseDamage(int amount) 
    {
        if (amount > this->damage) 
        {
            totalDamage -= this->damage;
            this->damage = 0;
        }
        else 
        {
            totalDamage -= amount;
            this->damage -= amount;
        }
    }

    void printInfo() const 
    {
        cout << "Type: " << this->type << ", Health: " << this->health << ", Damage: " << this->damage << endl;
    }

    static void printArmyStats() 
    {
        cout << "Total Army Health: " << totalHealth << ", Total Army Damage: " << totalDamage << endl;
    }
};

int BattleUnit::totalHealth = 0;
int BattleUnit::totalDamage = 0;

int main() 
{
    setlocale(LC_ALL, "Ru");

    BattleUnit unit1(100, 20, "Warrior");
    BattleUnit unit2(80, 15, "Archer");

    unit1.printInfo();
    unit2.printInfo();

    BattleUnit::printArmyStats();

    unit1.increaseHealth(50);
    unit2.decreaseDamage(5);

    cout << "\nAfter modifying health and damage:\n";
    unit1.printInfo();
    unit2.printInfo();

    BattleUnit::printArmyStats();
}
