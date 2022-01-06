#include "Employee.h"
void Employee::setEmp()
{
	while (true) {
		setEmpID();
		cout << "Please enter the Employee Field: "; cin >> empField;
		cout << "Please enter the Employee Name: "; cin >> empName;
		cout << "Please enter the Employee Salary: "; cin >> empSalary;
		cout << "Please enter the Employee Age: "; cin >> empAge;
		cout << "Please enter the Employee Phone Number: "; cin >> phoneNumber;
		cout << "Please enter the Employee Address: "; cin >> empAddress;
		if (searchField(empField)) {
			if (empField == field) {
				cout << "Employee registered succesfully!" << endl;
				break;
			}
		}
		else {
			cout << "This field doesn't exist, Please try again!" << endl;
			continue;
		}
	}
}

void Employee::empPack()
{
	line = empField + "|"
		+ empName + "|"
		+ empSalary + '|'
		+ empAge + '|'
		+ phoneNumber + '|'
		+ empAddress + '|'
		+ to_string(empID) + '|'
		+ "\n";
}

void Employee::empUnpack()
{
	string values[7];
	string temp = "";
	int counter = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '|')
		{
			values[counter] = temp;
			temp = "";
			counter++;
		}
		else if (i == line.length() - 1)
		{
			values[counter] = temp;
		}
		else
		{
			temp += line[i];
		}
	}
	empField = values[0];
	empName = values[1];
	empSalary = values[2];
	empAge = values[3];
	phoneNumber = values[4];
	empAddress = values[5];
	empID = stoi(values[6]);
}

void Employee::setEmpID()
{
	int counter = 0;
	fstream table;
	table.open("Employees.txt", ios::in);
	while (!table.eof()) {
		getline(table, line);
		if (line == "") {
			empID = counter;
			break;
		}
		empUnpack();
		counter++;
		if (empID == counter) {
			counter++;
			continue;
		}
	}
	table.close();
}

void Employee::insertEmp()
{
	setEmp();
	empPack();
	fstream file;
	file.open("Employees.txt", ios::out | ios::app);
	file << line;
	file.close();
}

void Employee::dispEmp()
{
	cout << "Employee Name: " << empName << endl
		<< "Employee ID: " << empID << endl
		<< "Employee Salary: " << empSalary << endl
		<< "Employee Age: " << empAge << endl
		<< "Employee Phone number: " << phoneNumber << endl
		<< "Employee Address: " << empAddress << endl;
}

bool Employee::searchEmp(int n)
{
	fstream table;
	table.open("Employees.txt", ios::in);
	while (!table.eof())
	{
		getline(table, line);
		if (line == "") {
			return false;
			break;
		}
		empUnpack();
		if (empID == n) {
			empPack();
			cout << line;
			return true;
		}
	}
	table.close();
}

void Employee::deleteEmp(int n)
{
	int key;
	key = n;
	fstream table1;
	fstream table2;
	table2.open("updatedData.txt", ios::out | ios::app);
	table1.open("Employees.txt", ios::in);
	while (!table1.eof())
	{
		getline(table1, line);
		if (line == "") {
			break;
		}
		empUnpack();
		if (key == empID) {
			cout << "Deleted!" << endl;
			continue;
		}
		empPack();
		table2 << line;
	}
	table1.close();
	table2.close();
	remove("Employees.txt");
	rename("updatedData.txt", "Employees.txt");
}

void Employee::updateEmp()
{
	int n;
	cout << "Enter the ID of the Employee to update: ";
	cin >> n;
	if (searchEmp(n)) {
		deleteEmp(n);
		cout << "Please choose an action from the following: " << endl;
		cout << "Option 1: Edit name." << endl;
		cout << "Option 2: Edit ID." << endl;
		cout << "Option 3: Edit type." << endl;
		cout << "Option 4: Edit Specification. " << endl;
		cout << "Option 5: Edit maker." << endl;
		char choice;
		while (true) {
			cout << "Choose: "; cin >> choice;
			if (choice == '1') {
				cout << "Enter the new Employee name: "; cin >> empName;
				break;
			}
			else if (choice == '2') {
				cout << "Enter the new Employee ID: "; cin >> empID;
				break;
			}
			else if (choice == '3') {
				cout << "Enter the new Employee salary: "; cin >> empSalary;
				break;
			}
			else if (choice == '4') {
				cout << "Enter the new Employee phone number: "; cin >> phoneNumber;
				break;
			}
			else if (choice == '5') {
				cout << "Enter the new Employee address: "; cin >> empAddress;
				break;
			}
			else {
				cout << "Invalid option, Please try again!" << endl;
			}
		}
		empPack();
		fstream table;
		table.open("Employees.txt", ios::app);
		table << line;
		table.close();
		cout << "Here are the new results:" << endl;
		dispEmp();
	}
	else {
		char choice2;
		cout << "Would you like to try again?(y/n): "; cin >> choice2;
		if (choice2 == 'y') {
			updateEmp();
		}
		else {
			NULL;
		}
	}
}

void Employee::dispAll()
{
	while (true) {
		string n;
		cout << "Enter the name of the Field to display it's employees: ";
		cin >> n;
		if (searchField(n)) {
			fstream table;
			table.open("Employees.txt", ios::in);
			cout << "Here are all the employees woriking in " << field <<" :" << endl;
			while (!table.eof()) {
				getline(table, line);
				if (line == "") {
					break;
				}
				empUnpack();
				if (empField == n) {
					cout << line << endl;
				}
				else {
					continue;
				}
			}
			table.close();
			break;
		}
		else {
			cout << "Field Doesn't Exist! Please try again." << endl;
			break;
		}
	}
}

void Employee::empStart()
{
	char choice;
	cout << "Please choose an action from the following: " << endl;
	cout << "Option 1: Add an Employee." << endl;
	cout << "Option 2: Search for an Employee." << endl;
	cout << "Option 3: Delete an Employee." << endl;
	cout << "Option 4: Edit an existing Employee." << endl;
	cout << "Option 5: View all Employees in a field." << endl;
	while (true) {
		line = "";
		cout << "Choose: "; cin >> choice;
		if (choice == '1') {
			insertEmp();
			break;
		}
		else if (choice == '2') {
			int n;
			cout << "Enter the ID of the Employee: ";
			cin >> n;
			searchEmp(n);
			break;
		}
		else if (choice == '3') {
			int n;
			cout << "Enter the ID of the employee to delete: ";
			cin >> n;
			deleteEmp(n);
			break;
		}
		else if (choice == '4') {
			updateEmp();
			break;
		}
		else if (choice == '5') {
			dispAll();
			break;
		}
		else {
			cout << "Invalid option, Please try again!" << endl;
		}
	}
	char choice2;
	cout << "Would you like to do something else in the Employee section?(y/n): "; cin >> choice2;
	if (choice2 == 'y') {
		empStart();
	}
	else {
		NULL;
	}
}
