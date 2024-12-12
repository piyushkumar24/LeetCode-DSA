// APPROACH-1

// class Solution {
// public:
//     int countHomogenous(string s) {
//         vector<int> Map(s.size(),1);
//         int sum = 1;
//         for(int i = 1; i < s.size(); i++){
//             int curr = 1;
//             if(s[i-1] == s[i]) Map[i] += Map[i-1];
//             sum += Map[i];
//         }
//         return sum;
//     }
// };




// APPROACH-2

class Solution {
public:
    int countHomogenous(string s) {
        int m=1e9+7;
        int result=0, length=0;
        for(int i=0;i<s.length();i++){
            if(i>0 && s[i]==s[i-1]) length+=1;
            else length=1;
            result=(result+length)%m;
        }
        return result;
    }
};