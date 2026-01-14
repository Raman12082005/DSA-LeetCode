class Solution {
public:
    class DisjointSet{
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUpar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUpar(parent[node]); // path compression
        }

        bool UnionBySize(int u, int v){
            int pu = findUpar(u);
            int pv = findUpar(v);

            if(pu == pv) return false;  // cycle found (redundant edge)

            if(size[pu] < size[pv]) swap(pu, pv);

            parent[pv] = pu;
            size[pu] += size[pv];
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto &e : edges){
            int u = e[0], v = e[1];
            if(!ds.UnionBySize(u, v)){
                return e;  // first edge that forms a cycle
            }
        }
        return {};
    }
};
