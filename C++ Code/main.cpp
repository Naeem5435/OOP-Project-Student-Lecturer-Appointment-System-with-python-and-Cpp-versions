#include <iostream>
#include <fstream>
#include <cstring>
#include<sstream>

using namespace std;

//global variable for array sizes
int count[3];

class People
{
	private:
		string number;
		string name;
		string surname;
		string department;
		string email;
		string phone;
	public:
		string getNumber()
		{
			return this->number;
		};
		void setNumber(string _number)
		{
			this->number = _number;
		};
		string getName()
		{
			return this->name;
		};
		void setName(string _name)
		{
			this->name = _name;	
		};
		string getSurname()
		{
			return this->surname;	
		};
		void setSurname(string _surname)
		{
			this->surname = _surname;	
		};
		string getDepartment()
		{
			return this->department;	
		};
		void setDepartment(string _department)
		{
			this->department = _department;	
		};
		string getEmail()
		{
			return this->email;	
		};
		void setEmail(string _email)
		{
			this->email = _email;	
		};
		string getPhone()
		{
			return this->phone;	
		};
		void setPhone(string _phone)
		{
			this->phone = _phone;	
		};
};

class Student : public People
{
	private:
		//Student properties
		string year;
	public:
		//constructor
		Student(){};
		Student(string *_temp,int size);
		string getYear()
		{
			return this->year;	
		};
		void setYear(string _year)
		{
			this->year = _year;	
		};
		//display students
		void display()
		{
			cout<<getNumber()<<" - ";
			cout<<getName()<<" - ";
			cout<<getSurname()<<" - ";
			cout<<getDepartment()<<" - ";
			cout<<getYear()<<" - ";
			cout<<getEmail()<<" - ";
			cout<<getPhone()<<endl;
		};
};

Student :: Student(string _temp[],int size)
{
	setNumber(_temp[0]);
	setName(_temp[1]);
	setSurname(_temp[2]);
	setDepartment(_temp[3]);
	setYear(_temp[4]);
	setEmail(_temp[5]);
	setPhone(_temp[6]);
}

class Lecturer : public People
{
	private:
		string chair;
	public:
		//constructor
		Lecturer(){};
		Lecturer(string *_temp);
		//get and set functions for Chair property
		string getChair()
		{
			return this->chair;	
		};
		void setChair(string _chair)
		{
			this->chair = _chair;	
		};
		//display lecturers
		void display()
		{
			cout<<" "<<getNumber()<<"   ";
			cout<<getName()<<" ";
			cout<<getSurname()<<"     ";
			cout<<getDepartment()<<"      ";
			cout<<getEmail()<<"    ";
			cout<<getPhone()<<"     ";
			cout<<getChair()<<endl;	
		};
};

Lecturer :: Lecturer(string *_temp)
{
	setNumber(_temp[0]);
	setName(_temp[1]);
	setSurname(_temp[2]);
	setDepartment(_temp[3]);
	setEmail(_temp[4]);
	setPhone(_temp[5]);
	setChair(_temp[6]);
}

class Appointment
{
	private:
		//appointment properties
		string date;
		string start;
		string end;
	public:
		//composition
		Lecturer L;
		Student S;
		//constructor
		Appointment(){};
		Appointment(string *_temp);
		string getDate()
		{
			return this->date;	
		};
		void setDate(string _date)
		{
			this->date = _date;	
		};
		string getStart()
		{
			return this->start;
		}
		void setStart(string _start)
		{
			this->start = _start;
		}
		string getEnd()
		{
			return this->end;
		}
		void setEnd(string _end)
		{
			this->end = _end;
		};
		//display appointments
		void display()
		{
			cout<<"   "<<S.getNumber()<<"   ";
			cout<<"   "<<L.getNumber()<<"   ";
			cout<<"     "<<getDate()<<"   ";
			cout<<"   "<<getStart()<<"   ";
			cout<<getEnd()<<endl;	
		};
};

Appointment :: Appointment(string *_temp)
{
	S.setNumber(_temp[0]);
	L.setNumber(_temp[1]);
	setDate(_temp[2]);
	setStart(_temp[3]);
	setEnd(_temp[4]);	
}

void countFile(char *filename, int filenum)
{
	
	string temp;
	ifstream readFile;
	readFile.open(filename);
	while(getline(readFile, temp))
	{
		count[filenum]++;
	}
	readFile.close();
}

void readFromFile(Student _s[], Lecturer _l[], Appointment _a[], char *f1, char *f2, char *f3)
{	
	
	string temp[10];
	int i=0, num=0, j=0;
	 ifstream readFile(f1);
     string line;
     while(getline(readFile,line)){
        stringstream ss(line);
          i=0;         
        while (getline(ss, temp[i], ',')) {
            i++;

            if (i == 7) {
                Student s(temp,7);

                _s[num] = s;

                num++;

                i = 0;
            }
        }
    }

    // Close the file
    readFile.close();
	//read from Lecturers.csv
	i=0;
	num=0;
	ifstream readFile2(f2);
     string line2;
     while(getline(readFile2,line2)){
        stringstream ll(line2);
          i=0;         
        while (getline(ll, temp[i], ',')) {
            i++;

			//control with 7, since each line contains 7 elements
			if(i==7)
			{
				Lecturer l(temp);
				_l[num] = l;
				num++;
				i=0;
			}
		}
	}
	readFile.close();
	
	//read from appointments.csv file
	bool control;
	i=0;
	num=0;
	ifstream readFile3(f3);
     string line3;
     while(getline(readFile3,line3)){
        stringstream mm(line3);
          i=0;         
        // Read each line from the CSV file
        while (getline(mm, temp[i], ',')) {
            i++;

			if(i==5)
			{
				if(num==0)
				{
					Appointment a(temp);
					_a[num] = a;
					num++;
					i=0;
				}
				else
				{
					for(j=0;j<num;j++)
					{
						if(_a[j].getDate() == temp[2] && (_a[j].getStart() == temp[3] || _a[j].getEnd() == temp[4] ))
						{
							cout<<"Error. "<<temp[0]<<" between "<<temp[1]<<" appointment cannot be scheduled."<<endl;
							cout<<"This time period is full. "<<endl<<endl;	
							control = false;
							break;
						}
						else control = true;
					}
					if(control)
					{
						Appointment a(temp);
						_a[num] = a;
						num++;
					}
					i=0;
				}
			}
		}
	}
	readFile.close();
}

int main()
{
	
	
	count[0]=0;
	count[1]=0;
	count[2]=0;
	
	char *file1 = "Students.csv"; 
	char *file2 = "Lecturers.csv";
	char *file3 =  "Appointments.csv";

	countFile(file1, 0);
	countFile(file2, 1);
	countFile(file3, 2);
	int x = count[0];
	int y = count[1];
	int z = count[2];
	Student _S[100];
	Lecturer _L[100];
	Appointment _A[100];
	readFromFile(_S, _L, _A, file1, file2, file3);
	
	int menuLoop = 0;
	int menu=0;
	int i;
	
	while(menuLoop!=5)
	{
		cout<<endl<<"Student - Lecturer Appointment System"<<endl<<endl;
		cout<<"Menu:"<<endl;
		cout<<"1 - Student Menu"<<endl;
		cout<<"2 - Lecturer Menu"<<endl;
		cout<<"3 - Appointment Menu"<<endl;
		cout<<"4 - Get Final Lists"<<endl;
		cout<<"5 - Exit"<<endl;
		cin>>menuLoop;
		
		if(menuLoop==1)
		{
			cout<<"1 - Add Student"<<endl;
			cout<<"2 - List Students"<<endl;
			cout<<"3 - Remove Student"<<endl;
			cout<<"4 - Update Student"<<endl;
			cin>>menu;
			
			if(menu==1)
			{
				string temp_;
				Student newS;
				cout<<"Student No.(6 digits):"<<endl;
				cin>>temp_;
				newS.setNumber(temp_);
				cout<<"Student Name:"<<endl;
				cin>>temp_;
				newS.setName(temp_);
				cout<<"Student Last Name:"<<endl;
				cin>>temp_;
				newS.setSurname(temp_);
				cout<<"Student Department:"<<endl;
				cin>>temp_;
				newS.setDepartment(temp_);
				cout<<"Student Starting Year:"<<endl;
				cin>>temp_;
				newS.setYear(temp_);
				cout<<"Student E-Mail:"<<endl;
				cin>>temp_;
				newS.setEmail(temp_);
				cout<<"Student Phone Number:"<<endl;
				cin>>temp_;
				newS.setPhone(temp_);
				
				_S[x] = newS; 
				x++;
			}
			else if(menu==2)
			{cout<<"****__________________STUDENT MENU_________________*****"<<endl;
				cout<<endl;
				for(i=0; i<x; i++)
				{
					_S[i].display();
				}
			}
			else if(menu==3)
			{
				string temp_;
				int deleted;
				cout<<"Enter the Student No(6 digits) to remove:"<<endl;
				cin>>temp_;
				i=0;
				while(i<x)
				{
					if(_S[i].getNumber()==temp_) deleted = i;
					i++;
				}
				for(i=deleted; i<x; i++)
				{
					_S[i] = _S[i+1];
				}
			}
			else if(menu==4)
			{
				string temp_;
				int updated;
				cout<<"Enter the Student No.(6 digits) to update:"<<endl;
				cin>>temp_;
				i=0;
				while(i<x)
				{
					if(_S[i].getNumber()==temp_) updated = i;
					i++;
				}
				cout<<"Updated Student Name:"<<endl;
				cin>>temp_;
				_S[updated].setName(temp_);
				cout<<"Updated Student Last Name:"<<endl;
				cin>>temp_;
				_S[updated].setSurname(temp_);
				cout<<"Updated Student Department:"<<endl;
				cin>>temp_;
				_S[updated].setDepartment(temp_);
				cout<<"Updated Student Starting Year:"<<endl;
				cin>>temp_;
				_S[updated].setYear(temp_);
				cout<<"Updated Student E-Mail:"<<endl;
				cin>>temp_;
				_S[updated].setEmail(temp_);
				cout<<"Updated Student Phone Number:"<<endl;
				cin>>temp_;
				_S[updated].setPhone(temp_);
			}
			else
			{
			cout<<"Error."<<endl;
			}
		}
		else if(menuLoop==2)
		{
			cout<<"1 - Add Lecturer"<<endl;
			cout<<"2 - List Lecturers"<<endl;
			cout<<"3 - Remove Lecturer"<<endl;
			cout<<"4 - Update Lecturer"<<endl;
			cin>>menu;
			
			if(menu==1)
			{
				string temp_;
				Lecturer newL;
				cout<<"Lecturer No.(4 digits):"<<endl;
				cin>>temp_;
				newL.setNumber(temp_);
				cout<<"Lecturer Name:"<<endl;
				cin>>temp_;
				newL.setName(temp_);
				cout<<"Lecturer Last Name:"<<endl;
				cin>>temp_;
				newL.setSurname(temp_);
				cout<<"Lecturer Department:"<<endl;
				cin>>temp_;
				newL.setDepartment(temp_);
				cout<<"Lecturer E-Mail:"<<endl;
				cin>>temp_;
				newL.setEmail(temp_);
				cout<<"Lecturer Phone Number:"<<endl;
				cin>>temp_;
				newL.setPhone(temp_);
				cout<<"Lecturer Title:"<<endl;
				cin>>temp_;
				newL.setChair(temp_);
				
				_L[y] = newL; 
				y++;
				
			}
			else if(menu==2)
			{
				cout<<"****__________________LECTURERS MENU_________________*****"<<endl;
				cout<<endl;
				
				for(i=0; i<y; i++)
				{
					_L[i].display();
				}
				
			}
			else if(menu==3)
			{
				string temp_;
				int deleted;
				cout<<"Enter the Lecturer No.(4 digits) to remove:"<<endl;
				cin>>temp_;
				i=0;
				while(i<y)
				{
					if(_L[i].getNumber()==temp_) deleted = i;
					i++;
				}
				for(i=deleted; i<y; i++)
				{
					_L[i] = _L[i+1];
				}
			}
			else if(menu==4)
			{
				//lecturer update is chosen
				string temp_;
				int updated;
				cout<<"Enter the Lecturer No.(4 digits) to update:"<<endl;
				cin>>temp_;
				i=0;
				while(i<y)
				{
					if(_L[i].getNumber()==temp_) updated = i;
					i++;
				}
				cout<<"Updated Lecturer Name:"<<endl;
				cin>>temp_;
				_L[updated].setName(temp_);
				cout<<"Updated Lecturer Last Name:"<<endl;
				cin>>temp_;
				_L[updated].setSurname(temp_);
				cout<<"Updated Lecturer Department:"<<endl;
				cin>>temp_;
				_L[updated].setDepartment(temp_);
				cout<<"Updated Lecturer E-Mail:"<<endl;
				cin>>temp_;
				_L[updated].setEmail(temp_);
				cout<<"Updated Lecturer Phone Number:"<<endl;
				cin>>temp_;
				_L[updated].setPhone(temp_);
				cout<<"Updated Lecturer title:"<<endl;
				cin>>temp_;
				_L[updated].setChair(temp_);
			}
			else
			{
			cout<<"Error."<<endl;
			}
		}
		else if(menuLoop==3)
		{
			//appointment menu is chosen
			cout<<"1 - Add Appointment"<<endl;
			cout<<"2 - List Appointments"<<endl;
			cout<<"3 - Remove Appointment"<<endl;
			cout<<"4 - Update Appointment"<<endl;
			cin>>menu;
			
			if(menu==1)
			{
				//appointment addition is chosen
				string temp_;
				Appointment newA;
				cout<<"Student No(6 digits):"<<endl;
				cin>>temp_;
				newA.S.setNumber(temp_);
				cout<<"Lecturer No(4 digits):"<<endl;
				cin>>temp_;
				newA.L.setNumber(temp_);
				cout<<"Appointment Date:"<<endl;
				cin>>temp_;
				newA.setDate(temp_);
				cout<<"Starting Hour:"<<endl;
				cin>>temp_;
				newA.setStart(temp_);
				cout<<"Ending Hour:"<<endl;
				cin>>temp_;
				newA.setEnd(temp_);
				
				_A[z] = newA; 
				z++;
				
			}
			else if(menu==2)
			{
				//appointment display is chosen
				cout<<"**--------------------------Appointment Menu----------------------**"<<endl;
			cout<<"**--------------------------  ***Welcome*** ----------------------**"<<endl;
			cout<<endl;
			
				for(i=0; i<z; i++)
				{
					_A[i].display();
				}
				
			}
			else if(menu==3)
			{
				//appointment deletion is chosen
				string temp_, temp_2;
				int deleted;
				cout<<"Enter the  Student No.(6 digits) to remove:"<<endl;
				cin>>temp_;
				cout<<"Enter the Lecturer No.(4 digits) to remove:"<<endl;
				cin>>temp_2;
				i=0;
				while(i<z)
				{
					if(_A[i].S.getNumber()==temp_ && _A[i].L.getNumber()==temp_2) deleted = i;
					i++;
				}
				for(i=deleted; i<z; i++)
				{
					_A[i] = _A[i+1];
				}
			}
			else if(menu==4)
			{
				//appointment update is chosen
				string temp_, temp_2;
				int updated;
				cout<<"Enter the Student No.(6 digits) to update:"<<endl;
				cin>>temp_;
				cout<<"Enter the Lecturer No.(4 digits) to update:"<<endl;
				cin>>temp_2;
				i=0;
				while(i<z)
				{
					if(_A[i].S.getNumber()==temp_ && _A[i].L.getNumber()==temp_2) updated = i;
					i++;
				}
				cout<<"Updated Appointment Date:"<<endl;
				cin>>temp_;
				_A[updated].setDate(temp_);
				cout<<"Updated Starting Hour:"<<endl;
				cin>>temp_;
				_A[updated].setStart(temp_);
				cout<<"Updated Ending Hour:"<<endl;
				cin>>temp_;
				_A[updated].setEnd(temp_);
			}
			else
			{
			cout<<"Error."<<endl;
			}
		}
		else if(menuLoop==4)
		{
			//write to file is chosen
			ofstream writeToFile;

// updated student file is writing
writeToFile.open("Students.csv");
for (i = 0; i < x; i++) {
    writeToFile << _S[i].getNumber() << ","<< _S[i].getName() << ","
                << _S[i].getSurname() << ","
                << _S[i].getDepartment() << ","
                << _S[i].getYear() << ","
                << _S[i].getEmail() << ","
                << _S[i].getPhone() << endl;
}
writeToFile.close();

// updated lecturer file is writing
writeToFile.open("Lecturers.csv");
for (i = 0; i < y; i++) {
    writeToFile << _L[i].getNumber() << ","
                << _L[i].getName() << ","
                << _L[i].getSurname() << ","
                << _L[i].getDepartment() << ","
                << _L[i].getEmail() << ","
                << _L[i].getPhone() << ","
                << _L[i].getChair() << endl;
}
writeToFile.close();

// updated appointment file is writing
writeToFile.open("Appointments.csv");
for (i = 0; i < z; i++) {
    writeToFile << _A[i].S.getNumber() << ","
                << _A[i].L.getNumber() << ","
                << _A[i].getDate() << ","
                << _A[i].getStart() << ","
                << _A[i].getEnd() << endl;
}
writeToFile.close();
		}
		else if(menuLoop==5)
		{
			cout<<"Program terminated."<<endl;
			return 0;
		}
		else
		{
			cout<<"Error."<<endl;
		}
	}
	
	return 0;
	
}
