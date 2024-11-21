class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int left=0, right=n-1;
        while(left<right){
            int total=numbers[left]+numbers[right];
            if(target>total) left++;
            else if(target<total) right--;
            else return{left+1, right+1};
        }
        return {-1,-1};
    }
};