#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
	private : 
		int rollno, age;
		string name;
	public : 
		Student( int stdRollno, string stdName, int stdAge){
			rollno = stdRollno;
			name = stdName;
			age = stdAge;
		}
		
		void setRollno(int stdRollno){
			rollno = stdRollno;
		}
		
		int getRollno(){
			return rollno;
		}	
		
		void setName(string stdName){
			name = stdName;
		}
		
		string getName(){
			return name;
		}
		
		void setAge(int stdAge){
			age =stdAge;
		}
		
		int getAge(){
			return age;
		}
		
		void displayStudent(){
			cout << "\t\tRoll No : " << rollno << endl;
			cout << "\t\tName : " << name << endl;
			cout << "\t\tAge : " << age << endl;
		}
};

// Creating function to add new student
void addNewStudent(vector<Student> &students){
	int rollno,age;
	string name;
	cout << "\t\tEnter Roll no : ";
	cin >> rollno;
	
	// check if roll no is repeated 
	for(int i = 0; i<students.size(); i++){
		if(students[i].getRollno() == rollno){
			cout << "\t\tStudent Already Exists..." << endl;
			return;
		}
	}
	cout << "\t\tEnter Name : ";
	cin >> name;
	cout << "\t\tEnter Age : ";
	cin >> age;
	
	Student newStudent(rollno, name, age);
	students.push_back(newStudent);
	
	cout << "\t\tStudent Added Successfully...." << endl;
}

// Creating function to display student name
void DisplayAllStudent(vector<Student>& students){
	if(students.empty()){
		cout << "\t\tNo Student Found" << endl;
		return;
	}
	for(int i = 0; i < students.size(); i++){
		students[i].displayStudent();
		cout << endl;
	}
}

//Creating function to search student
void SearchStudent(vector<Student>& students){
	int rollno;
	cout << "\t\tEnter Roll no : ";
	cin >> rollno;
	
	for(int i = 0; i<students.size(); i++){
		if(students[i].getRollno() == rollno){
			cout << "\t\t***Student Found***" << endl;
			students[i].displayStudent();
			return;
		}
	}
	cout << "\t\tStudent Not Found" << endl;
}

//Creating function to update student record
void updateStudent(vector<Student>& students){
	string name;
	bool found = false;
	int choice;
	
	cout << "\t\tEnter Name to update Student Record : ";
	cin.ignore();
	getline(cin,name);
	
	for(int i = 0; i<students.size(); i++){
		if(students[i].getName() == name){
			found = true;
			
			cout << "\t\t---Student Found---" << endl;
			cout << "\t\t1. Update Rollno " << endl;
			cout << "\t\t2. Update Name " << endl;
			cout << "\t\t3. Update age " << endl << endl;
			cout << "\t\tEnter Your Choice : ";
			cin >> choice;
			
			switch (choice){
				case 1 : {
						int rno;
					 	cout << "\t\tEnter New Rollno : ";
					 	cin >> rno;
					 	students[i].setRollno(rno);
					 	break;
				}
					 
				case 2 : {
						string name;
					 	cout << "\t\tEnter New Name : ";
					 	cin.ignore();
					 	getline(cin,name);
					 	students[i].setName(name);
					 	break;
				}
					 
				case 3 : {
						int age;
						cout << "\t\tEnter New Age : ";
						cin >> age;
						students[i].setAge(age);
						break;
				}
				
				default : cout << "\t\t!!Invalid Choice..." << endl;
			}
			
			return;
		}
	}
	cout << "\t\tRecord Not Found Here" <<endl;
}

//reating function to delete student
void deleteStudent(vector<Student>& students){
	string name;
	cout << "\t\tEnter Name To Delete : ";
	cin.ignore();
	getline(cin,name);
	
	for(int i = 0; i<students.size(); i++){
		if(students[i].getName() == name){
			students.erase(students.begin()+i);
			cout << "\t\tStudent Removed Successfully.." << endl;
			return;
		}
	}
	cout << "\t\tNo Student Found..." << endl;
}


int main(){

	vector<Student> students;
	
	//students.push_back(Student(1, "Abhi", 19));
	int op;
	char choice;
	do{
		system("clear");
		cout << "\t\t******************************" << endl;
		cout << "\t\t  Student Management System" << endl;
		cout << "\t\t******************************" << endl << endl;
		cout << "\t\t1. Add New student" << endl;
		cout << "\t\t2. Display All Students" << endl;
		cout << "\t\t3. Search student" << endl;
		cout << "\t\t4. Update Student" << endl;
		cout << "\t\t5. Delete Student" << endl;
		cout << "\t\t6. Exit" << endl << endl;
		cout << "\t\tEnter Your choice : ";
	
		cin >> op;
	
		switch(op){
			case 1 : addNewStudent(students);
				 break;
			
			case 2 : DisplayAllStudent(students);
				 break;
			
			case 3 : SearchStudent(students);
				 break;
				
			case 4 : updateStudent(students);
				 break;
				
			case 5 : deleteStudent(students);
				 break;
				 
			case 6 : exit(0);
			
			default : 
				 cout << "\t\tInvalid Number..." << endl;
				 exit(0);
		}
		
		cout << "\t\tDo You Want To Continue [Y/N] ? : ";
		cin >> choice;
	}while(toupper(choice) == 'Y');
	
	return 0;
}