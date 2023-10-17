// Bit Manipulation Approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0;
        int xor2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xor2=xor2 ^ nums[i];
            xor1=xor1 ^ i;
        }
        xor1=xor1 ^ n;
        return (xor1 ^ xor2);
    }
};


// Sum Approach

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int sum = 0; 
//         int total = nums.size()*(nums.size() + 1)/2; 
//         for (auto i:nums) { 
//             sum += i; 
//         }
//         return total - sum; 
//     }
// };