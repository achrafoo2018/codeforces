#include <bits/stdc++.h>
using namespace std;
int main(){
	queue<int> q;
	for(int i=0; i < 3; i++){
		int n;
		cin >> n;
		q.push(n);
	}
	while(! q.empty()){
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
