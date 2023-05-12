#pragma once

template <class T>
class Link {
private:
    T data;
public:
    Link<T>* next;

    Link(T data) {
        next = 0;
        this->data = data;
    }
    
    T GetData() {
        return data;
    }
};
