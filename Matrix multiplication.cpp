#define DEBUG

#ifdef DEBUG
#define NAME_OF(v) #v
#endif

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<float>> lyoVec2D;

void Print2DVector(const lyoVec2D &vec) {
    
    for (auto x = 0; x < vec.size(); x++) {  
            for (auto y = 0; y < vec[0].size(); y++) {            
                cout << vec[x][y] << " ";
            }
            cout << endl;
        }
}

lyoVec2D MultiplyMatrix2D(const lyoVec2D &MatrixA, const lyoVec2D &MatrixB) {

                    #ifdef DEBUG
                        printf("DEBUG: Initiating function\n");
                    #endif
    
    // Initial check to make sure the matrices can be multiplied
    if (MatrixA[0].size() != MatrixB.size()) {
        cout << "The amount of columns of matrix A and rows of matrix B must be equal.\n";
        return {{0}, {0}};
    }

                    #ifdef DEBUG
                        printf("DEBUG: Preparing result\n");
                    #endif

    // Defining and resizing the result
    lyoVec2D MultiplicationResult;
    for (auto i = 0; i < MatrixA.size(); i++) {
        vector<float> subVec;
        for (auto j = 0; j < MatrixB[0].size(); j++) {
            subVec.push_back(0);
        }
        MultiplicationResult.push_back(subVec);
        subVec.clear();
    }
    
                    #ifdef DEBUG
                        auto NameA = NAME_OF(MatrixA);
                        auto NameB = NAME_OF(MatrixB);
                        printf("DEBUG: Multiplying matrices\n");
                        printf("\nMultiplying %s:\n", NameA);
                        Print2DVector(MatrixA);
                        printf("\nby %s:\n", NameB);
                        Print2DVector(MatrixB);
                    #endif

    // The multiplication itself
    for (auto nRowsA = 0; nRowsA < MatrixA.size(); nRowsA++) {
        for (auto nColsB = 0; nColsB < MatrixB.size(); nColsB++) {
            for (auto nColsA = 0; nColsA < MatrixA.size(); nColsA++) {
                MultiplicationResult[nRowsA][nColsB] += MatrixA[nRowsA][nColsA] * MatrixB[nColsA][nColsB];
            }
        }
    }
    
                    #ifdef DEBUG
                        printf("\nSuccessfully multiplied!\n");
                    #endif

    return MultiplicationResult;
}

int main() {
    
    const lyoVec2D MatrixOne = {{1, 0, 0},
                                {0, 1, 0}};

    const lyoVec2D MatrixTwo = {{30}, {45}, {60}};
    
    lyoVec2D ResultingMatrix = MultiplyMatrix2D(MatrixOne, MatrixTwo);
    
    printf("\nMultiplication result:\n");
    Print2DVector(ResultingMatrix);
    
    cin.get();
    return 0;
}