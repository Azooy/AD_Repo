#include <iostream>
#include "src/lib/Rucksack.h"
#include "src/lib/Ringlist.h"
#include "random" 
#include "src/lib/Countsort.h"

using namespace std;



int main() {
    //Driver Code

    tuple_cl arr[3];
    arr[0].val=120.0;
    arr[0].weight = 10.0;
    arr[1].val = 100.0;
    arr[1].weight = 20.0;
    arr[2].val = 160.0;
    arr[2].weight = 30.0;





    // Declaring the upper and lower
    // bounds
    double lower_bound = 0;
    double upper_bound = 1000;

    uniform_real_distribution<double> unif(lower_bound,
                                           upper_bound);

    uniform_real_distribution<double> unid(3.0,6.0);
    default_random_engine re;

    

    backpack(arr, 50.0, 2);
    return 0;

}