#include<bits/stdc++.h>

using namespace std;



long long solve (long long K, long long N) {
	if(K > N)
        	K = N;
    	return ((((N-1)*N) / 2) - (((N-K) * (N-K+1)) / 2) + 1) % 1000000007;
}



int main() {



    ios::sync_with_stdio(0);

    cin.tie(0);

    int T;

    cin >> T;

    for(int t_i=0; t_i<T; t_i++)

    {

        long long N;

        cin >> N;

        long long K;

        cin >> K;



        long long out_;

        out_ = solve(K, N);

        cout << out_;

        cout << "\n";

    }

}

