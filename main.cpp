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

#include <iostream>
#include <string>

#include "Polynomial.h"

using namespace std;

int runMenu(Polynomial& lhs, Polynomial& rhs, Polynomial& ans);

/*
 * 
 *
int main() {
    bool quit = false;
    int code = 1;
    Polynomial polys[3];

    cout << "Intro" << endl;
    
    while(!quit) {
        code = runMenu(polys[0],polys[1],polys[2]);
        if (code <= 0) quit = true;
    }
    
    return 0;
}
*/

int main() {
    std::string s;
    std::cin >> s;
    Polynomial P;
    P.parse(s);
    
    return 0;

}


int runMenu(Polynomial& lhs, Polynomial& rhs, Polynomial& ans) {
    return 0;
}