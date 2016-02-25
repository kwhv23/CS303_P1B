#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include <list>
#include <sstream>
#include <stdexcept>

#include "Term.h"

class Polynomial {
public:
    Polynomial();
    Polynomial(const Polynomial& orig);
    Polynomial(std::list<Term>& lst);
    ~Polynomial();
    
    // needed for the menu
    bool parse(std::string input);
    Polynomial& operator+(const Polynomial& rhs);
    const Polynomial& operator=(const Polynomial& rhs);
    std::string toString();
    //reduces the polynomial into standard form
	void reduce();
    
    //more stuff!
private:
    std::list<Term> term_list;
};

#endif /* POLYNOMIAL_H */

