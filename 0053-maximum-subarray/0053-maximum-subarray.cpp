// Using Kadanes Algorithm Approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};


// Using Divide & Conquerer Approach

// class Solution {
// public:
//     int maxSubArray(vector<int>& n) {
//         int low = 0;
//         int high = n.size() - 1;
//         return divide(n, low, high);
//     }
//     int conquer(vector<int>& n, int low, int mid, int high, int l, int r) {
//         int lsum = INT_MIN;
//         int sum = 0;
//         for (int i = mid; i >= low; i--) {
//             sum += n[i];
//             if (lsum < sum) {
//                 lsum = sum;
//             }
//         }
//         sum = 0;
//         int rsum = INT_MIN;
//         for (int i = mid + 1; i <= high; i++) {
//             sum += n[i];
//             if (rsum < sum) {
//                 rsum = sum;
//             }
//         }
//         return max(l, max(r, lsum + rsum));
//     }
//     int divide(vector<int>& n, int low, int high) {
//         if (low >= high) {
//             return n[low];
//         }
//         int mid = (low + high) / 2;
//         int l = divide(n, low, mid);
//         int r = divide(n, mid + 1, high);
//         return conquer(n, low, mid, high, l, r);
//     }
// };