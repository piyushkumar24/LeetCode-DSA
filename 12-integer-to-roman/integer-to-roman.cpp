// class Solution {
// public:
//     string intToRoman(int num) {
//         int normal[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
//         string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
//         string res;
//         for(int i=0;i<13;i++){
//             while(num>=normal[i]){
//                 res.append(roman[i]);
//                 num-=normal[i];
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    string intToRoman(int num) {
        string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        return ths[num/1000]+hrns[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
    }
};