class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int ans=0, i=num1.length()-1, j=num2.length()-1;
        while(i>=0 || j>=0 ||ans==1){
            if(i>=0){
                ans+=num1[i]-'0';
                i--;
            }
            if(j>=0){
                ans+=num2[j]-'0';
                j--;
            }
            else ans+=0;
            res +=(char)(ans%10 + '0');
            ans=ans/10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};