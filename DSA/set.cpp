#include <bits/stdc++.h>
using namespace std;
int main(){
	set<int> s;
	for(int i=0; i<5; i++){
		int n;
		cin >> n;
		s.insert(n);
	}
	for(int i: s)
		cout << i << " | ";
	cout << "N:";
	int n;
	cin >> n;
	if(s.find(n) != s.end())
		cout << "N is found" << endl;
	else
		cout << "N not found" << endl;

	return 0;
}
