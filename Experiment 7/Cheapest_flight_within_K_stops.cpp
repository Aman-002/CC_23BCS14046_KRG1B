#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto a : flights){
            int u = a[0];
            int v = a[1];
            int d = a[2];
            adj[u].push_back({v,d});
        } 
        vector<int> vis(n,0);
        vector<int> dist(n,1e9);
        vector<int> kdist(n,1e9);
        queue<pair<pair<int,int>,int>> q;
        q.push({{src,0},0});
        while(!q.empty()){
            auto [u,d] = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(u==dst && lev-1 <= k){
                kdist[u] = min(kdist[u],d);
            }
            for(auto [v,w] : adj[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    dist[v] = d+w;
                    q.push({{v,d+w},lev+1});
                }else{
                    if(dist[v] > d+w){
                        dist[v] = d+w;
                        q.push({{v,d+w},lev+1});
                    }
                }
            }
        }

        return kdist[dst]==1e9?-1:kdist[dst];
    }
};