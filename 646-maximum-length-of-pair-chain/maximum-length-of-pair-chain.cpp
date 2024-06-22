class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });
        int lock=pairs[0][1];
        int counter=1;
        for(int i=1;i<pairs.size();i++){
            if(lock < pairs[i][0]){
                counter++;
                lock=pairs[i][1];
            }
        }
        return counter;
    }
};