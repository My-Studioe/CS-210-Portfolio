// Rolfe H. Green
// CS210 Project 3 - Corner Grocer Item Frequency Analyzer
// This program reads grocery purchase data, counts item frequencies,
// and provides a menu to search items, print frequencies, or show histogram.

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <vector>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;  // item name -> purchase count

    void loadDataFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            throw runtime_error("Error: Could not open input file: " + filename);
        }

        string item = "";
        while (inputFile >> item) {
            if (!item.empty()) {
                itemFrequency[item]++;
            }
        }
        inputFile.close();
    }

    void writeBackupFile(const string& filename) {
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            throw runtime_error("Error: Could not create backup file: " + filename);
        }

        for (const auto& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close();
    }

public:
    GroceryTracker(const string& inputFilename = "CS210_Project_Three_Input_File.txt") {
        try {
            vector<string> possiblePaths = {
                inputFilename,
                "../" + inputFilename,
                "../../" + inputFilename,
                "CS210_Project_Three_Input_File.txt"
            };

            bool loaded = false;

            for (const auto& path : possiblePaths) {
                ifstream testFile(path);
                if (testFile.is_open()) {
                    testFile.close();
                    loadDataFromFile(path);
                    cout << "Loaded file from: " << path << endl;
                    loaded = true;
                    break;
                }
            }

            if (!loaded) {
                throw runtime_error("Could not find CS210_Project_Three_Input_File.txt");
            }

            writeBackupFile("frequency.dat");
            cout << "Data loaded successfully! " << itemFrequency.size()
                << " unique items processed." << endl;
            cout << "Backup file 'frequency.dat' created." << endl << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
            throw;
        }
    }

    void searchItem() {
        string item = "";
        cout << "\nEnter the item you wish to look for: ";
        cin >> item;

        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            cout << "\n" << item << " appears " << it->second << " time(s)." << endl;
        }
        else {
            cout << "\n" << item << " was not found in today's purchases." << endl;
        }
    }

    void printAllFrequencies() {
        cout << "\n=== All Item Frequencies ===\n";
        for (const auto& pair : itemFrequency) {
            cout << left << setw(15) << pair.first << pair.second << endl;
        }
        cout << "============================\n";
    }

    void printHistogram() {
        cout << "\n=== Frequency Histogram ===\n";
        for (const auto& pair : itemFrequency) {
            cout << left << setw(15) << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << " (" << pair.second << ")\n";
        }
        cout << "===========================\n";
    }

    void displayMenu() {
        int choice = 0;

        do {
            cout << "\n=== Corner Grocer Menu ===\n"
                << "1. Search for an item\n"
                << "2. Print all frequencies\n"
                << "3. Print histogram\n"
                << "4. Exit\n"
                << "========================\n"
                << "Enter choice (1-4): ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Invalid input. Please enter a number.\n";
                continue;
            }

            if (choice == 1)      searchItem();
            else if (choice == 2) printAllFrequencies();
            else if (choice == 3) printHistogram();
            else if (choice == 4) {
                cout << "\nThank you for using Corner Grocer Analyzer. Goodbye!\n";
            }
            else {
                cout << "Error: Please select a number between 1 and 4.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    cout << "Welcome to Corner Grocer Item Frequency Analyzer\n" << endl;

    try {
        GroceryTracker tracker;
        tracker.displayMenu();
    }
    catch (const exception& e) {
        cout << "\nProgram error: " << e.what() << endl;
    }

    return 0;
}