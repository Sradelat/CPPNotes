#include <iostream>  // angled brackets are external directories

// Chapter 4 program 2

// FUNCTIONS DO 1 THING ONLY
double getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

double calculateHeight(const double height, int seconds) 
{
	constexpr double gravity{ 9.8 };
	const double newHeight{ height - gravity * (seconds * seconds) / 2 };
	return newHeight;
}

void printHeight(const double height, int seconds)
{
	if (height > 0)
		std::cout << "At " << seconds << 
		" seconds, the ball is at height : " << height << " meters\n";
	else
		std::cout << "At " << seconds << 
		" seconds, the ball is on the ground.\n";
}

void calculateAndPrintHeight(const double towerHeight, int seconds)
{
	const double newHeight{ calculateHeight(towerHeight, seconds) };
	printHeight(newHeight, seconds);

}

int main()
{
	const double towerHeight{ getTowerHeight() };

	calculateAndPrintHeight(towerHeight, 0);
	calculateAndPrintHeight(towerHeight, 1);
	calculateAndPrintHeight(towerHeight, 2);
	calculateAndPrintHeight(towerHeight, 3);
	calculateAndPrintHeight(towerHeight, 4);
	calculateAndPrintHeight(towerHeight, 5);

	return 0;
}






// Chapter 4 program 1
//
//double getDouble() 
//{
//	std::cout << "Enter a double value: ";
//
//	double num{};
//	std::cin >> num;
//
//	return num;
//}
//
//char getOp() 
//{
//	std::cout << "Enter one of the following: +, -, *, or /: ";
//	char ch{};
//	std::cin >> ch;
//	return ch;
//}
//
//void printResult(double x, double y, char op)
//{
//	if (op == '+')
//		std::cout << x << " + " << y << " is " << x + y << '\n';
//	else if (op == '-')
//		std::cout << x << " - " << y << " is " << x - y << '\n';
//	else if (op == '*')
//		std::cout << x << " * " << y << " is " << x * y << '\n';
//	else if (op == '/')
//		std::cout << x << " / " << y << " is " << x / y << '\n';
//}
//
//int main() 
//{
//	double x{ getDouble() };
//	double y{ getDouble() };
//	char  op{ getOp() };
//	printResult(x, y, op);
//	return 0;
//}


// USE std::string variable WHEN:
// String needs to be modified
// Storing user input
// Storing return value from a function that returns std::string

// USE std::string_view variable WHEN:
// Read-only access to part or all of string is needed and wont be modified
// Symbolic constant for C string is needed
// Need continued viewing of a return value from a function

// USE std::string function parameter WHEN:
// The function must modify the string without affecting the caller (rare)

// USE std::string_view function parameter WHEN:
// The fucntion needs a read-only string

// STRING VIEW remove prefix and suffix
// 
// Remove 3 characters from the left side of string
// myString.remove_prefix(3)
// 
// Remove 4 characters from the right side of string
// myString.remove_suffix(4)
//
// String does not return to original value after removal unless reassigned

// STRING CONVERSIONS
//std::string can convert to std::string_view but not vice versa unless cast
//string view variable can be modified to be different than original string
//however original string cannot be modified else undefined behavior
//^^ string view CAN be revalidated
//a function cannot return a value to a string view
// -----------------------
//#include <string>
//#include <string_view>
//
//int main()
//{
//	using namespace std::string_literals;		// s suffix
//	using namespace std::string_view_literals;	// sv suffix
//
//	std::cout << "foo\n";	// C string
//	std::cout << "goo\n"s;	// std::string literal
//	std::cout << "moo\n"sv;	// std::string_view literal
//	return 0;
//}


// OPTIMIZED STRING
//#include <string>
//#include <string_view>
//
//int main()
//{
//	// WHAT NOT TO DO
//	//std::string s{"Hello, world!"}; // makes copy - copy string slow and bad
//	//std::cout << s << '\n';
//
//	// WHAT DO - great for function parameter use
//	std::string_view s{"Hello, world!"};  // only reads - no copy. GOOD
//	std::cout << s << '\n';
//
//
//	return 0;
//}

// STRING EXERCISE
//#include <string>
//
//int main()
//{
//	std::cout << "Enter your full name: ";
//	std::string name{};
//	std::getline(std::cin >> std::ws, name);
//
//	int age{};
//	std::cout << "Enter your age: ";
//	std::cin >> age;
//
//
//	// CHEAP
//	//int nameLength{ static_cast<int>(name.length()) };
//	//std::cout << "Your age + Length of name is: " << age + nameLength;
//
//	// EXPENSIVE
//	std::cout << "Your age + Length of name is: " << age + std::ssize(name);
//
//	return 0;
//}

// STRING LENGTH - returns type size_t so needs to be static_cast if using as int
// stringName.length() <- method in Python, Member function in C++
// std::ssize(stringName) <- signed integral but expensive to copy


// INPUT STRINGS
//#include <string>
//
//int main()
//{
//	std::string name{};
//
//	std::cout << "Enter name: ";
//
//	// getline() able to take input with whitespace - otherwise it gets stuck in cin
//	std::getline(std::cin >> std::ws, name); 
//	// std::ws needed for proper function
//
//	std::cout << name;
//	return 0;
//}

// LITERAL SUFFIXES
// 6f = float
// 6s = string
// Recommend using namespace std::string_literals - for below
// "6"s - changes C string to std::string literal
// 6L = long
// 6u = unsigned int
// 5.1f = changes double to float since double is default
// * float x { 5.1 } will not work type of variable and literal dont match
// float x { 5.1f } is the correct way - doubles can also be in scientific notation
// C string = 'h' 'e' 'l' 'l' 'o' '\0' <- invisible null terminator NOT IN std::string
// Avoid magic numbers. Try to define or comment what each number in code means

// CONSTANTS - optimization option
// const int x {5}; - MUST be initialized (defined)
// constexpr int { sumOfSomething }; - defined as compile-time constant, else error
// expressions such as 3 + 4 will generally run at compile-time - optimization

// STATIC CAST EXERCISE
//int main()
//{
//	std::cout << "Enter a single character: ";
//	char mych{};
//	std::cin >> mych;
//
//	std::cout << "You entered '" << mych << "', which has ASCC code "
//		<< static_cast<int>(mych);
//
//	return 0;
//}

// STATIC CAST - compiler will not error this way
//void print(int x)
//{
//	std::cout << x << '\n';
//}
//
//int main()
//{
//	print(static_cast<int>(5.5)); //explicitly convert double value 5.5 to an int
//	return 0;
//}

// CHAR
// char ch{'a'}

// OR OPERATOR
//bool isPrime(int num)
//{
//	if (num == 2 || num == 3 || num == 5 || num == 7)
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	std::cout << "Enter a number 0 through 9: ";
//	int x{};
//	std::cin >> x;
//	if (isPrime(x))
//		std::cout << "This number is prime.\n";
//	else
//		std::cout << "This number is not prime.\n";
//	return 0;
//}

// IF STATEMENT
//int main() {
//	std::cout << "Enter an integer: ";
//	int x{};
//	std::cin >> x;
//
//	if (x > 0)
//		std::cout << "The value is positive.\n";
//	else if (x < 0) // elif isnt a thing
//		std::cout << "The value is negative\n";
//	else
//		std::cout << "The value is zero.\n";
//	return 0;
//}

// EXERCISE
//#include "io.h"  
//
//int main()
//{
//	int num1 = readNumber();
//	std::cout << num1 << '\n';
//	int num2 = readNumber();
//	std::cout << num2 << '\n';
//
//
//	writeAnswer(num1 + num2);
//	return 0;
//}

//#include "square.h"  // header guards are preventing duplication of code
//#include "wave.h"	 // from other files only
//
//int main()
//{
//	return 0;
//}

//#include "add.h"  // add declaration from header file - note double quotes
//#include <iostream>  // best practice ordered this way
//// generally do not #include .cpp files - double quotes for in-project files
//
//int add(int x, int y);
//
//int main()
//{
//	std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
//	return 0;
//}

// CONDITIONAL COMPILATION USING MACROS - cannot transcend files
//
//#define PRINT_JOE
//
//int main()
//{
//#ifdef PRINT_JOE // ifndef is the opposite of ifdef
//	std::cout << "Joe\n";
//#endif
//
//#ifdef PRINT_BOB
//	std::cout << "Bob\n";
//#endif
//	return 0;
//}

// COMPILATION IGNORE - can change to #if 1 to reengage code
//
//int main()
//{
//	std::cout << "Joe\n";
//
//#if 0 // dont compile anything starting here
//	std::cout << "Bob\n";
//	std::cout << "Bob\n";
//#endif // until this point
//	return 0;
//}







