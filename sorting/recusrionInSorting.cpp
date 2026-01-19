#include<iostream>
#include<vector>

using namespace std;

void PrintArray(vector<int> v);

void bubbleSort(vector<int> &v, int len){

    if(len == 0 || len == 1){
        return;
    }
    for(int i = 0; i < len - 1; i++){
        if(v[i] > v[i + 1]){
            swap(v[i], v[i + 1]);
        }
    }  
    bubbleSort(v, len - 1);  

}

void selectionSort(vector<int>& v, int size){

    if(size == 0 || size == 1){
        return;
    }

    int s = v.size() - size;
    for(int i = s + 1; i < v.size(); i++){
        if(v[s] > v[i]){
            s = i;
        }
    }
    swap(v[s], v[v.size() - size]);
    selectionSort(v, size - 1);


}

void insertionSort(vector<int> &v, int size){
    
    if(size == 0 || size == 1){
        return;
    }

    int i = v.size() - size + 1;
    int temp = v[i];

    int j = i - 1;

    while(j >= 0){
        if(v[j] > temp){
            v[j + 1] = v[j];
        }
        else break;
        j--;
    }
    v[j + 1] = temp;
    insertionSort(v, size - 1);
    
}


int main(){


    vector<int> v = { 5,46,3,848,32,42,2,1,45};
    // vector<int> v = {3,2,4,1};
    // bubbleSort(v, v.size());
    // selectionSort(v, v.size());
    insertionSort(v, v.size());
    PrintArray(v);

}

void PrintArray(vector<int> v){
    cout << endl;
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}
