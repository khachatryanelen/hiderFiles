#include <iostream>
#include "Matrix.h"
#include "Car.h"

int main() {
    Matrix m(3,3);
    m.init();
    m.print();
    m.rotate();
    std::cout << "After rotation:\n";
    m.print();
    return 0;
}
