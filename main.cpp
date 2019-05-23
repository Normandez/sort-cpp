#include <iostream>
#include <ctime>

#include "sort_cpp.h"

int main( int argc, char** argv )
{
	srand(time(0));

	const size_t arr_sz = 100000;
	int arr[arr_sz];
	for( size_t count = 0; count < arr_sz; count++ )
	{
		arr[count] = rand();
	}

	SortCpp::QuickSort<int>( arr, arr + arr_sz );

	for( size_t count = 0; count < 100; count++ )
	{
		std::cout << arr[count] << " ";
	}
	std::cout << std::endl;

	std::getch();
	return 0;
}
