class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (helper(nums,k)-helper(nums,k-1));
    }
    int helper(vector<int>&nums, int k){
        int left=0, right=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        while(right<nums.size()){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) mpp.erase(nums[left]);
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
};