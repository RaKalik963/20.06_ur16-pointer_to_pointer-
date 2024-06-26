#include <iostream>
#include <ctime>
using namespace std;



template<typename T>
T** createMatrix(int row, int col) {
    T** arr = new T * [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new T[col];
    }
    return arr;
}

template<typename T>
void fillMatrix(T** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

template<typename T>
void printMatrix(T** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
T** addColumnAtPosition(T** arr, int row, int& col, T* newCol, int position) {
    T** newArr = createMatrix<T>(row, col + 1);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < position; j++) {
            newArr[i][j] = arr[i][j];
        }
        newArr[i][position] = newCol[i];
        for (int j = position; j < col; j++) {
            newArr[i][j + 1] = arr[i][j];
        }
    }
    col++;
    return newArr;
}

int main() {
    srand(time(0));
    int col, row;
    cout << "enter column: ";
    cin >> col;
    cout << "enter rows: ";
    cin >> row;

    int** arr = createMatrix<int>(row, col);
    fillMatrix(arr, row, col);

    cout << "Original array:" << endl;
    printMatrix(arr, row, col);

    int* newCol = new int[row];
    for (int i = 0; i < row; i++) {
        newCol[i] = rand() % 10;
    }

    int position;
    cout << "Enter position to insert the new column: ";
    cin >> position;

    int** newArr = addColumnAtPosition(arr, row, col, newCol, position);

    cout << "Array after adding a new column at position " << position << ":" << endl;
    printMatrix(newArr, row, col);

    for (int i = 0; i < row; i++) {
        delete[] newArr[i];
    }
    delete[] newArr;
    delete[] newCol;
	system("pause");
	return 0;
}