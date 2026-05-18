class Solution{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>visP(n, vector<int>(m, 0));
        vector<vector<int>>visA(n, vector<int>(m, 0));

        queue<pair<int,int>> pq,aq;
        for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                if(i == 0){
                    pq.push({i,j});
                }
                if(j == 0){
                    pq.push({i,j});
                    visP[i][j] = 1;
                }
                if(i == n - 1){
                    aq.push({i,j});
                }
                if(j == m - 1){
                    aq.push({i,j});
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!pq.empty()){
            int row = pq.front().first;
            int col = pq.front().second;
            pq.pop();
            visP[row][col] = 1;

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visP[nrow][ncol] &&
                    heights[nrow][ncol] >= heights[row][col]){
                        pq.push({nrow,ncol});
                }
            }
        }
        while(!aq.empty()){
            int row = aq.front().first;
            int col = aq.front().second;
            aq.pop();
            visA[row][col] = 1;

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visA[nrow][ncol] &&
                    heights[nrow][ncol] >= heights[row][col]){
                        aq.push({nrow, ncol});
                }
            }
        }

        vector<vector<int>> result;
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                if(visP[i][j] == 1 && visA[i][j] == 1) 
                    result.push_back({i, j});
        
        return result;
    }
};