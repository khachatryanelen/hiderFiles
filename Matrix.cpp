#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Matrix.h"
#include "Car.h"

        Matrix::Matrix(int rows,int columns){
            m_rows=rows;
            m_columns=columns;
            allocateMemory();
        }
        Matrix::Matrix(){
            m_rows=5;
            m_columns=5;
            allocateMemory();
        }
        Matrix::Matrix(const Matrix& other){
            this->m_rows=other.m_rows;
            this->m_columns=other.m_columns;
            this->m_matrix=new Car*[m_rows];
            
            for(int i=0;i<m_rows;i++){
                m_matrix[i]=new Car[m_columns];
            }
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    m_matrix[i][j]=other.m_matrix[i][j];
                }
            }
        }
        Matrix& Matrix::operator =(const Matrix& other){
            if(this!=&other){
                if(this->m_rows!=other.m_rows || this->m_columns!=other.m_columns){
                    for(int i=0;i<m_rows;i++){
                        delete[] m_matrix[i];
                    }
                    delete[] m_matrix;
                    
                    this->m_rows=other.m_rows;
                    this->m_columns=other.m_columns;
                    this->m_matrix=new Car*[m_rows];
                    
                    for(int i=0;i<m_rows;i++){
                        m_matrix[i]=new Car[m_columns];
                    }
                }
                for(int i=0;i<m_rows;i++){
                    for(int j=0;j<m_columns;j++){
                        m_matrix[i][j]=other.m_matrix[i][j];
                    }
                }
                
            }
            return *this;
        }
        Car* Matrix::operator[](int row){
            return m_matrix[row];
        }
        Matrix::~Matrix(){
            for(int i=0;i<m_rows;i++){
                delete[] m_matrix[i];
            }
            delete[] m_matrix;
        }
        
        int Matrix::getRows(){
            return m_rows;
        }
        int Matrix::getColumns(){
            return m_columns;
        }
        void Matrix::allocateMemory(){
            m_matrix=new Car*[m_rows];
            for(int i=0;i<m_rows;i++){
                m_matrix[i]=new Car[m_columns];
            }
        } 
        void Matrix::init(){
            srand(time(0));
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    m_matrix[i][j]=Car();
                }
            }
            
        }
        void Matrix::rotate(){
            if(m_rows!=m_columns){
                std::cout <<"Can't rotate"<<std::endl;
            }
            else{
                (*this).rotateAboutDiagonal();
                (*this).rotateAboutMid();
            }
        }
            void Matrix::rotateAboutDiagonal(){
                Car temp;
                for(int i=0;i<m_rows;i++){
                    for(int j=0;j<i;j++){
                        temp=m_matrix[i][j];
                        m_matrix[i][j]=m_matrix[j][i];
                        m_matrix[j][i]=temp;
                    }
                }
            }
            void Matrix::rotateAboutMid(){
                Car temp;
                for(int i=0;i<m_rows;i++){
                    for(int j=0;j<m_columns/2;j++){
                        temp=m_matrix[i][j];
                        m_matrix[i][j]=m_matrix[i][m_rows-j-1];
                        m_matrix[i][m_rows-j-1]=temp;
                    }
                }
            }
        void Matrix::print(){
            for(int i=0;i<m_rows;i++){
                for(int j=0;j<m_columns;j++){
                    std::cout<<m_matrix[i][j]<<" ";
                }
                std::cout<<std::endl;
            }
        }
        void Matrix::set(int row,int col,const Car& car){
            m_matrix[row][col]=car;
        }
        Car& Matrix::get(int row,int col){
            return m_matrix[row][col];
        }
        
 std::ostream& operator <<(std::ostream& os,const Matrix& matrix){
    for(int i=0;i<matrix.m_rows;i++){
        for(int j=0;j<matrix.m_columns;j++){
            os<<matrix.m_matrix[i][j]<<" ";
        }
        os<<"\n";
    }
    return os;
 }
