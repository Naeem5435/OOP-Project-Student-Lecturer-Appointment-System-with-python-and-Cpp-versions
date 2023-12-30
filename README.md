# OOP-Project-Student-Lecturer-Appointment-System-with-python-and-Cpp-versions
-------------------------------------------------------------------------------
Student-lecturer Appointment System:
This documentation provides an overview of two implementations for managing student-lecturer appointments, one in Python and 
the other in C++.

Python Code Implementation:

Overview:
This Python-based system manages student-lecturer appointments using CSV files for data storage. It utilizes the tkinter library to create
a graphical user interface (GUI) to facilitate managing students, lecturers, and appointment records.

Features:
- Student Management:
Add, remove, and update student details such as number, name, department, and contact information.
- Lecturer Management:
Similar functionalities as student management for managing lecturer details.
- Appointment Handling:
Schedule, update, and remove appointments between students and lecturers.

File Structure:
- Student.csv:
  Stores student data.
- Lecturer.csv:
  Stores lecturer data.
- Appointment.csv:
  Records appointment details.
  
How to Use:
1. Run the Program:
Execute the Python file (main.py) in a Python environment.
UserName:admin   Password:123

2. Menu Options:
 The GUI offers various options for managing students, lecturers, and appointments.
3. Adding/Removing/Updating:
Use respective buttons to modify data.

4. Data Storage:
 Data is stored in CSV files (Student.csv, Lecturer.csv, Appointment.csv).

Functionality:
- Adding Students/Lecturers:
Use the respective "Add" buttons and follow the prompts to input necessary data.
- Removing Entries:
Select an entry and click the corresponding "Remove" button.
- Updating Information:
Select an entry, click "Update," and input the new details as prompted.
- Appointment Management:
 Schedule appointments between students and lecturers.

Usage:
- Dependencies:
 Python 3.x, tkinter library.
- Installation:
 Clone the repository and ensure the necessary CSV files are in the same directory as the code.
- Run the Program:
Execute the Python script to launch the GUI.

** Acknowledgments:**

Acknowledging contributions from developers:
- Naeem Ullah:
 Acknowledging pivotal role and contributions in improving the system's performance and reliability.
- Momina Nadeem:
Recognizing valuable contributions that strengthened the system's capabilities and usability.


**C++ Code Implementation:**

Overview:
The C++ code implementation of the Student-Lecturer Appointment System features similar functionalities to the 
Python version with some enhancements in structure, functions, file handling, and error messages.

Key Modifications:
- Better Structured Classes:
Utilizes inheritance and improved function definitions in People, Student, and Lecturer classes.
- Refined Functions:
Compact methods in Student and Lecturer classes optimizing inheritance usage.
- Improved File Handling:
Refined functions (count_file, read_from_file, write_to_file) for better data management.
- Enhanced Error Handling: 
Detailed and informative error messages for clearer user feedback.

Usage:
As this code is in C++, it might require a different development environment and compilation steps compared to Python.
Specific instructions regarding compiling and executing this code in a C++ environment would be included with the source code.
