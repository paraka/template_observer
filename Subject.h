#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include "Observer.h"

template <class T>
class Subject
{
public:
    Subject() = default;

    virtual ~Subject() = default;
    
    void register_observer(Observer<T> &observer)
    {
        vector_observers.push_back(&observer);
    }

    void unregister_observer(Observer<T> &observer)
    {
        vector_observers.erase(std::remove(std::begin(vector_observers), 
                                            std::end(vector_observers), &observer), std::end(vector_observers));
    }

    void notify()
    {
        for (const auto &observer : vector_observers)
            (*observer).update(static_cast<T *>(this));
    }

private:
    std::vector<Observer<T> *> vector_observers;
};

#endif // _SUBJECT_H_
