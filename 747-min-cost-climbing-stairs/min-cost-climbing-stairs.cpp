class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==0) return 0;
        int prev=0;
        int prev2=0;
        for(int i=2;i<=cost.size();i++){
            int fs=prev+cost[i-1];
            int ss=INT_MAX;
            if(i>1) ss=prev2+cost[i-2];
            int curr=min(fs,ss);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};