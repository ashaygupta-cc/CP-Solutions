#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        int A, B;
        cin >> A >> B;

        if(A % B == 0){
            cout << "0" << endl;
            continue;
        }

        int steps = 0;
      int A1 = A, B1 = B ;
  if(A<B){
        while(A % B != 0){
            A++;
            B--;
            steps++;
        }
      }
    if(A>B){
 while(A % B != 0 && A1 % B1 != 0){
           steps++;
          A++;
          B--;
          A1--;
          B1++;
       }
    }

        cout << steps << endl;
    }
    return 0;
}