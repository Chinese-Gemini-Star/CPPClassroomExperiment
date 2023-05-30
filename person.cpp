#include "person.h"

Person::Person(int from, int target, int weight) : from(from), target(target),weight(weight) {}

int Person::getFrom() const {
	return from;
}
int Person::getTarget() const {
	return target;
}

int Person::getWeight() const {
	return weight;
}

bool Person::operator<(const Person& per) const {
	return target < per.target;
}

bool Person::operator>(const Person& per) const {
	return target > per.target;
}
