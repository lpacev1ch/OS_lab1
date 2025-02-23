#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include "reporter.cpp" 

TEST(ReporterTest, GenerateReport) {
    std::string binary_filename = "test.bin";
    std::string report_filename = "report.txt";
    double hourly_rate = 10.0;

    // Создание тестового бинарного файла
    std::ofstream binfile(binary_filename, std::ios::binary);
    employee emp1 = {1, "John", 40};
    employee emp2 = {2, "Jane", 35};
    binfile.write(reinterpret_cast<char*>(&emp1), sizeof(emp1));
    binfile.write(reinterpret_cast<char*>(&emp2), sizeof(emp2));
    binfile.close();

    ASSERT_EQ(main(4, new char* [4]{ "reporter", binary_filename.c_str(), report_filename.c_str(), "10" }), 0);

    // Проверка, что отчет был создан
    std::ifstream infile(report_filename);
    ASSERT_TRUE(infile.is_open());
    infile.close();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
