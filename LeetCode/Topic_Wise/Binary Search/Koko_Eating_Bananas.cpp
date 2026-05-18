class Solution {
public:
    int max_ele(vector<int>&piles){
        int maxi=piles[0];
        for(int i=1;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    int calculateT_hrs(vector<int>&piles,int hourly){
        int total_hrs=0;
        for(int i=0;i<piles.size();i++){
            total_hrs += (piles[i]+hourly-1)/hourly;
            if(total_hrs>1e9) break;
        }
        return total_hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1 , high=max_ele(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            int total_hrs=calculateT_hrs(piles,mid);
            if(total_hrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};