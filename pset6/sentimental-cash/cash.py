import cs50
import math

def get_cents():
    n = -1
    while(n < 0):
        n = cs50.get_float("Change owed: ")
    return n

def calculate_quarters(cents):
    q = cents/25
    return q

def calculate_dimes(cents):
    q = cents/25
    d = (cents-q*25)/10
    return d

def calculate_nickels(cents):
    q = cents/25
    d = (cents-q*25)/10
    n = (cents-(q*25+d*10))/5
    return n

def calculate_pennies(cents):
    q = cents/25
    d = (cents-q*25)/10
    n = (cents-(q*25+d*10))/5
    p = cents-(q*25+d*10+n*5)
    return p


cents = get_cents()
quarters = calculate_quarters(cents)
cents = cents - quarters * 25
dimes = calculate_dimes(cents)
cents = cents - dimes * 10
nickels = calculate_nickels(cents)
cents = cents - nickels * 5
pennies = calculate_pennies(cents)
cents = cents - pennies * 1
coins = quarters + dimes + nickels + pennies
print(math.ceil(coins*100))


