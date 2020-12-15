// Ask for inputs: public key, 
// and public exponent
// the private exponent will be outputted

#include <iostream>
#include <vector>

#include "functions.hpp"

int main(){
    
    // declare variables needed
    int e, public_number;
    // ask for longer digit
    std::cout << "\nEnter the long number\n";
    std::cin >> public_number;

    // ask for public key
    std::cout << "\nEnter the public key\n";
    std::cin >> e;

    // return private key
    int pk = private_key(public_number, e);
    std::cout << "\n\nThe private key is:\n\n" << pk << "\n";
    

    return 0;
};