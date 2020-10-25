#include <stdlib.h>

int main(int argc, char **argv)
{
	int* a = malloc(sizeof(int));
	a[0] = 1;
	free(a);
	free(a);
}
