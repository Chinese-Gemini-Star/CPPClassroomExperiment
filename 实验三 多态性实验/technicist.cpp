#include "technicist.h"


Technicist::Technicist(int id,std::string name,std::string sex,std::string inDay,std::string position, double salary) :Staff(id,name,sex,inDay,position,salary) {}
double Technicist::get_pay() {
	return salary;
}
