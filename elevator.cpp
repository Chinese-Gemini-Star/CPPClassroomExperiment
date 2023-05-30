#include <iostream>
#include <windows.h>

#include "elevator.h"

Elevator::Elevator(int floor) : totalFloor(floor),currentFloor(1),isUp(false),isDown(false) {
	std::cout << "电梯已经创建,总楼层数为:" << totalFloor << std::endl;	
	std::cout << "当前电梯位于第1楼." << std::endl;
}

void Elevator::setUpButton() {
	isUp = true;
	isDown = false;
	std::cout << "已设置当前模式为上行." << std::endl;
}

void Elevator::setDownButton() {
	isDown = true;
	isUp = false;
	std::cout << "已设置当前模式为下行." << std::endl;
}

void Elevator::setFloorNumber(int floorNumber) {
	if(floorNumber == currentFloor) {
		// 当前已位于目标楼层
		std::cout << "指令非法,当前已位于第" << currentFloor << "楼." << std::endl;
	} else if(floorNumber > totalFloor) {
		// 目标超出总楼层
		std::cout << "指令非法,目标楼层超出总楼层,无法前往." << std::endl;
	} else if(floorNumber <= 0) {
		// 目标位于地下
		std::cout << "指令非法,无地下楼层,无法前往." <<std::endl;
	} else if(isUp) {
		// 上行
		if(floorNumber > currentFloor) {
			// 可以以上行模式前往目标楼层
			std::cout << "指令合法,正在从当前位于的第" << currentFloor << "楼前往目标楼层." << std::endl;
			
			// 前往目标楼层
			for(currentFloor+=1; currentFloor < floorNumber; currentFloor++) {
				std::cout << "当前已到达第" << currentFloor << "楼." << std::endl;
				Sleep(1000);
			}
			
			std::cout << "当前已到达目标的第" << currentFloor << "楼,指令完成." << std::endl;
		} else {
			// 不可以上行前往目标楼层
			std::cout << "指令非法,当前电梯处于上行模式,目标楼层高于当前楼层,无法前往.如有必要,请将电梯模式切换为下行." << std::endl;
		}
	} else if(isDown) {
		// 下行
		if(floorNumber < currentFloor) {
			// 可以以上行模式前往目标楼层
			std::cout << "指令合法,正在从当前位于的第" << currentFloor << "楼前往目标楼层." << std::endl;
			
			// 前往目标楼层
			for(currentFloor-=1; currentFloor > floorNumber; currentFloor--) {
				std::cout << "当前已到达第" << currentFloor << "楼." << std::endl;
				Sleep(300);
			}
			
			std::cout << "当前已到达目标的第" << currentFloor << "楼,指令完成." << std::endl;
		} else {
			// 不可以上行前往目标楼层 
			std::cout << "指令非法,当前电梯处于下行模式,目标楼层低于当前楼层,无法前往.如有必要,请将电梯模式切换为上行." << std::endl;
		}
	}
}

int Elevator::getCurrentFloor() {
	return currentFloor;
}
