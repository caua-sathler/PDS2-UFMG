#include <iostream>
#include <iomanip>
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

    virtual ~Geometric_figure() {}

};



class Rectangule : public Geometric_figure {
private:
    float side_a;
    float side_b;
public:
    Rectangule(int x, int y, float a, float b) : Geometric_figure(x,y), side_a(a), side_b(b) {};

    void draw() override {
        Geometric_figure::draw();
        std::cout << " RETANGULO" << std::endl;
    }

    float area() {
        return side_a*side_b;
    }

};



class Triangule : public Geometric_figure {
private:
    float base;
    float height;
    
public:
    Triangule(int x, int y, float b, float h) : Geometric_figure(x,y), base(b), height(h) {};

    void draw() override {
        Geometric_figure::draw();
        std::cout << " TRIANGULO" << std::endl;
    }
    float area() {
        return (base*height)/2;
    }
};



class Circle : public Geometric_figure {
private:
    float radius;
public:
    Circle(int x, int y, float r) : Geometric_figure(x,y), radius(r) {};

    void draw() override {
        Geometric_figure::draw();
        std::cout << " CIRCULO" << std::endl;
    }
    float area() {
        return M_PI*pow(radius,2);
    }
}; 



int main() {
    std::vector<Geometric_figure*> v;   
    char command;
    int x;
    int y;

    while (true) {
        std::cin >> command;
        if(command == 'R') {
            float side_a;
            float side_b;
            std::cin >> x >> y >> side_a >> side_b;

            Rectangule* r = new Rectangule(x, y, side_a, side_b);
            v.push_back(r);
        }
        
        if(command == 'C') {
            float radius;
            std::cin >> x >> y >> radius;

            Circle* c = new Circle(x, y, radius);
            v.push_back(c);
        }

        if(command == 'T') {
            float base;
            float height;
            std::cin >> x >> y >> base >> height;

            Triangule* t = new Triangule(x, y, base, height);
            v.push_back(t);
        }

        if(command == 'D') {
            for(auto figure : v) {
                figure->draw();
            }
        }

        if(command == 'A') {
            float total_area = 0;
            for(auto figure : v) {
                total_area += figure->area();
            }
            std::cout << std::setprecision(2) << std::fixed << total_area << std::endl;
        }

        if(command == 'E') {
            break;
        }
    }

    for(auto figure : v) {
        delete figure;
    }
    v.clear();

    return SUCCESS;
}



