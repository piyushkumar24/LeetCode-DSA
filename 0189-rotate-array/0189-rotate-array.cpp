class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        ReverseArr(nums,0,n-k-1);
        ReverseArr(nums,n-k,n-1);
        ReverseArr(nums,0,n-1);
    }
    void ReverseArr(vector<int>&arr,int low,int high){
        while(low<high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
};