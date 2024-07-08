class Solution {
public:
    bool subsetSumToK(int n, int k,vector<int>&nums){
        vector<bool>prev(k+1,0);
        vector<bool>curr(k+1,0);
        prev[0]=curr[0]=true;
        if(nums[0]<=k) prev[nums[0]]=true;
        for(int index=1;index<n;index++){
            for(int target=1;target<=k;target++){
                bool nottake=prev[target];
                bool take=false;
                if(target>=nums[index]) take=prev[target-nums[index]];
                curr[target]=take||nottake;
            }
            prev=curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        if(totalSum%2!=0) return false;
        int target=totalSum/2;
        return subsetSumToK(n, target, nums);
    }
};