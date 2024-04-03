Debug and release mode C and x86-64

**i.) Comparative execution time and short analysis of the performance of the kernels**
**Debug Mode** (average execution times for each vector size n)
n = 1048576 or 220
C = 0.004 seconds
x86-64 = 0.0013 seconds

n = 16777216 or 224
C = 0.0483 seconds
x86-64 = 0.019 seconds

n = 268435456 or 230
C =  0.7838 seconds
x86-64 = 0.3379 seconds

**Release Mode** (average execution times for each vector size n)
n = 1048576 or 220
C = 0.004 seconds
x86-64 = 0.0013 seconds

n = 16777216 or 224
C = 0.0584 seconds
x86-64 = 0.0284 seconds

n = 268435456 or 230
C = 0.9149 seconds
x86-64 = 0.4547 seconds

  Multiple tests were conducted for different vector size n = {220, 224, and 230}, for both debug mode and release mode, and recorded the time process in order to get the average execution time. By comparing the performance of the x86-64 implementation versus the C implementation across multiple tests, the x86-64 implementation consistently demonstrated superior performance across all tests and modes. This showcases the efficiency in execution time of the x86-64 kernel compared to the C kernel. This suggests potential optimizations or inherent performance advantages within the x86-64 architecture, especially in release mode, for these specific tasks.

**ii.) Screenshot of the program output with the correctness check (C)**

![C](https://github.com/Joaquin-Arevalo/x86-to-C-interface-programming-project/assets/160611650/b73b97d0-8dd5-4253-9286-b9fe8368dfcc)

**iii.) Screenshot of the program output, including the correctens check (x86-64)**

![x86-64](https://github.com/Joaquin-Arevalo/x86-to-C-interface-programming-project/assets/160611650/0dcfa821-c011-4cab-8bc6-c7dbe2638f3c)

