#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

// Advantage
// 1) adaptable
// 2) Stable algo

// SC = O(1)
// TC = O(n^2)
// Best case = O(n)
// Worst case = O(n^2)

void PrintArray(vector<int> v);

void InsertionSort(vector<int> &v){

    int i = 1;
    int n = v.size();

    while(i < n){
        int temp = v[i];
        int j = i - 1;
        
        while(j >= 0){
            if(v[j] > temp)
            {
                v[j+1] = v[j];
            }
            else{ break;}
            j--;
        }
        v[j+1] = temp;
        i++;
    }

}

int main(){

    vector<int> v = { 5,46,3,848,32,42,2,1,45};
    InsertionSort(v);
    PrintArray(v);

}

void PrintArray(vector<int> v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}