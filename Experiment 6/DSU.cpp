#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class DSU{
vector<ll> parent;
vector<ll> rank;
DSU(ll n){
    parent = vector<ll>(n);
    rank = vector<ll>(n,0);
    for(ll i=0;i<n;i++)parent[i] = i;
}
int find(ll a){
    if(parent[a]==a)return a;
    return parent[a] = find(parent[a]);
}

void Union(ll a, ll b){
    ll pa = find(a);
    ll pb = find(b);
    if(pa!=pb){
        if(rank[pa]<rank[pb])swap(pa,pb);
        parent[pb] = pa;
        if(rank[pa]==rank[pb])rank[pa]++;
    }
}
};