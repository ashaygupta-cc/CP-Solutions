class Solution {
public:
    vector<int>findThePrefixCommonArray(vector<int>& A, vector<int>& B){
           vector<int>result;
          set<int>freq;
          int count = 0;

        for(int i = 0; i < A.size(); i++){
            if(freq.find(A[i]) == freq.end()){
                  freq.insert(A[i]);
            }
            else{
                count++;
            }
            if(freq.find(B[i]) == freq.end()){
                  freq.insert(B[i]);
            }
            else{
                count++;
            }
             result.push_back(count);
        }
       return result;  
    }
};