#include "Header.h"

//Prototypes
void increment_reference(int&);
int increment_value(int);
void next_section();
void print_vector(std::vector <int>&);
void ref_value_practice();
void struct_practice();
void int_array_practice();
void vector_practice();
void class_practice();


void main() {
	ref_value_practice();
	struct_practice();
	int_array_practice();
	vector_practice();
	class_practice();
}


//Functions
void increment_reference(int& in) { in++; }
int increment_value(int in) { return in++; }

void next_section() {
	char input;
	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
}

void print_vector(std::vector <int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << "\n\t" << i << " " << &vec[i];
		std::cout << "\n\tValue: " << vec[i];
	}
}

void ref_value_practice() {
	//Below is some practice with increment by reference and value
	int x = 0;
	clock_t start, end;
	double duration;

	std::cout << "The purpose of this section is to increment a value by reference"
		<< "\nand also by value and compare the execution time of each.";
	std::cout << "\n\n\tExecution time of 9,999,999 Increment by reference: ";

	start = clock();
	for (int i = 0; i < 9999999; i++)
		increment_reference(x);
	end = clock();
	std::cout << double(end - start) << '\n';

	std::cout << "\n\tExecution time of 9,999,999 Increment by value: ";
	start = clock();
	for (int i = 0; i < 9999999; i++)
		increment_value(x);
	end = clock();
	std::cout << double(end - start) << '\n';

	next_section();
}

void struct_practice() {
	//Below is some practice with the C library item "struct"
	std::cout << "\nBelow is output from struct \'address\' practice:";
	address Bob;  address* Bob_ref = &Bob;
	Bob.name = "Bob";	Bob.street = "Greenfield";	Bob.city = "Mesa";	Bob.state = "AZ";
	//Accessing Bob's info by value
	std::cout << "\n\n\tBob's name: " << Bob.name;
	std::cout << "\n\tBob's street: " << Bob.street;
	std::cout << "\n\tBob's city: " << Bob.city;
	std::cout << "\n\n\tMemory location of Bob's data structure: " << Bob_ref << std::endl;
	std::cout << "\n\tMemory location of last element in structure: " << &Bob.zip;
	std::cout << "\n\n\tNumber of bytes in the structure: " << sizeof(Bob);
	next_section();
}

void int_array_practice() {
	//Below is some practice with int array and pointer:
	int nums[] = { 1,2,3,4,5,6 };
	int* nums_ptr = &nums[0];
	std::cout << "\n\nInteger array demonstration: ";
	std::cout << "\n\n\tAddress of nums array: " << &nums;
	std::cout << "\n\n\tSize of nums array: " << sizeof(nums);
	std::cout << "\n\n\tNumber of elements in nums array: " << sizeof(nums) / sizeof(int);
	std::cout << "\n\n\tAddress of each element of nums array: ";
	for (int i = 0; i < 6; i++) {
		std::cout << "\n\t" << i << " " << &nums[i];
		std::cout << "\n\tValue: " << nums[i];
	}
	//Access int array by reference
	std::cout << "\n\nAddress of beginning of nums array: " << nums_ptr;
	std::cout << "\n\n\tValue of first value: " << *nums_ptr;
	*nums_ptr = 1337;
	std::cout << "\n\n\tValue now of first value: " << *nums_ptr;
	std::cout << "\n\nModified second element using size of int";
	//Second element
	*(nums_ptr + 1) = 31337;
	std::cout << "\n\n\tValue of second element: " << nums[1];
	std::cout << "\n\nAccessing some data after the array should return random value: " << *(nums_ptr + 8);
	next_section();
}

void vector_practice() {
	//Below is some practice with 'vector'
	std::vector <int> numbers;
	std::cout << "\n\nVector practice: ";
	std::cout << "\n\n\tAddress of \'numbers\' vector: " << &numbers;
	std::cout << "\n\n\tSize of \'numbers\' vector: " << sizeof(numbers);
	numbers.push_back(3); numbers.push_back(2); numbers.push_back(1); numbers.push_back(0);
	std::cout << "\n\n\t\'numbers\' vector after pushing elements: " << numbers[0];
	print_vector(numbers);
	std::cout << "\n\n\t\'numbers\' Vector capacity: " << numbers.capacity();
	numbers.pop_back();
	numbers.shrink_to_fit();
	std::cout << "\n\n\t\'numbers\' Vector capacity after pop_back call and shrink_to_fit: " << numbers.capacity();
	std::cout << "\n\n\tUpdated Vector: ";
	print_vector(numbers);
	next_section();
}

void class_practice() {
	std::cout << "\nThe following is output from various class object operations:";
	//Initialize 25 objects based on Bank_Record class
	Bank_record clients[25];
	std::cout << "\n\tSize of one Bank_record object: " << sizeof(clients[0]);
	std::cout << "\n\tSize of all 25 objects: " << sizeof(clients);
	//Setting a couple of the accounts
	clients[0].customer_info.name = "John Smith";
	clients[0].customer_info.city = "Scottsdale";
	clients[0].pin = 4567;

	clients[1].customer_info.name = "Peter Doe";
	clients[1].customer_info.city = "Tempe";
	clients[1].pin = 9876;

	//Pointer to John's object
	Bank_record* John = &clients[0];

	std::cout << "\nJohn's accounts before deposit: \n\tChecking: " << John->getCheckingBalance()
		<< "\n\tSavings: " << John->getSavingsBalance();

	//Deposit into John's account
	John->makeDeposit(500, "checking");
	John->makeDeposit(1500, "savings");

	std::cout << "\nJohn's accounts after deposit: \n\tChecking: " << John->getCheckingBalance()
		<< "\n\tSavings: " << John->getSavingsBalance();
}
