#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void PrintArray(vector<int> v);


// TC = O(n^2)
// Best case = O(n) - when array is sorted
// Worst case = O(n^2)
// SC = O(1)

void BuubleSort(vector<int> &v){
    
    for(int i = 0; i < v.size()-1 ; i++){        
        
        bool swapped = false;

        for(int j = 0; j < v.size()-1 - i; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
    }


}

int main(){

    vector<int> v = { 5,46,3,848,32,42,2,1,45};
    BuubleSort(v);
    PrintArray(v);

}

void PrintArray(vector<int> v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}