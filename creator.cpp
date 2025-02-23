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
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <filename> <num_records>" << endl;
        return 1;
    }

    string filename = argv[1];
    int num_records = stoi(argv[2]);
    ofstream binfile(filename, ios::binary);

    for (int i = 0; i < num_records; ++i) {
        employee emp;
        cout << "Enter employee number: ";
        cin >> emp.num;
        cout << "Enter employee name: ";
        cin >> emp.name;
        cout << "Enter hours worked: ";
        cin >> emp.hours;
        binfile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
    }

    binfile.close();
    return 0;
}
