#include <iostream>

struct Something {
    int value1;
};
 
struct Other {
    Something something;
} other;

int main() {
    // Suppose we need to work with the value1 field
    // of the Something structure of the other variable
    // of the Other structure.
    // Typically, this field would be accessed through other.something.value1.
    // What if we need to access this member repeatedly?
    // In this case, the code becomes unwieldy and messy.
    // References provide an easier way to access data:

    int &ref = other.something.value1;

    // Thus, the following two statements are identical:
    other.something.value1 = 5;
    ref = 5;

    std::cout << "other.something.value1 = " << other.something.value1 << std::endl;
    std::cout << "ref = " << ref << std::endl;

    return 0;
}