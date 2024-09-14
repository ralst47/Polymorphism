#include <iostream>
#include <cmath>//<math.h>

using namespace std;

class Shape
{
public:
    string color;
    virtual double calculateArea()
    {
        return 0.0;
    }
};

class Circle : public Shape
{
    int radius;
public:
    Circle(int radius)
    {
        this->radius = radius;
    }
    double calculateArea() override
    {
        double  M_PI = atan(1) * 4;//Число Пи
        return M_PI * pow(radius, 2);
    }
};

class Rectangle : public Shape
{
    int width;
    int height;
public:
    Rectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    double calculateArea() override
    {
        return width * height;
    }
};

int main()
{
    Shape* shape1 = new Circle(1);
    Shape* shape2 = new Rectangle(3, 2);

    cout << shape1->calculateArea() << endl;
    cout << shape2->calculateArea() << endl;

    delete shape1;
    delete shape2;
    int test = 1;
}