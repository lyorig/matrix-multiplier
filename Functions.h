#ifdef HAMMER_TIME
    #include <chrono>
#endif

using namespace std;

// Generic matrix
typedef vector<vector<float>> lyoVec2D;

// Meshes
typedef float Coordinate[3];
typedef Coordinate Primitive[3];
typedef vector<Primitive> Mesh;

void Print2DVector(const lyoVec2D &vec) {
    
    for (uint8_t x = 0; x < vec.size(); x++) {  
            for (uint8_t y = 0; y < vec[0].size(); y++) {            
                cout << vec[x][y] << " ";
            }
            cout << endl;
        }
    }

lyoVec2D operator* (const lyoVec2D &MatrixA, const lyoVec2D &MatrixB) {
          
                    #ifdef DEBUG
                        printf("[INFO] Initiating function.\n");
                    #endif

                    #ifdef HAMMER_TIME
                        auto start = chrono::high_resolution_clock::now();
                    #endif

    // Some variables to make the code cleaner - RowsB would only be used once so it's not defined
    uint8_t RowsA = MatrixA.size();    // 2x
    uint8_t ColsA = MatrixA[0].size(); // 2x
    uint8_t ColsB = MatrixB[0].size(); // 2x
    
    // Initial check to make sure the matrices can be multiplied
    if (ColsA == MatrixB.size()) {
                    
                    #ifdef DEBUG
                        printf("[INFO] Preparing result.\n");
                    #endif

    // Defining and resizing the result
    lyoVec2D MultiplicationResult;
    for (uint8_t a = 0; a < RowsA; a++) {
        vector<float> tempVec;
        for (uint8_t b = 0; b < ColsB; b++) {
            tempVec.push_back(0);
        }
        
        MultiplicationResult.push_back(tempVec);
        tempVec.clear();
    }
                    #ifdef DEBUG
                        printf("[INFO] Multiplying matrices.\n");
                        printf("\nMultiplying:\n");
                        Print2DVector(MatrixA);
                        printf("\nby:\n");
                        Print2DVector(MatrixB);
                    #endif

    // The multiplication itself
    for (uint8_t i = 0; i < RowsA; i++) {
        for (uint8_t j = 0; j < ColsB; j++) {
            for (uint8_t k = 0; k < ColsA; k++) {
                MultiplicationResult[i][j] += MatrixA[i][k] * MatrixB[k][j];
            }
        }
    }
    
                    #ifdef DEBUG
                        printf("\nSuccessfully multiplied!\nResult:\n");
                        Print2DVector(MultiplicationResult);
                        printf("\n");
                    #endif

                    #ifdef HAMMER_TIME
                        auto end = chrono::high_resolution_clock::now();
                        chrono::duration<double> execTime = end - start;
                        printf("Execution time: %fs\n\n", execTime);
                    #endif

    return MultiplicationResult;
    } else { 
        // Since this is supposed to be an actual useable function
        // that returns an actual useable value, mistakes aren't tolerated.
        throw invalid_argument("The amount of columns of matrix A and rows of matrix B aren't equal!");
    }
}

class Matrix {
    
    public:
    lyoVec2D matrix;
    
};