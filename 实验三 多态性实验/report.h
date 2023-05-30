#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <set>
#include <iostream>

#include "staff.h"

class Report {
public:
	~Report();
	
	void insert(Staff *staff);
	void print();
	double getMax(std::set<Staff *> staffs);
	double getMin(std::set<Staff *> staffs);
	std::set<Staff *> operator[](std::string x);
private:
	std::set<Staff *> staffs;
};

#endif
