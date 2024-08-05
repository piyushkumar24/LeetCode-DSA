class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0, right=0;
        int maxLen=0;
        unordered_map<int,int>mpp;
        while(right<fruits.size()){
            mpp[fruits[right]]++;
            if(mpp.size()>2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]]==0) mpp.erase(fruits[left]);
                left++;
            }
            if(mpp.size()<=2) maxLen=max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};