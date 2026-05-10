class Solution {
public:
    #define ll long long

    vector<int>par,sz;

    int findp(int x){
        if(par[x] == x) return x;
        return par[x] = findp(par[x]);
    }

    void unite(int a,int b){
        a = findp(a);
        b = findp(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps){

        int n = source.size();
        int x = allowedSwaps.size();

        par.resize(n);
        sz.resize(n,1);

        for(int i = 0; i < n; i++) par[i] = i;

        for(int i = 0; i < x; i++){
            unite(allowedSwaps[i][0],allowedSwaps[i][1]);
        }
        unordered_map<int,vector<int>>comp;

        for(int i = 0; i < n; i++){           comp[findp(i)].push_back(i);
        }

        int ans = 0;

        for(auto &it : comp){

        unordered_map<int,int>freq;

            for(auto idx : it.second){
                freq[source[idx]]++;
            }

            for(auto idx : it.second){
                if(freq[target[idx]] > 0) freq[target[idx]]--;
                else ans++;
            }
        }

        return ans;
    }
};