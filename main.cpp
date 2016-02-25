/* 
 * Project 1B
 * TEAM ONE!
 *      Bothell, Jacob
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
    
    //introduction
    cout << "Welcome to this program which adds Polynomials. Here's an example:" << endl
         << "2x^9+2x^2-x+5-42x^-1" << endl
         << "You can enter terms in any order and even have several of the same." << endl
         << "x^2+x-2x+4+1+x^2+2x^9-42x^-1" << endl << endl;

    //run the menu until the user quits
    while(!quit) {
        code = runMenu(polys[0],polys[1],polys[2]);
        if (code <= 0) quit = true;
    }
    
    return 0;
}

int runMenu(Polynomial& lhs, Polynomial& rhs, Polynomial& ans) {
    //prompt
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
    
    switch (strtol(input.c_str(),NULL,10)) { //protects from cin >> int not getting an int and throwing a tantrum
        case 1: //enter two polynomials, compute, and view, without going back to the menu
            error = inputPoly(lhs);
            if (error) break;
            error = inputPoly(rhs);
            if (error) break;
            ans = lhs + rhs;
            lhs.reduce();
            rhs.reduce();
            cout << "\n\n" << lhs.toString() << endl
                 << "+\n" << rhs.toString() << endl
                 << "=\n" << ans.toString() << endl << endl; 
            break;
        case 2: //input left operand
            error = inputPoly(lhs);
            lhs.reduce();
            break;
        case 3: //input right operand
            error = inputPoly(rhs);
            rhs.reduce();
            break;
        case 4: //view stored polynomials without adding
            cout << lhs.toString() << endl << endl
                 << rhs.toString() << endl << endl
                 << ans.toString() << endl << endl;
            break;
        case 5: //add two polynomials and display the resulting equation
            ans = lhs + rhs;
            cout << "\n\n" << lhs.toString() << endl
                 << "+\n" << rhs.toString() << endl
                 << "=\n" << ans.toString() << endl << endl; 
            break;
        case 6: //end program
            cout << "See ya!" << endl; //only viewable if your terminal doesn't automatically close
            return 0;
            break;
        default: //unexpected input
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

