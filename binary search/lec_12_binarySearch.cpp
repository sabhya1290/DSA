#include<iostream>
using namespace std;

int BinarySearch(int arr[] ,int size , int key){
    
    int start = 0;
    int end = size - 1;

    // int mid = (start + end) / 2; 
    // optimizing mid value becuase if both value is too much greater thenn TLE occur
    int mid  = start + (end - start) / 2;
    while(start <= end){

        if(arr[mid] == key) return mid;

        // go to right
        if (arr[mid] < key ){
            start = mid + 1;
        }
        // go to left 
        if(arr[mid] > key ){
            end = mid - 1;
        }
        mid =  start + (end - start) / 2;
        
    }
    return -1;

}

int main(){
    int arr[6] = {1,2,3,6,12,14};
    int b[7] = {3,4,8,11,14,15,19};
    int ans = BinarySearch(arr ,6, 12);
    cout << ans;
}