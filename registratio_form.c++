#include<iostream>
#include<string>
#include<vector>
using namespace std;

class User{
	private:
		string username,password;
	public:
		User(string name, string pass){
			username = name;
			password = pass;
		}
		
		string getUsername(){
			return username;
		}
		
		string getPassword(){
			return password;
		}
};

class UserManger{
	private:
		vector<User> users; 
	public:
		void RegisterUser(){
			string username, password;
			cout << endl;
			cout << "\t\tEnter User Name : ";
			cin >> username;
			cout << "\t\tEnter Password : ";
			cin >> password;
			
			User newUser(username, password);
			users.push_back(newUser);
			
			cout << "\t\tUser Register Successfully.....1" << endl;
		}
		
		bool LoginUser(string name,string pass){
			for(int i = 0; i < users.size(); i++){
				if(users[i].getUsername() == name && users[i].getPassword() == pass){
					cout << "\t\tLogin Successfully...." << endl;
					return 1;
				}
			}
			
			cout << "\t\tInvalid User Name or Password.." << endl;
			return 0;
		}
		
		void showUser(){
			cout << "\t\t***Users List***" << endl;
			for(int i = 0; i < users.size(); i++){
				cout <<"\t\t"<< users[i].getUsername() << endl;
			}
		}
		
		void searchUser(string username){
			for(int i =0; i < users.size();i++){
				if(users[i].getUsername() == username){
					cout << "\t\tUser Found" << endl;
				}
			}
		}
		
		void deleteUser(string username){
			for(int i = 0; i < users.size(); i++){
				if(users[i].getUsername() == username){
					users.erase(users.begin() + i);
					cout << "\t\tUser Removed successfully..." << endl;
				}
			}
			
		}
	
};

int main(){
	UserManger usermanage;
	
	int op;
	string username,password;
	char choice;
	
	do{
		system("clear");
		cout << "\n\n\t\t1. Register User" << endl;
		cout << "\t\t2. Login" << endl;
		cout << "\t\t3. Show User list" << endl;
		cout << "\t\t4. Search User" << endl;
		cout << "\t\t5. Delete User" << endl;
		cout << "\t\t6. Exit" << endl;
		cout << "\t\tEnter Your choice : ";
	
		cin >> op;
		switch(op){
			case 1 :
				usermanage.RegisterUser();
				break;
				
			case 2 : 
				cout << "\t\tEnter Username :";
				cin >> username;
				cout << "\t\tEnter Password : ";
				cin >> password;
			
				usermanage.LoginUser(username,password);
				break;
				
			case 3 :
				usermanage.showUser();
				break;
				
			case 4 : 
				cout << "\t\tEnter User Name : ";
				cin >> username;
				usermanage.searchUser(username);
				break;
				
			case 5 : 
				cout << "\t\tEnter the username : ";
				cin >> username;
				usermanage.deleteUser(username);
				break;
				
			case 6 : 
				exit(0);
			
			default :
				cout << "\t\t!!!Invalid Choice..." << endl;
				exit(0);
			
		}
		
		cout << "\t\tDo you want to continue [Y/N] ? : ";
		cin >> choice;
	}while(toupper(choice) == 'Y');
	
	cout << endl;
	return 0;
}
