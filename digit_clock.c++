#include<iostream>
#include<iomanip>
using namespace std;

class DigitalC{
	private:
		int hours,minutes,seconds;
	public:
		DigitalC(int h, int m, int s){
			hours = h;
			minutes = m;
			seconds = s;
		}
		
		void displayTime (){
			
			if (hours < 24 && minutes <= 59 && seconds <= 59){
				cout << "Displaying the time according to the 24 hours clock" << endl;
				cout << setfill('0') << setw(2) << hours << " : " << setw(2) << minutes << " : " << setw(2) << seconds << " " << endl;
			}
			else 
				cout << "!!!INVALIDE INPUT!!" << endl;
		}
};

int main(){
	int hours, minutes, seconds;
	
	cout << "Enter Hours : ";
	cin >> hours;
	
	cout << "Enter Minutes : ";
	cin >> minutes;
	
	cout << "Enter Seconds : ";
	cin >> seconds;
	
	DigitalC clock(hours, minutes, seconds);
	clock.displayTime();
	
	return 0;
}
