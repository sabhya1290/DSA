#include<iostream>
#include<vector>

using namespace std;

void PrintArray(vector<int> v);

int partition(vector<int> &v, int s, int e){

    int pivot = v[s];
    int cnt = 0;

    for(int i = s + 1; i <= e; i++){
        if(v[i] <= pivot) cnt++;
    }

    // place pivot at right place
    int pivotIndex = s + cnt;
    swap(v[pivotIndex], v[s]);

    // left right ko sort kerna h 
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(v[i] < pivot){
            i++;
        }
        while(v[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(v[i++], v[j--]);
        }
    }
    return pivotIndex;

}

void quickSort(vector<int> &v, int s, int e){

    if(s >= e){
        return;
    }

    int p = partition(v, s, e);

    // left
    quickSort(v, s, p - 1);

    // right
    quickSort(v, p + 1, e);

}

int main(){
    // this method is fastest till now all the sorting i have done
    // O(log(n)) 

    vector<int> v = { 5,46,3,848,32,42,2,1,45};
    int arr[9] = { 5,46,3,848,32,42,2,1,45};
    int n = 9;
    quickSort(v, 0, v.size() );

    // for(int i = 0; i < 9; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    

    PrintArray(v);

}


void PrintArray(vector<int> v){
    cout << endl;
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
    cout << endl;
}
