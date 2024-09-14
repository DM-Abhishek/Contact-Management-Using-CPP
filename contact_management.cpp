// Includeing header files
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//Global variables
string fname,lname,phone_num;

//Functions
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main()
{
    short int choice;
    system("cls");
    system("color 0A");
    cout<<"\n\n\n\t\t\tContact Management.";
    cout<<"\n\n1. Add Contact\n\n2. Search Contact\n\n3. Help\n\n4. Exit\n>";
    cin>> choice;

    switch(choice)
    {
        case 1:
         addContact();
        break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default: 
            cout<< "\n\n\tInvalid Input !";
            cout<<"\n\tPress any key to continue..";
            getch();
            main();
    }

    return 0;
}

void self_exit()
{
    system("cls");
    cout<<"\n\n\n\t\tThank you for using !";
    exit(1);
}

void help()
{
    cout<< "This displays help";
}

void addContact()
{
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout<< "\n\n\tEnter First Name :";
    cin>>fname;
    cout<< "\n\tEnter Last Name : ";
    cin>>lname;
    cout<< "\n\tEnter 10 digit Phone Number : ";
    cin >> phone_num;

    if(check_digits(phone_num) == true)
    {
        if(check_numbers(phone_num) == true)
        {
            if(phone.is_open())
            {
                phone<<fname<<" "<<lname<<" "<< phone_num<<endl;
                cout<< "\n\tContact Saved successfully !";
            }
            else
            {
                cout<<"\n\tError Opening File !";
            }
        }
        else
        {
            cout<< "\n\tA phone number must contain numbers only";
        }
    }
    else
    {
        cout<< "\n\tA phone number must contain 10 digits.";
    }
    phone.close();
}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout<< "\n\tEnter Name to search : ";
    cin>> keyword;
    while(myfile >> fname >> lname >> phone_num)
    {
        if(keyword == fname || keyword == lname)
        {
            system("cls");
            cout<< "\n\n\n\t\tContact details..";
            cout<<"\n\n\tFirst Name : "<<fname;
            cout<<"\n\tLast name : "<<lname;
            cout<< "\n\tPhone Number : "<< phone_num;
            found = true;
            break;
        }
    }
    if(found == false)
    cout<< " \n\tNo such contact found";
}

bool check_digits(string x)
{
    if(x.length() == 10)
    return true;
    else 
    return false;
}

bool check_numbers(string x)
{
    bool check = true;

    for(int i=0; i<x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    return true;
    if(check == false)
    return false;
}