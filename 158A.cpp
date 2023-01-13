#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int res = 0;
	int x=0, j=0;
	while(n--){
		cin >> x;
		if( x != j && res >= k)
			break;
		res += x > 0;
		j = x;
	}	
	cout << res << endl;
	return 0;
}
