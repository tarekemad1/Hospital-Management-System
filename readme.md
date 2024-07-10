Hospital Management System
Overview
This Hospital Management System is designed to manage patient queues across different specializations within a hospital. Each specialization can accommodate up to 5 patients at a time, ensuring an organized and efficient process for handling regular and urgent cases.
Features
    1.	Patient Queue Management:
    o	Supports 20 different specializations (e.g., Children, Surgery, etc.).
    o	Each specialization can hold up to 5 patients in a queue.
    o	Patients can be either regular or urgent cases.
    2.Patient Addition:
    o	Patients can be added to a specific specialization.
    o	If a specialization queue is full, the system will apologize and not accept the patient.
    o	Regular patients are added to the end of the queue.
    o	Urgent patients are added to the beginning of the queue.
    3.Patient Listing:
    o Prints the list of patients for each specialization that has waiting patients.
    4.Doctor Pickup:
    o	Allows a doctor to pick up a patient from a specified specialization.
    o	If there are no patients in the queue, the doctor is informed accordingly.
    o	The picked patient is removed from the queue.
Usage
    Adding a Patient
        1.	Input the requested specialization number (1-20):
        o	Example: 5 for Surgery.
        2.	Input the patient's name and status:
        o	0 for regular.
        o	1 for urgent.
        3.	Example:
        o	Specialization: 5
        o	Name: John Doe
        o	Status: 1 (urgent)
Printing Patients
    •	The system will list all patients currently waiting in each specialization.
Doctor Pickup
        1.	Input the requested specialization number (1-20):
        o	Example: 5 for Surgery.
        2.	The system will either:
        o	Ask the picked patient to go with the doctor and remove them from the queue.
        o	Inform the doctor if there are no patients in the queue.
Error Handling
    •	If a specialization queue is full (5 patients), the system will inform the user and will not accept additional patients.
