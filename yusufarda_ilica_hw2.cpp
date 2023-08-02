#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Exam{
    protected:
        string name;
        double totalScore;
        int day, month, year;
    
    public:
        Exam(string a, int d, int m, int y):name(a), day(d), month(m), year(y){}
        void setName(string n){name=n;}
        void setDate(int dd, int mm, int yyyy){day=dd; month=mm; year=yyyy;}
        virtual void calculateScore()=0;
        double getTotalScore() const {return totalScore;}
};

class YokDil : public Exam{
    private:
        int correctAnswers;
    public:
        YokDil(string a, int d, int m, int y, int ans):Exam(a,d,m,y), correctAnswers(ans){}
        void setCorrectAnswers(int a){correctAnswers=a;}
        void calculateScore(){totalScore=correctAnswers*1.25;}
};

class TOEFL : public Exam{
    private:
        int reading, listening, speaking, writing;
    public:
        TOEFL(string a, int d, int m, int y, int r, int l, int s, int w):Exam(a,d,m,y)
        {reading=r; listening=l; speaking=s; writing=w;} 
        void calculateScore()
        {totalScore=reading+listening+speaking+writing;}
};

class IELTS : public Exam{
    private:
        int rea, lis, spe, wri;
        double reab, lisb, speb, wrib;
    public:
        IELTS(string a, int d, int m, int y, int r, int l, int s, int w):Exam(a,d,m,y)
        {rea=r; lis=l; spe=s; wri=w;}
        
        double calculateBandScore(int x)
        {
            double y;
            if(x == 40)
                y=9;
            else if(x == 39)
                y=8.5;
            else if(x == 38)
                y=8;
            else if(x == 36 || x == 37)
                y=7.5;
            else if(x == 34 || x == 35)
                y=7;
            else if(x == 32 || x == 33)
                y=6.5;
            else if(x == 30 || x == 31)
                y=6;
            else if(x >= 26 && x <= 29)
                y=5.5;
            else if(x >= 23 && x <= 25)
                y=5;
            else if(x >= 19 && x <= 22)
                y=4.5;
            else if(x >= 15 && x <= 18)
                y=4;
            else if(x >= 12 && x <= 14)
                y=3.5;
            else if(x >= 8 && x <= 11)
                y=3;
            else if(x >= 5 && x <= 7)
                y=2.5;
            else if(x >= 2 && x <= 4)
                y=2;
            else if(x == 1)
                y=1.0;
            else if(x == 0)
                y=0;
            else
                cout<<"Please input score out of 40."<<endl;
            return y;
        }
        
        void setBandScore(int rea, int lis, int spe, int wri)
        {
            reab=calculateBandScore(rea);
            lisb=calculateBandScore(lis);
            speb=calculateBandScore(spe);
            wrib=calculateBandScore(wri);
        }
        
        double readingBandValue(){return reab;}
        double listeningBandValue(){return lisb;}
        double speakingBandValue(){return speb;}
        double writingBandValue(){return wrib;}

        double calculateAverage(double reab, double lisb, double speb, double wrib)
        {double avg = (reab+lisb+speb+wrib)/4; return avg;}
        
        double roundToHalfBand(double value)        //to round average to its nearest whole or half band
        {
            double integerPart = floor(value);
            double decimalPart = value - integerPart;
            double roundedDecimalPart = round(decimalPart * 2) / 2.0;
            return integerPart + roundedDecimalPart;
        }
        
        void calculateScore()
        {totalScore=roundToHalfBand(calculateAverage(reab, lisb, speb, wrib));}
};

main()
{
    string name;
    char selection;
    int day, month, year, reading, listening, speaking, writing, answers;

    cout<<"Enter name of student: ";
    cin>>name;

    cout<<"Enter date of exam: ";
    cin>>day>>month>>year;

    cout<<"Enter T for TOEFL, I for IELTS, Y for Yokdil: ";
    cin>>selection;

    Exam *examptr;

    switch(selection)
    {
        case 'Y':{
            cout<<"Enter number of correct answers: ";
            cin>>answers;
            examptr= new YokDil (name, day, month, year, answers);
            cout<<"Name: "<<name<<"  Exam: Yokdil  Date of exam: "<<day<<"/"<<month<<"/"<<year<<endl;
            break;}
        case 'T':{
            cout<<"Enter score for Reading: ";
            cin>>reading;
            cout<<"Enter score for Listening: ";
            cin>>listening;
            cout<<"Enter score for Speaking: ";
            cin>>speaking;
            cout<<"Enter score for Writing: ";
            cin>>writing;
            examptr = new TOEFL (name, day, month, year, reading, listening, speaking, writing);
            cout<<"Name: "<<name<<"  Exam: TOEFL  Date of exam: "<<day<<"/"<<month<<"/"<<year<<endl;
            cout<<"Reading: "<<reading<<" Listening: "<<listening<<" Speaking: "<<speaking<<" Writing: "<<writing<<endl;
            break;}
        case 'I':{
            cout<<"Enter score for Reading: ";
            cin>>reading;
            cout<<"Enter score for Listening: ";
            cin>>listening;
            cout<<"Enter score for Speaking: ";
            cin>>speaking;
            cout<<"Enter score for Writing: ";
            cin>>writing;
            IELTS *ieltsExam = new IELTS (name, day, month, year, reading, listening, speaking, writing);
            cout<<"Name: "<<name<<"  Exam: IELTS  Date of exam: "<<day<<"/"<<month<<"/"<<year<<endl;
            ieltsExam->setBandScore(reading,listening,speaking,writing);
            cout<<"Reading: "<<ieltsExam->readingBandValue()<<" Listening: "<<ieltsExam->listeningBandValue()<<" Speaking: "<<ieltsExam->speakingBandValue()<<" Writing: "<<ieltsExam->writingBandValue()<<endl;
            examptr = ieltsExam;
            break;}
        default: {cout<<"Invalid exam type."<<endl; return 1;}
    }

    examptr->calculateScore();
    cout<<"Total score: "<<examptr->getTotalScore()<<endl;

    delete examptr;
}