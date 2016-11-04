#ifndef _OBSERVER_H_
#define _OBSERVER_H_

template <class T>
class Observer
{
public:
    Observer() = default;
    virtual ~Observer() = default;
    virtual void update(T *subject) = 0;
};

#endif // _OBSERVER_H_
