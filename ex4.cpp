// Overloading the '+' operator so that the following rules apply: eg. [3,5] + [1,8] => [4,13]
// As operator+ is implemented as a class member, the keyword 'this' represents the left-hand operand

#include <iostream>

class Foo {
public:
	Foo(int num1, int num2) {
		m_num1 = num1;
		m_num2 = num2;
	}

	Foo operator+(const Foo& obj) {
		Foo temp = *this;
		temp.m_num1 = temp.m_num1 + obj.m_num1;
		temp.m_num2 = temp.m_num2 + obj.m_num2;
		return temp;
	}
       
	int getNum1() const {
		return m_num1;
	}

	int getNum2() const {
		return m_num2;
	}

private:
	int m_num1;
	int m_num2;
};


int main() {
	Foo obj1(1,2);
	Foo obj2(3,4);
	Foo obj3 = obj1 + obj2;
	std::cout << obj3.getNum1() << " " << obj3.getNum2() << std::endl;
	return EXIT_SUCCESS;
}
