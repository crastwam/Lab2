#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
using namespace std;


void createReading(){
    ofstream outputFile("Reading.txt");
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<>intDistribution(512, 1024);
    uniform_real_distribution<double>doubleDistribution(50, 90);

    int limit = intDistribution(generator);
    for(int i = 0; i < limit; i++) {
        outputFile << i << " ";
        outputFile << fixed << setprecision(3) << doubleDistribution(generator) << endl;
    }
}


int main() {
    createReading();
    return 0;
}