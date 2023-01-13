#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int res=0;
	while(n--){
		int tot = 0;
		for(int i=0; i < 3;i++){
			int k;
			cin >> k;
			tot += k;
		}
		if (tot > 1)
			res += 1;
	}	
	cout << res << endl;
	return 0;
}
