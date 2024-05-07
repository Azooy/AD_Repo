//
// Created by Jendrik Juergens on 01.05.24.
//

#include "../lib/Rucksack.h"

// Überlegung: Array erst einmal sortieren?

tuple_cl::tuple_cl(): val(0), weight(0), ratio(0){};
tuple_cl::tuple_cl(double val_): val(val_), weight(0), ratio(0){};
tuple_cl::tuple_cl(double val_, double weight_): val(val_), weight(weight_), ratio(val_/weight_){};

void tuple_cl::print(){
    std::cout << val << " " << weight << endl;
}
void printarray(tuple_cl arr_cost[], int size_vals){
    for(int i = 0; i <= size_vals; i++){
        arr_cost[i].print();
    }std::cout << "------" << endl;}


// Iterates once over the sorted array and inserts the "best" element in terms of weight to value
// if the weight is to heavy for the remaining capacity go to the element with the next lower
// weight-to-value ratio
double max_weight(tuple_cl arr_cost[], int size, int cap) {
    int profit = 0;
    int postIndex = size;
    tuple_cl* array=new tuple_cl[size];
    double max = 0;
    while (postIndex) {
        if (arr_cost[postIndex].weight <= cap) {
            max += arr_cost[postIndex].weight;
            cap -= arr_cost[postIndex].weight;
            profit+=arr_cost[postIndex].val;
            array[postIndex] = arr_cost[postIndex];
            postIndex--;
        } else {
            postIndex--;
        }
    }
    delete[] array;
    std::cout << "The maximum profit is : " << profit << endl;
    return max;
}

void backpack(tuple_cl arr_cost[], double capacity, int size_vals) {
    mergesort(arr_cost,0, size_vals);
    // now calculate the maximum weights
    printarray(arr_cost, size_vals);
    double max = max_weight(arr_cost, size_vals, capacity);
    std::cout << "The maximum weight is " << max << std::endl;
}

void merge(tuple_cl arr_cost[], int first, int last, int middle) {
    int i;
    int n = last - first + 1;
    int leftfirst = first, leftlast = middle - 1;
    int rightfirst = middle, rightlast = last;
    auto arr_cost_temp = new tuple_cl[n];
    for (i = 0; i < n; i++) {
        /* Check for size of the left array == left array >= 1 Elements? */
        if (leftfirst <= leftlast) {
            /* Check for the size of the right array == right array >= 1 Elements? */
            if (rightfirst <= rightlast) {
                if (arr_cost[leftfirst].ratio <= arr_cost[rightfirst].ratio) {
                    arr_cost_temp[i] = arr_cost[leftfirst];
                    leftfirst++;
                } else {
                    arr_cost_temp[i] = arr_cost[rightfirst];
                    rightfirst++;
                };
            } else {
                arr_cost_temp[i] = arr_cost[leftfirst];
                leftfirst++;
            }
        } else {
            arr_cost_temp[i] = arr_cost[rightfirst];
            rightfirst++;
        }
    }
    for(int i = 0; i < n; i++) {
        arr_cost[first + i] = arr_cost_temp[i];}
    delete[] arr_cost_temp;
}

void mergesort(tuple_cl arr_cost[], int first, int last) {
    if(first < last){
        int middle = (last+first+1)/2;
        mergesort(arr_cost, first, middle-1);
        mergesort(arr_cost, middle, last);
        merge(arr_cost, first, last, middle);
    }
}

