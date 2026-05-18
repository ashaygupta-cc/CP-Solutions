class Solution {
public:
    #define ll long long
    vector<vector<vector<ll>>>dp;
    // vector<vector<vector<bool>>>vis;
    
    int n,m;
    
    ll rec(int i,int j,int picked,int k,vector<int>&nums1,vector<int>&nums2){
      if(picked == k) return 0;
      if(i == n || j == m) return -1e18;
      if((m-j < k-picked) || (n-i < k-picked)) return -1e18; 

      if(dp[i][j][picked] != -1e18) return dp[i][j][picked];

      ll maxi = -1e18;

      maxi = max(maxi,rec(i+1,j,picked,k,nums1,nums2));

      maxi = max(maxi,rec(i,j+1,picked,k,nums1,nums2));

      ll onTake = (1LL*nums1[i]*nums2[j]);
      ll next = rec(i+1,j+1,picked+1,k,nums1,nums2);

     if(next != -1e18) maxi = max(maxi,next+onTake);

     // vis[i][j][picked] = true;
     return dp[i][j][picked] = maxi;
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

         n = nums1.size();
         m = nums2.size();
        dp.assign(n,vector<vector<ll>>(m,vector<ll>(k+1,-1e18)));
        // vis.assign(n,vector<vector<bool>>(m,vector<bool>(k+1,0)));
        
    return rec(0,0,0,k,nums1,nums2);

    }
};