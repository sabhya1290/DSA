#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &v, int n, int m, int mid){

    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0; i < n; i++){
        if(pageSum + v[i] <= mid ){
            pageSum += v[i];
        }
        else{
            studentCount++;
            if(studentCount > m || v[i] > mid){
                return false;
            }
            pageSum = v[i];
        }
    }
    return true;

}

int allocateBook(vector<int> &v, int n, int m){
    int sum = 0; 
    for(int i = 0; i < n; i++ ){
        sum += v[i];
    }

    int start = 0;
    int end = sum;

    int mid = start + (end - start) / 2;

    int ans = -1;

    while( start <= end ){

        if (isPossible(v , n, m, mid)){
            ans = mid;
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
    
}

bool Paint(vector<int> &v, int n, int m, int mid){

    int ptCt = 1;
    int paintSum = 0;

    for(int i = 0; i < n; i++){
        if(v[i] + paintSum <= mid){
            paintSum += v[i];
        }
        else{
            ptCt++;
            if(ptCt > m || v[i] > mid){
                return false;
            }
            paintSum = v[i];
        }
    }
    return true;

}

int Painter(vector<int> &v, int n, int m){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    
    int s = 0;
    int e = sum;
    int ans = -1;

    int mid = s + (e - s) / 2;
    
    while(s <= e){
        if(Paint(v, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

bool Poss(vector<int> &v , int k, int m){

    int Cows = 1;
    int lastPos = v[0];

    for(int i = 0; i < v.size(); i++){
        if(v[i] - lastPos >=m){
            Cows++;
            if(Cows == k){
                return true;
            }
            lastPos = v[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){

    sort(stalls.begin(), stalls.end());
    
    int s = 0;
    int e = stalls[stalls.size() - 1];

    int m = s + (e - s) / 2;
    int ans = -1;

    while(s <= e){
        if(Poss(stalls, k, m)){
            ans = m;
            s = m + 1;
        }
        else{
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}

int main(){

    // Book Allocation Problem
    // vector<int> book = {10, 20, 30, 40};
    // int ans = allocateBook(book, 4, 2);
    // cout << ans;

    // Painter Partition Problem  = same code as above for book allocation problem
    // vector<int> v = {5,5,5,5};
    // cout << Painter(v, 4, 2);

    // Agressive Cow Problem
    vector<int> stalls = {4, 2, 1, 3, 6};
    cout << aggressiveCows(stalls, 2);

}