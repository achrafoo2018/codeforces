#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string n; 
		cin >> n;
		vector<int> diff;
		for(int i=0; i < 30; i++){
			string p = to_string(pow(2, i));
			int lp = p.size();
			int ln = n.size();
			int dif = 0, j = 0;
			bool k = false;
			while(j < lp && j < ln){
				if(p[j] != n[j]){
					if(k)
						dif += (ln-j) + 1;
					else{
						dif += 1;
						k = true;
					}	
				}
			}
		}
	}	
	return 0;
}
