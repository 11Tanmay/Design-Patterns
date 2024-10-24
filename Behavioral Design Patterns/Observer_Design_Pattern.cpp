#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Subscriber
{
public:
    virtual void update() = 0;
};

class ConcreteSubscriber : public Subscriber
{
private:
    int user_id;

public:
    ConcreteSubscriber(int id)
    {
        user_id = id;
    }
    void update() override
    {
        cout << "Subscriber: " << user_id << " was notified." << '\n';
    }
};

class Publisher
{
private:
    list<Subscriber *> subscribers;

public:
    void addSubscriber(Subscriber *subscriber)
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it == subscribers.end())
        {
            subscribers.push_back(subscriber);
        }
    }

    void removeSubscriber(Subscriber *subscriber)
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
        }
    }

    void notifySubscribers()
    {
        for (auto subscriber : subscribers)
        {
            subscriber->update();
        }
    }
};

int32_t main()
{
    Publisher *publisher = new Publisher();

    ConcreteSubscriber *subscriber1 = new ConcreteSubscriber(1);
    ConcreteSubscriber *subscriber2 = new ConcreteSubscriber(2);
    ConcreteSubscriber *subscriber3 = new ConcreteSubscriber(3);

    publisher->addSubscriber(subscriber1);
    publisher->addSubscriber(subscriber2);
    publisher->addSubscriber(subscriber3);

    publisher->notifySubscribers();
    publisher->removeSubscriber(subscriber3);
    publisher->notifySubscribers();

    return 0;
}
