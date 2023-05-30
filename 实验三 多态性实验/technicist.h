#ifndef TECHNICIST_H
#define TECHNICIST_H

#include "staff.h"

class Technicist : public Staff{
public:
	Technicist(int id,std::string name,std::string sex,std::string inDay,std::string position, double salary);
	double get_pay() override;
private:

};

#endif
