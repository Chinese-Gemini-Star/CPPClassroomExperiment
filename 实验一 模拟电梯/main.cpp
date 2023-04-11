#include <iostream>
#include <windows.h>
#include "elevator.h"

int main() {
	
	// 欢迎信息,初始化电梯系统
	std::cout << "欢迎使用本电梯系统,请先输入当前楼层的总楼层:";
	int totalFloor;
	std::cin >> totalFloor;
	std::cout << "正在创建电梯..." << std::endl;
	Sleep(100);
	Elevator elv(totalFloor);
	
	
	// 系统运行
	while(true) {
		std::cout << "请指定当前所需要执行的操作(0: 查询楼层;1: 前往指定楼层;2: 退出):";
		int op;
		std::cin >> op;
		
		if(op == 1) { 
			// 前往执行楼层
			
			// 确定模式
			std::cout << "请指定当前模式为上行还是下行(0: 下行;1: 上行):";
			int model;
			std::cin >> model;
			std::cout << "正在执行指令..." << std::endl;
			Sleep(500);
			if(model) {  // 上行
				elv.setUpButton();
			} else {  // 下行
				elv.setDownButton();
			}
			
			// 确定目标
			std::cout << "请指定要前往的楼层:";
			int targetFloor;
			std::cin >> targetFloor;
			std::cout << "正在执行指令..." << std::endl;
			Sleep(500);
			
			// 前往目标
			elv.setFloorNumber(targetFloor);	
		} else if(op == 0){
			// 查询当前楼层
			std::cout << "正在查询..." << std::endl;
			Sleep(500);
			std::cout << "查询完成,当前电梯位于第" << elv.getCurrentFloor() << "楼." << std::endl;
		} else {
			// 退出
			return 0;
		}
		std::cout << std::endl;
	}
	return 0;
}
