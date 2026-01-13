#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(int arr[] ,int size , int key){
    
    int start = 0;
    int end = size - 1;

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

int firstOccurance(vector<int> v, int size, int key){

    int start = 0;
    int end = size - 1;

    int mid = start + ((end - start)/2);

    int ans;

    while(start <= end){
        if (v[mid] == key){
            ans = mid;
            // start = mid + 1;
            end = mid - 1;
        }
        else if (v[mid] > key){
            end = mid - 1;
        }
        else if (v[mid] < key){
            start = mid + 1;
        }
        mid = start + ((end - start)/2);
    }

    return ans;

}

int lastoccurance(vector<int> v, int size, int key){

    int start = 0;
    int end = size - 1;

    int mid = start + ((end - start)/2);

    int ans;

    while(start <= end){
        if (v[mid] == key){
            ans = mid;
            start = mid + 1;
        }
        else if (v[mid] > key){
            end = mid - 1;
        }
        else if (v[mid] < key){
            start = mid + 1;
        }
        mid = start + ((end - start)/2);
    }

    return ans;
}

int peakIndexInMountainArray(vector<int>& arr) {
        
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + ((e - s) / 2);

    while(s < e){
        if(arr[mid] < arr [mid + 1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + ((e - s) / 2);
    }

    return mid;

}

int PivotElement(vector<int> &v){
    int start = 0;
    int end = v.size() - 1;

    int mid = start + (end - start) / 2;

    while(start < end ){

        if(v[mid] >= v[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return end;

}

int BinarySearch_forRotatedArray(vector<int> v ,int s, int e, int key){
    
    int start = s;
    int end = e;
 
    int mid  = start + (end - start) / 2;
    while(start <= end){

        if(v[mid] == key) return mid;

        // go to right
        if (v[mid] < key ){
            start = mid + 1;
        }
        // go to left 
        if(v[mid] > key ){
            end = mid - 1;
        }
        mid =  start + (end - start) / 2;
        
    }
    return -1;

}

int Findele(vector<int> v, int key){
    
    int pivot = PivotElement(v);
    
    if(key >= v[0]){
        return BinarySearch_forRotatedArray(v, 0, pivot-1 , key);
    }
    else{
        return BinarySearch_forRotatedArray(v, pivot, v.size()-1, key);
    }
}

int Sqrt(int x){
    int start = 0; 
    int end = x;

    long long int mid = start + (end - start) / 2;
         
    long long int ans = -1;
        
    while( start <= end){
            
        if( mid*mid == x){
            return mid;
        }
        else if(mid*mid > x){
            end = mid - 1;
        }
           else if(mid*mid < x){
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    } 
    return ans;
}

double SqrtDecimal(int x ,int pr, int key){
    
    double factor = 1;
    double ans = key;

    for(int i = 0; i < pr; i++){
        factor = factor / 10;

        for(double j = ans; j*j <x ; j = j+factor){
            ans = j;
        }
    }
    return ans;

}

int main(){
// lec 13
    //Q1) using binary search we find first and last occurance 
    // vector<int> v = {1,2,3,3,3,3,3,3,4,7};
    // int first = firstOccurance(v , v.size(), 3);
    // int last = lastoccurance(v, v.size() , 3);
    // 
    // pair<int,int> p = {first, last};
    // 
    // cout << "First occurance of 3 at index at " << p.first << endl;
    // cout << "last occurance of 3 at index at " << p.second << endl;
    // 
    // Q2
    // vector<int> v = {3,4,5,1};
    // cout << peakIndexInMountainArray(v);

// lec 14
    // Q1 Pivot element
    // vector<int> v = {7,9,13,14,16,87,2,4,5};
    // int pivot = PivotElement(v);
    // cout << pivot ;
    // Q2 Find element in rotated sorted array
    // vector<int> v = {7,9,13,14,16,87,2,4,5};
    // int ans = Findele(v, 14);
    // cout << ans;
    // Q3 sqrt(x)
    // int x = 239048;
    // cout << "Sqrt of x is " << Sqrt(x);
    // Modification of Q3
    // int x = 8;
    // int sqr = Sqrt(x);
    // cout << sqr << endl;
    // cout << "Sqrt of x is " << SqrtDecimal(x, 3, sqr);


}