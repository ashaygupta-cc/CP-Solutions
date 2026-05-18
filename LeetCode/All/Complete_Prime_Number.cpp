class Solution {
public:
  bool isPrime(int n){
      
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i * 1LL * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

    bool completePrime(int num){

       int x = num;
       vector<int>subs;
       int count = 0;

        while(x != 0){
            subs.push_back(x);
            // cout << x << "*";
            x /= 10;
            count++;
        }

        x = num;
        // cout << count << " " << endl;
        int temp = pow(10,count-1);
        
        while(temp/10 != 0){  
            subs.push_back(x%temp);
            // cout << x%temp << "*";
            temp /= 10;
        }        

        int N = subs.size();
        
        for(int i = 0; i < N; i++){
            if(!isPrime(subs[i])) return false;
        }
        return true;
    }
};