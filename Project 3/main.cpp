#include<iostream>
#include "VNT.cpp"

int main() {
	VNT a(5, 6);
	a.print();
	for (int i = 0; i<31; i++) {
		a.add(i*i);
	}

	a.print();
	if (a.find(25)) {
		std::cout << "found 25 int vnt table\n";
	}
	if (!a.find(26)) {
		std::cout << "26 is not in the vnt table\n";
	}
	std::cout << "the minimum value in vnt table is: " << a.getMin() << endl;
	a.print();

	int arr[10] = { 2,6,9,0,3,1,8,4,7,5 };
	std::cout << "unsorted array is:\n";
	for (auto e : arr)
		cout << e << " ";
	std::cout << endl;

	a.sort(arr, 10);
	std::cout << "sorted array is:\n";
	for (auto e : arr)
		std::cout << e << " ";
	std::cout << endl;

	return 0;
}
