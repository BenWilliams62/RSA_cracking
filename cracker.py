# Ask for inputs: the long key and
# the public exponent
# the private exponent will be outputted

import numpy as np
print()

def find_factors(num):
    factors = []
    lock = 0
    if num > 1:
        for i in range(2, num-1):
            if num%i == 0:
                factors = find_factors(int(num/i))
                lock = 1 
                factors.append(i)
                break
    if lock == 0:
        factors.append(num)

    return factors

def gcd(num1, num2):
    list1 = find_factors(num1)
    list2 = find_factors(num2)
    total = 1
    for i in range(len(list1)):
        if list1[i] in list2:
            total *= list1[i]
            # delete from list2 to prevent double counting
            x = list2.index(list1[i])
            del list2[x]
    return total

def lcm(num1, num2):
    product = num1*num2
    greatest = gcd(num1, num2)
    lowest = product / greatest
    return int(lowest)


def find_d(num1, num2, e):
    # 1 = e.d % lcm(num1-1, num2-1)

    # subtract 1 from each number
    num1 -= 1
    num2 -= 1

    # find lowest common multiple
    lowest = lcm(num1, num2)

    # loop to find value of d
    d = 1
    test = (e * d) % lowest
    while (test != 1):
        d += 1
        test = (e * d) % lowest
    
    return d

def find_prime(num1):
    # define maximum limit
    max_test = round(np.sqrt(num1))

    # loop through all values to find
    for i in range(2, max_test):
        if num1 % i == 0:
            factor1 = i
            factor2 = num1 / i
            break
    
    return int(factor1), int(factor2)


def private_key(num, e):
    
    # find primes that make number
    num1, num2 = find_prime(num)

    # find the private key
    pk = find_d(num1, num2, e)

    return pk


# ask for the keys then output the private key

x = find_factors(75)
print(x)

long = int(input("Long number\n"))
e = int(input("public key/e\n"))

pk = private_key(long, e)
print()
print("private key is:\n")
print(pk)