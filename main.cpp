#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** createMatrix(int row, int col)
{
    T** arr = new T * [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new T[col];
    }
    return arr;
}
void unite_arrays(int* arr1, int col, int* arr2, int row, int* C) {
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            C[i, j] = arr1[i, j];
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            C[col + i, row + j] = arr2[i, j];
        }
    }
}
/*template<typename T>
T** addRowToEnd(T** arr, int& row, int col, int* newRow) 
{
    T** P_arr = createMatrix<int>(row, col);
    for (int i = 0; i < row; ++i) 
    {
        P_arr[i] = arr[i];
    }
    P_arr[row] = newRow;
    ++row;
    delete[] arr;
    return P_arr;
}*/

template<typename T>
void fillMatrix(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

template<typename T>
void printMatrix(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int col, row;
    cout << "enter column";
    cin >> col;
    cout << "enter rows";
    cin >> row;
    int** arr1 = createMatrix<int>(row, col);
    int** arr2 = createMatrix<int>(row, col);

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr1[i][j] = rand() % 10;
        }
    }
   
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr2[i][j] = rand() % 10;
        }
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    fillMatrix(arr1, row, col);
    printMatrix(arr1, row, col);
    int* C = new int[col * 2, row * 2];

    unite_arrays(*arr1, col, *arr2, row, C);

    cout << "combined array ";
    for (size_t i = 0; i < col * 2; i++)
    {
        for (size_t j = 0; j < row * 2; j++)
        {
            cout << C[i, j] << " ";
        }
    }
    cout << endl;



    return 0;
}