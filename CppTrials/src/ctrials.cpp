#include <iostream>
#include <string>
#include <algorithm>
#include <calc.hpp>

#define REFERENCES 0
#define NAMESPACES 0
#define CLASSES 0
#define CONSTRUCTORS 0
#if (REFERENCES)
void increment (int& value)
{
	value++;
}
void references()
{
	int a = 5;
	increment(a);
	std::cout<< "a incremented by function: "<<a <<std::endl; 
	int& ref = a;
	ref++;
	std::cout<< "a incremented by direct reference: "<<a <<std::endl; 
}
#endif
#if (NAMESPACES)
namespace apple {

	void print(const char* text)
	{
		std::cout << text << std::endl;
	}
}
namespace orange {
namespace juice{
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(),temp.end());
		std::cout << temp << std::endl;
	}
}}
void namespaces()
{
	apple::print(" apple namespace test!");
	orange::juice::print(" orange namespace test!");
	{
	namespace a = apple; // this name space only available for this scope!
	a::print("a namespace test!");
	}
	// a::print("a namespace test!"); // Not visible here

	using namespace apple;
	print(" namespace test!");  // only apple print can be used afterwards



	// using namespace orange;
	// print(" namespace test!");
}
#endif 

#if (CLASSES)
class Player
{
	// by default all things inside the class is private (i.e: not visible outside the class) unless specified
public:	
	int x,y;
	int speed;
	void Move (int xa, int ya)
	{
		x += xa*speed;
		y += ya*speed;

	}
};
void classes ()
{
	Player player;
	player.Move(1,6);

}
#endif

#if (CONSTRUCTORS)
	class Player
	{
		private:
			std::string name;
			int health;
			int xp;
		public:
		void set_name(std::string name_val){
			name = name_val;
		}
	// overloaded constructors
	Player(){ 
	// if this constructor is removed while keeping the overloaded versions
	// We must create object of classes with initializers passed
		std::cout <<"No args constructor called" <<std::endl;
	}
	Player(std::string namey)
	:Player(namey,0,0)
	//delegating constructor (use initialization style same as three arg constructor)
	//When object is initialized the 3 Arg constructor is called first then the string Arg constructor.  
	{
		std::cout <<"String arg constructor called" <<std::endl;
	}
	// the following constructor is using initializer list
	Player(std::string namey, int healthy, int xpy)
		:name{namey},health{healthy},xp{xpy}
	{
		std::cout <<"Three args constructor called" <<std::endl;
	}

	~Player(){//destructor
		std::cout <<"destructor called for "<< name <<std::endl;
	}
	};

void constructors ()
{
	/* Observe when/which  constructor are called based on code !*/
	{
		Player slayer;
		slayer.set_name("Slayer");
	}

	{
		Player khaled;
		khaled.set_name("Khaled");
		Player Mo("Mo");
		Mo.set_name("Mo");
		Player Ko("Ko",90,60);
		Ko.set_name("Ko");
	}

	Player *enemy = new Player;
	enemy->set_name("Enemy");
		
	Player *boss = new Player("boss",1000,57);
	boss->set_name("boss");

	delete enemy;
	delete boss;
}
#endif

int main ()
{
	#if (REFERENCES)
	 references();
	#endif
	#if (NAMESPACES)
    //https://en.cppreference.com/w/cpp/language/namespace
	 namespaces();
	#endif

	#if (CONSTRUCTORS)
	 constructors();
	#endif

	cl::calc operation;
 	std::cout << " add oper: "<< operation.add(5,6) << std::endl;
 	std::cout << " sub oper: "<< operation.subtract(155,63) << std::endl;
	return 0;	
}