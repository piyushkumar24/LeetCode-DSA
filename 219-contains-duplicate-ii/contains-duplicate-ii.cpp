class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){ // Number map mai firse milgaya mtlb duplicate hai
                if(abs(i-mpp[nums[i]])<=k) return true; // Range kai andar ka duplicate milgaya
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};