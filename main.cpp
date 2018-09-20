#include <iostream>
#include <fstream>
#include <random>
using namespace std;


void createReading(){
    ofstream outputFile("Reading.txt");
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<>distribution(0, 9);

    for(int i =0; i < 5; i++) {
        outputFile << distribution(generator) << endl;
    }
}


int main() {
    createReading();
    return 0;
}