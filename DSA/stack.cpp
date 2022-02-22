#include <bits/stdc++.h>
using namespace std;
int main(){
	stack<int> s;
	for(int i=0; i<5; i++){
		int n;
		cin >> n;
		s.push(n);
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	return 0;
}
