#include <iostream>
#include <windows.h>
#include "advelevator.h"

int main() {
	
	// 欢迎信息,初始化电梯系统
	std::cout << "欢迎使用本电梯系统,请先输入当前楼层的总楼层:";
	int totalFloor;
	std::cin >> totalFloor;
	std::cout << "请指定电梯所能承载的重量限制:";
	int limitWeight;
	std::cin >> limitWeight;
	std::cout << "正在创建电梯..." << std::endl;
	Sleep(500);
	AdvElevator elv(totalFloor, limitWeight);
	
	// 系统运行
	while(true) {
		std::cout << "请指定当前所需要执行的操作(0: 查询楼层;1: 使用电梯;2: 退出):";
		int op;
		std::cin >> op;
		
		if(op == 1) { 
			// 使用电梯
			
			// 确定模式
			std::cout << "请指定当前模式为上行还是下行(0: 下行;1: 上行):";
			int model;
			std::cin >> model;
			std::cout << "正在执行指令..." << std::endl;
			if(model) {  // 上行
				elv.setUpButton();
			} else {  // 下行
				elv.setDownButton();
			}
			Sleep(500);
			
			// 确定人数
			std::cout << "请指定当前需要使用电梯的总人数:";
			int sum = 0;
			std::cin >> sum;
			Sleep(500);
			
			// 获取各乘客信息
			for(int i = 1;i <= sum;i++) {
				// 获取起点
				std::cout << "请指定当前第" << i << "位乘客当前所在的楼层:";
				int fromFloor;
				std::cin >> fromFloor;
				std::cout << "正在执行指令..." << std::endl;
				Sleep(500);
				if(fromFloor > totalFloor || fromFloor < 0) {
					std::cout << "此楼层不合法." << std::endl;
					i--;
					continue;
				} else if(model && fromFloor < elv.getCurrentFloor()) {
					// 上行无法经过
					std::cout << "电梯位于上行状态,无法接收当前乘客." << std::endl;
					i--;
					continue;
				} else if(!model && fromFloor > elv.getCurrentFloor()) {
					// 下行无法经过
					std::cout << "电梯位于下行状态,无法接收当前乘客." << std::endl;
					i--;
					continue;
				}
				
				// 获取目标
				std::cout << "请指定当前第" << i << "位乘客要去往的楼层:";
				int targetFloor;
				std::cin >> targetFloor;
				std::cout << "正在执行指令..." << std::endl;
				Sleep(500);
				if(fromFloor > totalFloor || fromFloor < 0) {
					std::cout << "此楼层不合法." << std::endl;
					i--;
					continue;
				} else if(model && targetFloor < fromFloor) {
					// 上行无法到达
					std::cout << "电梯位于上行状态,无法到达目标楼层." << std::endl;
					i--;
					continue;
				} else if(!model && targetFloor > fromFloor) {
					// 下行无法到达
					std::cout << "电梯位于下行状态,无法到达目标楼层." << std::endl;
					i--;
					continue;
				}
				
				// 获取体重
				std::cout << "请告知当前第" << i << "位用户的体重:";
				int weight;
				std::cin >> weight;
				std::cout << "正在执行指令..." << std::endl;
				bool isOk = elv.setFloorNumber(Person(fromFloor,targetFloor,weight));
				Sleep(500);
				if(!isOk) {
					std::cout << "当前用户会导致超重." << std::endl;
					i--;
					continue;
				}
				std::cout << "当前用户设置完毕." << std::endl;
				Sleep(500);
			}
			
			// 启动电梯
			elv.startElevator();	
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
