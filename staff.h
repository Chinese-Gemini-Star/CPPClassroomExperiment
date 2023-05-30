#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <string>

class Staff {
public:
	Staff(int id,std::string name,std::string sex,std::string inDay,std::string position, double salary);
	virtual ~Staff();
	
	std::string getPosition();
	virtual double get_pay() = 0;
	friend std::ostream& operator<<(std::ostream &out, Staff & staff);
protected:
	int id;
	std::string name;
	std::string sex;
	std::string inDay;
	std::string position;
	double salary;
};

#endif
