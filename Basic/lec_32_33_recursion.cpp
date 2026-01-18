#include<iostream>
#include<vector>

using namespace std;

void sayDigit(int n){

    // base case
    if(n == 0) return;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eigth", "nine"};
    
    // processing 
    int digit = n % 10;
    n /= 10;
    
    sayDigit(n);
    cout << arr[digit] << " ";

}


int countDistinctWayToClimbStair(long long nStairs){
    if(nStairs < 0) return 0;
    if(nStairs == 0) return 1;
    return countDistinctWayToClimbStair(nStairs - 1) + countDistinctWayToClimbStair(nStairs - 2);

}

// lec 33 started
bool isSorted(vector<int> &v, int size){
    // base case

    if(size == 0 || size == 1){
        return true;
    }

    if(v[size] > v[size - 1]){
        isSorted(v, size - 1);
    }
    else
    return false; 
}

int arraySum(vector<int> &v, int size){
    
    if( 0 == size){ return v[size];}

    return arraySum(v, size - 1) + v[size];


}

bool LinearSearch(vector<int> v,int size, int target){
    if(v[size] == target && size >= 0) return true;
    
    if(size == 0){return false;}

    bool ans = LinearSearch(v, size - 1, target) || false;

    return (ans);


}

int main(){

    // count of stairs
    // long long stairs = 4;
    // int ans = countDistinctWayToClimbStair(stairs);
    // cout << ans;

    // sayDigit(312);

    vector<int> v = {2,4,6,7,11,2,14};
    // bool ans = isSorted(v , v.size());
    // cout << ans << endl;

    // int ans = arraySum(v, v.size() - 1);
    // cout << ans << endl;

    bool ans = LinearSearch(v, v.size() - 1, 31);
    if(ans) cout << "Found" << endl;
    else cout << "Not Found" << endl;


}