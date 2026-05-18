class Solution {
public:
    #define ll long long

    struct DSU{
        vector<ll>par,sz;

        DSU(int n){
            par.resize(n+1);
            sz.resize(n+1,1);
            for(int i = 1; i <= n; i++) par[i] = i;
        }

        ll find(ll u){
            if(par[u] == u) return u;
            return par[u] = find(par[u]);
        }

        void unite(ll u,ll v){
            u = find(u);
            v = find(v);

            if(u != v){
                if(sz[u] < sz[v]) swap(u,v);
                par[v] = u;
                sz[u] += sz[v];
            }
        }
    };

    int removeStones(vector<vector<int>>& stones){
        int n = stones.size();
        if(n == 0) return 0;

        unordered_map<ll,vector<ll>>mp;

        for(int i = 0; i < n; i++){
            mp[stones[i][0]].push_back(i+1);
            mp[stones[i][1]+100001].push_back(i+1); 
        }

        DSU dsu(n);

        for(auto &[k,v] : mp){
            for(int i = 1; i < v.size(); i++){
                dsu.unite(v[0],v[i]);
            }
        }

        set<ll>s;
        for(int i = 1; i <= n; i++){
            s.insert(dsu.find(i));
        }

        return n - s.size();
    }
};