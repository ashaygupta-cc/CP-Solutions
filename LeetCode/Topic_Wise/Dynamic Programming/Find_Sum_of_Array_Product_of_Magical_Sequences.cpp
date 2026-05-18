class Solution {

public:

    typedef long long ll;
    const int MOD = 1e9+7;
    int N;
    vector<ll>fact;
    vector<ll>invFact;
    map<tuple<ll,int,int,int>,ll>val;

     ll binPow(ll a,ll b){
      ll result = 1;
      a %= MOD;
      while(b > 0){
        if(b & 1) result = (result*a) % MOD;
        a = (a*a) % MOD;  
        b /= 2;     
      }
     return result;
    }

    ll nCr(ll a,ll b){
        if(b < 0 || b > a) return 0;
        return (((fact[a]*invFact[b])% MOD)* invFact[a-b]) % MOD;
    }

    ll solve(ll binarySum,int m,int k,int i,vector<int> &nums){
        
        if (k < 0) return 0;

        auto key = make_tuple(binarySum,m,k,i);
        
        if(val.count(key)) return val[key];

        if(m == 0 && __builtin_popcountll(binarySum) == k){
            return 1;
        }  

        if(m == 0 || i >= N) return 0;
        
        ll totalSum = 0;
         totalSum = (totalSum + solve(binarySum >> 1,m,k-(binarySum&1),i+1,nums)) % MOD;

        for(int j = 1; j <= m; j++){

          ll newbinarySum = j + binarySum;
          ll prod = solve(newbinarySum >> 1,m-j,k-(newbinarySum & 1),i+1,nums)% MOD;
          prod = ((binPow(nums[i],j) % MOD) * (prod % MOD)) % MOD;
          prod = (prod * nCr(m,j)) % MOD;

          totalSum = (totalSum + prod) % MOD;
        }

    return val[key] = totalSum;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        
     N = nums.size();

     fact.assign(m+1,1);
     invFact.assign(m+1,1);

     for(int i = 2; i <= m; i++){
         fact[i] = (fact[i-1]*i) % MOD;
     }

     invFact[m] = binPow(fact[m],MOD-2);

     for(int i = m-1; i >= 0; i--){
     invFact[i] = (invFact[i+1]*(i+1)) % MOD;
     }

     return (int)(solve(0,m,k,0,nums)) % MOD;

    }
};