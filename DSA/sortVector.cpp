#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> numbers;
	for(int i=0;i<5;i++){
		int n;
		cin >> n;
		numbers.push_back(n);
	}
	// desc sort
	//sort(numbers, numbers+5, greater<int>());
	// asc sort
	sort(numbers.begin(), numbers.end());
	for(int i : numbers)
		cout << i << "\t";
	cout << endl;
	return 0;
}
