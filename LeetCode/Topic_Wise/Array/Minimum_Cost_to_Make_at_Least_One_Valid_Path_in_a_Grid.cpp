class Solution {
public:
    int minCost(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> directionCost = {1, 2, 3, 4};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>pq;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()){
            auto [curCost, cell] = pq.top();
            pq.pop();
            
            int x = cell.first, y = cell.second;
            
            if(x == m - 1 && y == n - 1){
                return curCost;
            }
            
            for(int i = 0; i < 4; i++){
                int nx = x + directions[i].first;
                int ny = y + directions[i].second;
                
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int newCost = curCost + (grid[x][y] != directionCost[i]);
                    if(newCost < cost[nx][ny]){
                        cost[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};
