class Solution {
public:
    #define ll long long
    
    long long minIncrease(vector<int>& nums) {

        ll n = nums.size();

        if(n == 4){
            ll op1 = 0,op2 = 0;

            ll maxi = max(nums[0],nums[2]);
            if(maxi >= nums[1]) op1 += (maxi-nums[1]+1);

            maxi = max(nums[1],nums[3]);
            if(maxi >= nums[2]) op2 += (maxi-nums[2]+1);

            return min(op1,op2);
        }
        
        if(n % 2){
            ll count = 0;
            for(int i = 1; i < n-1; i += 2){
                ll maxi = max(nums[i-1],nums[i+1]);
                if(maxi >= nums[i]){
                    count += (maxi-nums[i]+1);
                }      
            }
            return count;
        }

        vector<ll>pref(n-1,0);
        ll totEve = 0;
        ll totOddi = 0;
    
        for(int i = 1; i < n-1; i++){
            ll maxi = max(nums[i-1],nums[i+1]);
            if(maxi >= nums[i]){
                pref[i] = (maxi-nums[i]+1);
            }
            if(i % 2){
                totEve += pref[i];
            }
            else{
                totOddi += pref[i];
            }
        }  

        ll count = min(totOddi,totEve);
        ll tempOd = 0;
        ll tempEv = 0;
        
        for(int i = 1; i < n-1; i += 2){
            tempOd += pref[i];
            if(i+1 < n-1) tempEv += pref[i+1];
            
            count = min(count,max(0LL,totOddi-tempEv+tempOd));
        }      
        return count;  
    }
};
