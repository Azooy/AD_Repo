#include <iostream>
#include "lib/UE5/UE5.h"
#include "random"

using namespace std;



int main() {
    int random = rand();
    vector<vector<int>> matrix(128, vector<int>(128, 0));
    randomFill(matrix, 128);
    vector<vector<int>> matrix2(128, vector<int>(128, 0));
    randomFill(matrix2, 128);
    vector<vector<int>> matrix3(128, vector<int>(128, 0));
    matrix3 = strassen(matrix, matrix2,128);
    printmatrix(matrix3);

}