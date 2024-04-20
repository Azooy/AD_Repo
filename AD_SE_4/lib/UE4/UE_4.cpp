#include "iostream"
#include "tuple"
#include "stack"
#include "UE_4.h"

int binSearch(int a[], int length, int search){
    int up=length-1;
    int down=length;
    int i = length-1;
    while(a[i] != search){
        std::cout << i << std::endl;
        if(search < a[i]){
            up = i;
            i = i / 2;
        } else if(search > a[i]){
            i = (i + up)/2;
        }
    }
    return i;
}


void swapb(int &a, int &b){
    int helper = a;
    a=b;
    b = helper;
}


void bubblesortRev(int a[], int length){
    for(int i = length; i >= 0; i--){
        for(int j = 0; j<i; j++){
            if(a[j] >= a[j+1]){
                swapb(a[j],a[j+1]);
            }
        }

    }
}
/* Laufzeit und Korrektheit: Bubblesort Reverse:
 * Laufzeit:Ann.: Laufzeit = Bubblesort = O(n^2)
 * "Beweis" zur Korrektheit:
 * BubblesortRev iteriert über zwei Schleifen mit den Indizes i und j welche
 * dabei jeweils einen Zeiger auf das Ende des Arrays a[] (Hier Index i) und auf den Anfang des Arrays
 * darstellen. Hierbei laufen i & j entgegengesetzt (i--; j++).
 * Die Worst-Case Betrachtung des Bubblesort-Reverse wäre, dass das gegegebene Array bereits absteigend
 * sortiert wäre. Auf der rechten Seite des Arrays entsteht ein sortiertes Sub-Array, welches durch den
 * Laufindex j gefüllt wird.
 *
 */


void insertionSort(int a[], int length){
    int key;
    for(int i = 1; i < length; i++){ // Nehme das nächste rechte Element neben dem sortierten Subarray
        key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j]; //Schiebe das Array nach rechts
            j--;
        }
        a[j+1] = key;
    }
}

void insertionSortRev(int a[], int length){
    int key;
    for(int i = length - 1; i > 0; i--){ // Rechts beginnen, Sorted Subarray ist also am Ende des Arrays
        key = a[i]; // greife das Element auf dem i gerade steht
        int j = i + 1; // nehme das Element rechts von i
        while(j <= length && a[j] < key){ //
            a[j-1] = a[j]; // Schiebe alles nach links
            j++;
        }
        a[j-1] = key;
    }
}

/*
 * Laufzeit und Korrektheit: Insertionsort-Reverse
 * Laufzeit: Ann.: Worst-Case Betrachtung gleich wie bei "normalem" Insertionsort => O(n^2)
 * Korrektheit: Am Ende des Arrays wächst das sortierte Subarray. Durch key = a[i] wird das
 * nächste linke Element gegriffen. Der Index j wird dabei auf den "Anfang" des sortierten Subarrays gesetzt
 * Solange nun der "Key" größer als das Element ist, auf welches der Laufindex "j" zeigt, wird das sortierte
 * Array um eine stelle nach links geschoben und der Zeiger "j" wird inkrementiert für den nächsten Vergleich.
 * Sobald entweder das Ende des Arrays erreicht wird, wird der Key ans Ende des Arrays gesetzt oder, falls
 * der Key kleiner als a[j] ist, wird der Key eine Stelle vor a[j], also an a[j-1] gesetzt.
 * */


void swapq(int & a, int & b){
    int helper = a;
    a = b;
    b = helper;
}

void preparePartition(int a[], int indexOfPivot, int lastIndexOfArray, int &p) {
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
            swapq(a[i], a[p]);
        }
    }
    swapq(a[indexOfPivot], a[p]);


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

void quicksort(int a[], int firstIndex, int lastIndex){
    int part;
    if(firstIndex < lastIndex){
        preparePartition(a, firstIndex, lastIndex, part);
        quicksort(a, firstIndex, part - 1);
        quicksort(a, part+1, lastIndex);

    }

}

void selectionSort(int a[], int length){
    int i, j, max;
    for(int i = length-1; i >= 0; i--){
        max = i;
        for(int j = i; j >= 0; j--){
            if(a[max] < a[j]){
                max = j;
            }

        }
        int helper = a[max];
        a[max] = a[i];
        a[i] = helper;
    }
}

/* Laufzeit & Korrektheit:
 * Laufzeit: Best,Average & Worst-Case = O(n^2) (Es wird jedes Element mit jedem Element verglichen)
 * Korrektheit: SelectionSort hat wird über zwei geschachtelte For-Loops realisiert.
 * Im ersten Durchgang haben dabei beide Laufindizes den selben Wert. Der Laufindex i gibt dabei maßgeblich
 * den Start welcher hier von rechts beginnt, an. Die Laufvariable j läuft dabei von i bis 0 und vergleicht
 * dabei den Startwert a[i] mit jedem anderen Wert über den die innere Schleife iteriert.
 * Wird ein Wert mit Index j gefunden, welche größer als das derzeitige Maximum
 * (initialisierung auf i), so bekommt die Varibale "max" entsprechend j zugewiesen. Nachdem die innere
 * Schleife terminiert wird in jedem Fall ein Austausch der Werte von a[i] und a[max] durchgeführt.
 * Sollte kein Element gefunden werden, welches größer als a[i] ist, wird a[i] mit a[max] getautscht werden.
 * Da max = 1 zu beginn der äußeren For-Loop initialisiert wird, wird i mit sich selbst getauscht
 * */

void Merge(int a[],int f,int l,int m) {
    int i;
    int n = l - f + 1; // Calculate the size of the array
    int a1f = f, a1l = m-1; // Calculate the first and last index of the left array
    int a2f = m, a2l = l; // Calculate the first and last index of the right array
    int *anew = new int[n]; // Reserve Memory for extra array
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
    delete [] anew; // Gib Speicherplatz wieder frei
}

void MergeSort(int a[],int f,int l){
    if (f<l) { // Rufe die Funktion solange bis nur noch ein Element im Array ist.
        int m = (f+l+1)/2;
        MergeSort(a, f,m-1);
        MergeSort(a,m, l);
        Merge(a,f,l,m);
    }
}

bool findS(int a[], int length, int s){
    int leftpointer = 0;
    int rightpointer = length;
    while(leftpointer <= rightpointer){
        if(a[leftpointer] + a[rightpointer] > s){
            rightpointer--;
        } else if(a[leftpointer] + a[rightpointer] < s){
            leftpointer++;
        }
        else if(a[leftpointer]+a[rightpointer]==s){
            std::cout << leftpointer << " " << rightpointer << std::endl;
            return true;
        }
    }
    return false;
}

void insertionSort_rec(int a[], int length, int i) {
    if (i < length) {
        int key = a[i];
        int j = i - 1; // j ist der index um durch das Sortierte Array zu iterieren
        while (j >= 0 && key < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        insertionSort_rec(a, length, i + 1);
    }
}
