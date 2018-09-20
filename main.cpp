#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
const int DOUBLEMAX = 90;
const int DOUBLEMIN = 50;
const int INTMAX = 1024;
const int INTMIN = 512;

void createReading(){
    ofstream outputFile("Reading.txt");
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<>intDistribution(INTMIN, INTMAX);
    uniform_real_distribution<double>doubleDistribution(DOUBLEMIN, DOUBLEMAX);

    int limit = intDistribution(generator);
    //Setting decimal places to 3
    outputFile << fixed << setprecision(3);
    for(int i = 0; i < limit; i++) {
        //Writing integer
        outputFile << i << " ";
        //Writing double
        outputFile << doubleDistribution(generator) << endl;
    }
}

void readReading(){
    ifstream inputFile("Reading.txt");
    int numberOfReading = 0;
    double average = 0;
    double highest = DOUBLEMIN-1;
    double lowest = DOUBLEMAX+1;
    double median = 0;
    double arrayOfDouble[INTMAX];
    int arrayIndex = 0;
    double num;

    //Reading Reading.txt file
    while (inputFile >> num){
        if(numberOfReading++ % 2 == 1) {
            arrayOfDouble[arrayIndex++] = num;
            average += num;
            //Setting highest
            if(num > highest){
                highest = num;
            }
            //Setting lowest
            if(num < lowest){
                lowest = num;
            }
        }
    }

    //Calculating number of reading, average, and median
    numberOfReading /= 2;
    average /= numberOfReading;
    sort(arrayOfDouble, arrayOfDouble+numberOfReading);
    if(numberOfReading % 2 == 0){
        median = (arrayOfDouble[numberOfReading/2] + arrayOfDouble[numberOfReading/2-1])/2;
    }else{
        median = arrayOfDouble[numberOfReading/2];
    }

    //Printing report
    cout << fixed << setprecision(3);
    cout << "There are "<< numberOfReading << " readings in the file." << endl;
    cout << "The average reading is " <<average << "." << endl;
    cout << "The highest reading is "<< highest << "." << endl;
    cout << "The lowest reading is " << lowest << "." << endl;
    cout << "The median reading is "<< median << "." << endl;
}

int main() {
    createReading();
    readReading();
    return 0;
}