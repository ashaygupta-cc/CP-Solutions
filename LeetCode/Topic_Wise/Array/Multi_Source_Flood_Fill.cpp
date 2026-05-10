class Solution {
public:
    #define ll long long
    const ll INF = 1e18;

    vector<vector<int>> colorGrid(int n,int m,vector<vector<int>>& sources){
        
        int X = sources.size();

        vector<vector<ll>>g(n,vector<ll>(m,0));
        vector<vector<ll>>dist(n,vector<ll>(m,INF));

        for(int i = 0; i < X; i++){
            auto v = sources[i];
            g[v[0]][v[1]] = v[2];
            dist[v[0]][v[1]] = 0;
        }

        vector<vector<int>>dir = {{0,1},{0,-1},{-1,0},{1,0}};

        priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>
        >pq;

        for(int i = 0; i < X; i++){
            auto v = sources[i];
            pq.push({0,v[0],v[1]});
        }

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();

            ll d = get<0>(x);
            int r = get<1>(x);
            int c = get<2>(x);

            if(d > dist[r][c]) continue;

            for(auto dxy : dir){
                int nr = r+dxy[0];
                int nc = c+dxy[1];

                if (nr < 0 || nc < 0 || nr > n-1 || nc > m-1) continue;

                if(dist[nr][nc] > d+1){
                    dist[nr][nc] = d+1;
                    g[nr][nc] = g[r][c]; 
                    pq.push({dist[nr][nc],nr,nc});
                }
                else if(dist[nr][nc] == d+1 && g[r][c] > g[nr][nc]){
                    g[nr][nc] = g[r][c];
                }
            }
        }

        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = (int)g[i][j];
            }
        }

        return ans;
    }
};