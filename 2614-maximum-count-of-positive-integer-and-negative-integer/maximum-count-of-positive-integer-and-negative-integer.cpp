class Solution {
    int binaryFloor(vector<int> &nums){
        int l = 0, r = nums.size() - 1, res = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] > -1){
                r = m - 1;
            }else{
                res = m;
                l = m + 1;
            }
        }
        return res;
    }

    int binaryCeil(vector<int> &nums){
        int l = 0, r = nums.size() - 1, res = nums.size();
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] < 1){
                l = m + 1;
            }else{
                res = m;
                r = m - 1;
            }
        }
        return res;
    }
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        return max(binaryFloor(nums) + 1, n - binaryCeil(nums));
    }
};