#include <bits/stdc++.h>
using namespace std;
int main(){
	map<string, int> players;
	vector<pair<string, int> > v;
	int n, ma;
	cin >> n;
	for(int i=0; i < n; i++){
		string player;
		int score;
		cin >> player >> score;
		if(players.find(player) != players.end()){
			players[player] += score;
		}else{
			players[player] = score;
		}
		v.push_back(make_pair(player, players[player]));
	}
	ma=INT_MIN;
	for(auto it=players.begin(); it != players.end();it++){
		ma = max(ma, it->second);	
	}
	for(int i=0; i < n; i++){
		if(players[v[i].first] == ma && v[i].second >= ma){
				cout << v[i].first << endl;
				return 0;
		}
	}
	return 0;
}
