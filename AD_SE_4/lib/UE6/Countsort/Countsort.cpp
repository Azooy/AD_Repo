void countsort(int array[], int highestNumber, int size) {
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
