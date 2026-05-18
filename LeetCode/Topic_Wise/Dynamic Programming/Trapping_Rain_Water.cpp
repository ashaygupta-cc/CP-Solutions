class Solution {
public:
    int trap(vector<int>& height){
    // This is the two pointer approach
       int start = 0, end = height.size()-1;
    int leftMax = height[start], rightMax = height[end];

         int waterstored = 0;

    while(start < end){
       if(leftMax < rightMax){
             start++;
          leftMax = max(leftMax,height[start]);
          waterstored += leftMax-height[start];     
       }
       else{
             end--;
          rightMax = max(rightMax,height[end]);
          waterstored += rightMax- height[end];   
       }
    }
    return waterstored; 
    }
};