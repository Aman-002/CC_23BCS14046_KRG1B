#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define yes "YES\n";
#define no "NO\n";
#define ppb pop_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define Truncated_man ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using ll = long long;
// vector<ll> pse(vector<ll>& arr){ll n=arr.size();vector<ll> res(n,-1);stack<ll> s;for(ll i=0;i<n;i++){while(!s.empty() && arr[s.top()]>=arr[i]){s.pop();}if(!s.empty()){res[i]=s.top();}s.push(i);}return res;}
// vector<ll> nse(vector<ll>& arr){ll n=arr.size();vector<ll> res(n,-1);stack<ll> s;for(ll i=n-1;i>=0;i--){while(!s.empty() && arr[s.top()]>=arr[i]){s.pop();}if(!s.empty()){res[i]=s.top();}s.push(i);}return res;}  
// vector<ll> P;
// vector<ll> Pm;
// vector<ll> sieve(ll n){vector<ll > p(n+1,1);p[0] = 0;p[1] = 0;for(ll i=2;i<=n;i++){if(p[i]){Pm.pb(i);for(ll j=i*i;j<=n;j+=i)p[j] = 0;}}return p;}

// struct phash{
//   size_t operator()(const pair<ll,ll> &p) const{
//     return hash<ll>()(
//       (p.first)^(p.second)
//     );
//   }
// };

void solve(){
  ll n,m;cin>>n>>m;
  set<string> mp;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    mp.insert(s);
  }
  while(m--){
    string s;cin>>s;
    int len = s.length();
    bool ok = false;
    for(int i=0;i<len;i++){
      char ch = s[i];
      s[i] = 'a';
      if(ch!='a' && mp.count(s)){cout<<yes;ok = true;break;}
      s[i] = 'b';
      if(ch!='b' && mp.count(s)){cout<<yes;ok = true;break;}
      s[i] = 'c';
      if(ch!='c' && mp.count(s)){cout<<yes;ok = true;break;}
      s[i] = ch;
    }
    if(!ok)
      cout<<no;
  }
//end of solve
}

int main(){
    Truncated_man;
    // P = sieve(1e6);
    ll t=1;
    // cin>>t;
    while(t--){
      solve();
    }
    // solve();
    return 0;
}

































