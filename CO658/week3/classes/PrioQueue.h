#pragma once

template <class T>
class PrioQueue {
private:
    int count;
    T* data;
    int size;
public:
    PrioQueue(int size) {
        this->size = size;
        this->data = new T[size];
        this->count = 0;
    };

    ~PrioQueue() {
        delete data;
    };

    void Insert(T item) {
        if (IsEmpty()) {
            data[count++] = item;
            return;
        }

        int i = count - 1;
        for (; i >= 0; i--) {
            if (!(item > data[i])) break;
            data[i + 1] = data[i];
        }
        data[i + 1] = item;
        count++;
    };

    bool IsEmpty() { return count == 0; };
    bool IsFull() { return count == size; };
    T PeekMin() { return data[count - 1]; };
    T Pop() { return data[--count]; };
    int Size() { return count; };
};
