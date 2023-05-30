#include <iostream>
#include <string>

#include "staff.h"
#include "report.h"
#include "manager.h"
#include "salseperson.h"
#include "technicist.h"
#include "report.h"

Staff *getStaff();

int main(int argc, char** argv) {
	Report report;
	
	int num;
	std::cout << "请输入总人数:";
	std::cin >> num;
	for(int i = 0;i < num;i++) {
		report.insert(getStaff());
	}
	
	std::cout << std::endl;
	
	std::cout << "\t公司人员报表" << std::endl;
	
	report.print();

	return 0;
}

Staff *getStaff() {
	int id;
	std::string name;
	std::string sex;
	std::string inDay;
	std::string position;
	double salary;
	Staff *res;
	
	while(position != "经理" && position != "技术人员" && position != "营销人员") {
		std::cout << "请输入该员工的职位类型(经理、技术人员、营销人员):";
		std::cin >> position;	
	}
	std::cout << "请输入该员工的职位编号:";
	std::cin >> id;
	std::cout << "请输入该员工的姓名:";
	std::cin >> name;
	std::cout << "请输入该员工的性别:";
	std::cin >> sex;
	std::cout << "请输入该员工的入职时间(yyyy/MM/dd):";
	std::cin >> inDay;
	std::cout << "请输入该员工的基本工资:";
	std::cin >> salary;
	
	if(position == "技术人员") {
		res = new Technicist(id,name,sex,inDay,position,salary);
	} else if(position == "经理") {
		double bonus;
		std::cout << "请输入该员工的奖金:";
		std::cin >> bonus;
		res = new Manager(id,name,sex,inDay,position,salary,bonus);
	} else {
		double profit;
		std::cout << "请输入该员工的营销利润:";
		std::cin >> profit;
		res = new SalsePerson(id,name,sex,inDay,position,salary,profit);
	}
	return res;
}
