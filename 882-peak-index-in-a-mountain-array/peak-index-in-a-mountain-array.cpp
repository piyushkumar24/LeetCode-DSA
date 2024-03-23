// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int n=arr.size();
//         if(n==1){
//             return 0;
//         }
//         if(arr[0]>arr[1]){
//             return 0;
//         }
//         if(arr[n-1]>arr[n-2]){
//             return n-1;
//         }
//         int low=0;
//         int high=n-1;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
//                 return mid;
//             }
//             else if(arr[mid]>arr[mid-1]){
//                 low=mid+1;
//             }
//             else{
//                 high=mid-1;
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int mid  = (s+e)/2;
            if(arr[mid]> arr[mid+1] && arr[mid]> arr[mid-1] )
                return mid;
            else if(arr[mid]<arr[mid+1])
                s = mid+1;
            else if( arr[mid]<arr[mid-1])
                e = mid-1;
        }
        return -1;
    }
};