#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

class StatisticsCalculator {
private:
    int values[4]; // Array to store input values
    double mean;
    double stdDev;

public:
    void readValuesFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (inputFile.is_open()) {
            for (int i = 0; i < 4; ++i) {
                inputFile >> values[i];
            }
            inputFile.close();
        }
        else {
            std::cerr << "Error: Unable to open the input file." << std::endl;
            exit(1);
        }
    }

    void calculateMean() {
        mean = static_cast<double>(values[0] + values[1] + values[2] + values[3]) / 4.0;
    }

    void calculateStandardDeviation() {
        double sum = 0;
        for (int i = 0; i < 4; ++i) {
            sum += pow(values[i] - mean, 2);
        }
        stdDev = sqrt(sum / 4.0);
    }

    void displayResults() {
        std::cout << "Mean: " << std::fixed << std::setprecision(2) << mean << std::endl;
        std::cout << "Standard Deviation: " << std::fixed << std::setprecision(2) << stdDev << std::endl;

        std::ofstream outputFile("outMeanStd.dat");
        if (outputFile.is_open()) {
            outputFile << "Mean: " << mean << std::endl;
            outputFile << "Standard Deviation: " << stdDev << std::endl;
            outputFile.close();
        }
        else {
            std::cerr << "Error: Unable to open the output file." << std::endl;
        }
    }
};

int main() {
    StatisticsCalculator calculator;

    calculator.readValuesFromFile("inMeanStd.dat");
    calculator.calculateMean();
    calculator.calculateStandardDeviation();
    calculator.displayResults();

    return 0;
}