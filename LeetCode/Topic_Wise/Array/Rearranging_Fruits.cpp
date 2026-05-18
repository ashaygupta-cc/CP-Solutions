class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<long long,long long>freq;
        long long mini = LLONG_MAX;
        for(int i = 0; i < basket1.size(); i++){
            freq[basket1[i]]++;
        }
        for(int i = 0; i < basket2.size(); i++){
            freq[basket2[i]]++;
        }
        for(auto &[fruit,count]:freq){
            if(count % 2 !=0) return -1;
            mini = min(mini,fruit);
        }

        vector<long long>tobeSwapped;
        map<long long,long long>counter;
        for(int i = 0;i<basket1.size();i++){
            counter[basket1[i]]++;
        }
        for(auto &[fruit,total] : freq){
            long long toSwap = abs((total/2)-counter[fruit]);
            for(int i = 0;i < toSwap; i++){
                tobeSwapped.push_back(fruit);
            }
        }
        sort(tobeSwapped.begin(),tobeSwapped.end());

        long long total_cost = 0;
        for(int i = 0; i < tobeSwapped.size()/2; i++){
            total_cost += min(tobeSwapped[i],2*mini);
        }
        return total_cost;
        }
};