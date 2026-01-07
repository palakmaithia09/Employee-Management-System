#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Employee
{
    int id;
    char name[30];
    char pwd[30];
    double salary;
};

void addEmp()
{
    ofstream fout("Emp.dat", ios::binary | ios::app);
    Employee E;
    double incr;

    cout << "\nEnter Employee ID: ";
    cin >> E.id;

    cout << "Enter Employee Name: ";
    cin >> E.name;

    cout << "Enter Password: ";
    cin >> E.pwd;

    cout << "Enter Salary: ";
    cin >> E.salary;

    cout << "Enter Increment: ";
    cin >> incr;

    E.salary += incr;

    fout.write((char*)&E, sizeof(Employee));
    fout.close();

    cout << "\nEmployee added successfully.\n";
}

void displayAllEmp()
{
    ifstream fin("Emp1.dat", ios::binary);
    Employee E;

    if (!fin)
    {
        cout << "\nNo data file found.\n";
        return;
    }

    cout << "\nID\tNAME\tPASSWORD\tSALARY";
    cout << "\n----------------------------------------";

    while (fin.read((char*)&E, sizeof(Employee)))
    {
        if (E.id > 0 && strlen(E.name) > 0)
        {
            cout << "\n" << E.id << "\t"
                 << E.name << "\t"
                 << E.pwd << "\t\t"
                 << E.salary;
        }
    }

    fin.close();
}

void searchEmp()
{
    ifstream fin("Emp.dat", ios::binary);
    Employee E;
    int id;
    char pwd[30];
    bool found = false;

    cout << "\nEnter Employee ID: ";
    cin >> id;

    cout << "Enter Password: ";
    cin >> pwd;

    while (fin.read((char*)&E, sizeof(Employee)))
    {
        if (E.id == id && strcmp(E.pwd, pwd) == 0)
        {
            cout << "\nEmployee Found!";
            cout << "\nID\tNAME\tPASSWORD\tSALARY";
            cout << "\n" << E.id << "\t" << E.name << "\t" << E.pwd << "\t\t" << E.salary;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nInvalid ID or Password.";

    fin.close();
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n\n===== EMPLOYEE MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Employee";
        cout << "\n2. Display All Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addEmp(); break;
            case 2: displayAllEmp(); break;
            case 3: searchEmp(); break;
            case 4: exit(0);
            default: cout << "\nInvalid choice!";
        }
    }
}

