class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1] < b[1];
        });
        int cnt=1;
        int lastEndTime=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= lastEndTime){
                cnt=cnt+1;
                lastEndTime=intervals[i][1];
            }
        }
        return (intervals.size()-cnt);
    }
};