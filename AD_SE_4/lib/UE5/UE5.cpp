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

void randomFill(vector<vector<int>>& matrix, int length){
    int random;
    for(int i= 0; i < length; i++){
        for(int j = 0; j < length;j++){
            matrix[i][j] = rand()%100;
        }
    }
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


    // For upper left
    for(int i = 0; i < rowC; i++){
        for(int j = 0; j < colC; j++){
            result[i][j] = O_11[i][j];
        }
    }

    // For upper right
    for(int i = 0; i < rowC; i++){
        for(int j = colC; j < colEnd; j++){
            result[i][j] = O_12[i][j-colC];
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

void printmatrix(vector<vector<int>> matrix){
    cout << "---------------"<<endl;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix.size();j++){
            cout << matrix[i][j] << " ";
        }
     cout << endl;
    }
    cout << "----------" << endl;
}

vector<vector<int>> strassen(vector<vector<int>> m, vector<vector<int>> n, int len){
    int H1, H2, H3, H4, H5, H6, H7;
    int length = m.size();
    //vector<vector<int>> result(len/2, vector<int>(len/2, 0));
    if(length <= 2){
        vector<vector<int>> result(len, vector<int>(len, 0));
        result = matmul1(m,n);
        return result;
    } else {

        vector<vector<int>> m_11,m_12,m_21,m_22,n_11,n_12,n_21,n_22;
        vector<vector<int>> p1,p2,p3,p4,p5,p6,p7,p8;
        //Splitting the left matrix
        m_11 = split(m, 0, 0, (len / 2), (len / 2));
        m_12 = split(m, 0, (len / 2), (len / 2), len);
        m_21 = split(m, len / 2, 0, len, (len / 2));
        m_22 = split(m, len / 2, len / 2, len, len);

        //Splitting the right matrix
        n_11 = split(n, 0, 0, (len / 2), (len / 2));
        n_12 = split(n, 0, len / 2, (len / 2), len);
        n_21 = split(n, len / 2, 0, len, (len / 2));
        n_22 = split(n, len / 2, len / 2, len, len);
        int slength = len/2;
        p1= strassen(add(m_11, m_22), add(n_11, n_22), slength);
        p2= strassen(add(m_21, m_22), n_11, slength);
        p3= strassen(m_11, sub(n_12, n_22), slength);
        p4= strassen(m_22, sub(n_21, n_11), slength);
        p5= strassen(add(m_11, m_12), n_22, slength);
        p6= strassen(sub(m_21, m_11), add(n_11, n_12), slength);
        p7= strassen(sub(m_12, m_22), add(n_21, n_22), slength);



        vector<vector<int>> O_11,O_12,O_21,O_22;
        O_11 = sub(add(p1,p4), add(p5,p7));
        O_12 = add(p3,p5);
        O_21 = add(p2,p4);
        O_22 = add(sub(p1,p2),add(p3,p6));
        


        return join(O_11, O_12, O_21, O_22);
    }


}

/*
 *  a b     e f
 *  c d     g h
 *
 */

