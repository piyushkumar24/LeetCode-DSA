class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int diff = nums[1] - nums[0];
        int i = 0, res = 0;
        for (int j = 2; j < n; j++) {
            if (nums[j] - nums[j-1] == diff) res += (j-i-1); 
            else {
                i = j-1;
                diff = nums[j] - nums[j-1];
            }
        }
        return res;
    }
};