#include <iostream>
#define MAX_Capacity 5 // Maximum number of patients per specialization
using namespace std;

// Global Variables
// 'patient_DB' holds the names of patients for each specialization
// 'patient_status' holds whether the patient is regular or urgent (0 for regular, 1 for urgent)
string patient_DB[20][MAX_Capacity];
int patient_status[20][MAX_Capacity];

// 'ptr' keeps track of the current number of patients in each specialization
int ptr[20] = {0};

// Enum to represent patient status
typedef enum
{
    regular, // 0 for regular patients
    urgent   // 1 for urgent patients
} status;

// Function Declarations
void add_patient();
void print_patients();
void get_next();

int main()
{
    int choice;

    // Main menu loop to handle user input
    while (true)
    {
        cout << "Enter your choice:" << endl;
        cout << "1) Add new patient" << endl;
        cout << "2) Print all patients" << endl;
        cout << "3) Get next patient" << endl;
        cout << "4) EXIT" << endl;
        cin >> choice;

        // Handling the menu choices
        switch (choice)
        {
        case 1:
            add_patient();
            break;
        case 2:
            print_patients();
            break;
        case 3:
            get_next();
            break;
        case 4:
            return 0; // Exit program
        default:
            cout << "Undefined choice." << endl;
        }
    }

    return 0;
}

// Function to add a patient to a specialization
void add_patient()
{
    int ip_status;
    string patient_name;
    int dprtmnt;

    // Prompting user for input
    cout << "Enter Specialization (1-20), Patient Name, and Status (0 for regular, 1 for urgent): ";
    cin >> dprtmnt;

    // Adjusting user input to match array index (0-19)
    int specialization = dprtmnt - 1;
    cin >> patient_name >> ip_status;

    // Check if the specialization has reached max capacity
    if (ptr[specialization] == MAX_Capacity)
    {
        cout << "Sorry, This specialization is full." << endl;
        return;
    }

    // Adding a regular patient
    if (ip_status == regular)
    {
        patient_status[specialization][ptr[specialization]] = regular;
        patient_DB[specialization][ptr[specialization]] = patient_name;
        ptr[specialization]++; // Increase patient count
    }
    // Handling urgent patient
    else if (ip_status == urgent)
    {
        // Shift existing patients to make room for the urgent patient
        for (int i = ptr[specialization] - 1; i >= 0; i--)
        {
            patient_DB[specialization][i + 1] = patient_DB[specialization][i];
            patient_status[specialization][i + 1] = patient_status[specialization][i];
        }
        // Insert the urgent patient at the front
        patient_DB[specialization][0] = patient_name;
        patient_status[specialization][0] = urgent;
        ptr[specialization]++; // Increase patient count
    }
}

// Function to print all patients from all specializations
void print_patients()
{
    for (int i = 0; i < 20; i++)
    {
        // Skip specializations with no patients
        if (ptr[i] == 0)
        {
            continue;
        }

        // Print specialization details
        cout << "There are " << ptr[i] << " patients in specialization " << i + 1 << ":" << endl;

        // Print each patient in the specialization
        for (int j = 0; j < ptr[i]; j++)
        {
            cout << patient_DB[i][j];
            if (patient_status[i][j] == urgent)
                cout << " (urgent)" << endl;
            else
                cout << " (regular)" << endl;
        }
    }
}

// Function to get the next patient from a specialization
void get_next()
{
    int dprtmnt;

    // Prompting user to input specialization
    cout << "Enter Specialization (1-20): ";
    cin >> dprtmnt;

    // Adjusting user input to match array index (0-19)
    int specialization = dprtmnt - 1;

    // Check if there are no patients in the specialization
    if (ptr[specialization] == 0)
    {
        cout << "There are no patients in this specialization." << endl;
        return;
    }

    // Process the next patient and shift the remaining patients
    cout << "Please " << patient_DB[specialization][0] << ", go with the doctor." << endl;

    // Shift patients to the left after removing the first one
    for (int i = 0; i < ptr[specialization] - 1; i++)
    {
        patient_DB[specialization][i] = patient_DB[specialization][i + 1];
        patient_status[specialization][i] = patient_status[specialization][i + 1];
    }

    // Decrease patient count
    ptr[specialization]--;
}
