class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0){
            return mergedIntervals;   //empty
        }
        sort(intervals.begin(),intervals.end());  //sort
        vector<int> tempInterval=intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempInterval[1]){
                tempInterval[1]=max(it[1],tempInterval[1]);   //max of ending 
            }
            else{
                mergedIntervals.push_back(tempInterval);  // if not overlapping then direct push
                tempInterval=it;      // and check again
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};