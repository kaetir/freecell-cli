

all:
	gcc -Wall *.c -o freecell 
	./freecell

clean:
	rm freecell