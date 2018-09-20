#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
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
    for(int i = 0; i < limit; i++) {
        outputFile << i << " ";
        outputFile << fixed << setprecision(3) << doubleDistribution(generator) << endl;
    }
}

void readReading(){
    ifstream inputFile("Reading.txt");
    int numberOfReading = 0;
    double averge = 0;
    double highest = 0;
    double lowest = 0;
    double median = 0;

    double num;
    while (inputFile >> num){
        if(numberOfReading++ % 2 == 1) {
            cout << num << endl;

        }
    }
    numberOfReading /= 2;

    cout << "There are "<< numberOfReading << " readings in the file." << endl;
}


int main() {
    createReading();
    readReading();
    return 0;
}