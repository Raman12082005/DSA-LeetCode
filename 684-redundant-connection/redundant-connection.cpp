class Solution {
public:
    class DisjointSet{
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.assign(n+1, 1);

            for(int i=1; i<=n; i++){
                parent[i] = i;
            }
        }
        int findUpar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUpar(parent[node]);
        }
        bool UnionBySize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);

            if(ulp_u == ulp_v) return true;

            if(size[ulp_u] < size[ulp_v]) swap(ulp_u, ulp_v);

            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
            return false;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        vector<int> last;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            if(ds.UnionBySize(u, v)){
                last  = it;
            }
        }
        return last;
    }
};