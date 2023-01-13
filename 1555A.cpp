#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t, n;
	cin >> t;
	cout << fixed;
	while(t--){
		cin >> n;		
		if(n % 6 == 0)
			cout << (n / 6) * 15 << endl;
		else if(n % 8 == 0)
			cout << (n / 8) * 20 << endl;
		else if(n % 10 == 0)
			cout << (n / 10) * 25 << endl;
		else{
			if((6*ceil(n / 6.0)) - n < min((8*ceil(n/8.0))-n, (10*ceil(n/10.0))-n))
				cout << (long long)ceil(n / 6.0) * 15 << endl;
			else if((8*ceil(n / 8.0))-n < min((6*ceil(n/6.0))-n, (10*ceil(n/10.0))-n))
				cout << (long long)ceil(n / 8.0) * 20 << endl;
			else
				cout << (long long)ceil(n / 10.0) * 25 << endl;
		}
	}	
	return 0;
}
