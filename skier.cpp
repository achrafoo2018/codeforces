#include <bits/stdc++.h>
#define ll long long
using namespace std;
set< vector < pair<int, int> > > visted;
map<char, pair<int, int>> pairs;
void declarePairs(){
	pairs['N'] = pair<int, int>(0, 1);
	pairs['E'] = pair<int, int>(1, 0);
	pairs['S'] = pair<int, int>(0, -1);
	pairs['W'] = pair<int, int>(-1, 0);
}
int main(){
	declarePairs();
	int t;
	cin >> t;
	while(t--){
		string s;
		pair<int, int> pos(0, 0);
		visted.clear();
		int res = 0;
		cin >> s;
		for(int i=0; i < s.size(); i++){
			vector<pair<int, int>> v;
			v.push_back(pos);
			pair<int, int> newPos(pos.first+pairs[s[i]].first, pos.second+pairs[s[i]].second);
			v.push_back(newPos);
			sort(v.begin(), v.end());
			if(visted.find(v) != visted.end())
				res += 1;
			else{
				visted.insert(v);
				res += 5;
			}
			pos = newPos;
		}
		cout << res << endl;
	}	

	return 0;
}
