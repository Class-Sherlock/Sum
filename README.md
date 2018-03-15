# Sum

The program will take two arguments from the command line. The first argument is the name of the file containing the integers (one number per line) to be read into the array, and the second argument, T, is the number of threads to be created. You may assume that the input contains N integers where N ≤ 1,000,000 and the number of threads is always smaller than or equal to the number of integers in the file, i.e. T ≤ N.
The program will divide the array into T groups of roughly equal size:
 the first T-1 groups will contain ceil(N/T) number of elements;
 the last group will contain the remaining elements.
For example, given T=2 and the array [4,7,3,5,98,23,53], the first group contains [4,7,3,5] and the second group contains [98,23,53]. Each thread will compute the sum of the integers in one of the groups.The program will display the sum of the integers assigned to each thread and finally the overall sum. The expected output for the above example is as follows, assuming the numbers are provided in input.txt:

$./sum input.txt 2 Thread 1: 19 Thread 2: 174 Sum = 193
