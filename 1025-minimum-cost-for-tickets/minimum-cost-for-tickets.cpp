class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INT_MAX);
        for(int i=0; i<days.size(); i++){
            // cost for a day plan
            if(i == 0) dp[i] = costs[0];
            else dp[i] = min(dp[i-1]+costs[0], dp[i]);
            // cost for 7-day or 30-day plan
            int prevCost = 0;
            if(i != 0) prevCost = dp[i-1];
            for(int j=i; j<days.size(); j++){
                if(days[j]-days[i] < 7) dp[j] = min(prevCost+costs[1], dp[j]);
                if(days[j]-days[i] < 30) dp[j] = min(prevCost+costs[2], dp[j]);
                else break;
            }
        }
        return dp[days.size()-1];
    }
};