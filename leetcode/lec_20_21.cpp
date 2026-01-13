#include<iostream>
#include<vector>

using namespace std;

void PrintArray(vector<int> v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
}

void reverseArray(vector<int> &v, int p ){
    // for(int i = 0; i < v.size()/2 ; i++){
    //     swap(v[i] , v[v.size() - i - 1]);
    // }

    int s = p + 1;
    int e = v.size() - 1;

    while(s < e){
        swap(v[s], v[e]);
        s++;
        e--;
    }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = 0;
    int j = 0;
    vector<int> v;
    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            v.push_back(nums1[i]);
            i++;
        }
        else{
            v.push_back(nums2[j]);
            j++;
        }
    }
    nums1 = v;
}

vector<int> arraySum(vector<int> &v1, vector<int> &v2){
    
    vector<int> ans;
    
    int i = v1.size() - 1;
    int j = v2.size() - 1;

    int s = 0;
    int sum = 0;
    int carry = 0;


    while(i >= 0 && j >= 0){
        s = v1[i--] + v2[j--] + carry;
        sum = s % 10;
        carry = s / 10;
        ans.push_back(sum);
        
    }

    while (i >= 0)
    {
        s = v1[i--] + carry;
        sum = s % 10;
        carry = s / 10;
        ans.push_back(sum);
    }
    while (j >= 0)
    {
        s =v2[j--] + carry;
        sum = s % 10;
        carry = s / 10;
        ans.push_back(sum);
    }
    if(carry != 0){
        ans.push_back(carry);
    }


    reverseArray(ans, -1);
    return ans;

}

int main(){

    // Q1 Reverse an array
    // vector<int> v = {3,24,3,54,2,4,56};
    // PrintArray(v);
    // reverseArray(v, -1);
    // PrintArray(v);

    // Q2 Merge sorted array
    // vector<int> v1 = {1, 5, 6, 9, 13};
    // vector<int> v2 = {2,8,11,12};
    // merge(v1, v1.size() ,v2 , v2.size());
    // PrintArray(v1);

    // Q6 Sum of two arrays
    vector<int> ar1 = {1,8,2,2,3};
    vector<int> ar2 = {9,4,3,6,5};
    vector<int> ans = arraySum(ar1 , ar2);
    PrintArray(ans);

}