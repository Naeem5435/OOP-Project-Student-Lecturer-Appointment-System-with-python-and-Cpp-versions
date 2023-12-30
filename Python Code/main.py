import tkinter as tk
from tkinter import messagebox,simpledialog
import csv

# Global variable for array sizes
global count
count = [0, 0, 0]

class People:
    def __init__(self):
        self.number="" 
        self.name = ""
        self.surname = ""
        self.department = ""
        self.email = ""
        self.phone = ""

    def getNumber(self):
        return self.number

    def setNumber(self, _number):
        self.number = _number

    def getName(self):
        return self.name

    def setName(self, _name):
        self.name = _name

    def getSurname(self):
        return self.surname

    def setSurname(self, _surname):
        self.surname = _surname

    def getDepartment(self):
        return self.department
    
    def setDepartment(self, _department):
        self.department = _department

    def getEmail(self):
        return self.email

    def setEmail(self, _email):
        self.email = _email

    def getPhone(self):
        return self.phone

    def setPhone(self, _phone):
        self.phone = _phone
class Student(People):
    def __init__(self, _temp=None):
        super().__init__()
        if _temp:
            # Initialize with provided values
            self.number = _temp[0]
            self.name = _temp[1]
            self.surname = _temp[2]
            self.department = _temp[3]
            self.year = _temp[4]
            self.email = _temp[5]
            self.phone = _temp[6]
        else:
            # Initialize with default values
            self.number = None
            self.name = None
            self.surname = None
            self.department = None
            self.year = None
            self.email = None
            self.phone = None
    def display(self):
        return f"{self.getNumber()} - {self.getName()} - {self.getSurname()} - {self.getDepartment()} - {self.year} - {self.getEmail()} - {self.getPhone()}"
    def setYear(self, _temp):
        self.year = _temp
    def getYear(self):
        return self.year
class Lecturer(People):
    def setChair(self,_chair):
            self.chair=_chair
    def getChair(self):
        return self.chair
      
    def __init__(self, _temp=None):
        super().__init__()
        if _temp:
            # Initialize with provided values
              self.number = _temp[0]
              self.name = _temp[1]
              self.surname = _temp[2]
              self.department = _temp[3]
              self.email = _temp[4]
              self.phone = _temp[5]
              self.chair = _temp[6]
        else:
            # Initialize with default values
               self.number = None
               self.name = None
               self.surname = None
               self.department = None
               self.email = None
               self.phone = None
               self.chair = None
    def display(self):
                   return f"{self.getNumber()} - {self.getName()} {self.getSurname()} - {self.getDepartment()} - {self.getEmail()} - {self.getPhone()} - {self.chair}"
class Appointment:
  
    def __init__(self, _temp):
    
        self.student = Student()
        self.lecturer = Lecturer()

    
        self.student.setNumber(_temp[0])
        self.lecturer.setNumber(_temp[1])

        
        self.date = _temp[2]
        self.start = _temp[3]
        self.end = _temp[4]

    def display(self):
        
        return f"{self.student.getNumber()} - {self.lecturer.getNumber()} - {self.date} - {self.start} - {self.end}"


def count_file(filename, filenum):
    with open(filename, 'r') as file:
        count[filenum] = sum(1 for line in file)

def read_from_file(file1, file2, file3):
    x, y, z = count[0], count[1], count[2]
    global _S, _L, _A
    _S,_L,_A=[],[],[]
    with open(file1, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            s = Student(row)
            _S.append(s)
    with open(file2, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            l = Lecturer(row)
            _L.append(l)
    with open(file3, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            a = Appointment(row)
            _A.append(a)
    return _S, _L, _A


def write_to_file(file1, file2, file3, _s, _l, _a):
    with open(file1, 'w', newline='') as file:
        writer = csv.writer(file)
        for student in _s:  # _s is the total list of object of student class
            writer.writerow([student.getNumber(), student.getName(), student.getSurname(), 
                             student.getDepartment(), student.year, student.getEmail(), student.getPhone()])

    with open(file2, 'w', newline='') as file:
        writer = csv.writer(file)
        for lecturer in _l:  # Assuming _l is a list of Lecuturer ones
            writer.writerow([lecturer.getNumber(), lecturer.getName(), lecturer.getSurname(),
                             lecturer.getDepartment(), lecturer.getEmail(), lecturer.getPhone(), lecturer.getChair()])

    with open(file3, 'w', newline='') as file:
        writer = csv.writer(file)
        for appointment in _a:
            writer.writerow([
                appointment.student.getNumber(),
                appointment.lecturer.getNumber(),
                appointment.date, 
                appointment.start, 
                appointment.end
            ])
def handle_get_lists():
    global _S, _L, _A
    write_to_file("Student.csv", "Lecturer.csv", "Appointment.csv", _S, _L, _A)
    messagebox.showinfo("Success", "CSV Files Successfully Updated")
    refresh_lists()


    
def refresh_lists():
    listbox_students.delete(0, tk.END)
    listbox_lecturers.delete(0, tk.END)
    listbox_appointments.delete(0, tk.END)

    for student in _S:
        listbox_students.insert(tk.END, student.display())
    for lecturer in _L:
        listbox_lecturers.insert(tk.END, lecturer.display())
    for appointment in _A:
        listbox_appointments.insert(tk.END, appointment.display())
def add_student():
    number = simpledialog.askstring("Input", "Student Number")
    # Check if the student with the same ID already exists
    existing_student = next((s for s in _S if s.getNumber().strip() == number), None)
    
    if existing_student:
        messagebox.showinfo("Error", f"Student with ID {number} is already present.")
    else:
        name = simpledialog.askstring("Input", "Student Name")
        surname = simpledialog.askstring("Input", "Student Surname")
        department = simpledialog.askstring("Input", "Department")
        year = simpledialog.askstring("Input", "Starting Year")
        email = simpledialog.askstring("Input", "Email")
        phone = simpledialog.askstring("Input", "Phone Number")

        new_student = Student([number, name, surname, department, year, email, phone])
        _S.append(new_student)
        refresh_lists()

def remove_student():
    number = simpledialog.askstring("Input", "Enter Student Number to Remove")
    found = False  
    for i, student in enumerate(_S):
        if student.getNumber() == number:
            _S.pop(i)
            found = True  
            break

    if not found:
        messagebox.showerror("Error", f"No student found with ID {number}")

    refresh_lists()


def update_student():
    number = simpledialog.askstring("Input", "Enter Student Number to Update")
    found = False  # Flag to check if the student is found
    for student in _S:
        if student.getNumber() == number:
            student.setName(simpledialog.askstring("Input", "New Student Name", initialvalue=student.getName()))
            student.setSurname(simpledialog.askstring("Input", "New Student Surname", initialvalue=student.getSurname()))
            student.setDepartment(simpledialog.askstring("Input", "New Department", initialvalue=student.getDepartment()))
            student.setYear(simpledialog.askstring("Input", "New Starting Year", initialvalue=student.getYear()))
            student.setEmail(simpledialog.askstring("Input", "New Email", initialvalue=student.getEmail()))
            student.setPhone(simpledialog.askstring("Input", "New Phone Number", initialvalue=student.getPhone()))
            found = True  
            refresh_lists()
            break

    if not found:
        messagebox.showerror("Error", f"No student found with ID {number}")

def add_lecturer():
    number = simpledialog.askstring("Input", "Lecturer Number")
    # Check if the lecturer with the same ID already exists
    existing_lecturer = next((l for l in _L if l.getNumber().strip() == number), None)
    
    if existing_lecturer:
        messagebox.showinfo("Error", f"Lecturer with ID {number} is already present.")
    else:
        name = simpledialog.askstring("Input", "Lecturer Name")
        surname = simpledialog.askstring("Input", "Lecturer Surname")
        department = simpledialog.askstring("Input", "Department")
        email = simpledialog.askstring("Input", "Email")
        phone = simpledialog.askstring("Input", "Phone Number")
        chair = simpledialog.askstring("Input", "Chair")
        
        new_lecturer = Lecturer([number, name, surname, department, email, phone, chair])
        _L.append(new_lecturer)
        refresh_lists()
def remove_lecturer():
    number = simpledialog.askstring("Input", "Enter Lecturer Number to Remove")
    found = False  # Flag to check if the lecturer is found
   

    for lecturer in _L:
        if lecturer.getNumber().strip() == number:
             _L[:] = [l for l in _L if l.getNumber().strip() != number]
             found = True
             break

    refresh_lists()

    if not found:
        messagebox.showerror("Error", f"No lecturer found with ID {number}")

def update_lecturer():
    global _L
    number = simpledialog.askstring("Input", "Enter Lecturer Number to Update").strip()

    for lecturer in _L:
        if lecturer.getNumber().strip() == number:
            lecturer.setName(simpledialog.askstring("Input", "New Lecturer Name", initialvalue=lecturer.getName()))
            lecturer.setSurname(simpledialog.askstring("Input", "New Lecturer Surname", initialvalue=lecturer.getSurname()))
            lecturer.setDepartment(simpledialog.askstring("Input", "New Department", initialvalue=lecturer.getDepartment()))
            lecturer.setEmail(simpledialog.askstring("Input", "New Email", initialvalue=lecturer.getEmail()))
            lecturer.setPhone(simpledialog.askstring("Input", "New Phone Number", initialvalue=lecturer.getPhone()))
            lecturer.setChair(simpledialog.askstring("Input", "New Chair", initialvalue=lecturer.getChair()))
            refresh_lists()
            return
    
    messagebox.showinfo("Info", f"No lecturer found with ID {number}")


def remove_appointment():
    global _A
    student_number = simpledialog.askstring("Input", "Enter Student Number").strip()
    lecturer_number = simpledialog.askstring("Input", "Enter Lecturer Number").strip()

    _A = [a for a in _A if not (a.student.getNumber().strip() == student_number and a.lecturer.getNumber().strip() == lecturer_number)]
    refresh_lists()

def update_appointment():
    global _A
    student_number = simpledialog.askstring("Input", "Enter Student Number for Appointment to Update").strip()
    lecturer_number = simpledialog.askstring("Input", "Enter Lecturer Number for Appointment to Update").strip()

    for appointment in _A:
        if appointment.student.getNumber().strip() == student_number and appointment.lecturer.getNumber().strip() == lecturer_number:
            appointment.date = simpledialog.askstring("Input", "New Date", initialvalue=appointment.date)
            appointment.start = simpledialog.askstring("Input", "New Start Time", initialvalue=appointment.start)
            appointment.end = simpledialog.askstring("Input", "New End Time", initialvalue=appointment.end)
            refresh_lists()
            return
    
    messagebox.showinfo("Error", "Appointment not found")


    
def add_appointment():
    global _S, _L, _A
    student_number = simpledialog.askstring("Input", "Student Number")
    lecturer_number = simpledialog.askstring("Input", "Lecturer Number")
    date = simpledialog.askstring("Input", "Date (e.g., 01-01-2023)")
    start = simpledialog.askstring("Input", "Start Time (e.g., 10:00)")
    end = simpledialog.askstring("Input", "End Time (e.g., 11:00)")
    print("Input Student Number:", student_number, type(student_number))
    print("Input Lecturer Number:", lecturer_number, type(lecturer_number))

    existing_appointment = next(
        (a for a in _A if a.lecturer.getNumber().strip() == lecturer_number
                         and a.date == date and a.start == start),
        None
    )

    if existing_appointment:
        messagebox.showinfo("Error", "Appointment time is not available. Please choose a different time.")
    else:
        student = next((s for s in _S if s.getNumber().strip() == student_number), None)
        lecturer = next((l for l in _L if l.getNumber().strip() == lecturer_number), None)

        if student and lecturer:
            new_appointment = Appointment([student_number, lecturer_number, date, start, end])
            _A.append(new_appointment)
            refresh_lists()
        else:
            messagebox.showinfo("Error", "Invalid student or lecturer number")

count_file("Student.csv", 0)
count_file("Lecturer.csv", 1)
count_file("Appointment.csv", 2)
_S, _L, _A = read_from_file("Student.csv", "Lecturer.csv", "Appointment.csv")

# GUI setup from here 
root = tk.Tk()
menu_bar = tk.Menu(root)
manager_name = "admin"
manager_password = "123"

def authenticate_manager():
    global manager_name, manager_password
    for attempt in range(3):  
        entered_name = simpledialog.askstring("Manager Authentication", "Enter Manager Name:")
        entered_password = simpledialog.askstring("Manager Authentication", "Enter Manager Password:", show="*")

        if entered_name == manager_name and entered_password == manager_password:
            return True
        else:
            messagebox.showinfo("Authentication Failed", f"Invalid manager name or password. Attempts left: {3 - attempt}")
    
    return False

if not authenticate_manager():
    exit()

root.config(menu=menu_bar)
root.title("Student - Lecturer Appointment System")
tk.Label(root, text="Students").grid(row=0, column=0)
listbox_students = tk.Listbox(root, width=75)  
listbox_students.grid(row=1, column=0)
tk.Button(root, text="Add Student", command=add_student).grid(row=6, column=0)
tk.Button(root, text="Remove Student", command=remove_student).grid(row=7, column=0)
tk.Button(root, text="Update Student", command=update_student).grid(row=8, column=0)

# Lecturer Section
tk.Label(root, text="Lecturers").grid(row=0, column=1)
listbox_lecturers = tk.Listbox(root, width=68)  
listbox_lecturers.grid(row=1, column=1)
tk.Button(root, text="Add Lecturer", command=add_lecturer).grid(row=6, column=1)
tk.Button(root, text="Remove Lecturer", command=remove_lecturer).grid(row=7, column=1)
tk.Button(root, text="Update Lecturer", command=update_lecturer).grid(row=8, column=1)
tk.Button(root, text="Get Lists", command=handle_get_lists).grid(row=9, column=1, columnspan=3)


# Appointment Section
tk.Label(root, text="Appointments").grid(row=0, column=2)
listbox_appointments = tk.Listbox(root, width=45)  
listbox_appointments.grid(row=1, column=2)
tk.Button(root, text="Add Appointment", command=add_appointment).grid(row=6, column=2)
tk.Button(root, text="Remove Appointment", command=remove_appointment).grid(row=7, column=2)
tk.Button(root, text="Update Appointment", command=update_appointment).grid(row=8, column=2)
# Refresh lists with initial data
refresh_lists()
root.mainloop() 
