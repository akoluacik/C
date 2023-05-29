#include<stdio.h>

int main() {
	int hypotenus;
	int a;
	int b;
	
	for(a = 1; a < 50; a++){
		for(b = 1; b < 50; b++){
			for(hypotenus = 1; hypotenus < 50; hypotenus++){
				if((hypotenus * hypotenus) == (a * a + b * b))
					printf("%d-%d-%d\n", a, b, hypotenus);
			}
		}
	}
	return (0);
}