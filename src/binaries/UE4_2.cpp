//
// Created by Jendrik Juergens on 20.04.24.
//



#include "UE4_2.h"

void swapq_vec(int & a, int & b){
    int helper = a;
    a = b;
    b = helper;
}

void merge_vec(std::vector<int>& a,int f,int l,int m) {
    int i;
    int n = l - f + 1; // Calculate the size of the array
    int a1f = f, a1l = m-1; // Calculate the first and last index of the left array
    int a2f = m, a2l = l; // Calculate the first and last index of the right array
    std::vector<int> anew(n); // Reserve Memory for extra array
    for (i = 0; i < n; i++) // Iterate over the array
    {
        if (a1f <= a1l) { // Ist der letzte Index größer gleich als der erste? vom linken array
            if (a2f <= a2l){ // ist der letzte Index größer gleich als der Erste? vom rechten array
                if (a[a1f] <= a[a2f]) // Ist der erste Index vom linken array kleiner/gleich dem des rechten?
                    anew[i]=a[a1f++]; // Dann setze das anew[i] den Wert vom linken array, dann schiebe pointer weiter
                else anew[i]=a[a2f++]; // Wenn nicht dann nehme den Wert vom rechten Array
            }
            else anew[i]=a[a1f++]; } // Es gibt nur ein Element in dem ganzen Array => sortiere ein ?
        else anew[i]=a[a2f++]; }
    for (i=0;i<n;i++)
        a[f+i]=anew[i]; // Platziere den Inhalt an die richtige Stelle in a[]
     // Gib Speicherplatz wieder frei
}

void MergeSort_Vec(std::vector<int>& a,int f,int l){
    if (f<l) { // Rufe die Funktion solange bis nur noch ein Element im Array ist.
        int m = (f+l+1)/2;
        MergeSort_Vec(a, f,m-1);
        MergeSort_Vec(a,m, l);
        merge_vec(a,f,l,m);
    }
}

void preparePartition_vec(std::vector<int>& a, int indexOfPivot, int lastIndexOfArray, int &p) {
    /*Just for randomness -- Swap first with random index
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<>dis(indexOfPivot, lastIndexOfArray);
    int rnum = dis(gen);
    swapq(a[indexOfPivot], a[rnum]);*/


    int pivot=a[indexOfPivot];
    p = indexOfPivot - 1;
    for(int i = indexOfPivot; i <= lastIndexOfArray; i++){
        if(a[i] <= pivot){
            p++;
            swapq_vec(a[i], a[p]);
        }
    }
    swapq_vec(a[indexOfPivot], a[p]);


}

/* Laufzeit und Korrektheit:
 * Laufzeit: Worst-Case betrachtung O(n^2) (Annahme: mod. SelectionSort hat gleiche Laufzeit wie "normaler")
 * Korrekheit: Rekursiver Aufruf von QuickSort-Funktion. Nach Divide & Conquer Grundsatz:
 * Beim aufrufen von PreparePartition wird zu Beginn eine Zufallszahl errechnet, welche dann mit dem Element
 * an der Stelle des PivotElements vertauscht wird. Darauf hin startet der eigentliche ALgorithmus. Es
 * Es wird Laufvariable i verwendet, welche mit dem Pivot-Index initialisiert wird, dazu kommt eine
 * weietere Variable p welche mittels Referenz übergeben wird. Beim Durchlaufen des Arrays durch die
 * Laufvariable i wird jedes Mal verglichen ob a[i] <= Pivot ist. Ist dies der Fall wird p inkrementiert.
 * p läuft dabei im optimal-Fall gemeinsam mit i durch das Array. Sollte der Fall auftreten, dass
 * a[i] > pivot sein, so wird nur i inkrementiert. Da p mindestens i-1 zu Beginn des nächsten
 * Schleifendurchlaufes ist, läuft i weiter durch das Array. Sobald das nächste Element gefunden wird,
 * welches <= als das Pivot ist, wird p wieder inkrementiert (p steht nach Inkrement nun auf dem
 * Index des Elementes welches größer als das Pivot ist. Nun wird a[i] und a[p] getauscht.
 * Nach dem die Schleife terminiert, wird das Pivot an die aktuelleste Stelle p getauscht.
 */

void quicksort_vec(std::vector<int>& a, int firstIndex, int lastIndex){
    int part;
    if(firstIndex < lastIndex){
        preparePartition_vec(a, firstIndex, lastIndex, part);
        quicksort_vec(a, firstIndex, part - 1);
        quicksort_vec(a, part+1, lastIndex);

    }

}

void bubblesort_vec(std::vector<int> a, int length){
    for(int i = length; i >= 0; i--){
        for(int j = 0; j<i; j++){
            if(a[j] >= a[j+1]){
                swapq_vec(a[j],a[j+1]);
            }
        }

    }
}