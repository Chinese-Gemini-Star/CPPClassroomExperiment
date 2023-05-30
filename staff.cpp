#include <iomanip>

#include "staff.h"

std::ostream& operator<<(std::ostream &out, Staff & staff) {
	out << "编号:" << staff.id << "\t姓名:" << staff.name << "\t性别:" << staff.sex << "\t入职时间" << staff.inDay << "\t职位:" << staff.position << "\t基本工资:" << std::fixed << std::setprecision(3) << staff.salary << "\t实际薪金:" << std::fixed << std::setprecision(3) << staff.get_pay();
	return out;
}


std::string Staff::getPosition() {
	return position;
}

Staff::Staff(int id,std::string name,std::string sex,std::string inDay,std::string position, double salary) : id(id), name(name), sex(sex), inDay(inDay), position(position), salary(salary) {}

Staff::~Staff(){}
