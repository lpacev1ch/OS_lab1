#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include "creator.cpp"

TEST(CreatorTest, CreateBinaryFile) {
    std::string filename = "test.bin";
    int num_records = 2;
    std::string input = "1\nJohn\n40\n2\nJane\n35\n";

    std::istringstream ss(input);
    std::cin.rdbuf(ss.rdbuf());

    std::ofstream binfile(filename, std::ios::binary);
    ASSERT_EQ(main(3, new char* [3]{ "creator", filename.c_str(), "2" }), 0);

    // Проверка, что файл был создан
    std::ifstream infile(filename, std::ios::binary);
    ASSERT_TRUE(infile.is_open());
    infile.close();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
