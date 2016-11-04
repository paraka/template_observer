#include <iostream>
#include "Subject.h"

class ConcreteSubject : public Subject<ConcreteSubject>
{
public:
    ConcreteSubject() = default;
    
    ~ConcreteSubject() = default;
    
    std::string get_data() const { return data_; }

    void foo()
    {
        data_ = "foo";
        notify();
    }

private:
    std::string data_;
};

class ConcreteObserver : public Observer<ConcreteSubject>
{
public:
    ConcreteObserver() = default;

    ~ConcreteObserver() = default;

    void update(ConcreteSubject *subject)
    {
        std::cout << "Got data: " << subject->get_data() << std::endl;
    }
};

int main()
{
    ConcreteSubject cs;
    ConcreteObserver o;

    cs.register_observer(o);
    cs.foo();

    return 0;
}
