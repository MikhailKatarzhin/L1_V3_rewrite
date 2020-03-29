#include <string>

using namespace std;
class Car
{
protected:
    string model;
    short speed;
    string color;
public:
    Car();
    Car(string const * const model_in, short speed_in, string const * const color_in);
    Car(Car const &car);
    void printInformationAboutCar() const;
    void setModel(string model_in);
    void setSpeed(short speed_in);
    void setColor(string color_in);
    ~Car();

    Car& operator ++();
    Car operator ++(int);
    Car& operator --();
    Car operator --(int);
    bool operator == (const Car &car_in);
    bool operator != (const Car &car_in);
    bool operator > (const Car &car_in);
    bool operator < (const Car &car_in);
    bool operator <= (const Car &car_in);
    bool operator >= (const Car &car_in);
    Car& operator = (const Car &car_in);
    friend ostream& operator << (ostream &out, const Car &car_in);
    friend istream& operator >> (istream &in, Car &car_in);

    short getSpeed();
    string getModel();
private:
    string getColor();
};
