#include <iostream>
#include <string>
#include <fstream>

#include "FileInput.h"

FileInput::FileInput(const std::string& file){
    m_file.open(file);
}
void FileInput::write(const std::string& message){
    if(m_file.is_open()){
        m_file<<message<<" ";
    }
    else{
        std::cout<<"Failed to open the file. "<<std::endl;
    }
}
void FileInput::write(const Car& car){
    if(m_file.is_open()){
        m_file<<car<<" ";
    }
    else{
        std::cout<<"Failed to open the file. "<<std::endl;
    }
}
FileInput::~FileInput(){
    if(m_file.is_open())
        m_file.close();
};


