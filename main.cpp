#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

static const char alphum[] = "0123456789" "!@#$%&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int strLen = sizeof(alphum) - 1;

char GenRand() {
    return alphum[rand() % strLen];
}

int main() {
    int n, c = 0, s = 0;

    srand(time(0));

    cout << "Enter the length of the password you want: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid length. Must be greater than 0." << endl;
        return 1;
    }

    string D;

    do {
        c = 0;
        s = 0;
        D.clear();

        for (int z = 0; z < n; z++) {
            char C = GenRand();
            D += C;

            if (isdigit(C)) {
                c++;
            }

            if (C == '!' || C == '@' || C == '#' || C == '$' || C == '%' || C == '&' || C == '*') {
                s++;
            }
        }
    } while (n > 2 && (c == 0 || s == 0));

    cout << "Your password is: " << D << endl;

    return 0;
}
