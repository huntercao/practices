from debug_decorator import debug

@debug
def make_greeting(name, age=None):
   if age is None:
      return f"Howdy {name}!"
   else:
      return f"Whoa {name}! {age} already, you are growing up!"
