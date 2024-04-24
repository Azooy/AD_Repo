#include <iostream>
#include "lib/UE5/UE5.h"

using namespace std;



int main() {
    vector<vector<int>> matrix;
    matrix={
            {1,2,3,4},
            {1,2,3,4},
            {1,2,3,4},
            {1,2,3,4}

    };
    vector<vector<int>> matrix2(4, vector<int>(4, 3));
    vector<vector<int>> matrix3(4, vector<int>(4, 0));
    vector<vector<int>> matrix4(4, vector<int>(4,3));
    matrix4 = matmul1(matrix,matrix2);

    matrix3 = strassen(matrix, matrix2, 4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << "\n";
    }
    cout <<"--\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            std::cout << matrix4[i][j] << " ";
        }
        std::cout << "\n";
    }


}