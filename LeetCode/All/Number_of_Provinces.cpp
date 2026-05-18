class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected){
        
        int count = 0;
        int n = isConnected.size();

        vector<vector<int>> adj(n,vector<int>());
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j != i && isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        queue<int> q;
        
        for(int i = 0; i < n; i++){
           if(!visited[i]){
            q.push(i);
            visited[i] = true;
       
            while(!q.empty()){
                int s = q.front();
                q.pop();

                for(auto neighbour : adj[s]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }          
            }
            count++;
           }
        }
        return count;
    }
};
