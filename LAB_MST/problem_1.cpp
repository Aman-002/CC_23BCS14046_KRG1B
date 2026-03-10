#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll x,vector<pair<ll,ll>>& arr){
    for(auto &[m,a] : arr){
        if(x<m)return false;
        x-=a;
    }
    if(x<0)return false;
    return true;
}
int main(){
    int n; cin >> n;
    vector<pair<ll,ll>> arr(n);
    ll maxi = 0;
    for(ll i=0;i<n;i++){
        ll a,m;cin>>a>>m;
        maxi = max(maxi,m);
        arr[i].first = m;
        arr[i].second = a;
    }
    sort(arr.rbegin(),arr.rend());
    ll l=maxi,r=1e9;
    while(l<=r){
        ll mid = l+(r-l)/2;
        if(check(mid,arr)){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<l<<endl;
}