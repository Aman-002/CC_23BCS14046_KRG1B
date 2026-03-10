#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
 int n; cin >> n;
    vector<string> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }  

    vector<set<char>> v(n);

    for(ll i=0;i<n;i++){
        for(char c : arr[i]){
            v[i].insert(c);
        }
    }

    ll maxi = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j)continue;
            bool ok = true;
            for(char c : v[i]){
                if(v[j].count(c)){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ll k =arr[i].length()*arr[j].length();
                maxi = max(maxi,k);
            }
        }
    }

    cout<<maxi<<endl;
}
int main(){
    ll t=3;
    while(t--){
        solve();
    }
}