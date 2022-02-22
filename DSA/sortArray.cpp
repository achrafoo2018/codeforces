#include <bits/stdc++.h>
using namespace std;
int main(){
	int numbers[5];
	int n = sizeof(numbers);
	cout << n << endl;
	for(int i=0;i<5;i++)
		cin >> numbers[i];
	// desc sort
	//sort(numbers, numbers+5, greater<int>());
	// asc sort
	sort(numbers, numbers+5);
	for(int i : numbers)
		cout << i << "\t";
	cout << endl;
	return 0;
}
