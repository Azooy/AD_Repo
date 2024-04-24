//
// Created by jendrik on 22.04.2024.
//

#ifndef AD_SE_4_UE5_H
#define AD_SE_4_UE5_H
#include "iostream"
#include <vector>
using namespace std;

void Merge(int [], int, int, int);
void MergeSort(int [], int, int);
void Heapify(int [], int, int, int);
void HeapSort(int [], int, int);
void BuildHeap(int [], int, int);
void swap(int&, int&);
vector<vector<int>> matmul1(vector<vector<int>>, vector<vector<int>>);
vector<vector<int>> strassen(vector<vector<int>>,vector<vector<int>>, int);
vector<vector<int>> add(vector<vector<int>>, vector<vector<int>>);
vector<vector<int>> sub(vector<vector<int>>, vector<vector<int>>);
vector<vector<int>> join(vector<vector<int>>&,vector<vector<int>>&,vector<vector<int>>&,vector<vector<int>>&);
void randomFill(vector<vector<int>>&,int);
void printmatrix(vector<vector<int>>);
#endif //AD_SE_4_UE5_H
