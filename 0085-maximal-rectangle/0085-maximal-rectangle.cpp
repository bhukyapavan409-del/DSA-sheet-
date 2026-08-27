class Solution {
public:

    vector<int> findPse(vector<int>&heights){
        int n=heights.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
               pse[i]=-1;
               else
                 pse[i]=st.top();
                 st.push(i);
        }
        return pse;

    }

    vector<int> findNse(vector<int>&heights){
        int n=heights.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();

            }
            if(st.empty())
              nse[i]=n;
              else
                nse[i]=st.top();

                st.push(i);
        }
        return nse;
    }

    int largestRectangularArea(vector<int>&heights){
        int n=heights.size();
        vector<int>pse=findPse(heights);
        vector<int>nse=findNse(heights);
        int maxi=0;
        for(int i=0;i<n;i++){
        int width=nse[i]-pse[i]-1;
        int area=heights[i]*width;
        maxi=max(maxi,area);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                heights[j]+=1;
                else
                 heights[j]=0;
            }
            maxi=max(maxi,largestRectangularArea(heights));
        }
        return maxi;
    }
};