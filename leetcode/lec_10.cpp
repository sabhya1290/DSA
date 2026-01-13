#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void PrintArray(vector<int> v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}

void SwapAlternate(vector<int> vec){
    
    int n = vec.size();

    for(int i = 0; i < n ; i++){
        if (i%2 !=  0){
            int t = vec[i];
            vec[i] = vec[i-1];
            vec[i-1] = t;
        }
    }
}

int FindUnique(vector<int> v){
    
    int e = 0;

    for(int i = 0; i< v.size(); i++){
        e = e ^ v[i];
    }
    
    return e;

}

bool UniqueOccurence(vector<int> arr){

    sort(arr.begin(),arr.end());
    vector<int> v;

    for(int i = 0; i < arr.size(); i++){
        int ct = 0;
        while(i+1 < arr.size() && arr[i] == arr[i+1]){
            ct++;
            i++;
        }
        v.push_back(ct);
    }
    
    sort(v.begin(),v.end());

    for(int i = 1; i < v.size() ; i++){
        if(v[i-1] == v[i]) return false;
    }
    return true;

}

int findDuplucate(vector<int> v){
    int ans = 0;
    for(int i = 0; i<v.size(); i++){
        ans ^= v[i];
    }
    
    for(int i = 1; i<v.size(); i++){
        ans ^= i;
    }
    return ans;
}

void findDuplicates(vector<int> v){

    if(v.empty()) cout << "";
    
    vector<int> ans;
    
    for(int i = 0; i < v.size(); i++){
        if(v[abs(v[i]-1)]<0){
            ans.push_back(abs(v[i]));
        }
        v[abs(v[i])-1]=-v[abs(v[i])-1];
    }
    PrintArray(ans);
    
}

vector<int> intersectionOfArray(vector<int> &v1, vector<int> &v2){
    
    vector<int> ans;

    // Brute force
    // for(int i = 0; i< v1.size(); i++){
    //     for(int j = 0; j < v2.size(); j++){
    //         if(v1[i] < v2[j]) break;

    //         if(v1[i] == v2[j]){
    //             ans.push_back(v1[i]);
    //             v2[j] = -1;
    //             break;
    //         }
    //     }
    // }
    // return ans;

    // Two pointer appraoch
    int i = 0, j = 0;
    while ( i < v1.size() && j<v2.size())
    {
        if(v1[i] == v2[j]){
            ans.push_back(v1[i]);
            i++;
            j++;
        }

        else if(v1[i] < v2[j]) i++;
        else if(v1[i] > v2[j]) j++;
        
    }
    return ans;

}

vector<vector<int>> pairSum(vector<int> v, int sumValue){
    vector<vector<int>> ans;
    
    for(int i = 0; i < v.size(); i++){
        for (int j = i+1; j < v.size(); j++)
        {
            if(v[i] + v[j] == sumValue){
                vector<int> temp;
                temp.push_back(min(v[i],v[j]));
                temp.push_back(max(v[i],v[j]));
                ans.push_back(temp);
            }
        }
        
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void sort01(vector<int> &v){

    int i = 0, j = v.size()-1;
    
    while(i < j){

        if(v[i] == 0) i++;
        else if(v[j] == 1) j--;
        else if(v[i] == 1 && v[j] == 0){
            swap(v[i],v[j]);
            i++;
            j--;
        }

    }
    PrintArray(v);
}

void sort012(vector<int> &v){

    int i = 0 , j = 0 , k = v.size()-1;

    while( i < k && i<=j && j<k ){
        if(v[i] == 0 && i <= j) i++ ;
        if(v[j] == 0 && j < k) j++ ;
        if(v[j] == 1 && j < k) j++ ;
        if(v[k] == 2 && j < k) k-- ;
        if(v[i] == 1 && v[j] == 0){
            swap(v[i], v[j]);
            i++;
            j++;
        }
        if(v[i] == 2 && v[k] == 0){
            swap(v[i], v[k]);
            i++;
            k--;
        }
        if(v[k] == 1 && v[j] == 2){
            swap(v[k], v[j]);
            k--;
            j++;
        }
        // j=2,i=1,k=0
        if(v[i] == 1 && v[j] == 2 && v[k] == 0){
            swap(v[i],v[k]);
            swap(v[j],v[k]);
            i++;
            j++;
            k--;
        }

    }
    
    PrintArray(v);

}

int main(){

    // vector<int> vec = {1,2,3,4,7,4,2,4,5,3,2,1};
    // SwapAlternate(vec);
    // PrintArray(vec);

    // vector<int> uv = {2,4,2,3,4};
    // int ele = FindUnique(uv);
    // cout << ele;

    // vector<int> v = {1,2,1,1,3};
    // cout << UniqueOccurence(v);
    // bool a = true;
    // cout<< a;

    // vector<int> v = {1,2,3,4,5,2};
    // cout << findDuplucate(v);

    // vector<int> v = {1,2,3,3,2,5,6,4,1};
    // findDuplicates(v);

////////// Intersection Of Array //////////
    // vector<int> v1 = {1,2,2,2,2,2,2,3,4};
    // vector<int> v2 = {2,2,3,5};
    // vector<int> ans = intersectionOfArray(v1,v2);
    // PrintArray(ans);

////////// Pair Sum ///////////////////////
    // vector<int> v = {1,3,2,5,3,5,4};
    // vector<vector<int>> ans = pairSum(v,5); 
    // for(int i = 0; i< ans.size(); i++){
    //     PrintArray(ans[i]);
    // }

////////// Sort 0 & 1 /////////////////////
    // vector<int> v = {1,1,0,0,0,0,1,0};
    // sort01(v);

////////// Sort 0, 1 & 2 /////////////////////
    // vector<int> v = {1,2,0,1,1,0,2,2,1,2,0,0,2,1};
    // sort012(v);

}