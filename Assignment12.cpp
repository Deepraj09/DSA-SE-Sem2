#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void addemployee()
{
    ofstream f("dbe.txt",ios::app);

    string ID, name, desig, salary;

    cout<<"Enter Employee ID: ";
    cin>>ID;

    cout<<"Enter Employee Name: ";
    cin>>name;

    cout<<"Enter Employee Designation: ";
    cin>>desig;

    cout<<"Enter Employee salary: ";
    cin>>salary;

    f << left << setw(20) << ID << setw(20) << name << setw(20) << desig << setw(20) << salary <<endl;
    f.close();
    cout<<"Employees added successfully..!!\n";
}

void printemployee()
{
    ifstream f("dbe.txt");

    string line;

    cout<<"\n Printing file Data..."<<endl;
    while(getline(f,line))
    {
        cout<<line<<endl;
    
    }
    cout<<"Printing completed... \n";
    f.close();
}

void searchemployee()
{
    ifstream f("dbe.txt");

    string line,ID;

    cout<<"Enter the ID to search employee: ";
    cin>>ID;

    bool found = false;

    while(getline(f,line))
    {
        if(line.find(ID) != string::npos)
        {
            cout<<"Employee Details: "<<endl;
            cout<<line<<endl;
            found = true;
            break;
        }
    }
    f.close();
    if(!found)
    {
        cout<<"Employee Dosen't exists..!!"<<endl;
    }
}
void deleteemployee()
{
    ifstream f("dbe.txt");

    string line, ID;

    cout<<"Enter the ID to delete Employee: ";
    cin>>ID;

    string fileData;

    while(getline(f,line))
    {
        if(line.find(ID) == string::npos)
        {
            fileData += line;
            fileData += "\n";
        }
    }
    f.close();
    ofstream f1("dbe.txt",ios::out);
    f1<<fileData;
    f1.close();
}
int main()
{
    ofstream f("dbe.txt",ios::out);
    f << left << setw(20) << "ID" << setw(20) << "Name" << setw(20) << "Designation" << setw(20) << "Salary" <<endl;
    f.close();
    
    int ip;

    while(ip != -1)
    {
        cout<<"\nEnter your choice\n1. Add Employee\n2. Delete Employee\n3. Search Employee\n4. Print Employee\n5. Exit\n--->";
        cin>>ip;

        switch(ip)
        {
            case 1:
                addemployee();
                break;
            case 2:
                deleteemployee();
                break;
            case 3:
                searchemployee();
                break;
            case 4:
                printemployee();
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