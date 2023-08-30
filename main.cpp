#include <iostream>  // angled brackets are external directories


// 12.8.3
//
#include <vector>
#include <array>

using Numbers = std::vector<int>;

int getStart()
{
	std::cout << "Start where? ";
	int start{};
	std::cin >> start;
	return start;
}

int getLength()
{
	std::cout << "How many? ";
	int nums{};
	std::cin >> nums;
	return nums;
}

int main()
{
	int start{getStart()};
	int nums{getLength()};
	int multiple{2};

	std::cout << "I generated " << nums << " square numbers. Do you know what "
		"each number is after multiplying it by " << multiple << "?\n";

	Numbers v(static_cast<Numbers::size_type>(nums));
	//arr.resize(std::size_t(nums));

	for (int& number : v) // need ampersand otherwise you GET A COPY!!
	{
		number = ((start * start) * multiple);
		++start;
	}

	for (int num : v)
		std::cout << num << ' ';

	return 0;
}

// 12.7.2
//
//#include <algorithm>
//#include <array>
//#include <iostream>
//#include <string_view>
//
//struct Season
//{
//	std::string_view name{};
//	double averageTemperature{};
//};
//
//int main()
//{
//	std::array<Season, 4> seasons{
//		{ {"Spring", 285.0},
//		{  "Summer", 296.0},
//		{  "Fall",   288.0},
//		{  "Winter", 263.0}  }
//	};
//
//	std::sort(seasons.begin(), seasons.end(), 
//		[](const auto& a, const auto& b)
//		{
//			return a.averageTemperature < b.averageTemperature;
//		});
//
//	for (const auto& season : seasons)
//	{
//		std::cout << season.name << '\n';
//	}
//	
//	return 0;
//}

// 12.7.1
//
//#include <array>
//struct Student
//{
//    std::string name{};
//    int score{};
//};
//
//int main()
//{
//    std::array<Student, 8> arr{
//  { { "Albert", 3 },
//    { "Ben", 5 },
//    { "Christine", 2 },
//    { "Dan", 8 }, // Dan has the most points (8).
//    { "Enchilada", 4 },
//    { "Francis", 1 },
//    { "Greg", 3 },
//    { "Hagrid", 5 } }
//    };
//
//    const auto best{
//        std::max_element(arr.begin(), arr.end(), [](Student a, Student b)
//            {
//                return a.score < b.score;
//})
//    };
//
//    std::cout << best->name << " is the best student\n";
//
//	return 0;
//}

// LAMBDAS
// 
// Preferred when we need a trivial, one-off function to pass as an arguement to another function
// [](std::string_view str) <- no capture clause, param is str
// {
//	 return (str.find("nut") != std::string_view::npos) };
//
// Storing a lambda inside a named variable - makes code more readable
// auto isEven{
//		[](int i)
//		{
//			return ((i % 2) == 0);
//		}
//	};
// USING IT -> std::all_of(array.begin(), array.end(), isEven);
//
// CAPTURE CLAUSE - used to define variables that are needed within lambda 
// Creates a copy of the variable but cannot modify it normally
// 
// Using mutable keyword you can modify it but it only modifies the copy - try to avoid
// Capture by reference like this &ammo, &health to modify the variable normally
// Using [=] will capture all variables used in lambda by value
// Using [&] will capture all by reference
// 
// [userArea{ width * height }] creates a userArea variable specifically for 
// the lambda using height and width variables from other scope


// 12.4.3a
//
//void convert(int num)
//{
//
//	if (num == 0)
//		return;
//
//	convert(num / 2);
//
//	std::cout << num % 2;
//}
//
//int main()
//{
//	convert(-15);
//	return 0;
//}

// 12.4.2
//
//int sumOf(int num)
//{
//	if (num < 10)
//		return num;
//	return sumOf(static_cast<int>(num / 10)) + num % 10;
//}
//
//int main()
//{
//	std::cout << sumOf(357);
//	return 0;
//}

// 12.4.1
//
//int multitude(int num)
//{
//	if (num <= 0)
//		return 1;
//
//	return multitude(num - 1) * num;
//}
//
//int main()
//{
//	std::cout << multitude(4);
//	return 0;
//}

// VECTOR CAPACITY AND STACK BEHAVIOR
//
// A vector's capacity cannot be changed using at() or initializing an index
// such as vectorName[5] = 10
//
// Can use stack like functions to resize like push_back(), back(), and pop_back()
// Resizing this way may reserve more than one slot per push back
// 
// Resizing is still expensive though so we can use reserve() to allocate capacity

//11.x.6
//
//#include <array>
//#include <random>
//#include <cassert>
//#include <vector>
//
//enum CardRank
//{
//	rank_2,
//	rank_3,
//	rank_4,
//	rank_5,
//	rank_6,
//	rank_7,
//	rank_8,
//	rank_9,
//	rank_10,
//	rank_jack,
//	rank_queen,
//	rank_king,
//	rank_ace,
//
//	max_ranks
//};
//
//enum CardSuit
//{
//	clubs,
//	diamonds,
//	hearts,
//	spades,
//
//	max_suits
//};
//
//struct Card
//{
//	CardRank rank{};
//	CardSuit suit{};
//};
//
//using Deck = std::array<Card, 52>;
//using Index = Deck::size_type;
//using Hand = std::vector<Card>;
//
//void printCard(const Card& card)
//{
//	switch (card.rank)
//	{
//	case CardRank::rank_2:		std::cout << "2"; break;
//	case CardRank::rank_3:		std::cout << "3"; break;
//	case CardRank::rank_4:		std::cout << "4"; break;
//	case CardRank::rank_5:		std::cout << "5"; break;
//	case CardRank::rank_6:		std::cout << "6"; break;
//	case CardRank::rank_7:		std::cout << "7"; break;
//	case CardRank::rank_8:		std::cout << "8"; break;
//	case CardRank::rank_9:		std::cout << "9"; break;
//	case CardRank::rank_10:		std::cout << "T"; break;
//	case CardRank::rank_jack:	std::cout << "J"; break;
//	case CardRank::rank_queen:	std::cout << "Q"; break;
//	case CardRank::rank_king:	std::cout << "K"; break;
//	case CardRank::rank_ace:	std::cout << "A"; break;
//	default: std::cout << '?'; break;
//	}
//
//	switch (card.suit)
//	{
//	case CardSuit::clubs:		std::cout << "C"; break;
//	case CardSuit::diamonds:	std::cout << "D"; break;
//	case CardSuit::hearts:		std::cout << "H"; break;
//	case CardSuit::spades:		std::cout << "S"; break;
//	default: std::cout << '?'; break;
//	}
//	std::cout << ' ';
//}
//
//std::array<Card, 52> createDeck()
//{
//	std::array<Card, 52> deck{};
//
//	Index index{ 0 };
//	for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
//	{
//		for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
//		{
//			deck[index].suit = static_cast<CardSuit>(suit);
//			deck[index].rank = static_cast<CardRank>(rank);
//			++index;
//			//std::cout << static_cast<CardSuit>(suit) << static_cast<CardRank>(rank) << '\n';
//		}
//
//	}
//	return deck;
//}
//
//void printDeck(const Deck& deck)
//{
//	for (Card card : deck)
//	{
//		printCard(card);
//	}
//	std::cout << '\n';
//}
//
//Deck shuffleDeck(Deck& deck)
//{
//	std::random_device rd;
//	std::mt19937 mt(rd());
//	std::shuffle(deck.begin(), deck.end(), mt);
//	return deck;
//}
//
//int getCardValue(Card& card)
//{
//	switch (card.rank)
//	{
//	case (0): return 2; break;
//	case (1): return 3; break;
//	case (2): return 4; break;
//	case (3): return 5; break;
//	case (4): return 6; break;
//	case (5): return 7; break;
//	case (6): return 8; break;
//	case (7): return 9; break;
//	case (8): return 10; break;
//	case (9): return 10; break;
//	case (10): return 10; break;
//	case (11): return 10; break;
//	case (12): return 11; break;
//	default:
//		assert(false && "Should never happen");
//		return 0;
//	}
//}
//
//bool playBlackjack(Deck& deck)
//{
//	//DEAL CARDS
//	int dealerSum{};
//	int playerSum{};
//	Index deckIndex{ 0 };
//
//	dealerSum = getCardValue(deck[deckIndex]);
//	++deckIndex;
//	dealerSum += getCardValue(deck[deckIndex]);
//	++deckIndex;
//
//	playerSum = getCardValue(deck[deckIndex]);
//	++deckIndex;
//	playerSum += getCardValue(deck[deckIndex]);
//	++deckIndex;
//
//	std::cout << "Dealer's score: " << dealerSum << '\n';
//	std::cout << "Your score: " << playerSum << '\n';
//	
//	int game_over{false};
//
//	if (dealerSum > 21 || playerSum > 21)
//		game_over = true;
//
//	// PLAYERS TURN
//	while (!game_over && playerSum < 21)
//	{
//		std::cout << "Would the player like to 'hit' or 'stand'? ";
//		std::string choice{};
//		std::cin >> choice;
//		if (choice == "hit")
//		{
//			playerSum += getCardValue(deck[deckIndex]);
//			++deckIndex;
//			std::cout << "Your score: " << playerSum << '\n';
//			if (playerSum > 21)
//			{
//				game_over = true;
//				break;
//			}
//		}
//		else
//		{
//			std::cout << "You stand.\n";
//			break;
//		}
//	}
//
//	// DEALERS TURN
//	while (dealerSum < 17 && !game_over)
//	{
//		std::cout << "Dealer hits.\n";
//		dealerSum += getCardValue(deck[deckIndex]);
//		++deckIndex;
//		std::cout << "Dealer's score: " << dealerSum << '\n';
//	}
//
//	// DECIDE THE GAME
//	if (dealerSum > 21)
//	{
//		std::cout << "DEALER BUSTS. YOU WIN!\n";
//	}
//	else if (playerSum > dealerSum && playerSum <= 21)
//		std::cout << "YOU WIN!\n";
//	else
//		std::cout << "YOU LOSE.\n";
//	
//	return true;
//}
//
//int main()
//{
//	Deck myDeck{createDeck()};
//	printDeck(myDeck);
//	Deck shuffledDeck = shuffleDeck(myDeck);
//	printDeck(shuffledDeck);
//	//std::cout << shuffledDeck.size();
//	playBlackjack(shuffledDeck);
//
//	return 0;
//}

// 11.x.5.b
//
//int main()
//{
//	int x{ 5 };
//	int y{ 7 };
//
//	int* ptr{ &x };
//	std::cout << *ptr << '\n';
//	*ptr = 6;
//	std::cout << *ptr << '\n';
//	ptr = &y;
//	std::cout << *ptr << '\n';
//
//	return 0;
//}

//11.x.5.a
//
//int main()
//{
//	int array[]{ 0, 1, 2, 3 };
//
//	for (std::size_t count {0}; count < std::size(array); ++count)
//	{
//		std::cout << array[count] << ' ';
//	}
//
//	std::cout << '\n';
//
//	return 0;
//}

//11.x.4
//
//#include <string_view>
//
//void printString(const char* string)
//{
//	while (static_cast<int>(*string) != 0)
//	{
//		std::cout << *string;
//		++string;
//	}
//}
//
//int main()
//{
//	printString("Hello World!");
//
//	return 0;
//}

//11.x.3
//
//void swapNums(int& x, int& y)
//{
//	int holDis{ x };
//	x = y;
//	y = holDis;
//}
//
//int main()
//{
//	int x{ 2 };
//	int y{ 3 };
//
//	swapNums(x, y);
//
//	std::cout << "Variable x: " << x << "   Variable y: " << y;
//
//	return 0;
//}

// 11.x.2
//
//#include <vector>
//#include <string_view>
//#include <string>
//#include <cstddef>  //size_t
//#include <algorithm> // sort
//
//struct Student
//{
//	std::string name{};
//	int grade{};
//};
//
//int getClassSize()
//{
//	int classSize{};
//	do
//	{
//		std::cout << "How many students do you want to enter? ";
//		std::cin >> classSize;
//	} while (classSize <= 0);
//
//	return classSize;
//}
//
//std::vector<Student> createStudentList()
//{
//	using Students = std::vector<Student>;
//	Students students(static_cast<Students::size_type> (getClassSize()));
//
//	for (Student& i : students)
//	{
//		std::cout << "Enter student's name: ";
//		std::cin >> i.name;
//
//		std::cout << "Enter " << i.name << "'s grade: ";
//		std::cin >> i.grade;
//	}
//
//	return students;
//}
//
//bool sortStudents(Student& a, Student& b)
//{
//	return (a.grade > b.grade);
//}
//
//int main()
//{
//	std::vector<Student> student_list = { createStudentList() };
//
//
//	std::sort(student_list.begin(), student_list.end(), sortStudents);
//
//	std::cout << "After sort:\n";
//	for (Student k : student_list)  // FOR LATER
//	{
//		std::cout << k.name << " got a grade of " << k.grade << '\n';
//	}
//
//	return 0;
//}

// 11.x.1
// 
//#include <array>
//#include <numeric>
//
//enum ItemTypes
//{
//	health_potions = 0,
//	torches,
//	arrows,
//	max_items,
//};
//
//using Inventory = std::array<int, ItemTypes::max_items>;
//
//int countTotalItems(const Inventory& items)
//{
//	return std::reduce(items.begin(), items.end());
//}
//
//int main()
//{
//	Inventory items {2, 5, 10};
//
//	std::cout << "Total number of items: " << countTotalItems(items) << '\n';
//	std::cout << "Number of torches: " << items[ItemTypes::torches] << '\n';
//
//	return 0;
//}

//STD::REDUCE - gives sum of all elements in no particular order
//STD::ACCUMLATE - same as reduce but left to right - use if reduce isnt supported
//STD::SHUFFLE - takes list and randomly re-orders elements
//#include <algorithm> // shuffle
//#include <array>
//#include <chrono>
//#include <numeric> // reduce
//#include <random>
//
//int main()
//{
//	std::array arr{1, 2, 3, 4};
//
//	std::cout << std::reduce(arr.begin(), arr.end()) << '\n'; //10 - supported
//
//	// The 0 is the initial value
//	std::cout << std::accumulate(arr.begin(), arr.end(), 0) << '\n'; //10
//
//	// way over my head
//	std::mt19937 mt {static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())};
//	std::shuffle(arr.begin(), arr.end(), mt);
//
//	for (int i : arr)
//	{
//		std::cout << i << ' ';
//	}
//
//	std::cout << '\n';
//
//	return 0;
//}

//STD::FOR_EACH - do something to all elements of a container
//
//#include <algorithm>
//#include <array>
//
//void doubleNumber(int& i)
//{
//	i *= 2;
//}
//
//int main()
//{
//	std::array arr{1, 2, 3, 4};
//
//	// can use for_each(STD::NEXT(arr.begin(), arr.end(), doubleNumber);
//	// to start with the second element
//	std::for_each(arr.begin(), arr.end(), doubleNumber);
//
//	for (int i : arr)
//	{
//		std::cout << i << ' ';
//	}
//
//	std::cout << '\n';
//
//	return 0;
//}

//STD::SORT - custom sort with function POINTER no parentheses ()
//
//#include <algorithm>
//#include <array>
//
//bool greater(int a, int b)
//{
//	// Order @a before @b if @a is greater than @b.
//	return (a > b);
//}
//
// there is actually a std::greater{} call for this function
//int main()
//{
//	std::array arr{13, 90, 99, 5, 40, 80};
//
//	//Pass greater to std::sort
//	std::sort(arr.begin(), arr.end(), greater);
//
//	for (int i : arr)
//	{
//		std::cout << i << ' ';
//	}
//
//	std::cout << '\n';
//	return 0;
//}

//STD::COUNT / STD::COUNT_IF - search for all occurrences of an element or an element fulfilling a condition
//
//#include <array>
//#include <algorithm>
//#include <string_view>
//
//bool containsNut(std::string_view str)
//{
//	return (str.find("nut") != std::string_view::npos);
//}
//
//int main()
//{
//	std::array<std::string_view, 5> arr {"apple", "banana", "walnut", "lemon", "peanut"};
//
//	auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut) };
//
//	std::cout << "Counted " << nuts << " nut(s)\n";
//
//	return 0;
//}

// STD::FIND_IF - params: begin, end, function pointer "containsNut"
//
//#include <array>
//#include <string_view>
//#include <algorithm>
//
//// Our function will return true if the element matches
//bool containsNut(std::string_view str)
//{
//	// std::string_view::find returns std::string_view::npos if it doesn't find
//	// the substring. Otherwise it return the index where the substring occurs
//	// in str.
//	return (str.find("nut") != std::string_view::npos);
//}
//
//int main()
//{
//	std::array<std::string_view, 4> arr{"apple", "banana", "lemon", "walnut"};
//
//	// Scan our array to see if any elements contain the "nut" substring
//	auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };
//
//	if (found == arr.end())  // works cause end gives one index AFTER the last
//	{
//		std::cout << "No nuts\n";
//	}
//	else
//	{
//		std::cout << "Found " << *found << '\n';
//	}
//}

// STD::FIND - searches for first occurrence of a value in a container
// 
//#include <algorithm>
//#include <array>
//
//int main()
//{
//	std::array arr { 13, 90, 99, 5, 40, 80};
//
//	std::cout << "Enter a value to search for and replace with: ";
//	int search{};
//	int replace{};
//	std::cin >> search >> replace;
//
//	// std::find returns an iterator pointing to the found element (or the end of the container)
//	// we'll store it in a variable, using type inference to deduce the type of
//	// the iterator (since we don't care)
//	auto found{ std::find(arr.begin(), arr.end(), search) };
//
//	//Algorithms that don't find what they were looking for return the end iterator.
//	//We can acciess it by using the end() member function
//	if (found == arr.end())
//	{
//		std::cout << "Could not find " << search << '\n';
//	}
//	else
//	{
//		// Override the found element.
//		*found = replace;
//	}
//
//	for (int i : arr)
//	{
//		std::cout << i << ' ';
//	}
//
//	std::cout << '\n';
//
//	return 0;
//}

// ERASE() - iterator is revalidated below "it" = next element after erasure
//#include <vector>
//
//int main()
//{
//	std::vector v{ 1, 2, 3, 4, 5, 6, 7 };
//
//	auto it{ v.begin() };
//
//	++it; // move to second element
//	std::cout << *it << '\n';
//
//	it = v.erase(it); // erase the element currently being iterated over, set `it` to next element
//
//	std::cout << *it << '\n'; // now ok, prints 3
//
//
//	return 0;
//}

//STD::VECTOR - can handle its own memory management
//
//#include <vector>
//
////no need to specify length at the declaration
//std::vector<int> v {};
//std::vector<int> v2 = { 9, 7, 5, 3, 1 }; // use init list to init vector
//std::vector<int> v3 {9, 7, 5, 3, 1}; //uniform init
//
//// as with std::array, the type can be omitted
//std::vector v4 {9, 7, 5, 3, 1}; //deduced to std::vector<int>
//// when a vector goes out of scope there will be no memory leak
//// vectors do not decay in functions
//
//int main()
//{
//	std::vector v {0, 1, 2};
//	//RESIZING VECTORS is easy but expensive
//	v.resize(5); // set size to 5 (rest will be 0s)
//	std::vector<int> v(5); // init with size 5
//	std::vector<int> d(3, 4); // size 3 with values 4, 4, and 4
//	return 0;
//}
// returning an array from a func is expensive but not if using vector instead


//STD::ARRAY
//
// std::array<int, 3> myArray {3 shits here}; //length 3 and does not decay and not dynamic
// std::array myArray {shit here}; //deducted length and type
// myArray[1] = 3; //normal index - other indexing below
// myArray.at(9) = 10; //if length is less than 9 - runtime error
// myArray.size(); // get length - works in functions since no decay
// Pass arrays by reference to avoid expensive copies
// Array param type must have format <int, 3> for type and length
// Get around this by using templates (example):
//
//#include <array>
//
//template <typename T, std::size_t size> // parameterize type and size
//void printArray(const std::array<T, size>& myArray)
//{
//	for (auto element : myArray)
//		std::cout << element << ' ';
//	std::cout << '\n';
//}
//
//int main()
//{
//	std::array myArray5{9.0, 7.2, 5.4, 3.6, 1.8};
//	printArray(myArray5);
//
//	std::array myArray7{9.0, 7.2, 5.4, 3.6, 1.8, 0.7};
//	printArray(myArray7);
//
//	return 0;
//}

// VOID POINTER - avoid using if possible
//
// void pointers can be assigned to any type but cannot be dereferenced without
// fixing the type

// 11.12.1
//
//#include <sstream>
//#include <string_view>
//
//int main()
//{
//	std::string_view names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred",
//	"Greg", "Holly"};
//
//	std::cout << "Enter a name: ";
//	std::string name{};
//	std::getline(std::cin, name);
//
//	bool found{ false };
//	for (const auto& element : names)
//	{
//		if (name == element)
//		{
//			std::cout << name << " was found.";
//			found = true;
//			break;
//		}
//	}
//
//	if (!found)
//		std::cout << name << " was not found.";
//
//	return 0;
//}

// FOR-EACH LOOP - ranged based loop to iterate through every element in a list (or other)
//
//for (auto num : array); // best to use auto probably
//for (auto& string : array) // for string elements use reference
//wont work with pointers cause pointers dont know the length
//for (int i{}; auto num : array) // i is for index tracking

// 11.11.1
//
//#include <string>
//#include <sstream>
//#include <algorithm>
//#include <string_view>
//
//int main()
//{
//	std::size_t length{};
//	std::cout << "How many names do you wish to enter: ";
//	std::cin >> length;
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//	auto* array{ new std::string[length]{} };
//
//	for (int count{ 0 }; count < length; ++count)
//	{
//		std::string name;
//		std::cout << "Enter name #" << count + 1 << ": ";
//		std::getline(std::cin, name);
//
//		array[count] = name;
//		std::cout << array[count] << '\n';
//
//	}
//	for (int count{}; count < length; ++count)
//		std::cout << array[count] << " ";
//
//	std::cout << '\n';
//	std::sort(array, array + length);
//
//	for (int count{}; count < length; ++count)
//		std::cout << array[count] << " ";
//
//	return 0;
//}

// DYNAMIC ARRAY ALLOCATION
//
// Example:
//#include <cstddef>
//
//int main()
//{
//	std::cout << "Enter a position integer: ";
//	std::size_t length{};
//	std::cin >> length;
//
//	int* array{ new int[length] {} }; // use array new. Note that length does not need to be constant!
//									  // implicitly allocates array. For explicit allocation use new[]
//	std::cout << "I just allocated an array of integers of length " << length << '\n';
//
//	array[0] = 5; //set element 0 to value 5
//
//	delete[] array; // use array delete to deallocate array
//
//	return 0;
//}
// int* array{ new int[5]{ 9, 7, 5, 3, 1 } }; //list initialize dynamic array
// auto* array{ new int[5]{ 9, 7, 5, 3, 1 } }; // useful for longer type names
// to resize an array use std::vector - learned later

// DYNAMIC MEMORY ALLOCATION - single values
//
// new int; // dynamically allocate an interger( and discard the result )
// 'new' in this case creates assigns integer worth of memory, creates an object, and returns the address of that memory
// int* ptr{ new int}; //dynamically allocate an integer and assign the address to ptr so we can access it later
// *ptr = 7; // assign value of 7 to allocated memory
//
// int* ptr1{ new int (5) }; // use direct initialization - parenthesis
// int* ptr2{ new int { 6 } }; // use uniform initialization - curly bracket
// delete ptr1; // return the memory pointed to by ptr to the OS
// ptr2 = nullptr; // set ptr to be a null pointer
//
// Avoid having multiple pointers point at the same piece of memory if possible
// When a pointer is deleted, if the pointer is not going out of scope immediately after,
// set the pointer to a nullptr.
//
// To handle cases where not enough memory:
// int* value { new (std::nothrow) int }; // value will be nullptr if allocation fails
// if (!value) // handle case where new return null
//		handle exception here
//
// Memory leaks occur when a pointer goes out of scope before deleting the allocation
// - Can also happen when reassigning the pointer

// 11.8.2
//
//#include <iterator>
//
//int* findValue(int* beginning, int* end, int value)
//{
//    int* iterator{beginning};
//    while (iterator != end)
//    {
//        if (*iterator == value)
//            return iterator;
//
//        ++iterator;
//    }
//
//    return end;
//}
//
//int main()
//{
//    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };
//
//    // Search for the first element with value 20.
//    int* found{ findValue(std::begin(arr), std::end(arr), 20) };
//
//    // If an element with value 20 was found, print it.
//    if (found != std::end(arr))
//    {
//        std::cout << *found << '\n';
//    }
//
//    return 0;
//}

// ARRAY DECAY
//
// Arrays decay into a pointer when passed to functions
// Arrays do not decay in structs or classes passed to functions
// Arrays passed by reference do not decay

// 11.4.4
// 
//#include <iterator>
//#include <utility>
//
//int main()
//{
//	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
//
//	int length{ static_cast<int>(std::size(array)) };
//	for (int iteration{}; iteration < length-1; ++iteration)
//	{
//		bool swapOccured = false;
//		int stopHere{length - iteration};
//		for (int i{}; i < stopHere-1; ++i)
//		{
//			int nextIndex{ i + 1 };
//			if (array[i] > array[nextIndex])
//			{
//				std::swap(array[i], array[i + 1]);
//				swapOccured = true;
//			}
//		}
//		std::cout << "Iteration: " << iteration << '\n';
//		if (!swapOccured)
//		{
//			std::cout << "Early termination on iteration " << iteration + 1 << '\n';
//			break;
//		}
//	}
//	// print array
//	for (int element{}; element < std::size(array); ++element)
//	{
//		std::cout << array[element] << ' ';
//	}
//	return 0;
//}

// 11.4.3
//
//#include <iterator>
//#include <utility>
//int main()
//{
//	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
//
//	for (int element{}; element < (std::size(array) - 1); ++element)
//	{
//		for (int h{}; h < (std::size(array) - 1); ++h)
//		{
//			int nextIndex{ h + 1 };
//			if (array[h] > array[nextIndex])
//			{
//				std::swap(array[h], array[h + 1]);
//			}
//		}
//		for (int i{}; i < std::size(array); ++i)
//		{
//			std::cout << array[i] << ' ';
//		}
//		std::cout << '\n';
//	}
//	// print array
//	for (int element{}; element < std::size(array); ++element)
//	{
//		std::cout << array[element] << ' ';
//	}
//	return 0;
//}

// 11.4.2
//
//#include <iterator>
//#include <utility>
//
//int main()
//{
//	int array[]{ 30, 50, 20, 10, 40 };
//	constexpr int length{ static_cast<int>(std::size(array)) };
//
//	// Step through each element of the array
//	// (except the last one, which will already be sorted by the time we get there)
//	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
//	{
//		// smallestIndex is the index of the smallest element we’ve encountered this iteration
//		// Start by assuming the smallest element is the first element of this iteration
//		int smallestIndex{ startIndex };
//
//		// Then look for a smaller element in the rest of the array
//		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
//		{
//			// If we've found an element that is smaller than our previously found smallest
//			if (array[currentIndex] > array[smallestIndex])
//				// then keep track of it
//				smallestIndex = currentIndex;
//		}
//
//		// smallestIndex is now the index of the smallest element in the remaining array
//                // swap our start element with our smallest element (this sorts it into the correct place)
//		std::swap(array[startIndex], array[smallestIndex]);
//	}
//
//	// Now that the whole array is sorted, print our sorted array as proof it works
//	for (int index{ 0 }; index < length; ++index)
//		std::cout << array[index] << ' ';
//
//	std::cout << '\n';
//
//	return 0;
//}

// 11.4.1
//
//30 60 20 50 40 10
//10 60 20 50 40 30
//10 20 60 50 40 30
//10 20 30 50 40 60
//10 20 30 40 50 60

// SORT ARRAY - the easy way
//
// #include <algorithm>
// std::sort(std::begin(array), std::end(array);

// SORT ARRAY - the manual way
//#include <iterator>
//#include <utility>
//
//int main()
//{
//	int array[]{ 30, 50, 20, 10, 40 };
//	constexpr int length{ static_cast<int>(std::size(array)) };
//
//	// Step through each element of the array
//	// (except the last one, which will already be sorted by the time we get there)
//	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
//	{
//		// smallestIndex is the index of the smallest element we’ve encountered this iteration
//		// Start by assuming the smallest element is the first element of this iteration
//		int smallestIndex{ startIndex };
//
//		// Then look for a smaller element in the rest of the array
//		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
//		{
//			// If we've found an element that is smaller than our previously found smallest
//			if (array[currentIndex] < array[smallestIndex])
//				// then keep track of it
//				smallestIndex = currentIndex;
//		}
//
//		// smallestIndex is now the index of the smallest element in the remaining array
//				// swap our start element with our smallest element (this sorts it into the correct place)
//		std::swap(array[startIndex], array[smallestIndex]);
//	}
//
//	// Now that the whole array is sorted, print our sorted array as proof it works
//	for (int index{ 0 }; index < length; ++index)
//		std::cout << array[index] << ' ';
//
//	std::cout << '\n';
//
//	return 0;
//}

// 11.3.4
//
//#include <string_view>
//#include <iterator> // for std::size
//
//int main()
//{
//	int divisors[]{3, 5, 7, 11, 13, 17, 19};
//	std::string_view words[]{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
//
//	static_assert(std::size(divisors) == std::size(words));
//
//	int numRange{ 150 };
//	for (int num{1}; num <= numRange; ++num)
//	{
//		int divIndex{ 0 };
//		bool isDiv{ false };
//
//		do
//		{
//			if (num % divisors[divIndex] == 0)
//			{
//				std::cout << words[divIndex];
//				isDiv = true;
//			}
//			++divIndex;
//		} while (divIndex < std::size(divisors));
//
//		if (!isDiv)
//			std::cout << num << '\n';
//		else
//			std::cout << '\n';
//	}
//
//	return 0;
//}

// 11.3.3
//
//#include <iterator> // for std::size
//
//int main()
//{
//	constexpr int scores[]{ 84, 92, 76, 81, 56 };
//
//	int maxScore{ 0 };
//	int maxScoreIndex{};
//
//	for (int student{ 0 }; student < static_cast<int>(std::size(scores)); ++student)
//	{
//		if (scores[student] > maxScore)
//		{
//			maxScore = scores[student];
//			maxScoreIndex = student;
//		}
//	}
//
//	std::cout << "The best score's index was " << scores[maxScoreIndex] << '\n';
//
//	return 0;
//}

// 11.3.2
//
//#include <iterator> // for std::size
//#include <limits> // for ignore extra input
//int getNumber()
//{
//
//	int num{};
//
//	do  // really need to get into do while loops
//	{
//		std::cout << "Enter a number between 1 and 9: ";
//
//
//		std::cin >> num;
//
//		if (std::cin.fail())
//			std::cin.clear();
//
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//	} while (num < 1 || num > 9);
//
//}
//
//int main()
//{
//	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
//	constexpr int arraySize{ static_cast<int>(std::size(array)) };
//
//	int chosenNum{getNumber()};
//	int indexNum{};
//	for (int element{ 0 }; element < arraySize; ++element)
//	{
//		if (array[element] == chosenNum)
//		{
//			indexNum = element;
//		}
//		std::cout << array[element] << ' ';
//	}
//
//	std::cout << '\n';
//	std::cout << "The number " << chosenNum << " has index " << indexNum;
//	std::cout << '\n';
//
//	return 0;
//}

// 11.3.1
//
//#include <iterator> // for std::size
//
//int main()
//{
//	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
//	constexpr int arraySize{ static_cast<int>(std::size(array)) };
//
//	for (int element{ 0 }; element < arraySize; ++element)
//	{
//		std::cout << array[element] << ' ';
//	}
//	
//	std::cout << '\n';
//
//	return 0;
//}

// FOR LOOP ARRAY
//
// Find best score example:
//#include <iterator> // for std::size
//
//int main()
//{
//	// score are 0 (worst) to 100 (best)
//	constexpr int scores[]{ 84, 92, 76, 81, 56 };
//	constexpr int numStudents{ static_cast<int>(std::size(scores)) };
//
//	int maxScore{0}; // keep track of our largest score
//	for (int student{ 0 }; student < numStudents; ++student)
//	{
//		if (scores[student] > maxScore)
//		{
//			maxScore = scores[student];
//		}
//	}
//
//	std::cout << "the best score was " << maxScore << '\n';
//
//	return 0;
//}

// 11.2.1
//#include <iterator> // for std::size
//namespace Animals
//{
//	enum Animals
//	{
//		chicken,
//		dog,
//		cat,
//		elephant,
//		duck,
//		snake,
//		numberOfAnimals,
//	};
//}
//int main()
//{
//	//double temp[365]{}; // compiler didnt like that
//
//	int legs[]{2, 4, 4, 4, 2, 0};
//	static_assert(std::size(legs) == Animals::numberOfAnimals);
//
//	std::cout << "An elephant has " << legs[Animals::elephant] << " legs.";
//
//	return 0;
//}


// FIND ARRAY LENGTH
//
// std::size(array) // does not work inside functions because array decays  into pointer

// PASSING ARRAYS TO FUNCTIONS
//
// void print(int array[]) // array is modifiable in this function
// void print(const int array[]) // fixes that problem
// When passing an array to a function it decays into a pointer
// That explains why an out of scope array can be changed in a function

// FIXED ARRAYS - fixed as in length not fixed elements
//
// int numberOfDaysPerWeek[7]{}; // example of array with length 7 
// These are fixed and cannot be changed
// Cannot be defined with input or other run time variables
// int prime[5]{2, 3, 5, 7, 11}; // init list with 5 elements
// int prime[]{2, 3, 5}; // omitted length so it can be changed
//
// Example avoiding magic index numbers:
//enum StudentNames
//{
//	kenny,		 // 0
//	kyle,		 // 1
//	stan,		 // 2
//	butter,		 // 3
//	cartman,	 // 4
//	wendy,		 // 5 
//	max_students // 6
//};
//
//int main()
//{
//	int testScores[max_students]{}; //allocate 6 integers
//	testScores[stan] = 76;
//
//	return 0;
//}

// 10.x.3
//
//template <typename T>
//struct Triad
//{
//	T x{};
//	T y{};
//	T z{};
//};
//
//template <typename T>
//Triad(T, T, T) -> Triad<T>;
//
//template <typename T>
//void print(Triad<T> nums)
//{
//	std::cout << '[' << nums.x << ", " << nums.y << ", " << nums.z << ']';
//}
//
//int main()
//{
//	Triad t1{ 1, 2, 3 };
//	print(t1);
//
//	Triad t2{ 1.2, 3.4, 5.6 };
//	print(t2);
//
//	return 0;
//}

// 10.x.1
//
//#include <string_view>
//enum class MonsterType
//{
//	ogre,
//	dragon,
//	orc,
//	giant_spider,
//	slime,
//};
//
//struct Monster
//{
//	std::string_view name{};
//	int health{};
//	MonsterType type{};
//};
//
//std::string_view getMonsterType(MonsterType type)
//{
//	switch (type)
//	{
//	case MonsterType::ogre:			return "Ogre";
//	case MonsterType::dragon:		return "Dragon";
//	case MonsterType::orc:			return "Orc";
//	case MonsterType::giant_spider: return "Giant Spider";
//	case MonsterType::slime:		return "Slime";
//	default:						return "???";
//	}
//}
//
//void printMonster(Monster monster)
//{
//	std::cout << "This " << getMonsterType(monster.type) << " is named "
//		<< monster.name << " and has " << monster.health << " health.\n";
//}
//
//int main()
//{
//	Monster m1{ "Torg", 145, MonsterType::ogre };
//	Monster m2{ "Slurp", 23, MonsterType::slime };
//	printMonster(m1);
//	printMonster(m2);
//	return 0;
//}

// TEMPLATE ARGUEMENT DEDUCTION
//
//Don't need deduction guide using std::pair
//std::pair p2{1, 2}; // implicitly deduced to types int and int
//
//Program may need a deduction guide:
//template <typename T, typename U>
//struct Pair
//{
//	T first{};
//	U second{};
//};
//
//template <typename T, typename U>
//Pair(T, U) -> Pair<T, U>; // would be Pair(T, T) if second was also T
//
//int main()
//{
//	Pair<int, int> p1{1, 2}; //explicit - no deduction
//	Pair p2{ 1, 2 };		 // using deduction
//	return 0;
//}

// STD::PAIR
//
// Basically does the same as the mix and match class templates in below CLASS TEMPLATES sec
// 
// std::pair<int, double> p1 {1, 2.3};
// std::pair<int, int> p2 {7, 8};
//

// CLASS TEMPLATES - if in mult files define in header
//
//template <typename T>
//struct Pair
//{
//	T first{};
//	T second{};
//};
//
//// Now we can overload functions with our class template
//template <typename T>
//constexpr T max(Pair<T> p)
//{
//	return (p.first < p.second ? p.second :p.first)
//}
//
//int main()
//{
//	Pair<int>    p1{5, 6};
//	Pair<double> p2{1.2, 3.4};
//	Pair<double> p3{7.8, 9.0};  // oo yeah brother
//
//	return 0;
//}
//
// Can also mix and match like this:
// template <typename T>
// struct Foo
// {
//		T first{};
//		int second{};
// };
// 
// and this:
// template <typename T, typename U>
// struct Foo
// {
//		T first{};
//		U second{};
// };


// MISC STRUCT STUFF
// 
// Member selection using a pointer - most efficient:
// 
// struct Employee
//{
//    int id{};
//    int age{};
//    double wage{};
//};
//
//int main()
//{
//    Employee joe{ 1, 34, 65000.0 };
//
//    ++joe.age;
//    joe.wage = 68000.0;
//
//    Employee* ptr{ &joe };
//    std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object
//
//    return 0;
//}
// 
// Mixing pointers and non-pointers
// 
// struct Paw
//{
//    int claws{};
//};
//
//struct Animal
//{
//    std::string name{};
//    Paw paw{};
//};
//
//int main()
//{
//    Animal puma{ "Puma", { 5 } };
//
//    Animal* ptr{ &puma };
//
//    // ptr is a pointer, use ->
//    // paw is not a pointer, use .
//
//    std::cout << (ptr->paw).claws << '\n';
//
//    return 0;
//}
// 
// Structs are at least as large as its variables but could be larger
// due to implicit padding
//
// Example 1: - unrelated to size
//struct Employee
//{
//	int id{};
//	int age{};
//	double wage{};
//};
//
//struct Company
//{
//	int numberOfEmployees{};
//	Employee CEO{}; // Employee is a struct wiht the Company struct
//};
//
//int main()
//{
//	Company myCompany{ 7, {1, 32, 55000.0} }; //Nested init for CEO
//
//	return 0;
//}
// Example 2: - same thang but different
//struct Company
//{
//    struct Employee // accessed via Company::Employee
//    {
//        int id{};
//        int age{};
//        double wage{};
//    };
//
//    int numberOfEmployees{};
//    Employee CEO{}; // Employee is a struct within the Company struct
//};
//
//int main()
//{
//    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
//    std::cout << myCompany.CEO.wage << '\n'; // print the CEO's wage
//
//    return 0;
//}
//

// 10.8.2
//
//struct Fraction
//{
//	int numerator{0};
//	int denominator{1};
//};
//
//void printFraction(const Fraction& fraction)
//{
//	std::cout << "Your fractions multiplied together: "
//		<< fraction.numerator << "/" << fraction.denominator << '\n';
//}
//
//Fraction multiplyFraction(const Fraction& f1, const Fraction& f2)
//{
//
//	return { f1.numerator * f2.numerator, f1.denominator * f2.denominator};
//}
//
//Fraction getFraction()
//{
//	Fraction temp{};
//	std::cout << "Enter a value for the numerator: ";
//	std::cin >> temp.numerator;
//	std::cout << "Enter a value for the denominator: ";
//	std::cin >> temp.denominator;
//	std::cout << '\n';
//
//	return temp;  // dont return by reference because itll dingle dangle
//}
//
//int main()
//{
//	Fraction f1{getFraction()};
//	Fraction f2{getFraction()};
//
//	printFraction(multiplyFraction(f1, f2));
//
//	return 0;
//}

// 10.8.1
// not exactly the same answer but same principle
//struct Ad
//{
//	int views{};
//	double percUsersClicked{};
//	double earningsPerClick{};
//};
//
//double calculateEarnings(const Ad& ad)
//{
//	return ad.views * ad.percUsersClicked * ad.earningsPerClick;
//}
//
//void printAndCalculateAd(const Ad& ad)
//{
//	std::cout << "Views:           " << ad.views << '\n';
//	std::cout << "% of Users:      " << ad.percUsersClicked << '\n';
//	std::cout << "$ per Click:     " << ad.earningsPerClick << '\n';
//	std::cout << "Earnings today: $" << calculateEarnings(ad) << '\n';
//}
//
//int main()
//{
//	Ad burger{100, 0.5, 0.25};
//
//	printAndCalculateAd(burger);
//
//	return 0;
//}

//RETURNING STRUCTS FROM FUNCTIONS BY VALUE
//
//struct Point3d
//{
//	double x{0.0};
//	double y{0.0};
//	double z{0.0};
//};
//
//Point3d getZeroPoint()
//{
//	//Point3d temp{ 0.0, 0.0, 0.0 };
//	//return temp;  // redundant
//
//	//return Point3d{ 0.0, 0.0, 0.0 };  // efficient but still redundant
//
//	return {}; // most efficent because of return type
//}
//
//int main()
//{
//	Point3d zero{ getZeroPoint() };
//
//	return 0;
//}

//PASSING STRUCTS TO FUNCTIONS (BY REFERENCE).. generally
//
//struct Employee
//{
//	int id{};
//	int age{};
//	double wage{};
//};
//// passing by reference avoids expensive copy
//void printEmployee(const Employee& employee) // by reference using only 1 param
//{ 
//	std::cout << "ID:    " << employee.id << '\n';
//	std::cout << "Age:   " << employee.age << '\n';
//	std::cout << "Wage:  " << employee.wage << '\n';
//}
//
//int main()
//{
//	Employee joe{ 14, 32, 24.15 };
//	Employee frank{ 15, 28, 18.27 };
//
//	printEmployee(joe);
//
//	std::cout << '\n';
//
//	printEmployee(frank);
//
//	return 0;
//}

//AGGREGATE INITIALIZATION
//struct Employee
//{
//	int id{}; // always use braces
//	int age{}; // can add default value here
//	double wage{}; // best to add new members to the bottom
//};
//
//int main()
//{
//	Employee frank = { 1, 32, 60000.0 }; // copy-list init using braced list
//	Employee joe{ 2, 28, 45000.0 }; // list init using braced list (preferred)
//	Employee robert(3, 45, 62500.0); // avoid
//	Employee rick{ 2, 28 }; // valid but leaves wage at 0.0
//	Employee ned{}; // init with all values 0.0
//	const Employee ceo{}; // can be const
//	Employee judy{ .id{12}, .wage{80000.0} }; // by value - adds clutter tho
//
//	Employee joe = { joe.id, 33, 66000.0 }; //change multiple values
//	//or
//	joe = { .id = joe.id, .age = 33, .wage = 66000.0 };
//
//	Employee nick{}; //always use braces
//
//	return 0;
//}

// STRUCTURES - are also aggregates
//struct Employee  // type definition - not an object
//{
//	int id{};  // these are data members or member variables
//	int age{};
//	double wage{};
//};
//
//int main()
//{
//	Employee joe;  // Employee type, joe variable name
//	joe.id = 14;
//	joe.age = 32; // OoOoo looks familiar
//	joe.wage = 60000.0;
//
//	Employee frank;
//	frank.id = 15;
//	frank.age = 28;
//	frank.wage = 45000.0;
//
//	int totalAge{ joe.age + frank.age };
//
//	if (joe.wage > frank.wage)
//		std::cout << "Joe makes more than Frank\n";
//	else if (joe.wage < frank.wage)
//		std::cout << "Joe makes less than Frank\n";
//	else
//		std::cout << "Joe and Frank make the same amount\n";
//
//	// Frank got a promotion
//	frank.wage += 5000.0;
//
//	// Today is Joe's birthday
//	++joe.age;
//
//	return 0;
//}

//10.4.1
//
//enum class Animal
//{
//	pig,
//	chicken,
//	goat,
//	cat,
//	dog,
//	duck,
//};
//
//std::string_view getAnimalName(Animal animal)
//	{
//	using enum Animal;
//	switch (animal)
//	{
//	case pig:	  return "pig";
//	case goat:	  return "goat";
//	case cat:	  return "cat";
//	case dog:	  return "dog";
//	case duck:    return "duck";
//	case chicken: return "chicken";
//	default:      return "no";
//	}
//	}
//
//void printNumberOfLegs(Animal animal)
//{
//	std::cout << "A " << getAnimalName(animal) << " has ";
//
//	using enum Animal;
//	switch (animal)
//	{
//	case pig:
//	case goat:
//	case cat:
//	case dog:
//		std::cout << 4;
//		break;
//	case duck:
//	case chicken: 
//		std::cout << 2;
//		break;
//	default:      
//		std::cout << "no";
//	}
//
//	std::cout << " legs.\n";
//}
//
//int main()
//{
//	printNumberOfLegs(Animal::cat);
//	printNumberOfLegs(Animal::chicken);
//
//	return 0;
//}

// TYPE CONVERTING SCOPED ENUMS
//#include <utility>
//
//int main()
//{
//	enum class Color
//	{
//		red,
//		blue,
//	};
//
//	Color color{ Color::blue };
//
//	std::cout << color << '\n'; // wont work no int conversion
//	std::cout << static_cast<int>(color) << '\n'; // explicit conversion
//	std::cout << std::to_underlying(color) << '\n'; // convert to underlying
//	// can also static_cast to take input:
//	int input{};
//	std::cin >> input;
//	Color color{ static_cast<Color>(input) };
//  using enum Color; // allows use without prefixes like Color::
//}

//SCOPED ENUMS - do not implicitly convert to int
//int main()
//{
//	enum class Color //"enum class" defines this as a scoped enum
//	{
//		red, // red is considered part of color's scope region
//		blue,
//	};
//
//	enum class Fruit
//	{
//		banana, // banana is considered part of Fruit's scope region
//		apple,
//	};
//
//	Color color{ Color::red }; // note: red is not directly accessible
//	Fruit fruit{ Fruit::banana }; // we have to use Color::red
//
//	if (color == fruit) // compile error
//		std::cout << "color and fruit are equal\n";
//	else
//		std::cout << "color and fruit are not equal\n";
//
//	return 0;
//}

//ENUM WITH ASSIGNED INT VALUE FOR INITIALIZATION
//enum Pet: int // we've specified a base
//{
//    cat, // assigned 0
//        dog, // assigned 1
//        pig, // assigned 2
//        whale, // assigned 3
//};
//
//int main()
//{
//    Pet pet1{ 2 }; // ok: can brace initialize with integer
//    Pet pet2(2);   // compile error: cannot direct initialize with integer
//    Pet pet3 = 2;   // compile error: cannot copy initialize with integer
//
//    pet1 = 3;       // compile error: cannot assign with integer
//
//    return 0;
//}

// 10.2.2
//
//namespace Monster
//{
//	enum MonsterType
//	{
//		orc,
//		goblin,
//		troll,
//		ogre,
//		skeleton,
//	};
//}
//
//int main()
//{
//	Monster::MonsterType monster{Monster::troll};
//	if (monster == Monster::troll)
//		return 0;
//}

// 10.2.1
//
//enum MonsterType
//{
//	orc,
//	goblin,
//	troll,
//	ogre,
//	skeleton,
//};

// ENUMERATORS
// Avoiding global scope:
//namespace Color
//{
//    // The names Color, red, blue, and green are defined inside namespace Color
//    enum Color
//    {
//        red, //assigned 0
//        green, //assigned 1
//        blue,  // can also be assigned any number even negative
//    };
//}
//
//namespace Feeling
//{
//    enum Feeling
//    {
//        happy,
//        tired,
//        blue, // Feeling::blue doesn't collide with Color::blue
//    };
//}
//
//int main()
//{
//    Color::Color paint{ Color::blue };
//    Feeling::Feeling me{ Feeling::blue };
//
//    return 0;
//}
//
// Use-case example:
//enum Color
//{
//    red,
//    green,
//    blue,
//};
//
//int main()
//{
//    Color shirt{ blue };
//
//    if (shirt == blue) // if the shirt is blue
//        std::cout << "Your shirt is blue!";
//    else
//        std::cout << "Your shirt is not blue!";
//
//    return 0;
//}

// PROGRAM DEFINED TYPES
//  Example:
// Define a program-defined type named Fraction so the compiler understands what a Fraction is
// (we'll explain what a struct is and how to use them later in this chapter)
// This only defines what a Fraction type looks like, it doesn't create one
//struct Fraction
//{
//	int numerator{};
//	int denominator{};
//};
//
//// Now we can make use of our Fraction type
//int main()
//{
//	Fraction f{ 3, 4 }; // this actually instantiates a Fraction object named f
//
//	return 0;
//}


// CHAPTER 9 PROGRAM FUNCTION - write sort2 function
//
//void sort2(int& x, int& y)
//{
//	int swap{ x };
//	if (x > y)
//	{
//		x = y;
//		y = swap;
//	}
//}
//
//int main()
//{
//	int x{ 7 };
//	int y{ 5 };
//
//	sort2(x, y);
//	std::cout << x << ' ' << y << '\n'; //should print 5 7
//
//	sort2(x, y);
//	std::cout << x << ' ' << y << '\n'; // should print 5 7
//	return 0;
//}

// AUTO AND REFERENCES / CONST
// instantiating an auto type with a ref or const will have each be dropped
// it will have to be reapplied in the definition of the variable
// auto does not drop pointers

// IN AND OUT PARAMS
// IN params are normal params as we know
// OUT params are params by reference that change a variable in outer scope
// Generally avoid OUT params if possible

// RETURN BY ADDRESS AND REFERENCE
// const std::string& getProgramName() <- example reference function
// avoids expensive copying objects to return them
// return by address only necessary when ability to return null pointer is needed

// PASSING POINTERS TO FUNCTIONS AS PARAMS
// void printByAddress(const std::string* ptr) <-example function
//		std::cout << *ptr << '\n'; will print the value based on address passed
// printByAddress(&str) <-example call & passes the address
// no expensive copy is made this way
// passing by address or ref allows changing of variable referenced in func
// prefer passing as ref due to possible null pointers

// CONST POINTERS ex const int* const ptr {x};
//A const before the asterisk is associated with the type being pointed to. 
//Therefore, this is a pointer to a const value, and the value cannot be modified through the pointer.
// 
//A const after the asterisk is associated with the pointer itself.
//Therefore, this pointer cannot be assigned a new address.

// POINTERS - used to change the value at an address or change the address of a value
// printing something like this &x shows address of variable
// printing this *(&x) prints the value at that address
// int* < assigns pointer type
// int* ptr{ &x } < must assign to an address with &
// pointers must match the type of its pointee int -> int ect
//int main()
//{
//    int x{ 5 };
//    int* ptr{ &x }; // initialize ptr with address of variable x
//
//    std::cout << x << '\n';    // print x's value
//    std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)
//
//    *ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)
//
//    std::cout << x << '\n';
//    std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)
//
//    return 0;
//}
// the size of a pointer is always the same
// avoid dangling pointers
// pointers with no value are null pointers
// int* ptr { nullptr } initialize null pointer
// use conditionals to dereference pointers so no crash
// if (ptr) // true !ptr would mean null pointer value
//		std::cout << *ptr << '\n';
// else
//		//something maybe error message
//
// pointers that are not initialized with null or are destroyed will not
// default to null values - it needs to be set to a null value
// no easy way to determine if a non-null pointer is valid
// Favor references over pointers if you can

// PASSING REFERENCES TO FUNCTIONS AS PARAMS
// 
// void foo(int a, int& b, const std::string& c)
// a is passed by value, b by reference, c by const reference
// passing by reference enables a pass of string or class WITHOUT copying it
// which is expensive - best to pass by value if object is small tho
// #define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))
// can use above function to determine if small enough..

// 8.x.5c
//
//template <typename T, typename U>
//auto sub(T x, U y)
//{
//	return x - y;
//}
//
//int main()
//{
//	std::cout << sub(3, 2) << '\n';
//	std::cout << sub(3.5, 2) << '\n';
//	std::cout << sub(4, 1.5) << '\n';
//
//	return 0;
//}

// 8.x.5b
//
//template <typename T>
//T mult(T x, int y)
//{
//	return x * y;
//}
//
//int main()
//{
//	std::cout << mult(2, 3) << '\n';
//	std::cout << mult(1.2, 3) << '\n';
//
//	return 0;
//}

// 8.x.5a
//
//template <typename T>
//T add(T x, T y)
//{
//	return x + y;
//}
//
//int main()
//{
//	std::cout << add(2, 3) << '\n';
//	std::cout << add(1.2, 3.4) << '\n';
//
//	return 0;
//}

// NON-TYPE TEMPLATE
//
//template <int N> // declare a non-type template parameter of type int named N
//void print()
//{
//    std::cout << N << '\n'; // use value of N here
//}
//
//int main()
//{
//    print<5>(); // 5 is our non-type template argument
//
//    return 0;
//}

// FUNCTION TEMPLATES -- another way to overload functions
// 
// Base function
//int max(int x, int y)
//{
//    return (x < y) ? y : x;
//}
//
// Template version
//template <typename T> // this is the template parameter declaration
//T max(T x, T y) // this is the function template definition for max<T>
//{  // can use two different template types as params also (T & U) for example
//	 // might have to make function type auto max instead of T max
//    return (x < y) ? y : x;
//}
//
// Can be called like this
// max<int>(1, 2) or this max<double>(1.2, 1.3)
//
// Templates needed in multiple files should be defined in a header file
// and then #included
//
// Can also be shortened to this if params are not the same type
// auto max(auto x, auto y)
// {
//	   return (x < y) ? y : x;
// }

// OVERLOADED FUNCTIONS
// functions can be duplicated in order to use and produce different types
// such as int, double, float - long as param and return type matches
// can even create the same function with a different number of params

//#include "Random.h"
//#include <limits>
//
//void ignoreLine()
//{
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//}
//
//int getGuess(int count)
//{
//	while (true)
//	{
//		std::cout << "Guess #" << count << ": ";
//		int input{};
//		std::cin >> input;
//
//		if (!std::cin)
//		{
//			std::cin.clear();
//			ignoreLine();
//			std::cout << "Oops, that input is invalid. Please try again.\n";
//		}
//		else if (input < 1 || input > 100)
//		{
//			ignoreLine();
//			std::cout << "You cannot guess a number below 1 or above 100.\n";
//		}
//		else
//		{
//			ignoreLine();
//			return input;
//		}
//	}
//}
//
//bool playGame(int correctAnswer, int maxGuesses)
//{
//	for (int count {1}; count <= maxGuesses; ++count)
//	{
//		
//		int input{getGuess(count)};
//
//		if (input == correctAnswer)
//			return true;
//
//		else if (input > correctAnswer)
//			std::cout << "Your guess is too high.\n";
//
//		else
//			std::cout << "Your guess is too low.\n";
//	}
//
//	return false;
//}
//
//bool playAgain()
//{
//	while (true)
//	{
//		std::cout << "Would you like to play again (y/n)?";
//		char input{};
//		std::cin >> input;
//
//		if (!std::cin)
//			std::cin.clear();
//
//		ignoreLine();
//
//		switch (input)
//		{
//		case 'y': 
//			ignoreLine();
//			return true;
//		case 'n': 
//			ignoreLine();
//			return false;
//		default:
//			std::cout << "Oops, that input is invalid. Please try again.\n";
//		}
//	}
//}
//
//int main()
//{
//	constexpr int maxGuesses{7};
//
//	do
//	{
//		int solution{ Random::get(1, 100) };
//
//		std::cout << "Let's play a game. I'm thinking of a number between 1 and"
//			<< " 100. You have 7 tries to guess what it is.\n";
//
//		bool won{ playGame(solution, maxGuesses) };
//		if (won)
//			std::cout << "Correct! You win!\n";
//		else
//			std::cout << "Sorry, you lose. The correct number was "
//			<< solution << ".\n";
//
//	} while (playAgain());
//	
//	std::cout << "Thank you for playing.\n";
//
//	return 0;
//}

// CHAPTER 7 PROGRAM 2
//
//#include<cassert>
//#include<cmath>
//
//bool isPrime(int x)
//{
//    //MY OPTIMIZED ANSWER
//    if (x <= 1)
//        return false;
//
//    int maxTest{ static_cast<int>(std::sqrt(x)) };
//
//    for (int test{ maxTest }; test > 1; --test)
//    {
//        if (x % test == 0)
//            return false;
//    }
//
//    return true;
//
//
//    //MY ORIGINAL ANSWER - actually only need one success if starting below x
//    //if (x <= 1)
//    //    return false;
//    //int success{};
//    //for (int count{x}; count > 1; --count)
//    //    if (x % count == 0)
//    //    {
//    //        std::cout << "Yep\n";
//    //        ++success;
//    //    }
//    //if (success > 1)
//    //{
//    //    std::cout << x << " FALSE\n";
//    //    return false;
//    //}
//    //else
//    //{
//    //    std::cout << x << " TRUE\n";
//    //    return true;
//    //}
//}
//
//int main()
//{
//    assert(!isPrime(0));
//    assert(!isPrime(1));
//    assert(isPrime(2));
//    assert(isPrime(3));
//    assert(!isPrime(4));
//    assert(isPrime(5));
//    assert(isPrime(7));
//    assert(!isPrime(9));
//    assert(isPrime(11));
//    assert(isPrime(13));
//    assert(!isPrime(15));
//    assert(!isPrime(16));
//    assert(isPrime(17));
//    assert(isPrime(19));
//    assert(isPrime(97));
//    assert(!isPrime(99));
//    assert(isPrime(13417));
//
//    std::cout << "Success!\n";
//
//	return 0;
//}

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







