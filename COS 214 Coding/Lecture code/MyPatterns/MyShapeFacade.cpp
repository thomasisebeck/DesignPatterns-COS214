#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape()=default;
};

class Square: public Shape {
public:
    virtual void draw() {
        cout << "Drawing Square" << endl;
    }
    virtual ~Square()=default;
};

class Circle: public Shape {
public:
    virtual void draw() {
        cout << "Drawing Circle" << endl;
    }
    virtual ~Circle()=default;
};

class ShapeMaker {
private:
    //keep instances of the subclasses
    Shape* circle;
    Shape* square;
public:
    ShapeMaker() {
        circle = new Circle();
        square = new Square();
    }
    void drawCircle() {
        circle->draw();
    }
    void drawSquare() {
        square->draw();
    }
    ~ShapeMaker() {
        delete circle;
        delete square;
    }
};

int main() {

    ShapeMaker* maker = new ShapeMaker();

    maker->drawCircle();
    maker->drawSquare();

    delete maker;

    return 0;
}