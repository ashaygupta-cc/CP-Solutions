class Solution {
public:
    #define ll long long
    int longestBalanced(string s) {

      int n = s.size();

      vector<ll>prefixSum(n+1,0);
      vector<ll>diffi(n+1,0);
    
     for(int i = 0; i < n; i++){
         if(s[i] == '1'){
             prefixSum[i+1] = 1;
         }
         diffi[i+1] = diffi[i]+((s[i] == '1') ? 1 : -1);        
     }

    for(int i = n-1; i >= 0; i--){
        prefixSum[i] = prefixSum[i+1]+prefixSum[i];
    }

    ll ones = prefixSum[0];
    ll zeros = n-ones;
    ll maxi = 0,cur = 0;

    set<ll>st;
    map<ll,vector<ll>>mp;
    
    st.insert(0);
    mp[0].push_back(0);
        
    for(int i = 0; i < n; i++){
        cur = s[i]-'0';
        ll x = diffi[i+1];

        if(st.find(x) != st.end()){
            maxi = max(maxi,i+1-mp[x][0]);
        }
        
        if(st.find(x-2) != st.end()){
            auto it = lower_bound(mp[x-2].begin(),mp[x-2].end(),i-2*zeros);
            if(it != mp[x-2].end()){
               maxi = max(maxi,i+1-(*it));
            }
        }
        
        if(st.find(x+2) != st.end()){
            auto it = lower_bound(mp[x+2].begin(), mp[x+2].end(),i-2*ones);
            if(it != mp[x+2].end()){
               maxi = max(maxi,i+1-(*it));
            }
        }
    
        if(st.find(x) == st.end()){
            st.insert(x);
        }
        mp[x].push_back(i+1);
    }
     return maxi;
    }
};
