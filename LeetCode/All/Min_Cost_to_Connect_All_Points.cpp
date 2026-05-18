class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        
        int n = points.size();
        int cost = 0;

        vector<bool>visited(n,false);

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,points[0][0],points[0][1]});
 
        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int c = get<0>(it);
            int x = get<1>(it);
            int y = get<2>(it);

            int idx = -1;
            for(int i = 0; i < n; i++){
                if(points[i][0] == x && points[i][1] == y){
                    idx = i;
                    break;
                }
            }

            if(visited[idx]) continue;
            visited[idx] = true;

            cost += c;

            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    int nx = points[i][0];
                    int ny = points[i][1];
                    int newCost = abs(x-nx)+abs(y-ny);
                    pq.push({newCost,nx,ny});
                }
            }
        }
        return cost;
    }
};
