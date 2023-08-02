#include <iostream>

using namespace std;

class Person{
    protected:
        int id;
        string name;
    public:
        Person(int i, string n):id(i), name(n){}
};

class Student: public Person{
    protected:
       float cgpa;
    public:
        Student(int i, string n, float e): Person(i, n), cgpa(e){}
        void check()
        {
            if(cgpa>=3.0)
                cout<<name<<" is an honor student."<<endl;
        }
};

main()
{
    int stuid;
    string stuname;
    float stucgpa;

    for(int i=0; i<10; i++)
    {
        cout<<"Enter id, name and cgpa of the student: ";
        cin>>stuid>>stuname>>stucgpa;
        Student a(stuid,stuname,stucgpa);
        a.check();
    } 
}

