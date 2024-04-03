Debug and release mode; C and x86-64

i) comparative execution time and short analysis of the performance of the kernels
![C](https://github.com/Joaquin-Arevalo/x86-to-C-interface-programming-project/assets/160611650/b73b97d0-8dd5-4253-9286-b9fe8368dfcc)

iii) Take a screenshot of the program output, including the correctens check (x86-64)
![x86-64](https://github.com/Joaquin-Arevalo/x86-to-C-interface-programming-project/assets/160611650/0dcfa821-c011-4cab-8bc6-c7dbe2638f3c)

Multiple tests were conducted for different vector size n = {220, 224, and 230}, for both debug mode and release mode, and recorded the time process in order to get the average execution time. By comparing the performance of the x86-64 implementation versus the C implementation across multiple tests, the x86-64 implementation consistently demonstrated superior performance across all tests and modes. This showcases the efficiency in execution time of the x86-64 kernel compared to the C kernel. This suggests potential optimizations or inherent performance advantages within the x86-64 architecture, especially in release mode, for these specific tasks.
