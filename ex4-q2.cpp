#include <iostream>
#include <string>

using namespace std;

class GeometricObject{
    protected:
        string color;
        bool filled;

    public:
        GeometricObject(string c, bool f): color(c), filled(f){}
        void setColor(string abc){color = abc;}
        string getColor(){return color;}
        void setFill(bool cba){filled = cba;}
        bool getFill(){return filled;}
};

class Circle: public GeometricObject{
    protected:
        double radius;
        double const PI = 3.1415;
    
    public:
        Circle(double r, string c, bool f): GeometricObject(c,f){radius=r;}
        double calcArea(){return PI*radius*radius;}
        double calcPerimeter(){return 2*PI*radius;}

};

class Rectangle: public GeometricObject{
    protected:
        double width, height;
    
    public:
        Rectangle(double w, double h, string c, bool f): width(w), height(h), GeometricObject(c,f){}
        double calcArea(){return width*height;}
        double calcPerimeter(){return 2*width+2*height;}    
};

main()
{
    string color="white";
    bool filled=false;
    double radius=3, width=2, height=4;

    Circle c(radius, color, filled);
    Rectangle r(width, height, color, filled);

    cout<<"A circle is created with "<<endl;
    cout<<"color: "<<c.getColor()<<" and filled: "<<c.getFill()<<endl;
    cout<<"area: "<<c.calcArea()<<endl;
    cout<<"perimeter: "<<c.calcPerimeter();

    cout<<"A rectangle is created with "<<endl;
    cout<<"color: "<<r.getColor()<<" and filled: "<<r.getFill()<<endl;
    cout<<"area: "<<r.calcArea()<<endl;
    cout<<"perimeter: "<<r.calcPerimeter()<<endl;
}