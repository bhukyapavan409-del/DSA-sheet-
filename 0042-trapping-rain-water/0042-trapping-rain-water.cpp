class Solution {
public:


    vector<int> getLeftMax(vector<int>&height,int &n){   // max element till that index 
        vector<int>prefix(n);
        prefix[0]=height[0];           
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],height[i]);
        }
        return prefix;
    }
   vector<int> getRightMax(vector<int>&height,int &n){    // max element till the index
    vector<int>suffix(n);
    suffix[n-1]=height[n-1];    // it comes from the back side 
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],height[i]);
    }
    return suffix;
   }

    int trap(vector<int>& height) {
        int n=height.size();
        if(n<1) return 0;
        vector<int>leftMax=getLeftMax(height,n);
        vector<int>rightMax=getRightMax(height,n);
        int sum=0;
        for(int i=1;i<n-1;i++)
        {
            sum+=min(leftMax[i],rightMax[i])-height[i];
        }
        return sum;
    }
};