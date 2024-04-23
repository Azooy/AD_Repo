#include <iostream>
#include "lib/UE5/UE5.h"

using namespace std;



int main() {
    vector<vector<int>> matrix(8, vector<int>(8, 2));
    vector<vector<int>> matrix2(8, vector<int>(8, 1));
    vector<vector<int>> matrix3(8, vector<int>(8, 0));
    vector<vector<int>> matrix4(4, vector<int>(4, 0));

    matrix3 = strassen(matrix, matrix2, 8);
    matrix4 = matmul1(matrix, matrix2);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << matrix3[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrix4[i][j] << " ";
        }
        cout << "\n";
    }


}

