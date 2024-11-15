#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // long long n;cin>>n;
    // float s=0.2;
    // if(n==1){
    //     cout<<"0.200000";
    //     return 0;
    // }
    // s*=(n-1);
    // for(int i=2;i<=n;i++){
    //     long long k = pow(i,2);
    //     cout<<(float) k/(4*k+1) <<endl; 
    //     s -= (float) k/(4*k+1); 
    // }
    long long n;cin>>n;
    float s=0.2;
    if(n==1){cout<<"0.200000";
    return 0;}
    for(int i=3;i<=2*n-1;i+=2){
        s -= (float) i/(4 + pow(i,4));
    }
    cout<<fixed<<setprecision(6)<<s;
    return 0;

}