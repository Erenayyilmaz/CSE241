#include "dynamic_array.h"
#include <iostream>

using namespace std;
using namespace dynamic_array_nmspc;

int main()
{
	DynamicArray<int> da(1);
	da[0] = 1;


	int x = 66;
	cout << " int x = 66 "<<endl;	
	cout<< "size: " << da.size() << endl;
	cout << " da.add_elem(x) "<<endl;
	da.add_elem(x);
	cout << da.size() << endl;
	da.add_elem(10);
	cout << da.size() << endl;
	da.add_elem(20);
	cout << da.size() << endl;
	da.add_elem(30);
	cout << da.size() << endl;
	da.add_elem(40);
	cout << da.size() << endl;
	da.add_elem(50);
	cout << da.size() << endl;
	da.add_elem(60);
	cout << da.size() << endl;
	cout << "da.erase(1)" << endl;
	da.erase(1);

    cout << endl << "Testing range based for loop: " << endl;
	for (const auto& elem : da)
	{
        cout << elem << ' ';
    }

	cout << endl << "Testing sort: " << endl;
    sort(da.begin(), da.end());
    for (const auto& elem : da)
	{
        cout << elem << "  ";
    }
	cout << endl;

	DynamicArray<int> arr(0);
	cout << "	DynamicArray<int> arr()" << endl;
	cout << "Default constructor:\n";
	cout << "Size: " << arr.size() << endl;
	cout << "Capacity: " << arr.capacity() << endl;
	cout << "Empty: "<< arr.empty() << endl;
	arr.add_elem(5);
	arr.add_elem(9);
	cout << "	arr.add_elem(5) arr.add_elem(9)"<<endl;
	cout << "Size: " << arr.size() << endl;

	DynamicArray<int> arr2(5);
	cout << "\nSize constructor:\n";
	cout << "Size: " << arr2.size() << endl;
	cout << "Capacity: " << arr2.capacity() << endl;
	cout << "Empty: " << boolalpha << arr2.empty() << endl;


	DynamicArray<int> arr3(arr);
	cout << "\nCopy constructor:\n";
	cout << "Size: " << arr3.size() << endl;
	cout << "Capacity: " << arr3.capacity() << endl;
	cout << "Empty: " << boolalpha << arr3.empty() << endl;

	cout << endl;


    auto it = arr.begin();
    cout << "Prefix ++ : " << *it << ' ';
    ++it;
    cout << *it << '\n';

    it = arr.begin();
    cout << "Postfix ++ : " << *it << ' ';
    it++;
    cout << *it << '\n';

    it = arr.begin();
    cout << "Dereference: " << *it << '\n';

    it = arr.begin();
    auto it2 = arr.begin();
    cout << "operator== : " << (it == it2) << '\n';
    it2++;
    cout << "operator!= : " << (it != it2) << '\n';

	cout << endl;

	return (0);
}




