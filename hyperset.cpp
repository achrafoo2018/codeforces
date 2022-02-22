#include <bits/stdc++.h>
#define ll long long
using namespace std;
string tab[1500];
set<string> sett;
set<set<string>> result;

string getThirdString(string s1, string s2, int k){
	string res = "";
	for(int i=0; i < k; i++){
		if(s1[i] == s2[i])
			res += s1[i];
		else{
			if(s1[i] == 'S'){
				if(s2[i] == 'E')
					res += 'T';
				else
					res += 'E';
			}
			else if(s1[i] == 'E'){
				if(s2[i] == 'S')
					res += 'T';
				else
					res += 'S';
			}
			else{
				if(s2[i] == 'S')
					res += 'E';
				else
					res += 'S';
			}
		}
	}
	return res;
}
int main(){
	int n, k;
	cin >> n >> k;
	for(int i=0; i < n; i++){
		string card;
		cin >> card;
		tab[i] = card;
		sett.insert(card);
	}
	for(int i=0; i < n-1; i++){
		for(int j=i+1; j < n; j++){
			string res = getThirdString(tab[i], tab[j], k);
			if(sett.find(res) != sett.end()){
				set<string> r;
				r.insert(tab[i]);
				r.insert(tab[j]);
				r.insert(res);
				result.insert(r);
			}
		}
	}
	cout << result.size() << endl;
	return 0;
}
