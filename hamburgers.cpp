#include "bits/stdc++.h"
/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠏⢀⣀⣤⣤⣤⣤⣤⣤⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⣿⣿⣿⣿⡿⣿⣴⢶⣶⣿⣟⣶⣿⣭⠿⠦⠤⠽⣷⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⣿⣿⡿⢫⣿⢋⣠⣿⣿⡶⢻⡏⠄⠄⠄⠄⠄⠄⠄⠉⠙⢦⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⡿⠋⠈⣸⣿⣿⣿⡿⠿⠄⠈⠃⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⢯⠋⠈⠄⣴⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠸⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠒⠄⠄⢰⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢷⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢼⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⢀⡀⠤⠤⠤⣀⠄⢀⡀⠤⠤⠤⣀⣱⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢸⣿⣿⣿⣿⣿⠄⠄⠄⢀⡖⠁⠄⠄⠄⠄⠄⠱⡏⠄⠄⠄⠄⠈⠱⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠄⠄⠄⠄
⠄⠄⠄⠈⣿⣿⣿⣿⣿⡆⠄⠄⢸⠄⠄⠴⠆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠶⠄⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⢀⡴⠋⠉⢹⡶⠶⢤
⠄⠄⠄⠄⢸⣿⣿⣿⣿⣿⣸⢻⡜⡄⠄⠄⠄⠄⠄⠄⢀⠶⠒⠒⠄⠐⣄⡼⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣾⣿⣿⠟⠛⠓⠶⣏⠄⠄⣀
⠄⠄⠄⢸⢧⣿⣿⣿⣿⣿⡿⠄⠷⠙⠲⠄⠄⡀⠠⠔⠁⠄⠄⠄⢀⣠⡇⡧⠄⠄⠄⠄⠄⠄⠄⠄⠄⣴⣿⣿⣿⡇⠄⡀⠄⠄⠈⢦⠞⠁
⠄⠄⠄⢸⡈⢻⣿⣿⣿⡿⠧⣄⠄⠄⠄⢀⡴⠖⠒⠚⠛⠛⠛⠛⠉⠄⠈⠙⠦⣀⣠⣀⠄⠄⠄⠄⢰⣿⣿⣿⣿⠄⠄⠈⢢⡀⠠⢾⠄⠄
⠄⠄⠄⠄⣴⣾⣿⣿⣿⢲⡶⡄⠄⢀⡶⠋⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢁⠄⢸⠄⠄⠄⠄⣸⣿⣿⠟⠋⠄⠄⠄⡎⠄⠄⠈⠉⠄
⡀⠄⠄⠘⣿⣿⣿⣿⣿⣦⣤⡴⠄⣾⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢰⡷⢰⠃⠄⠄⣠⣾⣿⠟⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠
⠙⢦⡀⠄⠈⠛⢻⣿⣿⣿⣿⡇⠄⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢦⣀⣠⠎⢀⣤⣾⡿⠋⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠞⠄
⠄⠄⠈⠳⢄⠄⢸⣿⣿⣿⣿⡇⠄⠙⣆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡴⠃⠄⣠⣴⣿⠟⠋⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⡰⠁⠄⠄
⠄⠄⠄⠄⠈⠙⢾⣿⣿⣿⣿⡇⠄⠄⠈⠳⠤⣀⡀⠄⠄⢀⣀⠤⡖⠋⢀⡤⠾⠿⣏⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⠎⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢨⠇⠙⢿⠷⠖⠒⠛⠓⠒⠚⠛⠯⡉⠉⠄⠄⡷⠶⠯⡁⠄⠄⠄⠙⠢⡀⠄⠄⠄⠄⠄⠄⠄⠄⢀⠜⠁⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⢀⡌⠄⠄⠄⠳⡀⠄⠄⠄⠄⠄⡌⠄⠙⢆⠄⠄⡧⠂⠄⢡⠄⠄⠄⠄⠄⠈⠢⡀⠄⠄⠄⠄⢀⡔⠁⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⢀⠌⠄⠄⠄⠄⠄⠰⡀⠄⠄⠄⢰⠃⠄⠄⠈⠣⡴⠉⠡⡀⠈⡆⠄⠄⠄⠄⠄⠄⠘⠄⠄⢀⡴⠊⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⡠⠊⠄⠄⠄⠄⠄⠄⠄⢩⠉⠉⠉⠉⠄⠄⠄⠄⠄⠄⠄⠄⠱⡀⠁⠄⠄⠄⠄⠄⠄⠄⠈⣶⠊⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣷⣄⣠⠞⠁⠄⠄⠄⠄⠄⠄⠄⠄⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢡⠄⠄⠄⠄⠄⠄⠄⠄⢠⠎⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣎⡁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡆⠄⠄⠄⠄⢀⡠⠞⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⣿⣿⣶⣤⣀⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠠⢤⡤⠴⠒⠊⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠻⠿⢿⣿⣿⣿⣿⠏⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠢⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
*/
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
#define For(i, n) for(int i=0; i < n; ++i)

void solve(){
	string s;
	cin >> s;
	int nb, ns, nc;
	cin >> nb >> ns >> nc;
	int pb, ps, pc;
	cin >> pb >> ps >> pc;
	ll r;
	cin >> r;
	map<char, int> mp;
	for(auto i : s)
		mp[i]++;
	int rb, rs, rc;
	rb = nb % mp['B'];
	rs = ns % mp['S'];
	rc = nc % mp['C'];
	nb /= mp['B'];
	ns /= mp['S'];
	nc /= mp['C'];
	while(nb != ns != nc){
		if(nb = min(nb, min(ns, nc))){
			nb +=  (pb  * ((min(ns, nc)) - nb));
		}else if(ns = min(nb, min(ns, nc))){

		}else{

		}
	}
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	solve();
	return 0;
}
