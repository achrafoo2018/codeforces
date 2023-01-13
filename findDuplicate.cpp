#include <bits/stdc++.h>
using namespace std;
// Array Of size N
// Elements of array are Integer < N
// Floyd's Cycle
int findDuplicateNumber(vector<int> arr){
	int hare = arr[0];
	int turtle = arr[0];
	while(hare != turtle){
		turtle = arr[turtle];
		hare = arr[arr[hare]];
	}
	int ptr1 = arr[0];
	int ptr2 = hare;
	while(ptr1 != ptr2){
		ptr1 = arr[ptr1];
		ptr2 = arr[ptr2];
	}
	return ptr2;
}

int main(){
	int n;
	cout << "Enter N:";
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
		arr.push_back(rand() % n);
	for(int i : arr)
		cout << i << " | ";
	cout << endl;
	cout << arr[findDuplicateNumber(arr)] << " is duplicated!" << endl;
	return 0;
}
