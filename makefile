all:hexaPrint

sort:bubbleSort.c
	gcc -m32 -g -Wall bubbleSort.c -o bubbleSort

hexaPrint:hexaPrint.c
	gcc -m32 -g -Wall -o hexaPrint hexaPrint.c
 
clean:
	rm -f bubbleSort *.o