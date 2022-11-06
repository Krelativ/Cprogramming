#include <iostream>
#include <calc.hpp>

int cl::calc::add(const int a, const int b)
{
	return (a+b);
}
int cl::calc::subtract(const int a, const int b)
{
	return (a-b);
}

// int main()
// {
// 	cl::calc operation;
//  	std::cout << " add oper: "<< operation.add(5,6) << std::endl;
//  	std::cout << " sub oper: "<< operation.subtract(155,63) << std::endl;

//  	return 0;
//  }
