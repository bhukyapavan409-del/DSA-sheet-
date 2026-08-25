class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int water=0;
        while(left<right){
            if(height[left]<=height[right]){
                if(leftmax > height[left]){
                 water+=leftmax-height[left];}
                 else{
                     leftmax=height[left];
                   
            } 
             left=left+1; 
            }
            else{
                if(rightmax>height[right]){
                    water+=rightmax-height[right];
                }
                    else{
                       rightmax=height[right];
                    
                }  
                right=right-1;  
            }
        }
  return water;
    }
};