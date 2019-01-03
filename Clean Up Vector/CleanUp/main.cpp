#include <iostream>
#include <vector>
#include <map>

using namespace std;

int **allocateTwoDimensionArrayOnHeapUsingNew(int, int);
void destroyTwoDimensionArrayOnHeapUsingDelete(int **, int, int);
void showTwoDimensionArrayOnHeap(int **, int, int);
int **allocateTwoDimensionArrayOnHeapUsingMalloc(int, int);
void destroyTwoDimensionArrayOnHeapUsingFree(int **, int, int);

int main() {
//    int row = 2;
//    int col = 3;
//    int ** array = allocateTwoDimensionArrayOnHeapUsingNew(row, col);
//    for(int r_counter = 0; r_counter < row; r_counter++){
//        for(int c_counter = 0; c_counter < col; c_counter++){
//            array[r_counter][c_counter] = r_counter + c_counter;
//        }
//    }
//    showTwoDimensionArrayOnHeap(array, row, col);
//    destroyTwoDimensionArrayOnHeapUsingFree(array, row, col);
//

    return 0;
}

vector<int> deleteNth(vector<int> arr, int n)
{

    return {};
}

int **allocateTwoDimensionArrayOnHeapUsingNew(int rows, int columns){
    int **array = new int*[rows];
    for(int r_counter = 0; r_counter < rows; r_counter++){
        array[r_counter] = new int[columns];
    }
    return array;
}

void destroyTwoDimensionArrayOnHeapUsingDelete(int ** array, int rows, int cols){
    for(int r_counter = 0; r_counter < rows; r_counter++){
        delete []array[r_counter];
    }
    delete []array;
}

void showTwoDimensionArrayOnHeap(int **array, int rows, int cols){
    for(int r_counter = 0; r_counter < rows; r_counter++){
        for(int c_counter = 0; c_counter < cols; c_counter++){
            cout << array[r_counter][c_counter] << " ";
        }
        cout << endl;
    }
}

void destroyTwoDimensionArrayOnHeapUsingFree(int ** array, int rows, int cols){
    for(int r_counter = 0; r_counter < rows; r_counter++){
        free(array[r_counter]);
    }
    free(array);
}

int **allocateTwoDimensionArrayOnHeapUsingMalloc(int rows, int cols){
    int **array = (int **) malloc(sizeof(int *) * rows);
    for(int r_counter = 0; r_counter < rows; r_counter++){
        array[r_counter] = (int *) malloc(sizeof(int) * cols);
    }
    return array;
}