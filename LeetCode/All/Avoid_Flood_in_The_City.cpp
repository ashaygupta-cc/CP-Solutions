class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>result(n,-1);
        set<long long>dry;
        unordered_map<long long,int>lastRain;

      for(int i = 0;i < n; i++){
        if(rains[i]){
           if(lastRain.count(rains[i])){
                    auto it = dry.upper_bound(lastRain[rains[i]]);
                    if(it == dry.end()) return {}; 
                    result[*it] = rains[i];  
                    dry.erase(it);
            }
            lastRain[rains[i]] = i;
         }
        else dry.insert(i);
      }
    
    for(auto &a : dry){
        result[a] = 1;
    }

     return result;
    }
};