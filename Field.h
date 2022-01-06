#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
class Field
{
public:
	string line;
	string field;
	int fieldID;
	void setField();
	void setID();
	void pack();
	void unpack();
	void insert();
	void display();
	bool searchField(string n);
	void deleteField(string n);
	void updateField();
	void displayAll();
	void fieldStart();
};