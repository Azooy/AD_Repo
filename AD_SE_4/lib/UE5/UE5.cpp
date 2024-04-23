//
// Created by jendrik on 22.04.2024.
//

#include "UE5.h"




///For MergeSort Vizualisation

void swap(int& a, int& b){
    int helper = a;
    a = b;
    b = helper;
}

void Merge(int a[],int f,int l,int m) {
    int i;
    int n = (l - f) + 1;
    int a1f = f, a1l = m-1;
    int a2f = m, a2l = l;
    int *anew = new int[n];
    std::cout << "unmerged Array: \n";
    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    for (i = 0;i < n; i++)
    { if (a1f <= a1l) {
            if (a2f <= a2l)
            { if (a[a1f] <= a[a2f]) anew[i]=a[a1f++];
                else anew[i]=a[a2f++]; }
            else anew[i]=a[a1f++]; }
        else anew[i]=a[a2f++]; }

    std::cout << "merged array: \n";
    for (i=0;i<n;i++){
        std::cout << anew[i]<< " ";
        a[f+i]=anew[i];
    }
    std::cout << "\n";
    delete [] anew;
}

void MergeSort(int a[],int f,int l)
{ if (f<l) {
        int m = (f+l+1)/2;
        MergeSort(a,f,m-1);
        MergeSort(a,m,l);
        Merge(a,f,l,m); }
}


void Heapify(int a[],int f,int l,int root)
{
    int largest, left=f+(root-f)*2+1, right=f+(root-f)*2+2;

    if (left<=l && a[left]>a[root]) largest=left;
    else largest=root;
    if (right<=l && a[right]>a[largest]) largest=right;
    if (largest!=root) {
        swap(a[root],a[largest]);
        std::cout << "array after heapify: ";
        for(int i = 0; i < 9; i++){
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
        Heapify(a,f,l,largest);

    }
}

void HeapSort(int a[],int f,int l)
{
    BuildHeap(a,f,l);
    for (int i=l;i>f;i--)
    {
        swap(a[f],a[i]);
        Heapify(a,f,i-1,f);
    }
}

void BuildHeap(int a[],int f,int l)
{
    int n=l-f+1;
    for (int i=f+(n-2)/2;i>=f;i--)
        Heapify(a,f,l,i);
}



vector<vector<int>> matmul1(vector<vector<int>> m1, vector<vector<int>> m2){ // Annahme 2x2 Matrix
    int n = m1.size()/2;
    vector<vector<int>> result(n, vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> join(vector<vector<int>> O_11, vector<vector<int>> O_12,vector<vector<int>> O_21,vector<vector<int>> O_22){

}


vector<vector<int>> add(vector<vector<int>> m1, vector<vector<int>> m2){
    int size=m1.size()/2;
    vector<vector<int>> result(size/2, vector<int>(size/2,0));
    for(int i = 0; i < size; i++){
        for(int j=0; j < size; j++){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}


vector<vector<int>> sub (vector<vector<int>> m1, vector<vector<int>> m2) {
    int size = m1.size() / 2;
    vector<vector<int>> result(size / 2, vector<int>(size / 2, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }

    }
    return result;
}



vector<vector<int>> split(vector<vector<int>> m, int rstart,int cstart, int rend, int cend){
    vector<vector<int>> result(rend-rstart, vector<int>(cend-cstart,0));
    int row = 0;
    for(int i = rstart; i < rend; i++){
        int col = 0;
        for(int j = cstart; j < cend; j++){
            result[row][col] = m[i][j];
            col++;
        }
        row++;
    }

    return result;
}

vector<vector<int>> strassen(vector<vector<int>>& m, vector<vector<int>>& n, int len){
    int H1, H2, H3, H4, H5, H6, H7;
    int length = m.size();
    vector<vector<int>> result(len/2, vector<int>(len/2, 0));
    if(length <= 4){
        H1 = (m[0][0]+ m[1][1]) * (n[0][0] + n[1][1]);
        H2 = (m[1][0]+m[1][1]) * n[0][0];
        H3 = m[0][0]*(n[0][1] - n[1][1]);
        H4 = m[1][1]*(n[1][0] - n[0][0]);
        H5 = (m[0][0] + m[0][1]) * n[1][1];
        H6 = (m[1][0]-m[0][0]) * (n[0][0]+n[0][1]);
        H7 = (m[0][1]-m[1][1]) * (n[1][0]+n[1][1]);
        result[0][0] = H1 + H4 - H5 + H7;
        result[0][1] = H3+H5;
        result[1][0] = H2 + H4;
        result[1][1] = H1 - H2 + H3 + H6;
        return result;
    } else {
        vector<vector<int>> a,b,c,d,e,f,g,h;
        vector<vector<int>> p1,p2,p3,p4,p5,p6,p7,p8;
        //vector<vector<int>> a(20, vector<int>(20, 0));
        //Splitting the left matrix
        a = split(m, 0, 0, (len/2), (len/2));
        b = split(m, 0,(len/2)+1, len/2, len);
        c = split(m, len/2+1, 0, len, len/2);
        d = split(m, len/2+1, len/2+1, len, len);

        //Splitting the right matrix
        e = split(n, 0, 0, len/2, len/2);
        f = split(n, 0,len/2+1, len/2, len);
        g = split(n, len/2+1, 0, len, len/2);
        h = split(n, len/2+1, len/2+1, len, len);
        int slength = len/2;
        p1= strassen(add(a,d),add(e,h), slength);
        p2= strassen(add(c,d),e, slength);
        p3= strassen(a,sub(f,h), slength);
        p4= strassen(d,sub(g,e),slength);
        p5= strassen(add(a,b),h, slength);
        p6= strassen(sub(c,a),(e,f), slength);
        p7= strassen(sub(b,h),add(g,h), slength);

        vector<vector<int>> O_11,O_12,O_21,O_22;
        O_11 = sub(add(p1, p4), add(p5,p7));
        O_12 = add(p3,p4);
        O_21 = add(p2,p4);
        O_22 = add(sub(p1,p2),add(p3,p6));

        /*
         * Hier muss noch der Join realisiert werden, dafür eine weitere Zielmatrix mit der ganz ursprünglichen
         * Größe erstellen. Dabei 4 For-Loops die entsprechend für den Quadranten links oben, rechts oben, links unten, rechts unten
         * mappen. (ist easy trust me)
         *
         * */

    }

}

/*
 *  a b     e f
 *  c d     g h
 *
 */

