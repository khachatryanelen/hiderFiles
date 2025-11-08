#ifndef FILEINPUT_H
#define FILEINPUT_H
#include <string>
#include <fstream>
#include "Car.h"

class FileInput{
private:

    std::ofstream m_file;
public:

    FileInput(const std::string& file);

    void write(const std::string& message);
    void write(const Car& car);
    FileInput()=delete;
    FileInput(const FileInput& other)=delete;
    FileInput& operator=(const FileInput& other)=delete;
    ~FileInput();

};


#endif // FILEINPUT_H