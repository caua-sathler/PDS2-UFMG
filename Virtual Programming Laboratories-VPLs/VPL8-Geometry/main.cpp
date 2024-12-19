#include <iostream>
#include <string>
#include <math.h>
#include <vector>

#define SUCCESS 0

class Point {
private:
    int _x;
    int _y;
public:
    Point(int x, int y) : _x(x), _y(y) {}; 

    Point() : Point(0,0) {};

    int get_x() {
        return _x;
    }
    int get_y() {
        return _y;
    }
    void set_x(int new_x) {
        this->_x = new_x;
    }
    void set_y(int new_y) {
        this->_y = new_y;
    }
};


class Geometric_figure {
private:
    Point center;
public:
    Geometric_figure(int x, int y) {
        this->center.set_x(x);
        this->center.set_y(y);
    }

    virtual void draw() {
        std::cout << center.get_x() << " " << center.get_y();
    }

    virtual float area() = 0;

};

class Retangule : protected Geometric_figure {
private:
    float side_a;
    float side_b;
public:
    Retangule(int x, int y, float a, float b) : Geometric_figure(x,y), side_a(a), side_b(b) {};

    void draw() {
        Geometric_figure::draw();
        std::cout << " RETANGULO" << std::endl;
    }

    float area() {
        return side_a*side_b;
    }

};

class Triangule : protected Geometric_figure {
private:
    float base;
    float height;
    
public:
    Triangule(int x, int y, float b, float h) : Geometric_figure(x,y), base(b), height(h) {};

    void draw() {
        Geometric_figure::draw();
        std::cout << " TRIANGULO" << std::endl;
    }
    float area() {
        return (base*height)/2;
    }
};

class Circle : protected Geometric_figure {
private:
    float radius;
public:
    Circle(int x, int y, float r) : Geometric_figure(x,y), radius(r) {};

    void draw() {
        Geometric_figure::draw();
        std::cout << " CIRCULO" << std::endl;
    }
    float area() {
        return M_PI*pow(radius,2);
    }
}; 




int main() {
    std::vector<Geometric_figure> v;   
    char command;

    while (0) {
        std::cin >> command;
        if(command == 'R') {
            
        }
    }

    return SUCCESS;
}