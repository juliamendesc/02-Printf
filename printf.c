#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


int	precision(int *a){

	*a = 10;

	return *a;
}

int	minus(int *a){

	*a = 10;

	return *a;
}

int	star(int *a){

	*a = 10;

	return *a;
}

int main ()
{
	int 	a;

	a = 5;
	ft_muda(&a);
	printf("%d", a);

}