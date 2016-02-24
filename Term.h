#ifndef TERM_H
#define TERM_H

#include <string>
#include <sstream>

class Term {
public:
    Term();
    Term(const Term& orig);
    ~Term();
    
    std::string print() const;
    
    //getters&&setters
    void set_exponent(const int expo);
    void set_coefficient(const int coeff);
    int get_exponent() const;
    int get_coefficient() const;
    const Term& operator=(const Term& rhs);
	//boolean operators
	bool operator== (const Term& rhs);
	bool operator!= (const Term& rhs);
	bool operator> (const Term& rhs);
	bool operator>= (const Term& rhs);
	bool operator< (const Term& rhs);
	bool operator<= (const Term& rhs);

private:
    int exponent;
    int coefficient;
};

#endif /* TERM_H */

