class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int startingPosition=lower_bound(nums,low,high,target);
        int endingPosition=lower_bound(nums,low,high,target+1)-1;
        if(startingPosition<n && nums[startingPosition]==target){
            return {startingPosition,endingPosition};
        }
        return {-1,-1};
    }
    
    int lower_bound(vector<int>&arr,int low, int high, int target){
        int ans=arr.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};