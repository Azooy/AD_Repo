#include "../lib/Countsort.h"

void swap_6(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void countsort_6(int array[], int highestNumber, int size) {
    int *tempArray = new int[highestNumber + 1];
    int i, j = 1;
    // fill temparray with 0's -- Runtime k
    for (int i = 0; i < highestNumber + 1; i++) {
        tempArray[i] = 0;}

    // Iterate over the given array and insert values in tempArray, Runtime k
    for (int i = 0; i < highestNumber; i++) {
        tempArray[array[i]]++;}

    int* sortedArray = new int[size];
    int index =0;
    for(int i = 0; i<size;i++){
        while(tempArray[i]>0){
            sortedArray[index++] = i;
            tempArray[i]--;
        }
    }

    for (i = 0; i < size; i++) {
        array[i] = sortedArray[i];
    }

    delete[] tempArray;
    delete[] sortedArray;
}

void BuildHeap_6(int a[],int f,int l)
{
    int n=l-f+1;
    for (int i=f+(n-2)/2;i>=f;i--)
        Heapify_6(a,f,l,i);
}

void HeapSort_6(int a[],int f,int l){
    BuildHeap_6(a,f,l);
    for (int i=l;i>f;i--){
        swap_6(a[f],a[i]);
        Heapify_6(a,f,i-1,f);
    }
}

void Heapify_6(int a[],int f,int l,int root) {
    int largest, left=f+(root-f)*2+1, right=f+(root-f)*2+2;
    if (left<=l && a[left]>a[root]) largest=left;
        else largest=root;

    if (right<=l && a[right]>a[largest]) 
        largest=right;
    if (largest!=root) {
        swap_6(a[root],a[largest]);
        Heapify_6(a,f,l,largest); }
}

void MapSort(int a[],int n, double c) {
    int newn=(int)((double)n*c), i, j=0;
    int *bin=new int[newn], max=INT_MIN, min=INT_MAX;
    for (i=0;i<newn;i++) bin[i]=-1;
    for (i=0;i<n;i++) { if
         (a[i]<min) min=a[i];
        if (a[i]>max) max=a[i]; }
    double dist=(double)(max-min)/(double)(newn-1);
    for (i=0;i<n;i++) {
        int t=(int)((double)(a[i]-min)/dist), insert=a[i], left=0;
        if (bin[t]!=-1 && insert<=bin[t]) left=1;
        while (bin[t]!=-1) {
            if (left == 1) { 
                if (insert>bin[t]) 
                    swap_6(bin[t],insert);
                    if (t>0) 
                        t--; 
                    else left=0; }
        else { 
            if(insert<=bin[t]) 
                swap_6(bin[t],insert);
            if (t<newn-1) 
                t++; 
            else 
                left=1; } 
        }
            bin[t]=insert; 
        }
    for (i=0;i<newn;i++) if (bin[i]!=-1) a[j++]=bin[i];
    delete [] bin; 
    }
