#include <iostream>  // angled brackets are external directories




// CONSTANTS
// const int x {5}; - MUST be initialized (defined)
// constexpr int { sumOfSomething }; - defined as compile-time constant, else error

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







