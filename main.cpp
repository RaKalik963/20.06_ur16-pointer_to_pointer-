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

template<typename T>
T** addRowToEnd(T** arr, int& row, int col, int* newRow) 
{
    T** newArray = new T* [row + 1];
    for (int i = 0; i < row; ++i) 
    {
        newArr[i] = arr[i];
    }
    newArr[row] = newRow;
    ++row;
    delete[] arr;
    return newArr;
}

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
    int col, row;
    cout << "enter column";
    cin >>
    int** arr = createMatrix<int>(row, col);
    fillMatrix(arr, row, col);
    printMatrix(arr, row, col);
    for (int i = 0; i < row; ++i) {
        arr[i] = new int[col] {i + 1, i + 2};
    }

    int* newRow = new int[col] {5, 6};
    arr = addRowToEnd<int>(arr, row, col, newRow);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}