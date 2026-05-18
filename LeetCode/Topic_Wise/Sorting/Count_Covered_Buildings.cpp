class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings){
        
        int m = buildings.size();
             unordered_map<int,vector<int>>row,col;

        for(auto &b : buildings){
            int x = b[0],y = b[1];
            row[x].push_back(y);
            col[y].push_back(x);
        }

        for(auto &p : row) sort(p.second.begin(),p.second.end());
        for(auto &p : col) sort(p.second.begin(),p.second.end());

        int covered = 0;

        for(auto &b : buildings){
            int x = b[0],y = b[1];
            auto &r = row[x]; 
            auto &c = col[y]; 

            auto it = lower_bound(r.begin(),r.end(),y);
            bool left  = (it != r.begin());
            int idx = it-r.begin();
bool right = (idx+1 < r.size());

            auto it2 = lower_bound(c.begin(),c.end(),x);
            bool up = (it2 != c.begin());
            int idx2 = it2-c.begin();
bool down = (idx2+1 < c.size());

            if(left && right && up && down)
                covered++;
        }

        return covered;
    }
};