class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));

        for(auto &w : walls) grid[w[0]][w[1]] = -1;
        for(auto &g : guards) grid[g[0]][g[1]] = 2;

        auto guard = [&](int x, int y, int dx, int dy){
            int i = x + dx,j = y + dy;
        
        while(i >= 0 && i < m && j >= 0 && j < n){
            if(grid[i][j] == -1 || grid[i][j] == 2) break; 
            
            if(grid[i][j] == 0) grid[i][j] = 1; 
            
            i += dx; 
            j += dy;
            }
        };

        for(auto &g : guards){
            guard(g[0],g[1],-1,0); 
            guard(g[0],g[1],1,0);  
            guard(g[0],g[1],0,-1); 
            guard(g[0],g[1],0,1);  
        }

        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0) ans++;

        return ans;
    }
};