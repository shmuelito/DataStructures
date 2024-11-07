#include "Stack.h"
#include "Utils.h"
#include <windows.h> // WinApi header - needed for setting console color

#include <iostream>'
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;

 #define GREEN 2
 #define DARK_RED 4
 #define PURPLE 5
 #define YELLOW 6
 #define LIGHT_BLUE 9
 #define LIGHT_GREEN 10
 #define TEAL 11
 #define RED 12
 #define PURPLE 13
 #define LIGHT_YELLOW 14
 #define WHITE 15

 void set_console_color(unsigned int color)
 {
 	// colors are 0=black 1=blue 2=green and so on to 15=white
 	// colorattribute = foreground + background * 16
 	// to get red text on yellow use 4 + 14*16 = 228
 	// light red on yellow would be 12 + 14*16 = 236
 	// a Dev-C++ tested console application by vegaseat 07nov2004

 	HANDLE hConsole;

 	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 	SetConsoleTextAttribute(hConsole, color);
 }

std::string popElementsAndGetPrintedStack(Stack* s)
{
	std::stringstream output;
	while (!isEmpty(s))
	{
		output << pop(s) << " ";
	}
	// removing the last letter (space)
	std::string outputString = output.str();
	outputString = outputString.substr(0, outputString.length() - 1);
	return outputString;
}

bool test1()
{
	// check basic data structure functions
	set_console_color(LIGHT_YELLOW);
	cout <<
		"*******************************\n" <<
		"Test 1 - basic stack functions\n" <<
		"*******************************\n" << endl;
	set_console_color(WHITE);

	cout << "Initializing new stack ... \n" << endl;
	Stack* s0 = new Stack;
	initStack(s0);

	bool empty = isEmpty(s0);
	cout << "Checking if stack is empty ... \n"
		<< "Expected: true\n"
		<< "Got     : " << (empty ? "true" : "false")
		<< "\n" << endl;

	if (!empty)
		// stack is not empty - test failed
		return false;

	const std::string stack0elements = "11 22 33 44 55";

	cout << "Pushing elements to stack ... " << stack0elements << "\n" << endl;
	for (int i = 0; i < 5; i++)
	{
		push(s0, (i + 1) * 11);
	}

	std::string output = popElementsAndGetPrintedStack(s0);
	const std::string stack0PoppedElements = "55 44 33 22 11";
	cout << "Popping and printing each element in stack ...\n"
		<< "Expected: " << stack0PoppedElements << "\n"
		<< "Got     : " << output
		<< "\n " << endl;

	if (output != stack0PoppedElements)
	{
		return false;
	}

	cout << "Cleaning stack...\n" << endl;
	cleanStack(s0);
	delete s0;
	return true;
}

bool test2()
{
	// check basic data structure functions
	set_console_color(LIGHT_YELLOW);
	cout <<
		"*******************************\n" <<
		"Test 2 - More Stack tests\n" <<
		"*******************************\n" << endl;
	set_console_color(WHITE);

	cout << "Initializing new stack ... \n" << endl;
	Stack* s0 = new Stack;
	initStack(s0);

	bool empty = isEmpty(s0);
	cout << "Checking if stack is empty ... \n"
		<< "Expected: true\n"
		<< "Got     : " << (empty ? "true" : "false")
		<< "\n" << endl;

	if (!empty)
		// stack is not empty - test failed
		return false;

	cout << "Pushing 100,000 elements to stack ... " << "\n" << endl;
	for (int i = 0; i < 100000; i++)
	{
		push(s0, i);
	}

	cout << "Popping 10,000 elements from stack ... " << "\n" << endl;
	for (int i = 0; i < 10000; i++)
	{
		pop(s0);
	}

	empty = isEmpty(s0);
	cout << "Checking if stack is empty ... \n"
		<< "Expected: false\n"
		<< "Got     : " << (empty ? "true" : "false")
		<< "\n" << endl;

	if (empty)
		// stack is not empty - test failed
		return false;

	cout << "Pop 90,000 elements from stack ... " << "\n" << endl;
	for (int i = 0; i < 90000; i++)
	{
		pop(s0);
	}

	empty = isEmpty(s0);
	cout << "Checking if stack is empty ... \n"
		<< "Expected: true\n"
		<< "Got     : " << (empty ? "true" : "false")
		<< "\n" << endl;

	if (!empty)
		// stack is not empty - test failed
		return false;


	cout << "Cleaning stack...\n" << endl;
	cleanStack(s0);
	delete s0;
	return true;
}

std::string arrayToString(int numbers[], int size)
{
	std::stringstream output;
	for (int i = 0; i < 10; i++)
	{
		output << numbers[i] << " ";
	}
	std::string outputString = output.str();
	outputString = outputString.substr(0, outputString.length() - 1);
	return outputString;
}

bool test3()
{
	set_console_color(LIGHT_YELLOW);
	// check basic data structure functions
	cout <<
		"*******************************\n" <<
		"Test 3 - utils\n" <<
		"*******************************\n" << endl;
	set_console_color(WHITE);

	cout << "Creating array ... [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]\n" << endl;
	int numbers[10];
	for (int i = 0; i < 10; i++)
	{
		numbers[i] = (i+1) * 2;
	}

	reverse(numbers, 10);
	std::string reversedArray = "20 18 16 14 12 10 8 6 4 2";
	std::string resultfromReverse = arrayToString(numbers, 10);
	cout << "Using reverse() on array and printing it... " << endl
		<< "Expected: " << reversedArray << "\n"
		<< "Got     : " << resultfromReverse
		<< "\n" << endl;

	if (resultfromReverse != reversedArray)
		return false;

	return true;
}

 void printGreatJob()
 {
 	cout <<	"  _____             __       __     __  \n" << 
 	    	" / ___/______ ___ _/ /_  __ / /__  / /  \n" <<
 	    	"/ (_ / __/ -_) _ `/ __/ / // / _ \\/ _ \\ \n" <<
         	"\\___/_/  \\__/\\_,_/\\__/  \\___/\\___/_.__/ \n" <<
 			"\n\t\t\tYou are amazing!!!\n" ;
 }

int main()
{
	bool test1Result = test1();
	bool test2Result = test2();
	bool test3Result = test3();


	if (test1Result && test2Result && test3Result)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex1 Part3 Tests Passed!!! ##########\n" << endl;
		printGreatJob();
		set_console_color(WHITE);
	}
	else
	{
		set_console_color(RED);
		std::cout << "\n########## TEST Failed :( ##########\n";
		set_console_color(WHITE);
	}


	return 0;
}