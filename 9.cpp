#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void writeToFiles() {
    // Check if Car.txt and Manufacturer.txt exist and are non-empty
    if (fs::exists("Car.txt") && fs::file_size("Car.txt") > 0 &&
        fs::exists("Manufacturer.txt") && fs::file_size("Manufacturer.txt") > 0) {
        // Files exist and are non-empty, no need to write initial data
        return;
    }

    // Open Car.txt in append mode
    ofstream carFile("Car.txt", ios::app);
    if (!carFile) {
        cerr << "Error opening Car.txt for writing." << endl;
        return;
    }

    // Open Manufacturer.txt in append mode
    ofstream manufacturerFile("Manufacturer.txt", ios::app);
    if (!manufacturerFile) {
        cerr << "Error opening Manufacturer.txt for writing." << endl;
        return;
    }

    // Write to Car.txt
    carFile << "1 BMW" << endl;
    carFile << "2 Audi" << endl;
    carFile << "3 Tesla" << endl;

    // Write to Manufacturer.txt
    manufacturerFile << "BMW 2020" << endl;
    manufacturerFile << "Audi 2021" << endl;
    manufacturerFile << "Tesla 2022" << endl;

    carFile.close();
    manufacturerFile.close();
}

void readFromFiles() {
    // Open Car.txt for reading
    ifstream carFile("Car.txt");
    if (!carFile) {
        cerr << "Error opening Car.txt for reading." << endl;
        return;
    }

    // Open Manufacturer.txt for reading
    ifstream manufacturerFile("Manufacturer.txt");
    if (!manufacturerFile) {
        cerr << "Error opening Manufacturer.txt for reading." << endl;
        return;
    }

    // Read and display content of Car.txt
    cout << "Contents of Car.txt:" << endl;
    string line;
    while (getline(carFile, line)) {
        cout << line << endl;
    }
    carFile.close();

    // Read and display content of Manufacturer.txt
    cout << "\nContents of Manufacturer.txt:" << endl;
    while (getline(manufacturerFile, line)) {
        cout << line << endl;
    }
    manufacturerFile.close();
}

void addNewInformation() {
    // Append new information to Car.txt
    ofstream carFile("Car.txt", ios::app);
    if (!carFile) {
        cerr << "Error opening Car.txt for appending." << endl;
        return;
    }

    // Append new cars
    int id;
    string carName;
    cout << "Enter new car ID and Name (ID Name): ";
    cin >> id;
    cin.ignore(); // Ignore newline character after integer input
    getline(cin, carName);
    carFile << id << " " << carName << endl;

    carFile.close();

    // Append new information to Manufacturer.txt
    ofstream manufacturerFile("Manufacturer.txt", ios::app);
    if (!manufacturerFile) {
        cerr << "Error opening Manufacturer.txt for appending." << endl;
        return;
    }

    // Append new manufacturers
    string manufacturer;
    int year;
    cout << "Enter new manufacturer and year (Manufacturer Year): ";
    getline(cin, manufacturer);
    cin >> year;
    manufacturerFile << manufacturer << " " << year << endl;

    manufacturerFile.close();
}

int main() {

    cout << endl;
    cout << "|----------FAZLIDDIN----------|" << endl;
    cout << endl;

    // Write initial data to files if they don't already exist or are empty
    writeToFiles();

    // Read and display contents of the files
    readFromFiles();

    // Allow user to add new information
    addNewInformation();

    // Display updated contents of the files
    cout << "\nUpdated contents of the files:" << endl;
    readFromFiles();

    return 0;
}

