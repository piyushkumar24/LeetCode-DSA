class Solution {
public:
    string largestOddNumber(string num) {
        if(num.back()%2!=0) return num;
        int n=num.length()-1;
        while(n>=0){
            if(num[n]%2!=0) return num.substr(0, n+1);
            else n--;
        }
        return "";
    }
};