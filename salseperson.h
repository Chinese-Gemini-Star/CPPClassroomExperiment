#ifndef SALSEPERSON_H
#define SALSEPERSON_H

#include "staff.h"

class SalsePerson:public Staff {
public:
	SalsePerson(int id,std::string name,std::string sex,std::string inDay,std::string position, double salary, double porfit);
	double get_pay() override;
private:
	double profit;
};

#endif
