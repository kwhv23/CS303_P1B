#include "Term.h"

Term::Term() {
}

Term::Term(const Term& orig) {
    exponent = orig.exponent;
    coefficient = orig.coefficient;
}

Term::~Term() {
}

//getters&&setters
void Term::set_exponent(const int expo){
    exponent = expo;
}
void Term::set_coefficient(const int coeff){
    coefficient = coeff;
}
int Term::get_exponent(){
    return exponent;
}
int Term::get_coefficient(){
    return coefficient;
}