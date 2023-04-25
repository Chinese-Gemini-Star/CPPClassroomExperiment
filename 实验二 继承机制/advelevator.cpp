#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <windows.h>
#include "advelevator.h"

AdvElevator::AdvElevator(int floor, int limitWeight) : Elevator(floor), limitWeight(limitWeight), sumWeight(floor + 1) {}

bool AdvElevator::setFloorNumber(const Person &per) {
	for(int i = std::min(per.getFrom(),per.getTarget());i <= std::max(per.getFrom(),per.getTarget());i++) {
		if(sumWeight[i] + per.getWeight() > limitWeight) {
			std::cout << sumWeight[i] << std::endl;
			return false;
		}
	}
	for(int i = std::min(per.getFrom(),per.getTarget());i <= std::max(per.getFrom(),per.getTarget());i++) {
		sumWeight[i] += per.getWeight();
	}
	waits.push_back(per);
	return true;
}

void AdvElevator::startElevator() {
	// 对等待乘坐乘客进行排序
	std::sort(waits.begin(),waits.end(),[this](const auto &a,const auto &b)->bool {
		if(isUp) {
			return a.getFrom() < b.getFrom();
		} else {
			return a.getFrom() > b.getFrom();
		}
	});
	
	// 上行
	if(isUp) {
		// 存放各个乘客的目标楼层
		std::priority_queue<Person,std::vector<Person>,std::greater<Person>> use;
		
		// 启动电梯
		for(;waits.size() || use.size();currentFloor++) {
			std::cout << "当前电梯已到底第" << currentFloor << "层." << std::endl;
			Sleep(500);
			
			// 当前等待乘客上电梯
			while(waits.size() && currentFloor == waits[0].getFrom()) {
				use.emplace(waits[0]);
				std::cout << "有一位体重为" << waits[0].getWeight() << "的乘客登上电梯!" << std::endl;
				waits.erase(waits.begin());
				Sleep(500);
			}
			
			// 当前到底乘客下电梯
			while(use.size() && currentFloor == use.top().getTarget()) {
				std::cout << "有一位体重为" << use.top().getWeight() << "的乘客离开了电梯!" << std::endl;
				use.pop();
				Sleep(500);
			}
			Sleep(500);
		}
		currentFloor--;
		std::cout << "所有乘客均已到达,电梯当前位于" << currentFloor << "层,运行结束." << std::endl;
	} else {
		// 存放各个乘客的目标楼层
		std::priority_queue<Person> use;
		
		// 启动电梯
		for(;waits.size() || use.size();currentFloor--) {
			std::cout << "当前电梯已到底第" << currentFloor << "层." << std::endl;
			Sleep(500);
			
			// 当前等待乘客上电梯
			while(waits.size() && currentFloor == waits[0].getFrom()) {
				use.emplace(waits[0]);
				waits.erase(waits.begin());
				std::cout << "有一位体重为" << waits[0].getWeight() << "的乘客登上电梯!" << std::endl;
				Sleep(500);
			}
			
			// 当前到底乘客下电梯
			while(use.size() && currentFloor == use.top().getTarget()) {
				std::cout << "有一位体重为" << use.top().getWeight() << "的乘客离开了电梯!" << std::endl;
				use.pop();
				Sleep(500);
			}
			Sleep(500);
		}
		currentFloor++;
		std::cout << "所有乘客均已到达,电梯当前位于" << currentFloor << "层,运行结束." << std::endl;
	}
	sumWeight = std::vector<int>(totalFloor + 1,0);
}
