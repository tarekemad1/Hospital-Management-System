#include <iostream>
using namespace std;
string patient_DB[20][5];
int patient_status[20][5];
int ptr[20] = {0};
typedef enum
{
    regular,
    urgent
} status;
void add_patient();
void print_patients();
void get_next();
int main()
{
    int choice;
    while (true)
    {
        cout << "Enter your choice:" << endl;
        cout << "1) Add new patient  " << endl;
        cout << "2) Print all patients" << endl;
        cout << "3) Get next patient " << endl;
        cout << "4) EXIT" << endl;
        cin >> choice;
        if (choice == 1)
            add_patient();
        else if (choice == 2)
            print_patients();
        else if (choice == 3)
            get_next();
        else if (choice == 4)
            break;
        else
            cout << "undefined choice " << endl;
    }
    return 0;
}
void add_patient()
{

    int ip_status;
    string patient_name;
    int dprtmnt = 0;
    cout << "Enter Specialization , name and status :";
    cin >> dprtmnt;
    int specialization = dprtmnt - 1;
    cin >> patient_name >> ip_status;
    if (ptr[specialization] == 5)
        cout << "Sorry , This specialization is full" << endl;
    else
    {
        if (ip_status == regular)
        {
            patient_status[specialization][ptr[specialization]] = regular;
            if (ptr[specialization] != 5)
            {
                patient_DB[specialization][ptr[specialization]] = patient_name;
                ptr[specialization]++;
            }
        }
        else
        {
            for (int i = 3; i >= 0; i--)
            {
                if (patient_DB[specialization][i].empty())
                    continue;
                else
                {
                    patient_DB[specialization][i + 1] = patient_DB[specialization][i];
                    patient_status[specialization][i + 1] = patient_status[specialization][i];
                }
            }
            ptr[specialization]++;
            patient_DB[specialization][0] = patient_name;
            patient_status[specialization][0] = urgent;
        }
    }
}
void print_patients()
{
    for (int i = 0; i < 19; i++)
    {
        if (ptr[i] == 0)
        {
            continue;
        }
        else
            cout << "There are " << " " << ptr[i] << " " << "patients in specialization" << " " << i + 1 << endl;
        for (int j = 0; j < ptr[i]; j++)
        {
            cout << patient_DB[i][j];
            if (patient_status[i][j] == urgent)
                cout << " urgent" << endl;
            else if (patient_status[i][j] == regular)
                cout << " regular" << endl;
        }
    }
}
void get_next()
{
    int dprtmnt = 0;
    cout << "Enter Specialization :";
    cin >> dprtmnt;
    int specialization = dprtmnt - 1;
    if (!(ptr[specialization]) )
        cout << "There are no patients in this spacialization" << endl;

    else
    {
        cout << "Please " << patient_DB[specialization][0] << ", go with the Dr" << endl;
        ptr[specialization]--;
        for (int i = 0; i <= 3; i++)
        {
            if (patient_DB[specialization][i].empty())
            {
                continue;
            }
            else
            {
                patient_DB[specialization][i] = patient_DB[specialization][i + 1];
                patient_status[specialization][i] = patient_status[specialization][i + 1];
            }
        }
    }
}
