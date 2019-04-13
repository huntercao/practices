import math
from debug_decorator import debug

# Apply a decorator to a stand library function
math.factorial = debug(math.factorial)

def approximate_e(terms=18):
   return sum(1 / math.factorial(n) for n in range(terms))
