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
// vector<ll> sieve(ll n){vector<ll > p(n+1,1);p[0] = 0;p[1] = 0;for(ll i=2;i*i<=n;i++){if(p[i]){for(ll j=i*i;j<=n;j+=i)p[j] = 0;}}return p;}

// struct phash{
//   size_t operator()(const pair<ll,ll> &p) const{
//     return hash<ll>()(
//       (p.first)^(p.second)
//     );
//   }
// };
void solve(){
  ll n;cin>>n;
  vector<string> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  vector<vector<ll>> g(26);
  vector<ll> indeg(26,0);
  for(ll i=1;i<n;i++){
    string p = a[i-1];
    string c = a[i];
    ll len = min(p.length(),c.length());
    ll dif = -1;
    for(ll j=0;j<len;j++){
      if(p[j]!=c[j]){
        dif = j;
        break;
      }
    }
    if(dif == -1 && p.length()<=c.length())continue;
    else if(dif == -1){
      cout<<"Impossible\n";return;
    }
    g[p[dif]-'a'].pb(c[dif]-'a');
    indeg[c[dif]-'a']++;
  }
  
  queue<ll> q;
  for(ll i=0;i<26;i++){
    if(indeg[i]==0)q.push(i);
  }
  vector<ll> res;
  while(!q.empty()){
    ll top = q.front();
    q.pop();
    res.pb(top);
    for(ll nei : g[top]){
      indeg[nei]--;
      if(indeg[nei]==0){
        q.push(nei);
      }
    }
  }
  
  if(res.size()!=26){
    cout<<"Impossible\n";return;
  }

  for(ll e : res)cout<<char(e+'a');
  cout<<endl;
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

































