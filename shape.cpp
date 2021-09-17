#include <cmath>
#include <iostream>

#define PI 3.14159;

using namespace std;

class shape
{
public:
    virtual void area() = 0;
};

class circle :public shape
{
private:    
    int radius;
public:
    circle(int radius2) :radius(radius2) {  }
    void area()
    {
        double area = radius * radius * PI;
        cout << " \n �~�̖ʐ�: " << area << endl;
    }
};

class rectangle:public shape
{
private:
    int width;
    int length;
public:
    rectangle(int width2, int length2) : width(width2), length(length2) {  }
    void area()
    {
        double area = width * length;
        cout << " \n �l�p�`�̖ʐ�: " << area << endl;
    }
};

class triangle :public shape
{
private:
    double a;
    double b;
    double c;
public:
    triangle(double a1, double b1, double c1) : a(a1), b(b1), c(c1)
    {
        if (!(a + b > c && a + c > b && b + c > a))
            cout << "�O�p�`��3�ӂł͂���܂���" << endl;
    }

    void area()
    {
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << " \n �O�p�`�̖ʐ�: " << area << endl;
    }
};

int main()
{
    shape* p1[] = {
        new circle(5),
        new rectangle(4,5),
        new triangle(3, 4, 5)
    };

    for (shape* s : p1) {
        s->area();
    }
}