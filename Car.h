#ifndef CAR_H
#define CAR_H
#include <string>
class Car{
private:
        std::string m_model;
        int m_year;
public:
	Car(const std::string& model,int year);
	Car();
	Car(const Car& other);
	Car& operator =(const Car& other);
	~Car();
	std::string getModel();
	int getYear();
	friend std::ostream& operator<<(std::ostream& os, const Car& car);

};

#endif //CAR_H