#include "HeapInt.hpp"

HeapInt::HeapInt() {
    this->heap_int = new int(0);
}

HeapInt::HeapInt(int num) {
    this->heap_int = new int(num);
}

HeapInt::HeapInt(const HeapInt &other) {
    this->heap_int = new int(*(other.heap_int));
}

HeapInt::~HeapInt() {
    delete this->heap_int;
}

HeapInt& HeapInt::operator=(const HeapInt &other) {
    if (this != &other) { 
        *heap_int = *(other.heap_int);
    }
    return *this;
}

HeapInt& HeapInt::operator=(const int &other) {
    *heap_int = other;
    return *this;
}

HeapInt HeapInt::operator+(const HeapInt& other) const {
    return HeapInt(*heap_int + *(other.heap_int));
}

HeapInt HeapInt::operator-(const HeapInt& other) const {
    return HeapInt(*heap_int - *(other.heap_int));
}

bool HeapInt::operator==(const HeapInt& other) const {
    return *heap_int == *(other.heap_int);
}

std::ostream& operator<<(std::ostream& out, const HeapInt& other) {
    out << *(other.heap_int);
    return out;
}

std::istream& operator>>(std::istream& in, HeapInt& other) {
    in >> *(other.heap_int);
    return in;
}