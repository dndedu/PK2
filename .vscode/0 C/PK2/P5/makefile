main: main.c tasks
	gcc main.c -o main task1_count_space_in_string.o task2_minimum_in_array.o task3_string_concatenation.o task4_factorial_binomial.o
	
tasks: task1_count_space_in_string.c task2_minimum_in_array.c task3_string_concatenation.c task4_factorial_binomial.c
	gcc task1_count_space_in_string.c -c
	gcc task2_minimum_in_array.c -c
	gcc task3_string_concatenation.c -c
	gcc task4_factorial_binomial.c -c

clean:
	rm main task1_count_space_in_string.o task2_minimum_in_array.o task3_string_concatenation.o task4_factorial_binomial.o