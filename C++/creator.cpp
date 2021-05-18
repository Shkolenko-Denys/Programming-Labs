/*-------------------------------------------------------------------<Header>-
 Name: creator.cpp
 Title: Creator
 Description: Create cpp-file(s) in the current folder.
 Place creator.exe in the folder where the cpp-file(s) should be created.
 -------------------------------------------------------------------</Header>-*/

#include <iostream>     // std::cout, std::cin, std::cerr
#include <fstream>      // std::ofstream
#include <string>       // std::string, std::to_string
#include <limits>       // std::numeric_limits
#include <cstdlib>      // system

int main() {
    int n; // number of files

    while (true) {
        std::cout << " Enter the number of files: ";
        std::cin >> n;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << " Oops, that input is invalid. Please try again.\n\n";
        }
        else { // remove unnecessary values
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    std::string line(67, '-');
    std::string str_i;

    for (int i = 1; i <= n; ++i) {
        if (i < 10) {
            str_i = "0" + std::to_string(i);
        }
        else {
            str_i = std::to_string(i);
        }
        std::ofstream outf("ex_" + str_i + ".cpp");

        if (!outf) {
            std::cerr << " File could not be opened for writing!\n\n";
            system("pause");
            exit(EXIT_FAILURE);
        }

        outf <<
        "/*" << line << "<Header>-\n" <<
        " Name: ex_" + str_i + ".cpp\n" <<
        " Title: —\n" <<
        " Description: \n" <<
        " " << line << "</Header>-*/\n\n" <<
        "#include <iostream>\n\n" <<
        "using namespace std;\n\n" <<
        "int main() {\n\n" <<
        "    return 0;\n" <<
        "}";

        outf.close();
    }
    std::cout << "\n File(s) created successfully!\n\n";
    system("pause");
    return 0;
}