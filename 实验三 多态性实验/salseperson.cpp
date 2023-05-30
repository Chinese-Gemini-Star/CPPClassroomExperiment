#include "salseperson.h"

SalsePerson::SalsePerson(int id,std::string name,std::string sex,std::string inDay,std::string position, double salary, double profit):Staff(id,name,sex,inDay,position,salary),profit(profit) {}

double SalsePerson::get_pay() {
	return salary + profit * 0.05;
}
