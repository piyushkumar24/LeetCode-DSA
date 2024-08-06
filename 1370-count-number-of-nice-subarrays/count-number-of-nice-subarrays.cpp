class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    int atMost(vector<int>&nums, int goal){
        if(goal<0) return 0;
        int left=0, right=0;
        int sum=0, cnt=0;
        while(right<nums.size()){
            sum+=(nums[right]%2);
            while(sum>goal){
                sum-=(nums[left]%2);
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
};