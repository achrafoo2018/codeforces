#include <bits/stdc++.h>
#include <unistd.h>
#include <math.h>

using namespace std;
int main(){
	long long n, p = (long long) pow(2, 68) + 1;
	n = p;
	while(true){
		if(n % 2 != 0){
			n = n * 3 + 1;
		}else{
			n = n / 2;
		}
		if(n == 4){
			cout << p << " is a bitch" << endl;
			p++;
			n = p;
		}	
	}
	return 0;
}

