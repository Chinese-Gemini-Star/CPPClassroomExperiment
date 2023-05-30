#ifndef MANAGER_H
#define MANAGER_H

#include <string>

#include "staff.h"

class Manager : public Staff{
public:
	Manager(int id,std::string name,std::string sex,std::string inDay,std::string position,double salary, double bonus);
	double get_pay() override;
	
private:
	double bonus;
};

#endif
