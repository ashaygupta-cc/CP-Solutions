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
 
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
 
// struct DSU{
//     vector<ll>p,sz;
//     DSU(ll n){p.resize(n+1);sz.resize(n+1,1);read(i,0,n+1)p[i]=i;}
//     ll find(ll x){if(p[x]==x)chalna x;chalna p[x]=find(p[x]);}
//     void unite(ll a,ll b){
//         a=find(a);b=find(b);
//         if(a!=b){
//             if(sz[a]<sz[b])swap(a,b);
//             p[b]=a;sz[a]+=sz[b];
//         }
//     }
// };
 
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
 
class DarkSeggyTree{
    
 public:
 
   int n;
   vector<ll>tree,lazy;
   
   DarkSeggyTree(int size){
      n = size;
      tree.resize(4*n,0);
      lazy.resize(4*n,0);
   }
   
   void buildRelationship(int node,int s,int e,vector<ll>&a){
      
       if(s == e){
           tree[node] = a[s];
           return;
       }
       
       int mid = s+(e-s)/2;
       
       buildRelationship(2*node,s,mid,a);
       buildRelationship(2*node+1,mid+1,e,a);
       
       tree[node] = min(tree[2*node],tree[2*node+1]);
       
   }
   
   void pushMeHarder(int node){
    if(lazy[node]){
        ll val = lazy[node];
        tree[2*node] += val;
        lazy[2*node] += val;
        tree[2*node+1] += val;
        lazy[2*node+1] += val;
        lazy[node] = 0;
    }
   }
   
   void updateMeBaby(int node,int s,int e,int l,int r,int val){
       
    if(e < l || s > r) return;
 
    if(l <= s && e <= r){
        tree[node] += val;
        lazy[node] += val;
        return;
    }
 
    pushMeHarder(node);
 
    int mid = s+(e-s)/2;
    updateMeBaby(2*node,s,mid,l,r,val);
    updateMeBaby(2*node+1,mid+1,e,l,r,val);
 
    tree[node] = min(tree[2*node],tree[2*node+1]);
   }
   
   void turnMeOn(int s,int e,int val){
       if(s < 0 || s > e) return;
       updateMeBaby(1,0,n-1,s,e,val);
   }
   
   ll query(int node,int s,int e,int l,int r){
   
    if(e < l || s > r) return LLONG_MAX;
    
    if(l <= s && e <= r) return tree[node];
 
    pushMeHarder(node);
 
    int mid = s+(e-s)/2;
 
    return min(
        query(2*node,s,mid,l,r),
        query(2*node+1,mid+1,e,l,r)
     );
   }
};
 
void ZodiacZ408(){
  
   ll n,m;
   cin >> n;
   
   vector<ll>a(n);
   
   read(i,0,n){
       cin >> a[i];
   }
   
   DarkSeggyTree DST(n);
   DST.buildRelationship(1,0,n-1,a);
   
   cin >> m;
   
   string line;
   getline(cin,line);
   
   read(i,0,m){
       
       getline(cin,line);
       stringstream ss(line);
       
       vector<ll>v;
       ll temp;
       
       while(ss >> temp) v.push_back(temp);
       
       if(v.size() == 2){
           
           ll x = v[0];
           ll y = v[1];
           
           if(x > y){
              cout << min(DST.query(1,0,n-1,x,n-1),DST.query(1,0,n-1,0,y)) << endl;
           }
           else{
               cout << DST.query(1,0,n-1,x,y) << endl;
           }
       }
       else{
           
           ll x = v[0];
           ll y = v[1];
           ll z = v[2];
           
           if(x > y){
               DST.turnMeOn(x,n-1,z);
               DST.turnMeOn(0,y,z);
           }
           else{
               DST.turnMeOn(x,y,z);
           }
       }
   }
 
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