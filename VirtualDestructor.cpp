// Making the parent destructor virtual will execute both destructors when 
// delete is called on the instance of the derived class.

#include <iostream>

class Foo {
public:
  virtual ~Foo() {
    std::cout << "Foo destructor" << std::endl;
	}
};

class Bar : public Foo {
public:
	~Bar() {
		std::cout << "Bar destructor" << std::endl;
	}
};

int main() {
	Foo* F = new Bar;
	delete F;
	return EXIT_SUCCESS;
}
