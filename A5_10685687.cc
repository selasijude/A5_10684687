#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    struct student {
    string id;
    string name;
    int age;
    char gender;
    int score;
    char grade;
    };
    student st[5];
    for (int i=0; i<5; i++)
    {
        cout<<"Enter the ID of student "<<i+1<<endl;
        cin>>st[i].id;
        cout<<"Enter the name of student "<<i+1<<endl;
        cin>>st[i].name;
        cout<<"Enter the Age of student "<<i+1<<endl;
        cin>>st[i].age;
        cout<<"Enter the Gender of student ( m for male and f for female ) "<<i+1<<endl;
        cin>>st[i].gender;
        cout<<"Enter the score of student "<<i+1<<endl;
        cin>>st[i].score;

        while(st[i].score>100 || st[i].score<0)
       {
            cout<<"Scores should be from 0 to 100 \n kindly enter score again"<<endl;
            cin>>st[i].score;
       }

    }



    int sumsc=0;
    int sumag=0;
    double avgsc =0;
    double avgag=0;
    int male =0;
    int female =0;


    for(int i=0; i< 5; i++)
    {
        if (st[i].score <= 100 && st[i].score >= 80)
                st[i].grade = 'A';
        else if (st[i].score < 80 && st[i].score >= 70)
                st[i].grade = 'B';
        else if (st[i].score < 70 && st[i].score >= 60)
                st[i].grade = 'C';
        else if (st[i].score <= 60 && st[i].score >=50)
                st[i].grade = 'D';
        else if (st[i].score <= 50 && st[i].score >= 40)
                st[i].grade = 'E';
        else if (st[i].score < 40 && st[i].score >= 0)
                st[i].grade = 'F';
        else
               st[i].grade = 'N';



        sumsc += st[i].score;
        sumag += st[i].age;

        avgsc = sumsc /5.0 ;
        avgag = sumag /5.0;

        if(st[i].gender == 'm')
            male++;
        else female++;
    }

    ofstream display;

       display.open("info.txt");

       display<<"   ID Number   Name   Age   Gender  Score    Grade      "<<endl;

        display<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;

    for (int i =0; i< 5; i++)
    {
        display<<i+1<<".  "<<st[i].id<<"      "<<st[i].name<<"      "<<st[i].age<<"      "<<st[i].gender<<"     "<<st[i].score<<"     "<<st[i].grade<<endl;
    }

      display<<endl;
      display<<endl;

      display<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;

      display<<endl;
      display<<endl;


      display<<" Average age = "<<avgag<<endl;
      display<<"Average Score = "<<avgsc<<endl;
      display<<"Male count = "<<male<<endl;
      display<<"Female counnt = "<<female;






    return 0;
}
