#ifndef ADVELEVATOR_H
#define ADVELEVATOR_H

#include <vector>
#include "elevator.h"
#include "person.h"

class AdvElevator : public Elevator {
public:
	/*
	 * 构造函数,生成多人电梯对象
	 * 
	 * @param{int} floor 总的楼层数
	 * @param{int} limitWeight 总限重
	 */
	AdvElevator(int floor, int limitWeight);
	/*
	 * 设置电梯楼层(通过乘客对象设置)
	 */
	bool setFloorNumber(const Person &per);
	/*
	 * 启动电梯
	 */
	void startElevator();
private:
	/*
	  废止基类的单独设置楼层功能
	 */
	using Elevator::setFloorNumber;
	/*
	 * 等待乘坐电梯的乘客
	 */
	std::vector<Person> waits;
	/*
	 * 总限制重量
	 */
	int limitWeight;
	/*
	 * 各层乘客总重量
	 */
	std::vector<int> sumWeight;
};

#endif
