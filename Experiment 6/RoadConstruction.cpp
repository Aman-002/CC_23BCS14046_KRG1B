#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> parent(1e6,0);
vector<ll> Size(1e6,1);

int find(ll a){
    if(parent[a]==a)return a;
    return parent[a] = find(parent[a]);
}

bool Union(ll a, ll b,ll &c){
    ll pa = find(a);
    ll pb = find(b);
    if(pa!=pb){
        if(Size[pa]<Size[pb])swap(pa,pb);
        parent[pb] = pa;
        Size[pa]+=Size[pb];
        c = max(c,Size[pa]);
        return true;
    }
    return false;
}

int main(){
    ll n,m;cin>>n>>m;
    for(ll i=0;i<n;i++)parent[i] = i;
    ll cmp = n;
    ll lcmp = 1;
    vector<pair<int,pair<int,int>>> edges;
    for(ll i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(auto &e:edges){
        if(Union(e.second.first,e.second.second,lcmp))cmp--;
        // if(lcmp==cmp)cout<<"NONE\n";
        cout<<cmp<<" "<<lcmp<<endl;
        
    }
}