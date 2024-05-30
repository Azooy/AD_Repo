//
// Created by Jendrik Juergens on 18.04.24.
//

#include "UE_3.h"
#include "iostream"
#include "vector"
#include "stack"
#include "tuple"
#include <limits.h>

#define ROW 3
#define COL 3

int kadane(std::vector<int> arr){
    int currSum;
    int max;
    int s;
    for(int i = 0; i < ROW; i++){
        std::cout << arr[i] << " ";
        s = currSum + arr[i];
        if(s > arr[i]) {
            currSum = s;
        } else {
            currSum=arr[i];
        }
        if(currSum > max) {
            max = currSum;
        }
    }
    std::cout << " \n";
    return max;
}

int maxSum2D(std::vector<std::vector<int>> array){
    int left;
    int right;
    int selection;
    int max = INT_MIN;
    std::vector<int> temp(ROW, 0);
    int sum;
    for(left = 0; left < COL; left++){
        fill(temp.begin(), temp.end(), 0);
        for(right = left; right<COL; right++){
            for(selection = 0; selection < ROW; selection++){
                temp[selection] += array[selection][right];
            }
            sum = kadane(temp);
            if(sum > max){
                max = sum;
            }
        }

    }
    return max;
}



int ackermannRec(int n, int m){
    if(n == 0){
        return m+1;
    } else if(m == 0 && n >=1){
        return ackermannRec(n-1, m);
    } else {
        ackermannRec(n-1, ackermannRec(n,m-1));
    }
    return m;
}


int ackermannIT(int n, int m){
    std::stack<std::pair<int, int>> stack;
    while(true){
        if(n == 0){
            return m+1;
        } else if(m == 0 && n >= 1){
            stack.push({n-1, 1});
        } else {
            stack.push({n-1, ackermannIT(n,m-1)});
        }
        if(stack.empty()){
            break;
        }
        std::tie(n,m)=stack.top();
        stack.pop();
    }
    return m;
}