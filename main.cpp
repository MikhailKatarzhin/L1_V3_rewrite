#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "Car.h"
#include <stdio.h>

#define min(left, right) (left < right ? left : right)

using namespace std;

void showMenu()
{
    cout << "\n\t\t\t***Menu***" << endl;
    cout << "\t0)Menu up" << endl;
    cout << "\t1)Set model of car" << endl;
    cout << "\t2)Set speed of car" << endl;
    cout << "\t3)Set color of car" << endl;
    cout << "\t4)----------" << endl;
    cout << "\t5)----------" << endl;
    cout << "\t6)----------" << endl;
    cout << "\t7)----------" << endl;
    cout << "\t8)Create a duplicate of this car" << endl;
    cout << "\t9)Delete this car" << endl;
    cout << "\t10)Add some cars" << endl;
    cout << "\t11)Upgrade car" << endl;
    cout << "\t12)Downgrade car" << endl;
    cout << "\t13)Battle between cars!!!" <<endl;
}

void showAllCars(short countOfCar, Car const * const cars)
{
    for (short i = 0; i < countOfCar; i++)
    {
        cout << i+1 << ")";
        cars[i].printInformationAboutCar();
    }
}

short requestNumberOfCar(short const countOfCar)
{
    short i;
    do{
        cout << "\nEntry number of car(to " << countOfCar << ") or close program(input 0)\n" << endl;
        string buffer;
        cin >> buffer;
        istringstream bufferStream(buffer);
        bufferStream >> i;
    }while((i < 0)||(i > countOfCar));
    return i;
}

void changeCarModel(Car * const car)
{
    string tmpModel;
    while(1)
    {
        cout << "\nEntry model of car (Normal, Rarity, Epic, Legendary, Mythical):\t";
        cin >> tmpModel;
        if((tmpModel == "Normal")||(tmpModel == "Rarity")||(tmpModel == "Epic")||(tmpModel == "Legendary")||(tmpModel == "Mythical"))
        {
            car->setModel(tmpModel);
            break;
        }else{
            cout << "\nInvalid input, repeat..." << endl;
        }
    }
}

void changeCarSpeed(Car * const car)
{
    short tmpSpeed;
    while(1)
    {
        cout << "\nEntry speed of car(more than 0):\t";
        string buffer;
        cin >> buffer;
        istringstream bufferStream(buffer);
        bufferStream >> tmpSpeed;
        if (tmpSpeed > 0)
        {
            car->setSpeed(tmpSpeed);
            break;
        }else{
            cout << "\nInvalid input, repeat..." << endl;
        }
    }
}

void changeCarColor(Car * const car)
{
    cout << "\nEntry the color of the car:\t";
    string tmpColor;
    cin >> tmpColor;
    car->setColor(tmpColor);
}

void resizeCars(Car ** cars, short const size, short const newSize)
{
    Car *newCars = new Car[newSize];
    for(short i = 0; i < min(size, newSize); ++i)
    {
        newCars[i] = cars[1][i];
    }
    delete[] cars;
    *cars=newCars;
}

int main()
{
    string tmpModel, tmpColor;
    short var = 0, countOfCar = 1, i = 0, y = 0, addCount = 0;
    Car *cars = new Car[1], *tmpCars;
    while (cars)
    {
        system("cls");
        cout << "\n\t\t\t***Car's database***\n\n";
        showAllCars(countOfCar, cars);
        i = requestNumberOfCar(countOfCar);
        if (0 == i)
        {
            delete[] cars;
            return 0;
        }

        while (i != 0)
        {
            system("cls");
            cout << "\nYou are working with car #" << i << "\t" << cars[i-1] << endl;
            showMenu();
            cin >> var;
            switch (var)
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    system("cls");
                    changeCarModel(&cars[i-1]);
                    break;
                case 2:
                    system("cls");
                    changeCarSpeed(&cars[i-1]);
                    break;
                case 3:
                    system("cls");
                    changeCarColor(&cars[i-1]);
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:{
                    resizeCars(&cars, countOfCar, countOfCar+1);
    /*Car *newCars = new Car[countOfCar+1];
    for(short z = 0; z < min(countOfCar, countOfCar+1); ++z)
    {
        newCars[z] = cars[z];
    }
    delete[] cars;
    cars=newCars;*/
                    ++countOfCar;
                    cars[countOfCar-1] = cars[i-1];
                    break;}
                case 9:{
                    break;}
                case 10:{
                    while (addCount < 1)
                    {
                        cout << "How many car add in database?" << endl;
                        cin >> addCount;
                    }
                    countOfCar += addCount;
                    tmpCars = new Car[countOfCar];
                    for (y = 0; y < countOfCar-addCount; y++)
                    {
                        tmpCars[y] = cars[y];
                        delete &(cars[y]);
                    }
                    addCount = 0;
                    delete cars;
                    cars = tmpCars;
                    for (; y < countOfCar; y++)
                    {
                       /* cout << "\nCar #" << y << endl;
                        cout << "Entry model of car" << endl;
                        cin >> tmpModel;
                        cout << "Entry speed of car" << endl;
                        cin >> tmpspeed;
                        cout << "Entry color of car" << endl;
                        cin >> tmpColor;
                        Car newCar(tmpModel, tmpspeed, tmpColor);*/
                        Car newCar;
                        cout << "\nCar #" << y+1 << " \nModel\tSpeed\tColor" << endl;
                        cin >> newCar;
                        cars[y] = newCar;
                    }
                }
                case 11:
                    //++ cars[i-1];
                    cars[i-1] ++;
                    break;
                case 12:
                    //-- cars[i-1];
                    cars[i-1] --;
                    break;
                case 13:
                    do{
                        cout << "\nSelect enemy for battle(to " << countOfCar <<"): ";
                        cin >> y;
                    }while ((y < 0)||(y > countOfCar));
                    if (cars[i-1] < cars[y-1])
                    {
                        cout << "\nWin car... IN RIGHT CONNER!!!" << endl;
                        cars[y-1] ++;

                        cars[i-1] = cars[countOfCar-1];
                        delete &(cars[countOfCar-1]);
                        countOfCar --;
                        tmpCars = new Car[countOfCar];
                        for (y = 0; y < countOfCar; y++)
                        {
                            tmpCars[y] = cars[y];
                            delete &(cars[y]);
                        }
                        delete cars;
                        cars = tmpCars;
                    }else{
                        if (cars[i-1] == cars[y-1])
                        {
                            cout << "\nWin car... No, no winner... Both rivals fell.." << endl;
                            cars[i-1] --;
                            cars[y-1] --;
                        }else{
                            if (cars[i-1] > cars[y-1])
                            {
                                cout << "\nWin car... IN LEFT CONNER!!!" << endl;
                                cars[i-1] ++;

                                cars[y-1] = cars[countOfCar-1];
                                delete &(cars[countOfCar-1]);
                                countOfCar --;
                                tmpCars = new Car[countOfCar];
                                for (y = 0; y < countOfCar; y++)
                                {
                                    tmpCars[y] = cars[y];
                                    delete &(cars[y]);
                                }
                                delete cars;
                                cars = tmpCars;
                            }
                        }
                    }
                    i = 0;
                    break;
            }
        }
    }
}
