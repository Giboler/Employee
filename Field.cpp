#include "Field.h"
void Field::setField()
{
	while (true) {
		string tempField;
		cout << "Enter the field name: "; cin >> tempField;
		if (searchField(tempField)) {
			if (tempField == field) {
				cout << "This field already exists. Try something else!" << endl;
				continue;
			}
		}
		else {
			cout << "Field Added!" << endl;
			setID();
			field = tempField;
			break;
		}
	}
}

void Field::setID()
{
	int counter = 0;
	fstream table;
	table.open("Fields.txt", ios::in);
	while (!table.eof()) {
		getline(table, line);
		if (line == "") {
			fieldID = counter;
			break;
		}
		unpack();
		counter++;
		if (fieldID == counter) {
			counter++;
			continue;
		}
	}
	table.close();
}

void Field::pack()
{
	line = field + "|" + to_string(fieldID) + "|" "\n";
}

void Field::unpack()
{
	string values[4];
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
	field = values[0];
	fieldID = stoi(values[1]);
}

void Field::insert()
{
	setField();
	pack();
	fstream file;
	file.open("Fields.txt", ios::out | ios::app);
	file << line;
	file.close();
}

void Field::display()
{
	cout << "Field Name: " << field << endl
		<< "Field ID: " << fieldID << endl;
}

bool Field::searchField(string n)
{
	fstream table;
	table.open("Fields.txt", ios::in);
	while (!table.eof())
	{
		getline(table, line);
		if (line == "") {
			return false;
			break;
		}
		unpack();
		if (field == n) {
			pack();
			cout << "Department: " << line;
			return true;
		}
	}
	table.close();
}

void Field::deleteField(string n)
{
	string key;
	key = n;
	fstream table1;
	fstream table2;
	table2.open("updatedData.txt", ios::out | ios::app);
	table1.open("Fields.txt", ios::in);
	while (!table1.eof())
	{
		getline(table1, line);
		if (line == "") {
			break;
		}
		unpack();
		if (key == field) {
			cout << "Deleted!" << endl;
			continue;
		}
		pack();
		table2 << line;
	}
	table1.close();
	table2.close();
	remove("Fields.txt");
	rename("updatedData.txt", "Fields.txt");
}

void Field::updateField()
{
	string n;
	cout << "Enter the name of the field to update: ";
	cin >> n;
	if (searchField(n)) {
		deleteField(n);
		cout << "Please choose an action from the following: " << endl;
		cout << "Option 1: Edit name." << endl;
		cout << "Option 2: Edit ID." << endl;
		char choice;
		while (true) {
			cout << "Choose: "; cin >> choice;
			if (choice == '1') {
				cout << "Enter the new Field name: "; cin >> field;
				break;
			}
			else if (choice == '2') {
				cout << "Enter the new Field ID: "; cin >> fieldID;
				break;
			}
			else {
				cout << "Invalid option, Please try again!" << endl;
			}
		}
		pack();
		fstream table;
		table.open("Fields.txt", ios::app);
		table << line;
		table.close();
		cout << "Here are the new results:" << endl;
		display();
	}
}

void Field::displayAll()
{
	fstream table;
	table.open("Fields.txt", ios::in);
	cout << "Here are all the available fields:" << endl;
	while (!table.eof()) {
		getline(table, line);
		cout << line << endl;
	}
	table.close();
}

void Field::fieldStart()
{
	char choice;
	cout << "Please choose an action from the following: " << endl;
	cout << "Option 1: Add a Field." << endl;
	cout << "Option 2: Search for a specific Field." << endl;
	cout << "Option 3: Delete a Field." << endl;
	cout << "Option 4: Edit an existing Field." << endl;
	cout << "Option 5: View all available Fields." << endl;
	while (true) {
		line = "";
		cout << "Choose: "; cin >> choice;
		if (choice == '1') {
			insert();
			break;
		}
		else if (choice == '2') {
			string n;
			cout << "Enter the name of the Field: ";
			cin >> n;
			if (searchField(n)) {
				break;
			}
			else {
				cout << "This Field Doesn't Exist! Please try again." << endl;
				break;
			}
		}
		else if (choice == '3') {
			string n;
			cout << "Enter the name of the Field to delete: ";
			cin >> n;
			deleteField(n);
			break;
		}
		else if (choice == '4') {
			updateField();
			break;
		}
		else if (choice == '5') {
			displayAll();
			break;
		}
		else {
			cout << "Invalid option, Please try again!" << endl;
		}
	}
	char choice2;
	cout << "Would you like to do something else in the Field section?(y/n): "; cin >> choice2;
	if (choice2 == 'y') {
		fieldStart();
	}
	else {
		NULL;
	}
}