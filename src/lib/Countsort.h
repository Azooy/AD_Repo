//
// Created by Jendrik Juergens on 30.04.24.
//

#ifndef AD_SE_4_COUNTSORT_H
#define AD_SE_4_COUNTSORT_H
#include <stdlib.h>
#include <limits.h>

void MapSort_6(int[],int, double);
void countsort_6(int [], int, int);
void HeapSort_6(int [],int,int);
void BuildHeap_6(int [],int ,int );
void Heapify_6(int [],int,int,int);
void swap_6(int&, int&);

// Count-Sort ist besonders gut, wenn der Wertebereich von 0 bis k relativ klein ist. Die Laufzeit wird nicht durch die 
// Größe des Eingabe-Arrays bestimmt, sondern durch k
// Heap-Sort hat im Worst-Case die Laufzeit O(n log(n)) (über alle Eingabelängen)
// Map-Sort dagegen ist besonders gut wenn k groß ist. 

#endif //AD_SE_4_COUNTSORT_H
