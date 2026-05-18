class Solution {
public:
    vector<long long> findXSum(vector<int>& nums,int k,int x){
        
        unordered_map<int,int>freq;
        multiset<pair<int,int>>top,bottom;
        long long top_sum = 0;
        
        auto get_key = [&](int num){
            return make_pair(freq[num],num);
        };
        
        auto add_to_top = [&](int num){
            top.insert(get_key(num));
            top_sum += (long long)freq[num] * num;
        };
        
        auto remove_from_top = [&](int num){
            top.erase(get_key(num));
            top_sum -= (long long)freq[num] * num;
        };
        
        auto add_to_bottom = [&](int num){
            bottom.insert(get_key(num));
        };
        
        auto remove_from_bottom = [&](int num){
            bottom.erase(get_key(num));
        };
        
        auto balance = [&]() {
            while(top.size() > x){
                auto key = *top.begin();
                top.erase(top.begin());
                top_sum -= (long long)key.first * key.second;
                bottom.insert(key);
            }

            while(top.size() < x && !bottom.empty()){
                auto key = *prev(bottom.end());
                bottom.erase(prev(bottom.end()));
                top.insert(key);
                top_sum += (long long)key.first * key.second;
            }

            while(!bottom.empty() && !top.empty() && *prev(bottom.end()) > *top.begin()){
                auto bot_key = *prev(bottom.end());
                auto top_key = *top.begin();
                bottom.erase(prev(bottom.end()));
                top.erase(top.begin());
                top_sum = top_sum - (long long)top_key.first * top_key.second + (long long)bot_key.first * bot_key.second;
                top.insert(bot_key);
                bottom.insert(top_key);
            }
        };
        
        auto add_num = [&](int num) {
            if(freq.find(num) != freq.end()){
                auto old_key = get_key(num);

                if(top.find(old_key) != top.end()){
                    remove_from_top(num);
                    freq[num]++;
                    add_to_top(num);
                } 
                else{
                    remove_from_bottom(num);
                    freq[num]++;
                    add_to_bottom(num);
                }
            } 
            else{
                freq[num] = 1;
                add_to_bottom(num);
            }
            balance();
        };
        
        auto remove_num = [&](int num){
            auto old_key = get_key(num);
            
            if(top.find(old_key) != top.end()){
                remove_from_top(num);
                freq[num]--;
                if(freq[num]){
                    add_to_top(num);
                } 
                else{
                    freq.erase(num);
                }
            } 
            else{
                remove_from_bottom(num);
                freq[num]--;
                if(freq[num]){
                    add_to_bottom(num);
                } 
                else{
                    freq.erase(num);
                }
            }
            balance();
        };
        
        vector<long long>result;
        
        for(int i = 0; i < nums.size(); i++){
            add_num(nums[i]);
            
            if(i >= k){
                remove_num(nums[i-k]);
            }
            
            if(i >= k-1){
                result.push_back(top_sum);
            }
        }      
        return result;
    }
};