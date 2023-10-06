#include<iostream>
using namespace std;

class ATM{
	private : 
		int balance;
		int pinCode, success;
	public :
		ATM(int bal, int pin){
			balance = bal;
			pinCode = pin;
		}
		
		int getBalance(){
			return balance;
		}
		
		int withdraw(int amount, int pin){
			if(pin != pinCode){
				cout << "Invalid Pin..." << endl;
				return false;
			}
			
			if(amount > balance){
				return false;
			}
			balance = balance - amount;
			return true;
		}
		
		void deposit(int amount){
			balance = balance + amount;
		}
		
		int transfer(int amount, ATM receiver, int pin){
			if(pin != pinCode){
				return false;
			}
			
			success = withdraw(amount, pin);
			if(success){
				receiver.deposit(amount);
				return true;
			}
			
			else{
				return false;
			}
		}
};

int main(){

	ATM atm(1000,1234);
	
	int op, amount, success,pin;
	char choice;
	
	do{
		system("clear");
		cout << "1. View Balance" << endl;
		cout << "2. Cash Withdraw" << endl;
		cout << "3. Cash Deposit" << endl;
		cout << "4. Cash transfer" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter Your Choice : ";
		cin >> op;
		switch(op){
			case 1 : 
				cout << "Your Balance is : " << atm.getBalance() << endl;
				break;
			case 2 : 
				//cout << "Your Availabel Balance is : " << atm.getBalance() << endl;
				cout << "Enter the amount to withdraw : ";
				cin >> amount;
				cout << "Enter The Pin code : ";
				cin >> pin;
				success = atm.withdraw(amount, pin);	
				if(success){
					cout << "Withdraw Successfully..." << endl;
				}
				else {
					cout << "Insufficent Balance..." << endl;
				}
				break;
			case 3 :
				cout << "Enter the amount to deposit : ";
				cin >> amount;
				atm.deposit(amount);
				cout << "Deposit Successfully..." << endl;
				break;
			case 4 :
				cout << "Enter The Amount to Transfer : ";
				cin >> amount;
				cout << "Enter The Pin code : ";
				cin >> pin;
				success = atm.transfer(amount, atm, pin);
				if(success){
					cout << "Transfer Successful..." << endl;
				}
				else{
					cout << "Invalid Pin or Insufficient Balance" << endl;
				}
				break;
			case 5 :
				cout << "THANKS FOR USING ATM" << endl;
				exit(0);
			default :
				cout << "!!Invalid Choice..." << endl;
				break;
		}
		
		cout << "Do You Want To try Another Transaction [Yes/No]  : ";
		cin >> choice;
	}while(toupper(choice) == 'Y');
	
	
	return 0;
}
