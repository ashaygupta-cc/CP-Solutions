#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define read(i,a,b) for(ll i = a; i < b; i++)
#define read2(i,a,b) for(ll i = a; i >= b; i--)
#define chalna return
#define shi true
#define galat false
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ll INF = 1e18;
using namespace std;
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
// const ll MAXN = 5000005;
// ll fact[MAXN],invfact[MAXN],prime[MAXN],spf[MAXN],pf_cnt[MAXN],pref_pf[MAXN];
// vector<ll>pr;
 
ll binpow(ll a,ll b,ll m=mod){
    ll res=1;
    while(b>0){
        if(b&1)res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    chalna res;
}
 
ll modinv(ll a,ll m=mod){
    chalna binpow(a,m-2,m);
}
 
// void pre(ll n=MAXN-1,ll m=mod){
//     fact[0]=1;
//     read(i,1,n+1)fact[i]=(fact[i-1]*i)%m;
//     invfact[n]=binpow(fact[n],m-2,m);
//     read2(i,n-1,0)invfact[i]=(invfact[i+1]*(i+1))%m;
// }
 
// ll nCr(ll n,ll r,ll m=mod){
//     if(r<0||r>n)chalna 0;
//     chalna (((fact[n]*invfact[r])%m)*invfact[n-r])%m;
// }
 
ll gcdll(ll a,ll b){
    chalna b==0?a:gcdll(b,a%b);
}
 
ll lcmll(ll a,ll b){
    chalna (a/gcdll(a,b))*b;
}
 
bool isPrime(ll n){
    if(n<2)chalna galat;
    for(ll i=2;i*i<=n;i++)if(n%i==0)chalna galat;
    chalna shi;
}
 
// void sieve(ll n=MAXN-1){
//     read(i,0,n+1)prime[i]=1;
//     prime[0]=prime[1]=0;
//     for(ll i=2;i*i<=n;i++){
//         if(prime[i]){
//             for(ll j=i*i;j<=n;j+=i)prime[j]=0;
//         }
//     }
//     read(i,2,n+1)if(prime[i])pr.push_back(i);
// }
 
// void pre_spf(ll n=MAXN-1){
//     spf[1]=1;
//     pf_cnt[1]=0;
//     read(i,2,n+1)spf[i]=i;
//     for(ll i=2;i<=n;i++){
//         if(spf[i]==i){
//             for(ll j=i;j<=n;j+=i){
//                 if(spf[j]==j)spf[j]=i;
//             }
//         }
//         pf_cnt[i]=pf_cnt[i/spf[i]]+1;
//     }
//     read(i,1,n+1)pref_pf[i]=pref_pf[i-1]+pf_cnt[i];
// }
 
// vector<ll> get_pf(ll x){
//     vector<ll>res;
//     while(x>1){
//         res.push_back(spf[x]);
//         x/=spf[x];
//     }
//     chalna res;
// }
 
// map<ll,ll>get_pf_cnt(ll x){
//     map<ll,ll>res;
//     while(x>1){
//         res[spf[x]]++;
//         x/=spf[x];
//     }
//     chalna res;
// }
 
map<ll,ll> factor(ll x){
    map<ll,ll> res;
    for(ll i=2;i*i<=x;i++){
        while(x%i==0){
            res[i]++;
            x/=i;
        }
    }
    if(x>1) res[x]++;
    return res;
}
 
string to_binary(ll n){
   string s = "";
   while(n){
      s += (n&1)+'0';
      n >>= 1;
   }
   reverse(s.begin(),s.end());
   return s;
}
 
struct DSU{
    vector<int>p,sz;
    int components;
    
    DSU(int n){components = n;p.resize(n+1);sz.resize(n+1,1);read(i,0,n+1)p[i]=i;}
    int find(int x){if(p[x]==x)chalna x;chalna p[x]=find(p[x]);}
    bool unite(int a,int b){
        a=find(a);b=find(b);
        if(a!=b){
            if(sz[a]<sz[b])swap(a,b);
            p[b]=a;sz[a]+=sz[b];
            components--;
            return true;
        }
        return false;
    }
};
 
// vector<vector<ll>>g;
// vector<ll>vis;
 
// void dfs(ll u){
//     vis[u]=1;
//     for(auto v:g[u])if(!vis[v])dfs(v);
// }
 
// void bfs(ll s){
//     queue<ll>q;q.push(s);
//     vis[s]=1;
//     while(!q.empty()){
//         ll u=q.front();q.pop();
//         for(auto v:g[u])if(!vis[v]){vis[v]=1;q.push(v);}
//     }
// }
 
priority_queue<ll>pq_max;
priority_queue<ll,vector<ll>,greater<ll>>pq_min;
priority_queue<pair<ll,ll>>pq_pair_max;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq_pair_min;
 
void ZodiacZ408(){
  
   ll n;
   cin >> n;
   
   vector<int>a(n);
   
  bool bl = true;
   
  read(i,0,n){
      cin >> a[i];
  }
   
  int x = a[0];
   
  read(i,0,n-1){
      if(a[i] != a[i+1]) bl = false;
  }
   
  if(bl){
      cout << (n-1)*x << endl;
      return;
  }
   
   vector<pair<int,int>>GCD;
   vector<tuple<int,int,int>>edges;
   
   read(i,0,n){
       vector<pair<int,int>>temp;
       temp.push_back({a[i],i});
       
       for(auto gg : GCD){
          if(gcdll(gg.first,a[i]) == temp.back().first) continue;
          else temp.push_back({gcd(gg.first,a[i]),gg.second});
       }
   
       GCD = temp;
   
       for(auto gg : GCD){
           if(gg.second != i) edges.push_back({gg.second,i,gg.first});
       }
    }
    
    GCD.erase(GCD.begin(),GCD.end());
   read2(i,n-1,0){
       vector<pair<int,int>>temp;
       temp.push_back({a[i],i});
       
       for(auto gg : GCD){
           if(gcdll(gg.first, a[i]) == temp.back().first) continue;
           else temp.push_back({gcdll(gg.first,a[i]),gg.second});
       }
   
       GCD = temp;
   
       for(auto gg : GCD){
           if(gg.second != i) edges.push_back({gg.second,i,gg.first});
       }
    }    
    
       
    sort(edges.begin(),edges.end(),[](const tuple<int,int,int>& a,const tuple<int,int,int>& b){
        return get<2>(a) < get<2>(b);
    });
         
   DSU dsu(n);
   
   int totCost = 0;
   
   for(const auto& [u,v,w] : edges){
        if(dsu.unite(u,v)){
            totCost += w;
            if(dsu.components == 1) break;
        }
    }
 
    cout << totCost << endl;
}
 
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    // ll t;
    // cin >> t;
    
    ll t = 1;
    
    while(t--){
        ZodiacZ408();
    }
    chalna 0;  
}