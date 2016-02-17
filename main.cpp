/* 
 * Project 1B
 * TEAM ONE!
 *      Bother, Jacob
 *      Brown, Joshua
 *      Hamilton, Kenton
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

bool startMenu(Polynomial& lhs, Polynomial& rhs, Polynomial& ans);

/*
 * 
 */
int main() {
    Polynomial polys[3];
    
    bool error = startMenu(polys[0],polys[1],polys[2]);
    
    if (error) return 1;
    return 0;
}
