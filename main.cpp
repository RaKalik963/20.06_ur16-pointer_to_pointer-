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
T** addRowAtPosition(T** arr, int& row, int col, T* newRow, int position) {
    T** newArr = createMatrix<T>(row + 1, col);
    for (int i = 0; i < position; i++) {
        for (int j = 0; j < col; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
    for (int j = 0; j < col; j++) {
        newArr[position][j] = newRow[j];
    }
    for (int i = position; i < row; i++) {
        for (int j = 0; j < col; j++) {
            newArr[i + 1][j] = arr[i][j];
        }
    }
    row++;
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

    int* newRow = new int[col];
    for (int i = 0; i < col; i++) {
        newRow[i] = rand() % 10;
    }

    int position;
    cout << "Enter position to insert the new row: ";
    cin >> position;

    int** newArr = addRowAtPosition(arr, row, col, newRow, position);

    cout << "Array after adding a new row at position " << position << ":" << endl;
    printMatrix(newArr, row, col);

    // Free allocated memory
    for (int i = 0; i < row; i++) {
        delete[] newArr[i];
    }
    delete[] newArr;
    delete[] newRow;


	system("pause");
	return 0;
}