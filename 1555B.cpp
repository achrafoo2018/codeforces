#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int w, h;
		cin >> w >> h;
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// second table
		int w2, h2;
		cin >> w2 >> h2;
		if(y2-y1+h2 > h && x2-x1+w2 > w)
			cout << -1 << endl;		
		else{
			
		}
	}	
	return 0;
}
