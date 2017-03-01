// Very simple example of the usage of class templates
//
// With class templates you must explicitly pass the template type, which demonstrated on line 23 and 26

#include <iostream>

template<class T>
class Foo {
public:
	Foo(const T& val) {
		m_val = val;
	}

	T getValue() const {
		return m_val;
	}

private:
	T m_val;
};

int main() {
	Foo<int> foo1(20);
	std::cout << foo1.getValue() << std::endl;

	Foo<double> foo2(4.5);
	std::cout << foo2.getValue() << std::endl;
	return EXIT_SUCCESS;
}
