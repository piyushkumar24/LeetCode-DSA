class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<long long,long long> mpp;
        long long sum=0;
        long long cnt=0;
        mpp[sum]++;
        for(auto i:nums){
            sum=sum^i;
            cnt+=mpp[sum];
            mpp[sum]++;
        }
        return cnt;
    }
};