#include <stdio.h>
#include <stdlib.h>
#include <libintl.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "");
    bindtextdomain ("main", getenv("PWD"));
    textdomain ("main");


    printf(gettext("Choose integer x in range [1, 100]\n"));
    int guess(int a, int b)
    {
	if ((b-a) == 0) return a;
        int cur = (a+b)/2 + (a+b)/2;
        printf(gettext("If your number >= %d, input 1, else input anything\n"), cur);
	int ans;
        scanf("%d", &ans);
        if (ans == 1)
	{
	    if (b-a == 1) return b;
	    return guess(cur, b);
	} else {
	    if (b-a == 1) return a;
	    return guess(a, cur-1);
	}
	return 0;
    }

    printf(gettext("The number is: %d\n"), guess(1, 100));

    return 0;
}
