#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void PrintArray(vector<int> v);

    // T.C. = O(n^2)
    // Best case TC = O(n^2) when our array is already sorted
    // Worst case = O(n^2)
    // S.C = O(1)

    // Use case = when our array is small in size 

void SelectionSort(vector<int> &v){

    for(int i = 0; i < v.size() - 1; i++){
        int minIndex = i;

        for(int j = i+1; j < v.size(); j++){
            
            if(v[minIndex] > v[j]){
                minIndex = j;
            }
        }
        swap(v[i] , v[minIndex]);
    }

}

int main(){

    vector<int> v = {3,2,5,1,4};
    SelectionSort(v);
    PrintArray(v);

}


void PrintArray(vector<int> v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}