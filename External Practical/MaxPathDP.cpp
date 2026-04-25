#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll m,n;cin>>m>>n;
    vector<vector<ll>> dp(m,vector<ll>(n,1));
    for(ll i=1;i<m;i++){
        for(ll j=1;j<n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout<<dp[m-1][n-1]<<endl;
    return 0;
}