#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int n;
	cin >> n;
	ll res = 0;
	set<ll> s;
	for(int i=0; i< n; i++){
		ll a;
		cin >> a;
		if(s.find(a) == s.end()){
			res++;
			s.insert(a);
		}
	}
	cout << res << endl;
	return 0;
}
