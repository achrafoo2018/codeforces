#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool v[100000];
int main(){
	memset(v, false, sizeof v);
	int n;
	cin >> n;
	int target = n;
	for(int i=0; i < n; i++){
		int k;
		cin >> k;
		v[k] = true;
		while(v[k] && k == target){
			cout << k << " ";
			k--;
			target--;
		}
		cout << endl;
	}
	return 0;
}
