#ifndef PERSON_H
#define PERSON_H

class Person {
public:
	/*
	 * 构造函数,生成乘客对象
	 * 
	 * @param{int} from 乘客位置
	 * @param{int} targer 目标楼层
	 * @param{int} weight 乘客体重
	 */
	Person(int from, int target,int weight);
	/*
	 * 获得当前乘客的起点楼层
	 * 
	 * @return{int} 乘客起点的楼层
	 */
	int getFrom() const;
	/*
	 * 获得当前乘客的目标楼层
	 * 
	 * @return{int} 乘客目标的楼层
	 */
	int getTarget() const;
	/*
	 * 获得当前乘客的体重
	 * 
	 * @return{int} 乘客的体重
	 */
	int getWeight() const;
	/*
	 * 按照目标楼层比较大小
	 */
	bool operator<(const Person& per) const;
	bool operator>(const Person& per) const;
private:
	/*
	 * 起点楼层
	 */
	int from;
	/*
	 * 目标楼层
	 */
	int target;
	/*
	 * 体重
	 */
	int weight;
};

#endif
