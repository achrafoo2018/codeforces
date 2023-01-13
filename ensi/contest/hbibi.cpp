	#include <bits/stdc++.h>
	typedef long long ll;
	using namespace std;
	int main(){
		double n, m, k;
		cin >> n >> m >> k;
		cout << fixed;
		if(n*m==k)
			cout << "Equal" << endl;
		else if(n*m < k)
			cout << "Mounir" << endl;
		else
			cout << "!Mounir" << endl;
		return 0;
	}
