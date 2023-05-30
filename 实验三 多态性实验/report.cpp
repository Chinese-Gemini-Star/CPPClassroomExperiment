#include <algorithm>
#include <iomanip>

#include "report.h"

void Report::insert(Staff *staff) {
	staffs.emplace(staff);
}

void Report::print() {
	std::string book[3] = {"经理", "技术人员", "营销人员"};
	for(auto &s : book) {
		std::cout << s << ":" << std::endl;
		std::set<Staff *> staffs = (*this)[s];
		
		if(staffs.size()) {
			for(auto &i : staffs) {
				std::cout << *i << std::endl;
			}
			std::cout << "最低薪金:" << std::fixed << std::setprecision(3) << getMin(staffs) << "\t最高薪金:" << std::fixed << std::setprecision(3) << getMax(staffs) << std::endl;
			std::cout << "----------------------------------------------" << std::endl;	
		}
	}
}

double Report::getMax(std::set<Staff *> staffs) {
	double res = (*staffs.begin())->get_pay();
	for(auto &i : staffs) {
		res = std::max(i->get_pay(), res);
	}
	return res;
}

double Report::getMin(std::set<Staff *>staffs) {
	double res = (*staffs.begin())->get_pay();
	for(auto &i : staffs) {
		res = std::min(i->get_pay(), res);
	}
	return res;
}

std::set<Staff *> Report::operator[](std::string x) {
	std::set<Staff *> res;
	for(auto &i : staffs) {
		if(i->getPosition() == x) {
			res.emplace(i);
		}
	}
	return res;
}

Report::~Report() {
	for(auto &i : staffs) {
		delete i;
	}
	staffs.clear();
}
