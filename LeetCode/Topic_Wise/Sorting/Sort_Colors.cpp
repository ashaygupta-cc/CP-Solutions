class Solution{
public:
    void sortColors(vector<int>& nums){
       
        vector<int>count(3,0);

    for(int i = 0; i < nums.size(); i++){
        count[nums[i]]++;
    }
     
      
    fill(nums.begin(),nums.begin()+count[0],0);
    fill(nums.begin()+count[0],nums.begin()+count[0]+count[1],1);
    fill(nums.begin()+count[0]+count[1],nums.begin()+count[0]+count[1]+count[2],2);

  }
};
