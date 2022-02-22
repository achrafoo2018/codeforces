#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e5+7;
using namespace std;
int main(){
	int t, i = 0;
	cin >> t;
	while(t--){
		map<int, int> m;
		set<pair<int, int>> s;
		int a[N];
		int n;
		cin >> n;
		for(int i=0; i < n; i++){
			cin >> a[i];
			m.insert(make_pair(a[i], i+1));
		}
		int res = 0;
		for(int i=0; i < n; i++){
			for(int j=1; a[i] * j <= n+i+1; j++){
				if(m.find(j) != m.end() && m[j] == a[i]*j-(i+1)){
					pair<int, int> p = make_pair(max(i+1, m[j]), min(m[j], i+1));
					if(s.find(p) == s.end()){
						res++;
						s.insert(p);
					}
				}
			}
		}
		cout << res << endl;
	}	
	return 0;
}
