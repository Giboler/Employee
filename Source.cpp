#include "Employee.h"
int main() {
	Employee e1;
	Field f1;
	char choice;
	cout << "Welcome to our project!" << endl;
	while (true) {
	cout << "Please choose an action from the following: " << endl;
	cout << "Option 1: Field Section." << endl;
	cout << "Option 2: Employee Section." << endl;
		cout << "Choose: "; cin >> choice;
		if (choice == '1') {
			f1.fieldStart();
		}
		else if (choice == '2') {
			e1.empStart();
		}
		else {
			cout << "Invalid option, Please try again!" << endl;
		}
		char choice2;
		cout << "Would you like to do something else in the Project?(y/n): "; cin >> choice2;
		if (choice2 == 'y') {
			continue;
		}
		else {
			break;
		}
	}
}