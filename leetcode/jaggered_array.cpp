#include<iostream>
#include<vector>

using namespace std;

int main(){

    // Jagged array 
    // First create a row
    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    // Array to store column sizes for each row
    int *colSizes = new int[row];

    // For creating different length of columns we can take column either in run time or in compile time

    // For taking in run time 
    int **arr = new int*[row];

    for(int i = 0; i < row; i++){
        int col;
        cout << "Enter col length for row " << i << ": ";
        cin >> col;
        colSizes[i] = col;
        arr[i] = new int[col];

        // Input values for this row
        for(int j = 0; j < col; j++){
            cout << "Enter value for arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // Now jagged array created with values, now printing 
    cout << "The jagged array is:" << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < colSizes[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for(int i = 0; i < row; i++){
        delete[] arr[i];
    }
    delete[] arr;
    delete[] colSizes;

    return 0;
}