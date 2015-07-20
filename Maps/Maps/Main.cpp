#include <map>
#include <set>

using namespace std;

int main()
{
	// Map syntax (indices contain pointers to variables of specific data types)
	map < int, double >  myMap;

	int num = 0;
	double decimal = 0;

	myMap[num] = decimal;

	myMap.count(num);
	myMap.erase(num);
	myMap.empty();
	myMap.size();

	// Set syntax (indices contain values)
	set <int> S;

	S.insert(4);
	S.count(4);
	S.erase(4);
	S.empty();

	for (set <int>::iterator it = S.begin(); it != S.end(); it++)
	{ }

	return 0;
}