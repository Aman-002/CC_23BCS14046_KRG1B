// Kruskal's Algorithm to find the weight of the Minimum Spanning Tree (MST) of a given graph.
// GFG
class Solution {
  public:
    vector<int> p;
    vector<int> r;
    int find(int n){
        if(p[n]==n)return n;
        return p[n]=find(p[n]);
    }
    bool Union(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa!=pb){
            if(r[pa]<r[pb])swap(pa,pb);
            p[pb] = pa;
            if(r[pa]==r[pb])r[pa]++;
            return true;
        }
        return false;
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        p = vector<int>(V);
        r = vector<int>(V,0);
        for(int i=0;i<V;i++)p[i]=i;
        
        vector<pair<int,pair<int,int>>> g;
        for(auto rw : edges){
            g.push_back({rw[2],{rw[0],rw[1]}});
        }
        sort(g.begin(),g.end());
        int ans = 0;
        for(auto p : g){
            int w = p.first;
            int u = p.second.first;
            int v = p.second.second;
            if(Union(u,v))ans+=w;
        }
        
        return ans;
    }
};