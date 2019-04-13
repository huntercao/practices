from timer_decorator import timer

@timer
def timer_test(run_times):
   for _ in range(run_times):
      sum([i**2 for i in range(10000)])

if __name__ == '__main__':
   print("Called directly")
   timer_test(50)
else:
   print("Imported")
   timer_test(500)
