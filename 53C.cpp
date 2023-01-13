#include <bits/stdc++.h>
using namespace std;
void solve(int n){
	int i, j;
	for(i=1; i < (n / 2)+1; i++)
		cout << i << " " << n - i + 1 << " ";
	if(n % 2 == 1)
		cout << (int)( n / 2) + 1 << " ";
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	solve(n);
	return 0;
}
