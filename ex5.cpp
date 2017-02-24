// Created a simple class to help demonstrate the rule of five
// The rule of five specifies that if a class defines one of the following:
//    1. destructor
//    2. copy constructor
//    3. copy assignment
//    4. move constructor
//    5. move assignment
// The class should define all five
// 
// This class also helps demonstrates RAII (Resource Acquisition is Initialisation), which is when a 
// resource (usually allocated on the heap) is relinquished in the destructor.

#include <iostream>
#include <string>
#include <algorithm>

class Foo {
public:
	// constructor
	Foo(const char* arg) : m_resource(new char[std::strlen(arg)+1]) {
		std::strcpy(m_resource, arg);
	}	

	// destructor
	~Foo() {
		delete[] m_resource;
	}

	// copy constructor
	Foo(const Foo& other) : m_resource(new char[std::strlen(other.m_resource)+1]) {
		std::strcpy(m_resource, other.m_resource);
	}

	// copy assignment
	Foo& operator=(Foo& other) {
		std::swap(m_resource, other.m_resource);
		return *this;	
	}

	// move constructor
	Foo(Foo&& other) : m_resource(other.m_resource) {
		other.m_resource = nullptr;	
	}

	// move assignment
	Foo& operator=(Foo&& other) {
		std::swap(m_resource, other.m_resource);
		return *this;
	}

	char* getResource() {
		return m_resource;
	}

private:
	char* m_resource;	
};

int main() {
	// invoke constructor
	Foo foo("Hello World!");

	// invoke copy constructor
	Foo foo_dup(foo);

	// invoke move constructor
	Foo bar = std::move(foo_dup);
	
	// invoke copy assignment
	foo_dup = foo;

	// invoke move assignment
	bar = std::move(foo_dup);
	return EXIT_SUCCESS;
}
