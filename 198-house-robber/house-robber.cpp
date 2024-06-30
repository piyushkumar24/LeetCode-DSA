class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i]+prev2;
            int nontake=0+prev;
            int curri=max(take, nontake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};