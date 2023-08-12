#include <iostream>  // angled brackets are external directories

// CHAPTER 7 PROGRAM 2
//
#include<cassert>
#include<cmath>

bool isPrime(int x)
{
    if (x <= 1)
        return false;

    int maxTest{ static_cast<int>(std::sqrt(x)) };

    for (int test{ maxTest }; test > 1; --test)
    {
        if (x % test == 0)
            return false;
    }

    return true;



    //MY ORIGINAL ANSWER
    //if (x <= 1)
    //    return false;
    //int success{};
    //for (int count{x}; count > 1; --count)
    //    if (x % count == 0)
    //    {
    //        std::cout << "Yep\n";
    //        ++success;
    //    }
    //if (success > 1)
    //{
    //    std::cout << x << " FALSE\n";
    //    return false;
    //}
    //else
    //{
    //    std::cout << x << " TRUE\n";
    //    return true;
    //}
}

int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

	return 0;
}






// CHAPTER 7 PROGRAM
//
//#include "constants.h"
//
//
//double calculateHeight(double initialHeight, int seconds)
//{
//
//	double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
//	double heightNow{ initialHeight - distanceFallen };
//
//	//Check whether we've gone under the ground
//	//If so, set the height to ground-level
//	if (heightNow < 0.0)
//		return 0.0;
//	else
//		return heightNow;
//}
//
//bool calculateAndPrintHeight(double initialHeight, int seconds)
//{
//	double currentHeight{ calculateHeight(initialHeight, seconds) };
//
//	std::cout << "At " << seconds << " seconds, the ball is at height: "
//		<< currentHeight << '\n';
//
//	return (currentHeight == 0.0);
//}
//
//int main()
//{
//	std::cout << "Enter the initial height of the tower in meters: ";
//	double initialHeight{};
//	std::cin >> initialHeight;
//
//	int seconds{};
//
//	//returns true if the ground was hit
//	while (!calculateAndPrintHeight(initialHeight, seconds))
//		++seconds;
//
//	
//	return 0;
//}

// RANDOM STUFF
// Use random device and only seed it once per program run

// EXAMPLE PROGRAM WITH ERROR CHECKING USER INPUT
//#include <limits>
//
//void ignoreLine()
//{
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//}
//
//double getDouble()
//{
//    while (true) // Loop until user enters a valid input
//    {
//        std::cout << "Enter a decimal number: ";
//        double x{};
//        std::cin >> x;
//
//        // Check for failed extraction
//        if (!std::cin) // if the previous extraction failed
//        {
//            if (std::cin.eof()) // if the stream was closed (Unix systems)
//            {
//                exit(0); // shut down the program now
//            }
//
//            // let's handle the failure
//            std::cin.clear(); // put us back in 'normal' operation mode
//            ignoreLine();     // and remove the bad input
//
//            std::cout << "Oops, that input is invalid.  Please try again.\n";
//        }
//        else
//        {
//            ignoreLine(); // remove any extraneous input
//            return x;
//        }
//    }
//}
//
//char getOperator()
//{
//    while (true) // Loop until user enters a valid input
//    {
//        std::cout << "Enter one of the following: +, -, *, or /: ";
//        char operation{};
//        std::cin >> operation;
//
//        if (!std::cin) // if the previous extraction failed
//        {
//            if (std::cin.eof()) // if the stream was closed
//            {
//                exit(0); // shut down the program now
//            }
//
//            // let's handle the failure
//            std::cin.clear(); // put us back in 'normal' operation mode
//        }
//
//        ignoreLine(); // remove any extraneous input
//
//        // Check whether the user entered meaningful input
//        switch (operation)
//        {
//        case '+':
//        case '-':
//        case '*':
//        case '/':
//            return operation; // return it to the caller
//        default: // otherwise tell the user what went wrong
//            std::cout << "Oops, that input is invalid.  Please try again.\n";
//        }
//    } // and try again
//}
//
//void printResult(double x, char operation, double y)
//{
//    switch (operation)
//    {
//    case '+':
//        std::cout << x << " + " << y << " is " << x + y << '\n';
//        break;
//    case '-':
//        std::cout << x << " - " << y << " is " << x - y << '\n';
//        break;
//    case '*':
//        std::cout << x << " * " << y << " is " << x * y << '\n';
//        break;
//    case '/':
//        std::cout << x << " / " << y << " is " << x / y << '\n';
//        break;
//    default: // Being robust means handling unexpected parameters as well, even though getOperator() guarantees operation is valid in this particular program
//        std::cout << "Something went wrong: printResult() got an invalid operator.\n";
//    }
//}
//
//int main()
//{
//    double x{ getDouble() };
//    char operation{ getOperator() };
//    double y{ getDouble() };
//
//    printResult(x, operation, y);
//
//    return 0;
//}

// CIN.IGNORE
// std::cin.ignore(100, '\n') // clear up to 100 chars or until linebreak
// or for no limit.. can put in its own function for readability
// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// 7.10.5 FIZZ BUZZ POP
//
//void fizzbuzz(int num)
//{
//	for (int count{ 1 }; count <= num; ++count)
//	{
//		bool word{ false };
//		if (count % 3 == 0)
//		{
//			std::cout << "fizz";
//			word = true;
//		}
//
//		if (count % 5 == 0)
//		{
//			std::cout << "buzz";
//			word = true;
//		}
//
//		if (count % 7 == 0)
//		{
//			std::cout << "pop";
//			word = true;
//		}
//
//		if (!word)
//		{
//			std::cout << count;
//		}
//
//		std::cout << '\n';
//	}
//}
//
//int main()
//{
//	fizzbuzz(150);
//	return 0;
//}

// 7.10.4 FIZZ BUZZ
//
//void fizzbuzz(int num)
//{
//	for (int count{ 1 }; count <= num; ++count)
//
//		if (count % 3 == 0 && count % 5 == 0)
//			std::cout << "fizzbuzz\n";
//
//		else if (count % 3 == 0)
//			std::cout << "fizz\n";
//
//		else if (count % 5 == 0)
//			std::cout << "buzz\n";
//
//		else
//			std::cout << count << '\n';
//}
//
//int main()
//{
//	fizzbuzz(15);
//	return 0;
//}

// 7.10.2 EXERCISE
//
//int sumTo(int value)
//{
//	int sum{};
//	for (int count{ value }; count > 0; --count)
//		sum += count;
//	return sum;
//}
//
//int main()
//{
//	std::cout << sumTo(5);
//	return 0;
//}

// 7.10.1 EXERCISE
//
//int main()
//{
//	for (int x{}; x <= 20; x += 2)
//		std::cout << x << '\n';
//	return 0;
//}

// FOR EXAMPLE WITH MORE THAN ONE VARIABLE
//
//int main()
//{
//    for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y)
//        std::cout << x << ' ' << y << '\n';
//
//    return 0;
//}

// FOR STATEMENTS - EXAMPLE
//
//int main()
//{
//	for (int count{ 1 }; count <= 10; ++count)
//		std::cout << count << ' ';
//
//	std::cout << "\nDone.";
//
//	return 0;
//}

// DO WHILE STATEMENTS - EXAMPLE - not generally recommended to use
//
//int main()
//{
//	int selection{};
//
//	do
//	{
//		std::cout << "Please make a selection: \n";
//		std::cout << "1) Addition\n";
//		std::cout << "2) Subtraction\n";
//		std::cout << "3) Multiplication\n";
//		std::cout << "4) Division\n";
//		std::cin >> selection;
//	} 
//	while (selection != 1 && selection != 2 && selection != 3 &&
//		selection != 4);
//
//	std::cout << "You selected option #" << selection << '\n';
//
//	return 0;
//

// 7 EXERCISE inner outer ish
//
//int main()
//{
//	int outer{1};
//
//	while (outer <= 5)
//	{
//		int inner{ 5 };
//
//		while (inner >= 1)
//		{
//			if (inner <= outer)
//				std::cout << inner << ' ';
//			else
//				std::cout << "  ";
//
//			--inner;
//		}
//
//		std::cout << '\n';
//
//		++outer;
//	}
//
//	return 0;
//}

// 7.8.2 EXERCISE
//
//int main()
//{
//	char ch{ 'a' };
//	while (ch <= 'z')
//	{  // supposed to static_cast I guess
//		std::cout << ch << " ASCII Code: " << static_cast<int>(ch) << '\n';
//		++ch;
//	}
//	return 0;
//}

// WHILE STATEMENTS
// while (count <= 10)  - loop variables should be signed to avoid overflow
//		{ std::cout << yada yada; }
// while (true)

// GOTO STATEMENTS - generally best to avoid using unless exiting a nest
// can jump forward or backward but cannot jump between functions

// EXERCISE 7.6 - switch case
//
//int calculate(int x, int y, char op)
//{
//	switch (op)
//	{
//		case '+':
//			return x + y;
//		case '-':
//			return x - y;
//		case '*':
//			return x * y;
//		case '/':
//			return x / y;
//		case '%':
//			return x % y;
//		default:
//			std::cout << "ERROR\n";
//			return 0;
//	}
//}
//
//int main()
//{  // not great, I would have liked catch the error before printing anything
//   // BUT this is the accepted answer
//	int num1{1};
//	int num2{2};
//	char op{'g'};
//	std::cout << num1 << ' ' << op << ' ' << num2 
//		<< " is " << calculate(num1, num2, op) << '\n';
//	return 0;
//}

// CHAPTER 6 QUESTION 3 WRITE FUNCTION
//
//int accumulate(int x)
//{  // this function is the answer - downfall is that it can't be reset
//	static int stickyNum{ 0 };
//	return stickyNum += x;;
//}
//
//
//int main()
//{
//	std::cout << accumulate(4) << '\n';	// print 4
//	std::cout << accumulate(3) << '\n';	// 7
//	std::cout << accumulate(2) << '\n';	// 9
//	std::cout << accumulate(1) << '\n'; // 10
//	return 0;
//}

// CHAPTER 6 QUESTION 2 CREATE HEADER FOR BELOW
//
//#include "constants.h"
//
//int main()
//{
//	std::cout << "How many students are in your class? ";
//	int students{};
//	std::cin >> students;
//	// check constants.h for answer
//
//	if (students > constants::max_class_size)
//		std::cout << "There are too many students in this class";
//	else
//		std::cout << "This class isn't too large";
//
//	return 0;
//}

// CHAPTER 6 QUESTION 1 FIX PROGRAM
//
//int main()
//{
//	std::cout << "Enter a positive number: ";
//	int num{};
//	std::cin >> num;
//
//
//	if (num < 0)
//	{  // just needed to insert a block here - ez
//		std::cout << "Negative number entered.  Making positive.\n";
//		num = -num;
//	}
//
//	std::cout << "You entered: " << num;
//
//	return 0;
//}

// EXERCISE 6.3.1
//
//int main()
//{
//	std::cout << "Enter an integer: ";
//	int smaller{};
//	std::cin >> smaller;
//
//	std::cout << "Enter a larger integer: ";
//	int larger{};
//	std::cin >> larger;
//	if (larger < smaller)
//	{
//		// std::swap(larger, smaller) // nice one liner instead of below
//		std::cout << "Swapping the values.\n";
//		int temp = { smaller };
//		smaller = larger;
//		larger = temp;
//	}
//	std::cout << "The smaller value is " << smaller << '\n';
//	std::cout << "The larger value is " << larger << '\n';
//	return 0;
//}

// USER DEFINE NAMESPACES
// Place to put user created functions
// Name it with capital letter to start: Foo
// std is a standard library. Call namespaces the same way Foo::doSomething()
// ::doSomething() blank operator accesses global namespace after checking local

// NESTING
// Keep nesting level to 3 or less in any program - consider breaking it up

// Exercise O.4
//
//int getNum()
//{
//	std::cout << "Enter a number between 0 and 255: ";
//	int num{};
//	std::cin >> num;
//
//	return num;
//}
//
//int numChecker(int x, int pow)
//{
//	if (x >= pow)
//	{
//		std::cout << 1;
//		return x - pow;
//	}
//	else
//	{
//		std::cout << 0;
//		return x;
//	}
//}
//
//int main()
//{
//	int input{ getNum() };
//	int output{};
//	output = numChecker(input, 128);
//	output = numChecker(output, 64);
//	output = numChecker(output, 32);
//	output = numChecker(output, 16);
//	output = numChecker(output, 8);
//	output = numChecker(output, 4);
//	output = numChecker(output, 2);
//	output = numChecker(output, 1);
//
//	return 0;
//}

// Exercise O.3
// 
//#include <bitset>
//#include <cstdint>
//int main()
//{
//    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
//    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
//    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
//    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
//    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };
//
//    std::uint8_t myArticleFlags{ option_favorited };
//
//    myArticleFlags |= option_viewed;
//
//    if (myArticleFlags & option_deleted)
//        std::cout << "Deleted\n";
//    else
//        std::cout << "Not Deleted\n";
//
//    myArticleFlags &= ~option_favorited;
//
//    std::cout << std::bitset<8>{ myArticleFlags } << '\n';
//
//    return 0;
//}

// BIT MASKS
// allow you to modify multiple bits in one statement

// Exercise 0.2.2
//
//#include <bitset>
//
//std::bitset<4> rotl(std::bitset<4> bits)
//{
//	const bool leftbit{ bits.test(3) };
//
//	bits <<= 1;
//
//	if (leftbit)
//		bits.set(0);
//
//	return bits;
//}
//
//
//int main()
//{
//	std::bitset<4> bits1{0b0001};
//	std::cout << rotl(bits1) << '\n';
//	
//	std::bitset<4> bits2{0b1001};
//	std::cout << rotl(bits2) << '\n';
//
//	return 0;
//}

// Exercise O.2.3 - no set or test allowed
// 
//#include <bitset>
//
//std::bitset<4> rotl(std::bitset<4> bits)
//{
//	return (bits << 1) | (bits >> 3);
//}
//
//
//int main()
//{
//	std::bitset<4> bits1{0b0001};
//	std::cout << rotl(bits1) << '\n';
//	
//	std::bitset<4> bits2{0b1001};
//	std::cout << rotl(bits2) << '\n';
//
//	return 0;
//} 

// BIT MANIPULATION
// .test()	query whether bit is 0 or 1
// .set()	turns a bit on from 0 to 1 but not 1 to 0
// .reset() turns a bit off from 1 to 0 but not 0 to 1
// .flip()  flip from 0 to 1 or 1 to 0


// BITWISE OPERATORS
// LEFT SHIFT <<  0110 << 1 is 1100
// RIGHT SHIFT >> 0110 >> 2 is 0001
// NOT ~ flips 0 to 1 or vice versa so 0110 to 1001
// AND &  0 1 1 1
//		  1 0 1 0 
//		 =0 0 1 0
// 
// OR |   0 1 1 0
//		  1 0 1 0 
//		 =1 1 1 0
//
// XOR ^ evaluates true if one and ONLY ONE of its operands is true
//		  0 1 1 0
//		  0 0 1 1
//	 	 =0 1 0 1





// OPERATOR '?'  - if else but can be placed inside initializers
//int main()
//{ // pretty cool but not useful for complex if else statements
//	constexpr bool inBigClassroom{ true };
//	constexpr int classSize{ inBigClassroom ? 30 : 20 };
//	std::cout << "The class size is: " << classSize << '\n';
//	return 0;
//}

// INCREMENT AND DECREMENT - does permanently effect variables
// Not recommended to use directly in passing function parameters or in expressions
// ++x - increment by 1
// --x - decrement by 1
// x++ - evaluate copy of num first then increment
// x-- - evaluate copy of num first then decrement

// 5.3 EXERCISE
//
//int getNum()
//{
//	std::cout << "Enter an integer: ";
//	int x{};
//	std::cin >> x;
//	return x;
//}
//
//bool isEven(int num)
//{
//	// HYPER CHAD CODE
//	return (num % 2) == 0;
//
//	// MY LAME CODE
//	//if (num % 2 == 0)
//	//	return true;
//	//else
//	//	return false;
//}
//
//void print(int num, bool even)
//{
//	if (even)
//		std::cout << num << " is even\n";
//	else
//		std::cout << num << " is odd\n";
//}
//
//int main()
//{
//	int x{ getNum() };
//	bool even{ isEven(x) };
//	print(x, even);
//	return 0;
//}

// Chapter 4 program 2
//
// FUNCTIONS DO 1 THING ONLY
//double getTowerHeight()
//{
//	std::cout << "Enter the height of the tower in meters: ";
//	double towerHeight{};
//	std::cin >> towerHeight;
//	return towerHeight;
//}
//
//double calculateHeight(const double height, int seconds) 
//{
//	constexpr double gravity{ 9.8 };
//	const double newHeight{ height - gravity * (seconds * seconds) / 2 };
//	return newHeight;
//}
//
//void printHeight(const double height, int seconds)
//{
//	if (height > 0)
//		std::cout << "At " << seconds << 
//		" seconds, the ball is at height : " << height << " meters\n";
//	else
//		std::cout << "At " << seconds << 
//		" seconds, the ball is on the ground.\n";
//}
//
//void calculateAndPrintHeight(const double towerHeight, int seconds)
//{  // DOESNT DO ONE THING?? My solution made more sense?
//	const double newHeight{ calculateHeight(towerHeight, seconds) };
//	printHeight(newHeight, seconds);
//
//}
//
//int main()
//{
//	const double towerHeight{ getTowerHeight() };
//
//	calculateAndPrintHeight(towerHeight, 0);
//	calculateAndPrintHeight(towerHeight, 1);
//	calculateAndPrintHeight(towerHeight, 2);
//	calculateAndPrintHeight(towerHeight, 3);
//	calculateAndPrintHeight(towerHeight, 4);
//	calculateAndPrintHeight(towerHeight, 5);
//
//	return 0;
//}

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
// expressions such as 3 + 4 will generally run at compile-time - optimization - IF USING CONSTEXPR VARIABLES

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







