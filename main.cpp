#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

struct employee {
    int num;
    char name[10];
    double hours;
};

void runCreator(const string &command) {
    system(command.c_str());
}

void runReporter(const string &command) {
    system(command.c_str());
}

int main() {
    string binary_filename;
    int num_records;
    string report_filename;
    double hourly_rate;

    cout << "Enter binary file name: ";
    cin >> binary_filename;
    cout << "Enter number of records: ";
    cin >> num_records;

    string creator_command = "./Creator " + binary_filename + " " + to_string(num_records);
    thread creatorThread(runCreator, creator_command);
    creatorThread.join(); // Ожидание завершения утилиты Creator

    cout << "Binary file contents:\n";
    ifstream binfile(binary_filename, ios::binary);
    employee emp;
    while (binfile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        cout << "Number: " << emp.num << ", Name: " << emp.name << ", Hours: " << emp.hours << "\n";
    }
    binfile.close();

    cout << "Enter report file name: ";
    cin >> report_filename;
    cout << "Enter hourly rate: ";
    cin >> hourly_rate;

    string reporter_command = "./Reporter " + binary_filename + " " + report_filename + " " + to_string(hourly_rate);
    thread reporterThread(runReporter, reporter_command);
    reporterThread.join(); // Ожидание завершения утилиты Reporter

    cout << "Report contents:\n";
    ifstream reportfile(report_filename);
    string line;
    while (getline(reportfile, line)) {
        cout << line << "\n";
    }
    reportfile.close();

    return 0;
}
