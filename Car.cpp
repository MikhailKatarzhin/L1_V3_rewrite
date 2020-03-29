#include <iostream>
#include "Car.h"

using namespace std;
    Car :: Car()
    {
        setModel("Normal");
        setSpeed(1);
        setColor("UNKNOWN");
        //cout << "\nConstruction... " << this;
    }

    Car :: Car(string const * const model_in, short speed_in, string const * const color_in)
    {
        this -> model = *(model_in);
        this -> speed = speed_in;
        this -> color = *(color_in);
        //cout << "\nConstruction... " << this;
    }

    Car :: Car(Car const &otherCar)
    {
        this -> model = otherCar.model;
        this -> speed = otherCar.speed;
        this -> color = otherCar.color;
        //cout << "\nConstruction copy... " << this;
    }
    void Car :: printInformationAboutCar() const
    {
       cout << "||\tModel: " << this->model << "\t||\tSpeed: " << this->speed << "\t||\tColor: " << this->color << "\t||";
    }

    void Car :: setModel(string model_in)
    {   this -> model = model_in;  }

    void Car :: setSpeed(short speed_in)
    {   this -> speed = speed_in;  }

    void Car :: setColor(string color_in)
    {   this -> color = color_in;  }

    string Car :: getModel()
    {
        return model;
    }

    short Car :: getSpeed()
    {
        return speed;
    }

    string Car :: getColor()
    {
        return color;
    }

    Car :: ~Car()
    {
        //cout << "\nDestruction... " << this;
    }

    Car& Car :: operator ++()
    {
        if (this->model == "Legendary") this->model = "Mythical";
        if (this->model == "Epic") this->model = "Legendary";
        if (this->model == "Rarity") this->model = "Epic";
        if (this->model == "Normal") this->model = "Rarity";
        this->speed += 20;
        return *this;
    }

    Car Car:: operator ++(int)
    {
        return ++(*this);
    }

    Car& Car :: operator --()
    {
        if (this->model == "Rarity") this->model = "Normal";
        if (this->model == "Epic") this->model = "Rarity";
        if (this->model == "Legendary") this->model = "Epic";
        if (this->model == "Mythical") this->model = "Legendary";
        if (this->speed > 20) this->speed -= 20;
        return *this;
    }

    Car Car:: operator --(int)
    {
        return --(*this);
    }

    bool Car :: operator == (const Car &car_in)
    {
        return ((this -> model == car_in.model)&&(this -> speed == car_in.speed)&&(this -> color == car_in.color));
    }

    bool Car :: operator != (const Car &car_in)
    {
        return ((this -> model != car_in.model)||(this -> speed != car_in.speed)||(this -> color != car_in.color));
    }

    bool Car :: operator > (const Car &car_in)
    {
        if ((this -> model == "Mythical")&&(car_in.model != "Mythical"))
            {return true;}
        if ((this -> model == "Legendary")&&(car_in.model != "Mythical")&&(car_in.model != "Legendary"))
            {return true;}
        if ((this -> model == "Epic")&&((car_in.model == "Normal")||(car_in.model == "Rarity")))
            {return true;}
        return ((this -> model == "Rarity")&&(car_in.model == "Normal"));
    }

    bool Car :: operator < (const Car &car_in)
    {
        if ((this -> model == "Normal")&&(car_in.model != "Normal"))
            {return true;}
        if ((this -> model == "Rarity")&&(car_in.model != "Normal")&&(car_in.model != "Rarity"))
            {return true;}
        if ((this -> model == "Epic")&&((car_in.model == "Legendary")||(car_in.model == "Mythical")))
            {return true;}
        return ((this -> model == "Legendary")&&(car_in.model == "Mythical"));
    }

    bool Car :: operator <= (const Car &car_in)
    {
        return ((*(this) == car_in) || (*(this) < car_in));
    }

    bool Car :: operator >= (const Car &car_in)
    {
        return ((*(this) == car_in) || (*(this) > car_in));
    }

    Car& Car :: operator = (const Car &car_in)
    {
        this -> model = car_in.model;
        this -> speed = car_in.speed;
        this -> color = car_in.color;
        return *this;
    }

    ostream& operator << (ostream &out, const Car &car_in)
    {
        out << "||\tModel: " << car_in.model << "\t||\tSpeed: " << car_in.speed << "\t||\tColor: " << car_in.color << "\t||";
        return out;
    }

    istream& operator >> (istream &in, Car &car_in)
    {
        in >> car_in.model;
        in >> car_in.speed;
        in >> car_in.color;
        return in;
    }
