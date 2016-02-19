#ifndef TERM_H
#define TERM_H

class Term {
public:
    Term();
    Term(const Term& orig);
    ~Term();
    
    //getters&&setters
    void set_exponent(const int expo);
    void set_coefficient(const int coeff);
    int get_exponent();
    int get_coefficient();

private:
    int exponent;
    int coefficient;
};

#endif /* TERM_H */

