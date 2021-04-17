// Create cpp-files in the current folder

#include <iostream>
#include <fstream>
#include <cstdlib> // system()

using namespace std;

int main() {
    int n;

    while (true) {
        cout << "Enter the number of files: ";
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that input is invalid. Please try again.\n\n";
        }
        else {
            cin.ignore(32767, '\n'); // remove unnecessary values
            break;
        }
    }

    string line(67, '-');

    for (int i = 1; i <= n; ++i) {
        string str_i = to_string(i);
        ofstream outf("ex_" + str_i + ".cpp");

        if (!outf) {
            cerr << "ERROR!\n\n";
            exit(1);
        }

        outf <<
        "/*" << line << "<Header>-\n" <<
        " Name: ex_" + str_i + ".cpp\n" <<
        " Title: —\n" <<
        " Description: \n" <<
        " " << line << "</Header>-*/\n\n" <<
        "#include <iostream>\n" <<
        "#include <cstdlib> // system()\n\n" <<
        "using namespace std;\n\n" <<
        "int main() {\n\n" <<
        "    system(\"pause\");\n" <<
        "    return 0;\n" <<
        "}";

        outf.close();
    }
    cout << "\nFile(s) created successfully!\n\n";
    system("pause");
    return 0;
}