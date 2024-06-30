class Solution {
public:
    int maxNonAdjacentSum(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(maxNonAdjacentSum(temp1), maxNonAdjacentSum(temp2));
    }
};