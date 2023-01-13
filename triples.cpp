#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> v;
bool isPerfectSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll k = v.size() == 0 ? 1 : v[v.size()-1] + 1;
		for(ll i = k; i < n + 1; i++){
			if(isPerfectSquare(2*i+1))
			{
				ll a = sqrt(2*i+1);
				ll c = a*a - i;
				if(c > 1e9)
					break;
				v.push_back(c);
			}
		}
		auto x = upper_bound(v.begin(), v.end(), n);
		cout << x - v.begin() << endl;
	}	
	return 0;
}
