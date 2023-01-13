#include "bits/stdc++.h"
/***************************************************/
/***************************************************/
/******************* 3ak3ek ************************/
/***************************************************/
/***************************************************/
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
 
#define fastio ios_base::sync_with_stdio(false)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; i++)

const int _N = 1024;

int sup(int x1, int x2, int x3, int x4){
	return max(max(x1, x2), max(x3, x4));
}
int maximum(int T[_N][_N], int a, int b, int N){
	if(N == 2)
		return sup(T[a][b], T[a][b+1], T[a+1][b], T[a+1][b+1]);
	int x1 = maximum(T, a, b, N / 2);
	int x2 = maximum(T, a, b+(N/2), N / 2);
	int x3 = maximum(T, a+(N/2), b, N/2);
	int x4 = maximum(T, a+(N/2), b+(N/2), N/2);
	return sup(x1, x2, x3, x4);
}
int maxIterative(int T[_N][_N]){
	int ans = -1;
	For(i, _N)
		For(j, _N)
			ans = max(ans, T[i][j]);
	return ans;
}

void solve(){
	srand (time(NULL));
	int v[_N][_N];
	For(i, _N)
		For(j, _N)
			v[i][j] = rand() % 100078870 + 1 ;
	cout << "Max = " << maximum(v, 0, 0, _N) << endl;
	cout << "MaxIterative = " << maximum(v, 0, 0, _N) << endl;
}

int main(){
	fastio;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
