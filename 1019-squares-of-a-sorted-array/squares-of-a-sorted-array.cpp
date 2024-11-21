// APPROACH-1

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++){
//             ans.push_back(nums[i]*nums[i]);
//         }
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };



// APPROACH-2
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int left=0, right=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[right])>abs(nums[left])){
                ans[i]=nums[right] * nums[right];
                right--;
            }
            else{
                ans[i]=nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};