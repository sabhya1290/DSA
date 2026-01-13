#include<iostream>
#include<vector>
#include<string>

using namespace std;

void WavePrint(vector<vector<int>> &mat){
    
    for(int col = 0; col < 3; col++){
        // odd index
        if( col&1 ){
            for(int row = 2; row >= 0; row--){
                cout << mat[row][col] << " ";
            }
        }
        // even
        else{
            for(int row = 0; row < 3; row++){
                cout << mat[row][col] << " ";
            }
        }
        cout << endl;
    }
    
}

void SpiralPrinting(vector<vector<int>> &mat){
    int i = 0;

    int row = mat.size();
    int col = mat[0].size();

    int count = 0;
    int total = col * row;

    // index initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while(count < total){

        // For printing starting row
        for(int i = startingCol; count < total && i <= endingCol; i++){
            cout << mat[startingRow][i] << " ";
            count++;
        }
        startingRow++;

        // Printing last coloum
        for(int i = startingRow; count < total && i <= endingRow; i++){
            cout << mat[i][endingCol] << " ";
            count++;
        }
        endingCol--;
        
        // Printing last row
        for(int i = endingCol; count < total && i >= startingCol; i--){
            cout << mat[endingRow][i] << " ";
            count++;
        }
        endingRow--;

        // Printing first coloum
        for(int i = endingRow; count < total && i >= startingRow; i--){
            cout << mat[i][startingCol] << " ";
            count++;
        }
        startingCol++;
    }

}

bool BinarySearch(vector<vector<int>> &mat, int target){

    int row = mat.size();
    int col = mat[0].size();

    int start = 0;
    int end = row * col - 1;

    int mid =(start + end) / 2;

    while(start <= end){

        int element = mat[mid/col][mid%col];

        if(element == target) return true;
        else if(element > target) end = mid - 1;
        else if(target > element) start = mid + 1;

        mid = (start + end) / 2;
        
    }

    return false;

}

int main (){

    vector<vector<int>> mat = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};
    // WavePrint(mat);
    // SpiralPrinting(mat);
    int find = 4;
    bool ans = BinarySearch(mat, find);
    cout << ans ;
    return 0;
}