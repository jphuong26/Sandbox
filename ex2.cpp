// Should always make class functions constant if member variable is not to be modified
// and always pass by reference for non-builtin types (eg. string, size_t, vector).
//
// Also good to use size_t in this situation as age is positive and will resolve 
// any portibility issues.

#include <iostream>
#include <cstddef>

class Person {
public:
  Person(std::size_t age) {
    m_age = age;
  }
	
  std::size_t getAge() const {
    return m_age;
  }	

  void setAge(std::size_t& age) {
    m_age = age;
  }
  
private:
	std::size_t m_age;
};
