#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cout << "Enter the matrix dimensions ";
    if (!(cin >>n) || n<1 || n>10) {
        cout<<"ERROR"<<endl;
        return 0;
    }                               //ввод размерности матрицы

    int** matrix = new int*[n];
    for (int i=0; i<n; ++i) {
        matrix[i] = new int[n];
    }                                        //выделение памяти

    cout <<"Enter the matrix elements."<< endl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >>matrix[i][j];
        }
    }                                      // Ввод элементов матрицы

    cout <<"Matrix:"<< endl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }                                           //вывод матрицы

    int neighbor=0;
    int a=0;
    for (int i=1; i<n-1; ++i){
        for (int j=1; j<n-1; ++j){
           neighbor = max({matrix[i-1][j-1], matrix[i][j-1], matrix[i+1][j-1],matrix[i-1][j],matrix[i+1][j],matrix[i-1][j+1], matrix[i][j+1], matrix[i+1][j+1]});
           if (neighbor<matrix[i][j]){
                cout<<"Local max --"<< matrix[i][j] << "("<< i << "," << j << ")"<< endl;
                a++;
            }
        }
    }
    if (a==0)
    cout <<"No local max"<< endl;      //вывод локального максимума

    int pr=1; 
    for (int i=1; i<n; ++i) {
        for (int j=n-i; j<n; ++j) {
            pr*=matrix[i][j];
        }
    }                      
    cout<<"product of elements -- "<< pr << endl;                                  //вывод произведения

    for (int i=0; i<n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;                //освобождение памяти

    return 0;
}
