// FiboDongXi.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <unordered_map>

using std::cout;
using std::cerr;
using std::endl;
using std::unordered_map;
using std::setw;
using std::ofstream;

typedef unordered_map<int, unsigned long long> FibonacciMap;

unsigned long long NormalFibonacci(int);
unsigned long long DynamicFibonacci(int, FibonacciMap&);

unsigned long long numberOfNormalCalls = 0, numberOfDynamicCalls = 0;

int main(int argc, char* argv[])
{
	if (argc != 3){
		cerr << "Not enough parameters" << endl << "Usage: " << argv[0] << " max file" << endl
			 << "max is the number of iterations to do, file is the filename to save the running information" << endl;
		exit(1);
	}
	size_t iterations = atoi(argv[1]);
	FibonacciMap fiboMap;
	fiboMap[0] = 0;
	fiboMap[1] = 1;
	ofstream out(argv[2]);
	for (size_t i = 0; i < iterations; i++)
	{
		numberOfNormalCalls = numberOfDynamicCalls = 0;
		unsigned long long normalResult = NormalFibonacci(i);
		unsigned long long dynamicResult = DynamicFibonacci(i, fiboMap);
		cout << setw(4) << i << setw(35) << normalResult << setw(35) << dynamicResult << setw(15) << numberOfNormalCalls << setw(15) << numberOfDynamicCalls << setw(10) << fiboMap.size() << endl;
		out << setw(4) << i << setw(35) << normalResult << setw(35) << dynamicResult << setw(15) << numberOfNormalCalls << setw(15) << numberOfDynamicCalls << setw(10) << fiboMap.size() << endl;
	}
    return 0;
}

unsigned long long NormalFibonacci(int n)
{
	numberOfNormalCalls++;
	if (n == 0 || n == 1)
		return n;
	else
		return NormalFibonacci(n - 1) + NormalFibonacci(n - 2);
}

unsigned long long DynamicFibonacci(int n, FibonacciMap& map)
{
	numberOfDynamicCalls++;
	if (map.count(n) > 0)
		return map[n];
	else {
		unsigned long long retVal = DynamicFibonacci(n - 1, map) + DynamicFibonacci(n - 2, map);
		map[n] = retVal;
		return retVal;
	}

}
