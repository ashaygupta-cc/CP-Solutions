class Solution{
public:
    vector<vector<int>>highestPeak(vector<vector<int>>& isWater){
        int m = isWater.size();
        int n = isWater[0].size();
        
        // Initialize the height matrix with -1 for land cells
        vector<vector<int>> height(m,vector<int>(n,-1));
        
        // stores (height, x, y)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;
        
        // Push all water cells with height 0 into the pq
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    pq.push({0, i, j});  // (height, x, y)
                }
            }
        }
        
        // Directions (up, down, left, right)
        vector<pair<int, int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!pq.empty()){
            auto [h, x, y] = pq.top();
            pq.pop();
            
            // Check all 4 possible adjacent cells
             for(auto& dir : directions){
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1){
            // Set the height for the neighboring cell
                    height[nx][ny] = h + 1;
                    pq.push({h + 1, nx, ny});
                }
            }
        }  
        return height;
    }
};
