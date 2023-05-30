#include "manager.h"

Manager::Manager(int id,std::string name,std::string sex,std::string inDay,std::string position, double salary, double bonus): Staff(id,name,sex,inDay,position,salary),bonus(bonus) {}

double Manager::get_pay() {
	return salary + bonus;
}
