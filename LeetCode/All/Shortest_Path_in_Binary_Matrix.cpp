class Solution {
public:
    int N,M;

    bool isvalidIdx(int i,int j){
        if(i >= 0 && i < N && j < M && j >= 0) return true;
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        N = n;
        M = m;

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        vector<vector<int>>dirs({{0,1},{1,1},{1,0},{1,-1},{-1,-1},{-1,1},{-1,0},{0,-1}});

        dist[0][0] = 1;
        q.push({0,0});

        while(!q.empty()){
           
            auto p = q.front(); 
            q.pop();

            int x = p.first;
            int y = p.second;

            if(x == n-1 && y == m-1) return dist[x][y];
            
            for(auto &d : dirs){
                int nx = x+d[0];
                int ny = y+d[1];
                if(isvalidIdx(nx,ny) && grid[nx][ny] == 0 && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    return -1;

    }
};