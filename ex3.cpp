// Making area() a pure virtual function implicity makes the class abstract, and as a result, cannot be instantiated.
// Also the area function will be implemented by dervied classes, which can be seen below.

#include <iostream>
#include <cstddef>

class Shape {
public:
	Shape(const std::size_t& width, const std::size_t& height) {
		m_width = width;
		m_height = height;
	}
	virtual std::size_t area() = 0;

protected:
	std::size_t m_width;
	std::size_t m_height;
};

class Triangle : public Shape {
public:
	Triangle(const std::size_t& width, const std::size_t& height) : Shape(width, height) {}
	std::size_t area() {
		return (m_width*m_height)/2;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(const std::size_t& width, const std::size_t& height) : Shape(width, height) {}
	std::size_t area() {
		return m_width*m_height;
	}
};

int main() {
	Shape* s1 = new Triangle(4,13);
	std::cout << s1->area() << std::endl;	
	Shape* s2 = new Rectangle(6,11);
	std::cout << s2->area() << std::endl;	
	return EXIT_SUCCESS;
}
