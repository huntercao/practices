# https://realpython.com/primer-on-python-decorators/

#python3 -c 'from primer import print_hello; print_hello()'
def print_hello():
    print( "Hello!" )

#python3 -c 'from primer import add_one; print(add_one(2))'
def add_one(number):
    return number + 1

def say_hello(name):
    return f"Hello {name}"

def be_awesome(name):
    return f"Yo {name}, together we are the awesomeest!"

def greet_bob(greeter_func):
    return greeter_func("Bob")

def parent():
    print("Printing from the parent() function")
    
    def first_child():
        print("Printing from the first_child() function")

    def second_child():
        print("Printing from the second_child() function")

    second_child()
    first_child()

def parent2(num):
    def first_child():
        return "Hi, I am Emma"

    def second_child():
        return "Call me Liam"

    if num == 1:
        return first_child
    else:
        return second_child

    #first = parent2(1)
    #second = parent2(2)

    #first

    #second

    #first()

    #second()

#python3 primer.py
if __name__ == '__main__':
    print( add_one(30) )

