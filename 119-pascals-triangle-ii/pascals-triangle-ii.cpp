class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans=1;
        vector<int>result;
        result.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            ans=ans*(rowIndex-i+1);
            ans=ans/i;
            result.push_back(ans);
        }
        return result;
    }
};