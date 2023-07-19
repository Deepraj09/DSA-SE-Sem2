#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>

using namespace std;

void addstudent()
{
    ofstream f("db.txt",ios::app);

    string rn,name,div,add;

    cout<<"Enter the Roll No. of student: ";
    cin>>rn;

    cout<<"Enter the name of student: ";
    cin>>name;

    cout<<"Enter the division of student: ";
    cin>>div;

    cout<<"Enter the Address of student: ";
    cin>>add;

    f << left << setw(20) << rn << setw(20) << name << setw(20) << div << setw(20) << add <<endl;
    f.close();
    cout<<"Student added successfully..\n";
}

void deletestudent()
{
    ifstream f("db.txt");
    
    string line,rn;

    cout<<"Enter the Roll No to delete: ";
    cin>>rn;

    string fileData;

    while(std::getline(f,line))
    {
        if(line.find(rn) == string::npos)
        {
            fileData += line;
            fileData += "\n";
        }
    }
    f.close();
    ofstream f1("db.txt",ios::out);
    f1 << fileData;
    f1.close();
}

void searchstudent()
{

    ifstream f("db.txt");

    string line,rn;

    cout<<"Enter the student Roll No. to search: ";
    cin>>rn;

    bool found = false;

    while(std::getline(f,line))
    {
        if(line.find(rn) != string::npos)
        {
            cout<<"students Details: "<<endl;
            cout<< line <<endl;
            found = true;
            break;
        }

    }
    f.close();
    if(!found)
    {
        cout<<"Student Dosen't exists! "<<endl;
    }
    
}

void printstudent()
{
    ifstream f("db.txt");

    string line;

    cout<<"\n Printing file Data..."<<endl;
    while(std::getline(f,line))
    {
        cout<<line<<endl;
    }
    cout<<"Printing completed! \n";
    f.close();
}

int main()
{

    ofstream f("db.txt",ios::out);    
    f << left << setw(20) << "Roll No." << setw(20) << "Name" << setw(20) << "Division" << setw(20) << "Address" <<endl;
    f.close();

    int ip;
    while(ip != -1)
    {
        cout<<"\nEnter your choice: \n1. Add Student\n2. Delete Student\n3. Search Student\n4. Print Data\n5. Exit\n--->";
        cin>>ip;

        switch(ip)
        {
            case 1:
                addstudent();
                break;
            case 2:
                deletestudent();
                break;
            case 3:
                searchstudent();
                break;
            case 4:
                printstudent();
                break;
            case 5:
                return(0);
                break;
            default:
                cout<<"Please ReEnter your choice: ";
                break;
        }
    }
}