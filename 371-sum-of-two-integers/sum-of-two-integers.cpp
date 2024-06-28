class Solution {
public:
    int getSum(int a, int b) {
        if(b==0) return a;
        if(a==0) return b;
        return log2(pow(2,a) * pow(2,b));
    }
};