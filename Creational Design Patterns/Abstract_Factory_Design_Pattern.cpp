#include <iostream>
using namespace std;

class Jet
{
public:
    virtual void fly() {};
};

class CommercialJet : public Jet
{
public:
    void fly()
    {
        cout << "This is a Commercial Jet." << '\n';
    }
};

class BattleJet : public Jet
{
public:
    void fly()
    {
        cout << "This is a Battle Jet." << '\n';
    }
};

class Ship
{
public:
    virtual void sail() {};
};

class CommercialShip : public Ship
{
public:
    void sail()
    {
        cout << "This is a Commercial Ship." << '\n';
    }
};

class BattleShip : public Ship
{
public:
    void sail()
    {
        cout << "This is a Battle Ship." << '\n';
    }
};

class AbstractFactory
{
public:
    virtual Jet *createJet() = 0;
    virtual Ship *createShip() = 0;
};

class CommercialFactory : public AbstractFactory
{
public:
    Jet *createJet()
    {
        return new CommercialJet();
    }
    Ship *createShip()
    {
        return new CommercialShip();
    }
};

class BattleFactory : public AbstractFactory
{
public:
    Jet *createJet()
    {
        return new BattleJet();
    }
    Ship *createShip()
    {
        return new BattleShip();
    }
};

class ConcreteFactory
{
public:
    static AbstractFactory *getFactory(string type)
    {
        if (type == "commercial")
        {
            return new CommercialFactory();
        }
        if (type == "battle")
        {
            return new BattleFactory();
        }
        return nullptr;
    }
};

int32_t main()
{
    AbstractFactory *commercial_factory = ConcreteFactory::getFactory("commercial");
    AbstractFactory *battle_factory = ConcreteFactory::getFactory("battle");

    Ship *commercial_ship = commercial_factory->createShip();
    Jet *commercial_jet = commercial_factory->createJet();

    Ship *battle_ship = battle_factory->createShip();
    Jet *battle_jet = battle_factory->createJet();

    commercial_ship->sail();
    commercial_jet->fly();

    battle_ship->sail();
    battle_jet->fly();

    return 0;
}