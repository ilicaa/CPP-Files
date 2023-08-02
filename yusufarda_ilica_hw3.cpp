#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Triangle{
    private:
        double a, b, c;
        double alpha=0, beta=0, perpendicular=90;
    public:
        Triangle(double x, double y, double z): a(x), b(y), c(z)
        {
            const double PI = 3.14159;
            alpha = asin(abs(a)/abs(c)) * 180 / PI;
            beta = asin(abs(b)/abs(c)) * 180 / PI;

        }
        
        double getSide1(){return a;}
        double getSide2(){return b;}
        double getSide3(){return c;}

        double getAlpha(){return alpha;}
        double getBeta(){return beta;}
        double getPerpendicular(){return perpendicular;}
        
        void setSide1(double a);
        void setSide2(double b);
        void setSide3(double c);
        
        friend ostream& operator<<(ostream& os, const Triangle& t)
        {
            os << "Triangle with sides a=" << t.a << " b=" << t.b << " c=" << t.c << " is a right triangle with angles " << t.alpha << " " << t.beta << " " << t.perpendicular;
            return os;
        }
};

class TriangleException{
    private:
        double a, b, c;
    public:
        TriangleException(double x, double y, double z):a(x), b(y), c(z){}
        
        void errorMessage(){cout << "Triangle with sides a=" << a << " b=" << b << " c=" << c <<" is not a right triangle."; }
};

main()
{
    ifstream input("triangleinput.txt");

    if(!input){cout << "Can not open the input file." << endl; return -1;}

    double side1, side2, side3;
    
    while(input >> side1 >> side2 >> side3){
        try{
            if(side1 < 0)
            {
                cout << "Negative side " << side1 << " is corrected to " << abs(side1) << "." << endl;
                side1 = abs(side1);
            }
            if(side2 < 0)
            {
                cout << "Negative side " << side2 << " is corrected to " << abs(side2) << "." << endl;
                side2 = abs(side2);
            }
            if(side3 < 0)
            {
                cout << "Negative side " << side3 << " is corrected to " << abs(side3) << "." << endl;
                side3 = abs(side3);
            }

            if(side1*side1 + side2*side2 != side3*side3){throw TriangleException(side1, side2, side3);}

            Triangle t(side1, side2, side3);
            cout << t << endl;
        }

        catch(TriangleException& e){
            e.errorMessage();
        }
    }
    
    input.close();

}

