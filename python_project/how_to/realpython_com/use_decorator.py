from datetime import datetime
from my_decorator import do_twice

def not_during_the_night(func):
    def wrapper():
        if 7 <= datetime.now().hour < 22:
            func()
        else:
            pass    #Hush, the neighbors are asleep
    return wrapper

#say_whee = not_during_the_night(say_whee)

@do_twice
def say_whee():
        print("Whee!")

@do_twice
def greet(name):
    print(f"Hello {name}")

@do_twice
def return_greeting(name):
    print("Creating greeting")
    return f"Hi {name}"
