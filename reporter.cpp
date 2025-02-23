#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct employee {
    int num;
    char name[10];
    double hours;
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <binary_filename> <report_filename> <hourly_rate>" << endl;
        return 1;
    }

    string binary_filename = argv[1];
    string report_filename = argv[2];
    double hourly_rate = stod(argv[3]);

    ifstream binfile(binary_filename, ios::binary);
    ofstream reportfile(report_filename);

    reportfile << "Отчет по файлу \"" << binary_filename << "\"\n";
    reportfile << "Номер сотрудника\tИмя сотрудника\tЧасы\tЗарплата\n";

    employee emp;
    while (binfile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        double salary = emp.hours * hourly_rate;
        reportfile << emp.num << "\t" << emp.name << "\t" << emp.hours << "\t" << salary << "\n";
    }

    binfile.close();
    reportfile.close();
    return 0;
}
