#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include <list>

class Polynomial {
public:
    Polynomial();
    Polynomial(const Polynomial& orig);
    ~Polynomial();
    
    // needed for the menu
    bool parse(std::string input);
    const Polynomial& operator+(const Polynomial& rhs) const;
    const Polynomial& operator=(const Polynomial& rhs);
    std::string toString();
    
    //more stuff!
private:

};

#endif /* POLYNOMIAL_H */

