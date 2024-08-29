class Solution {
public:
    int getVal(char i){
        if(i=='I') return 1;
        else if(i=='V') return 5;
        else if(i=='X') return 10;
        else if(i=='L') return 50;
        else if(i=='C') return 100;
        else if(i=='D') return 500;
        else if(i=='M') return 1000;
        else return 0;
    }
    int romanToInt(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            if(i+1<n && getVal(s[i])<getVal(s[i+1])) sum=sum-getVal(s[i]);
            else sum=sum+getVal(s[i]);
        }
        return sum;
    }
};