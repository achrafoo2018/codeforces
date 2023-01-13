#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int i, j, k;
		if(s.size() == 1 && s[0] == 'a'){
			cout << "YES" << endl;
			continue;
		}
		if(int(s[0]) > int(s[s.size()-1])){
			k = int(s[0]);
			i = 1;
			j = s.size() -1;
		}else if (int(s[0]) < int(s[s.size()-1])) {
			i = 0;
			j = s.size() - 2;
			k = int(s[s.size() - 1]);
		}else{
			cout << "NO" << endl;
			continue;
		}
		while(i < j){
			if(int(s[i]) == k-1){
				i++;
				k--;
			}else if(int(s[j]) == k-1){
				j--;
				k--;
			}else{
				break;
			}
		}
		if( i == j && s[i] == 'a' && int('a') == k-1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
