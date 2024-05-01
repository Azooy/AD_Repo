#include <iostream>
#include "lib/UE6/Lottery/Ringlist.h"
#include "lib/UE6/Rucksack/Rucksack.h"
#include "random"

using namespace std;



int main() {
    //Driver Code

    tuple_cl arr[3];
    arr[0].val=60.0;
    arr[0].weight = 10.0;
    arr[1].val = 100.0;
    arr[1].weight = 20.0;
    arr[2].val = 120.0;
    arr[2].weight = 30.0;


    // Declaring the upper and lower
    // bounds
    double lower_bound = 0;
    double upper_bound = 1;

    uniform_real_distribution<double> unif(lower_bound,
                                           upper_bound);

    uniform_real_distribution<double> unid(3.0,6.0);
    default_random_engine re;

    /*for(int i = 0; i < 10; i++){
        double random_value = unif(re);
        double random_weight = unid(re);
        arr[i] = tuple_cl((random_value / 100) * 100, random_weight);
    }*/

    backpack(arr, 50.0, 2);

}