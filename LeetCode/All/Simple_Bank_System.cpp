class Bank {
public:
    typedef long long ll;
    vector<ll>stored;

    Bank(vector<ll>& balance){
        stored = balance;  
    }
    
    bool transfer(int account1,int account2,ll money){
        int a1 = account1-1, a2 = account2-1;
        if(a1 < 0 || a1 >= stored.size() || a2 < 0 || a2 >= stored.size()) return false;
        if(stored[a1] < money) return false;
        stored[a1] -= money;
        stored[a2] += money;
        return true;
    }
    
    bool deposit(int account,ll money){
        int idx = account-1;
        if(idx < 0 || idx >= stored.size()) return false;
        stored[idx] += money;
        return true;
    }
    
    bool withdraw(int account,ll money){
        int idx = account-1;
        if(idx < 0 || idx >= stored.size() || stored[idx] < money) return false;
        stored[idx] -= money;
        return true;
    }
};


/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */