#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Car.h"
#include "FileInput.h"

int main() {
    Matrix m(3,3);
    m.init();
    m.print();
    m.rotate();
    std::cout << "After rotation:\n";
    m.print();

    FileInput file("matrix.txt");
    for(int i=0;i<m.getRows();i++){
        for(int j=0;j<m.getColumns();j++){
            file.write(m[i][j]);
        }
        file.write("\n");
    }
    return 0;
}
