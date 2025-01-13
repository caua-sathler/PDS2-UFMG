#ifndef HEAPINT_H
#define HEAPINT_H
#include <iostream>

class HeapInt {
private:
    int* heap_int;

public:
    HeapInt();
    HeapInt(int num);
    HeapInt(const HeapInt& other);
    ~HeapInt();
    HeapInt& operator=(const HeapInt& other);
    HeapInt& operator=(const int& other);
    HeapInt operator+(const HeapInt& other) const;
    HeapInt operator-(const HeapInt& other) const;
    bool operator==(const HeapInt& other) const;
    friend std::ostream& operator<<(std::ostream& out, const HeapInt& other);
    friend std::istream& operator>>(std::istream& in, HeapInt& other);
};

#endif