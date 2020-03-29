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
    cout << "\t4)Create a duplicate of this car" << endl;
    cout << "\t5)Delete this car" << endl;
    cout << "\t6)Add some cars" << endl;
    cout << "\t7)Upgrade car" << endl;
    cout << "\t8)Downgrade car" << endl;
    cout << "\t9)Battle between cars!!!" << endl;
}

void showAllCars(short countOfCar, Car const * const cars)
{
    for (short i = 0; i < countOfCar; i++)
    {
        cout << "\n" << i+1 << ")";
        cars[i].printInformationAboutCar();
    }
}

short requestNumberOfCar(short const countOfCar)
{
    short i;
    do{
        cout << "\n\nEntry number of car(to " << countOfCar << ") or close program(input 0)\n" << endl;
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
        newCars[i] = cars[0][i];
    }
    delete[] cars[0];
    *cars=newCars;
}

Car* resizeCars(Car const * const cars, short const size, short const newSize)
{
    Car *newCars = new Car[newSize];
    for(short i = 0; i < min(size, newSize); ++i)
    {
        newCars[i] = cars[i];
    }
    delete[] cars;
    return newCars;
}

void addSomeCar(Car ** cars, short * const countOfCar)
{
    short addCount = 0;
    while (addCount < 1)
    {
        cout << "How many car add in database?" << endl;
        string buffer;
        cin >> buffer;
        istringstream bufferStream(buffer);
        bufferStream >> addCount;
        if (addCount > 0)
        {
            break;
        }else{
            cout << "\nInvalid input, repeat..." << endl;
        }
    }
    //cars = resizeCars(cars, countOfCar, countOfCar + addCount);
    resizeCars(cars, *(countOfCar), *(countOfCar)+addCount);
    *(countOfCar) += addCount;
    for (; 0 < addCount; --addCount)
    {
        system("cls");
        while(1)
        {
            cout << "\nCar #" << *(countOfCar)-addCount+1 << " \n|| Model ||\t|| Speed ||\t|| Color ||" << endl;
            cin >> cars[0][*(countOfCar)-addCount];
            if((cars[0][*(countOfCar)-addCount].getSpeed() > 0)&&
               ((cars[0][*(countOfCar)-addCount].getModel() == "Normal")||
                (cars[0][*(countOfCar)-addCount].getModel() == "Rarity")||
                (cars[0][*(countOfCar)-addCount].getModel() == "Epic")||
                (cars[0][*(countOfCar)-addCount].getModel() == "Legendary")||
                (cars[0][*(countOfCar)-addCount].getModel() == "Mythical")))
            {
                break;
            }else{
                cout << "\nInvalid input, repeat..." << endl;
            }
        }
    }
}

int main()
{
    short countOfCar = 1, i = 0;
    Car *cars = new Car[1];
    while (countOfCar)
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
            cout << "\nYou are working with car #" << i << "\t" << cars[i-1] << endl; ///Падает тут
            showMenu();
            short var;
            string buffer;
            cin >> buffer;
            istringstream bufferStream(buffer);
            bufferStream >> var;
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
                case 4:{
                    cars = resizeCars(cars, countOfCar, countOfCar+1);
                    //resizeCars(&cars, countOfCar, countOfCar+1);
                    ++countOfCar;
                    cars[countOfCar-1] = cars[i-1];
                    break;}
                case 5:{
                    cars[i-1] = cars[countOfCar-1];
                    cars = resizeCars(cars, countOfCar, countOfCar-1);
                    //resizeCars(&cars, countOfCar, countOfCar-1);
                    --countOfCar;
                    i = 0;
                    break;}
                case 6:
                    addSomeCar(&cars, &countOfCar);
                    break;
                case 7:
                    //++ cars[i-1];
                    cars[i-1] ++;
                    break;
                case 8:
                    //-- cars[i-1];
                    cars[i-1] --;
                    break;
                case 9:
                    short y;
                    do{
                        cout << "\nSelect enemy for battle(to " << countOfCar <<"): ";
                        cin >> y;
                    }while ((y < 0)||(y > countOfCar));
                    if (cars[i-1] < cars[y-1])
                    {
                        system("cls");
                        cout << "\n\n\t!!!Win car... IN RIGHT CONNER!!!" << endl;
                        system("pause");
                        cars[y-1] ++;
                        cars[i-1] = cars[countOfCar-1];
                        cars = resizeCars(cars, countOfCar, countOfCar-1);
                        //resizeCars(&cars, countOfCar, countOfCar-1);
                        --countOfCar;
                    }else{
                        if (cars[i-1] == cars[y-1])
                        {
                            system("cls");
                            cout << "\n\n\tWin car... No, no winner... Both rivals fell.." << endl;
                            system("pause");
                            cars[i-1] --;
                            cars[y-1] --;
                        }else{
                            if (cars[i-1] > cars[y-1])
                            {
                                system("cls");
                                cout << "\n\n\n\t\t!!!Win car... IN LEFT CONNER!!!" << endl;
                                system("pause");
                                cars[i-1] ++;

                                cars[y-1] = cars[countOfCar-1];
                                cars = resizeCars(cars, countOfCar, countOfCar-1);
                                //resizeCars(&cars, countOfCar, countOfCar-1);
                                --countOfCar;
                            }
                        }
                    }
                    i = 0;
                    break;
            }
        }
    }
    if (countOfCar == 0)
    {
        system("cls");
        showAllCars(countOfCar, cars);
        cout << "\n\n\t||**||\tWe're out of cars\t||**||\n\n";
    }
}
