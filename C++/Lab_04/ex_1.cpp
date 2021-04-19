#include <iostream>

class letters {
    char ch;
public:
    letters() { ch = '\0'; } // called for non-initialized arrays
    letters(char c) { ch = c; }
    char get_ch() { return ch; }
};

letters make_obj(char ch) {
    letters let(ch);
    return let;
}

void print_obj_arr(letters *obj_arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << obj_arr[i].get_ch() << " ";
    }
    std::cout << "\n\n";
}

int main() {
    // short form of initialization for few characters (10)
    letters obj_arr[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    std::cout << "\n" << "From A to J:" << "\n";
    print_obj_arr(obj_arr, 10);

    // for more characters (26)
    letters alphabet[26];
    int i;
    char chr;
    for (i = 0, chr = 'A'; i < 26; i++, chr++) {
        alphabet[i] = make_obj(chr);
    }
    std::cout << "Alphabet:" << "\n";
    print_obj_arr(alphabet, 26);

    return 0;
}