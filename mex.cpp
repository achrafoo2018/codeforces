#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int res = 0;
		int i = 0;
		while(i < n){
			if(a[i] != b[i])
				res += 2;
			else{
				if(a[i] == '0'){
					if(i+1 == n)
						res++;
					else{
						if(a[i+1] != b[i+1]){
							res += 3;
							i++;
						}else{
							if(a[i+1] == '1'){
								res += 2;
								i++;
							}else
								res++;
						}
					}
				}else{
					while(i < n && a[i] == b[i] && a[i] == '1'){
						i++;
					}
					if(i < n)
						res += 2;
				}
			}
			i++;
		}
		cout << res << endl;
	}	
	return 0;
}
