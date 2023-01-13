#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	map<string, int> requests;
	while(n--){
		string request;
		cin >> request;
		if(requests.find(request) != requests.end()){
			cout << request << requests[request] << endl;
			requests[request]++;
		}
		else{
			cout << "OK" << endl;
			requests[request] = 1;
		}
	}
	return 0;
}
