#include<iostream>
#include<vector>

using namespace std;

void PrintArray(vector<int> v);

void merge(int *arr, int s, int e){
    int mid = (s + e) / 2;
    
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] =  first[index1++];
        }
        else{
            arr[mainArrayIndex++] =  second[index2++];
        }
    }

    while (index1 < len1){
        arr[mainArrayIndex++] =  first[index1++];
        
    }
    while (index2 < len2){
        arr[mainArrayIndex++] =  second[index2++];
        
    }
    
    delete []first;
    delete []second;
}

void mergeSort(int *v, int s, int e){

    // base case 
    if(s >= e){
        return;
    }

    int mid = (s + e) / 2;

    // left part sort
    mergeSort(v, s, mid);

    // right part sort
    mergeSort(v, mid + 1, e);

    // merge
    merge(v, s, e);

}

int main(){
    // this method is fastest till now all the sorting i have done
    // O(log(n)) 

    vector<int> v = { 5,46,3,848,32,42,2,1,45};
    int arr[9] = { 5,46,3,848,32,42,2,1,45};
    int n = 9;
    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < 9; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    

    PrintArray(v);

}


void PrintArray(vector<int> v){
    cout << endl;
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}
