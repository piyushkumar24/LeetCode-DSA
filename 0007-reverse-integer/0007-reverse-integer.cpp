class Solution {
public:
    int reverse(int x) {
        int reverseNumber=0;
        while(x!=0){
            int lastDigit=x%10;
            if(reverseNumber>INT_MAX/10 || reverseNumber<INT_MIN/10){
                return 0;
            }
            reverseNumber=(reverseNumber*10)+lastDigit;
            x=x/10;
        }
        if(x<0){
            return reverseNumber*(-1);
        }
        else{
            return reverseNumber;
        }
    }
};