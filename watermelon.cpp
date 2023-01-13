#include <bits/stdc++.h>
using namespace std;
int main(){
	int w;
	cin >> w;
	if(w < 4)
		cout << "No" << endl;
	else
		cout << (( w % 2 == 0 ) ? "Yes" : "No") << endl;
	return 0;
}
