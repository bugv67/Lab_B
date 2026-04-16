all:AntiVirus 

sort:bubbleSort.c
	gcc -m32 -g -Wall bubbleSort.c -o bubbleSort

hexaPrint:hexaPrint.c
	gcc -m32 -g -Wall -o hexaPrint hexaPrint.c
 
AntiVirus:AntiVirus.c
	gcc -m32 -g -Wall -o AntiVirus AntiVirus.c
clean:
	rm -f bubbleSort hexaPrint AntiVirus *.o