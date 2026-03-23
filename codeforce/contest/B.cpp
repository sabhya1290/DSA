#include<iostream>
#include<vector>

using namespace std;

vector<int> permutaiton(vector<int> &v){
    vector<int> ans;
    vector<int> d(v.size() + 1,0);

    int m = 0;
    int l = 0;
    for(int i = 0 ; i < v.size(); i++){
        if(v[i] > m){
            m = v[i];
            l = i;
        }
        
    }
    
    for(int i = 0 ; i < v.size(); i++){
        int idx = v[i];
        d[idx] = 1;
        
    }
    
    for(int i = 0 ; i < v.size() ; i++){
        if(d[i+1] == 0){
            ans.push_back(-1);
        }
        ans.push_back(v[i]);
    }
    swap(ans[l],ans[0]);

    return ans;

}

int main(){
    vector<int> v = {3, 2, 1, 4};
    vector<int> ans = permutaiton(v);
    for(int i = 0 ; i < v.size(); i++){
        cout << ans[i] << " ";
    }

}