#include <bits/stdc++.h>

using namespace std;

int sum(long long n){
	if(n == 1)
		return 1;
	else
		return (n+sum(n-1));
}

int main(){
	long long n;
	cin >> n;
	cout << "Sum of : " << n << " = " << sum(n) << endl;
	return 0;
}
