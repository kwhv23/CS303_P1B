/* 
 * Project 1B
 * TEAM ONE!
 *      Bother, Jacob
 *      Brown, Joshua
 *      Hanifl, Kenton
 * 
 * UMKC
 * CS303
 * 0002
 * Dr. Kuhail
 * 22 Feb 2016
 */

#include <cstdlib> //strtol
#include <iostream>
#include <string>

#include "Polynomial.h"

using namespace std;

int runMenu(Polynomial& lhs, Polynomial& rhs, Polynomial& ans);
bool inputPoly(Polynomial& p);

/*
 * 
 */
int main() {
    bool quit = false;
    int code = 1;
    Polynomial polys[3];
    
    cout << "Welcome to this program which adds Polynomials. Here's an example:" << endl
         << "2x^9+2x^2-x+5-42x^-1" << endl
         << "You can enter terms in any order and even have several of the same." << endl
         << "x^2+x-2x+4+1+x^2+2x^9-42x^-1" << endl << endl;

    while(!quit) {
        code = runMenu(polys[0],polys[1],polys[2]);
        if (code <= 0) quit = true;
    }
    
    return 0;
}

int runMenu(Polynomial& lhs, Polynomial& rhs, Polynomial& ans) {
    cout << "How would you like to add Polynomials?" << endl
         << "    1. Do the whole shebang!" << endl
         << "    2. Enter first Polynomial." << endl
         << "    3. Enter second Polynomial." << endl
         << "    4. View current Polynomials." << endl
         << "    5. Compute!" << endl
         << "    6. Quit." << endl
         << ": ";
    
    string input;
    bool error;
    
    cin >> input;
    
    switch (strtol(input.c_str(),NULL,10)) {
        case 1:
            error = inputPoly(lhs);
            if (error) break;
            error = inputPoly(rhs);
            if (error) break;
            ans = lhs + rhs;
            cout << "\n\n" << lhs.toString() << endl
                 << "+\n" << rhs.toString() << endl
                 << "=\n" << ans.toString() << endl << endl; 
            break;
        case 2:
            error = inputPoly(lhs);
            break;
        case 3:
            error = inputPoly(rhs);
            break;
        case 4:
            cout << lhs.toString() << endl << endl
                 << rhs.toString() << endl << endl
                 << ans.toString() << endl << endl;
            break;
        case 5:
            ans = lhs + rhs;
            cout << "\n\n" << lhs.toString() << endl
                 << "+\n" << rhs.toString() << endl
                 << "=\n" << ans.toString() << endl << endl; 
            break;
        case 6:
            cout << "See ya!" << endl;
            return 0;
            break;
        default:
            cout << "Invalid selection" << endl;
    }
    if (error) cout << "\nError parsing string!" << endl;
    return 1;
}

bool inputPoly(Polynomial& p) {
    cout << "Enter a polynomial below." << endl;
    string input;
    cin >> input;
    return !p.parse(input);
}

