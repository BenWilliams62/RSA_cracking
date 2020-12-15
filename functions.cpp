#include <iostream>
#include <vector>

#include "functions.hpp"

// find factors of a number, using recursion
std::vector<int> find_factors(int num){
    // set up variables
    std::vector<int> factors;
    int lock = 0;

    if (num > 1){
        for (int i = 2; i < num-1; i++){
            if (num % i == 0){
                factors = find_factors(num/i);
                lock = 1;
                factors.push_back(i);
                break;
            };
        };
    };

    // if not divisible by any number, then add the number itself
    if (lock == 0){
        // append num to factors
        factors.push_back(num);
    };

    return factors;
};

// find the greatest common divisor of two numbers
int gcd(int num1, int num2){
    // list1
    std::vector<int> list1;
    std::vector<int> list2;
    list1 = find_factors(num1);
    list2 = find_factors(num2);

    // set total to 1 to avoid multiplying by 0 error
    int total = 1;

    // loop through all values of list 1, multiply by total if in btoh lists
    for (int i = 0; i <= list1.size(); i++){
        if (std::find(list2.begin(), list2.end(), list1[i]) != list2.end()){
            total *= list1[i];
            std::vector<int>::iterator it = std::find(list2.begin(), list2.end(), list1[i]);
            //std::cout << *it << "\n";
            list2.erase(it);

        };
    };
    return total;
};

// find the lowest common multiple of two numbers
int lcm(int num1, int num2){
    int product = num1 * num2;
    int greatest = gcd(num1, num2);

    int lowest = product / greatest;
    return lowest;
};

// find the private key
int find_d(int num1, int num2, int e){
    
    // function: 1 = e*d % (lcm(prime1 - 1, prime2 - 1))
    
    // reduce both primes by 1 for function
    num1 -= 1;
    num2 -= 1;

    // lowest common mulitple
    int lowest = lcm(num1, num2);

    // set up loop
    int d = 1;
    int test = (e * d) % lowest;

    // loop through values of d to find the lowest correct solution
    while (test != 1){
        d += 1;
        test = (e * d) % lowest;
    };


    return d;
};

// return the two primes used to make up the long public key
int find_prime(int num1){
    // outputs
    int prime1;

    // loop through values 2 to prime until factors found
    int it = 2;
    float test = num1 % it;

    while (test !=  0){
        it ++;
        test = num1 % it;

        if ( test == 0){
            prime1 = it;
        };
    };
    return prime1;
};

// find the private key from the primary key and the large number
int private_key(int num, int e){
    int num1, num2;
    
    // find the two primes
    num1 = find_prime(num);
    num2 = num / num1;

    // find the private key
    int pk = find_d(num1, num2, e);

    return pk;

};