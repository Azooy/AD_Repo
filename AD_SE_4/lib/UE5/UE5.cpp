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
    int n1 = m1.size();
    vector<vector<int>> result(n1, vector<int>(n1,0));
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n1; j++){
            for(int k = 0; k < n1; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}




vector<vector<int>> add(vector<vector<int>> m1, vector<vector<int>> m2){
    int size=m1.size();
    int size2=m2.size();
    vector<vector<int>> result(size, vector<int>(size,0));
    for(int i = 0; i < size; i++){
        for(int j=0; j < size; j++){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}


vector<vector<int>> sub (vector<vector<int>> m1, vector<vector<int>> m2) {
    int size = m1.size();
    vector<vector<int>> result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }

    }
    return result;
}



vector<vector<int>> split(vector<vector<int>> m, int rstart,int cstart, int rend, int cend){
    vector<vector<int>> result(m.size()/2, vector<int>(m[0].size()/2,0));
    int row = 0;
    int col = 0;
    for(int i = rstart; i < rend; i++){
        col = 0;
        for(int j = cstart; j < cend; j++){
            int test = m[i][j];
            result[row][col] = m[i][j];
            col++;
        }
        row++;
    }

    return result;
}

vector<vector<int>> join (vector<vector<int>>& O_11,vector<vector<int>>& O_12,vector<vector<int>>& O_21,vector<vector<int>>& O_22){
    int rowC = O_11.size();
    int colC = O_11[0].size();
    int rowEnd = rowC*2;
    int colEnd = colC*2;
    vector<vector<int>> result(2*rowC, vector<int>(2*colC, 0));

    int rowIndex=0;
    int colIndex=0;
    //For upper left
    // For upper left
    for(int i = 0; i < rowC/2; i++){
        for(int j = 0; j < colC/2; j++){
            result[i][j] = O_11[i][j];
        }
    }

    // For upper right
    for(int i = 0; i < rowC; i++){
        for(int j = colEnd/2; j < colEnd; j++){
            result[i][j*2] = O_12[i][j];
        }
    }

    // For lower left
    for(int i = rowC; i < rowEnd; i++){
        for(int j = 0; j < colC; j++){
            result[i][j] = O_21[i-rowC][j];
        }
    }

    // For lower right
    for(int i = rowC; i < rowEnd; i++){
        for(int j = colC; j < colEnd; j++){
            result[i][j] = O_22[i-rowC][j-colC];
        }
    }

    return result;
}
  /*  for(int i = 0; i < rowC;i++){
        colIndex=0;
        for(int j = 0; j < colC;j++){
            result[i][j] = O_11[rowIndex][colIndex];
            colIndex++;
        }
        rowIndex++;
    }


    //For upper right
    rowIndex=0;
    colIndex=0;

    for(int i = 0; i < rowEnd; i++){
        colIndex=0;
        for(int j = colEnd/2; j < colEnd;j++){
            result[i][j] = O_12[rowIndex][colIndex];
            colIndex++;
        }
        rowIndex++;
    }

    //For lower left
    rowIndex=0;
    colIndex=0;
    for(int i = rowEnd/2; i < rowEnd; i++){
        colIndex=0;
        for(int j = 0; j < colEnd/2; j++){
            result[i][j] = O_21[rowIndex][colIndex];
            colIndex++;
        }
        rowIndex++;
    }

    //For lower right
    rowIndex=0;
    colIndex=0;
    for(int i = rowC + 1; i < rowEnd; i++){
        colIndex=0;
        for(int j = colC; j < colEnd; j++){
            result[i][j] = O_22[rowIndex][colIndex];
            colIndex++;
        }
        rowIndex++;
    }

    return result;
}*/

vector<vector<int>> strassen(vector<vector<int>> m, vector<vector<int>> n, int len){
    int H1, H2, H3, H4, H5, H6, H7;
    int length = m.size();
    //vector<vector<int>> result(len/2, vector<int>(len/2, 0));
    if(length <= 2){
        //vector<vector<int>> result(len, vector<int>(len, 0));
        return matmul1(m,n);
    } else {
        //vector<vector<int>> result(len/2, vector<int>(len/2, 0));
        vector<vector<int>> a,b,c,d,e,f,g,h;
        vector<vector<int>> p1,p2,p3,p4,p5,p6,p7,p8;
        //Splitting the left matrix
        a = split(m, 0, 0, (len/2), (len/2));
        b = split(m, 0,(len/2), (len/2), len);
        c = split(m, len/2, 0, len, (len/2));
        d = split(m, len/2, len/2, len, len);

        //Splitting the right matrix
        e = split(n, 0, 0, (len/2), (len/2));
        f = split(n, 0,len/2, (len/2), len);
        g = split(n, len/2, 0, len, (len/2));
        h = split(n, len/2, len/2, len, len);
        int slength = len/2;
        p1= strassen(add(a,d),add(e,h), slength);
        p2= strassen(add(c,d),e, slength);
        p3= strassen(a,sub(f,h), slength);
        p4= strassen(d,sub(g,e),slength);
        p5= strassen(add(a,b),h, slength);
        p6= strassen(sub(c,a),add(e,f), slength);
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

        return join(O_11, O_12, O_21, O_22);
    }


}

/*
 *  a b     e f
 *  c d     g h
 *
 */

