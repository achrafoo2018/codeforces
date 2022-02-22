#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e3 + 7;
ll a[N];
ll b[N];
int n, k1, k2, k;
priority_queue<ll> p;
int main(){
	cin >> n >> k1 >> k2;
	k = k1 + k2;
	for(int i=0; i < n; i++)
		cin >> a[i];
	for(int i=0; i < n; i++)
		cin >> b[i];
	for(int i=0; i < n; i++)
		p.push(abs(a[i] - b[i]));
	while(k--){
		ll g = p.top();
		p.pop();
		g--;
		p.push(abs(g));
	}
	ll ans = 0;
	while(!p.empty()){
		ans += p.top() * p.top();
		p.pop();
	}
	cout << ans << endl;
	return 0;
}
