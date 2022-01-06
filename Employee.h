#pragma once
#include "Field.h"
class Employee:public Field
{
public:
	string empName;
	int empID;
	string empSalary;
	string empAge;
	string phoneNumber;
	string empAddress;
	string empField;
	void setEmp();
	void empPack();
	void empUnpack();
	void setEmpID();
	void insertEmp();
	void dispEmp();
	bool searchEmp(int n);
	void deleteEmp(int n);
	void updateEmp();
	void dispAll();
	void empStart();
};

