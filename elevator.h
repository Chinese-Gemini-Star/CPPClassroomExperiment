#ifndef ELEVATOR_H
#define ELEVATOR_H

/*
 * 电梯类
 */
class Elevator {
public:
	
	/*
	 * 构造函数,生成电梯对象
	 * 
	 * @param{int} floor 总的楼层数
	 */
	Elevator(int floor);
	
	/*
	 *按下上行按钮,当前楼层电梯启动上行模式
	 */
	void setUpButton();
	/*
	 *按下下行按钮,当前楼层电梯启动下行模式  
	 */
	void setDownButton();
	
	/*
	 * 输入要前往的楼层,启动电梯,电梯开始运行,并逐层显示经过的楼层
	 * 
	 * @param{int} floorNumber 要前往的楼层
	 */
	void setFloorNumber(int floorNumber);
	
	/*
	 * 获得当前所在的楼层
	 * 
	 * @return{int} 当前所在的楼层
	 */
	int getCurrentFloor();
protected:
	
	int totalFloor;  // 总的楼层数
	int currentFloor;  // 当前所在楼层
	bool isUp;  // 当前是否上行
	bool isDown;  // 当前是否下行
};

#endif
