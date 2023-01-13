#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define MP make_pair
#define PB push_back
#define ll long long
#define FOR(x,n) for(int (i)=(x);(i)<(n);(i)++)

#include <bits/stdc++.h>
using namespace std;
int t,p;
ll x;
bool ok;
int main(){
    cin>>t;
    while(t--){
        cin>>x;
        p=0;
        if(x%25==0)
            cout<<0<<endl;
        else{
            ok=false;
            while(x%10!=5 && x%10!=0){
                x=x/10;
                p++;
            }
            if((x%10)==0){
                x=x/10;
                do{
                    if(x%10==5 || x%10==0)
                        ok=true;
                    else{
                        p++;
                        x=x/10;
                        if(x%25==0){
                            p++;
                            break;
                        }
                    }
                }while(ok==false);
            }
            else if((x%10)==5){
                x=x/10;
                do{
                    if(x%10==2 || x%10==7)
                        ok=true;
                    else{
                        p++;
                        x=x/10;
                        if(x%25==0){
                            p++;
                            break;
                        }
                    }
                }while(ok==false);
            }


            cout<<p<<endl;
    }
    }
}
