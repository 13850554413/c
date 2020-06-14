#include <stdio.h>
#include <stdlib.h>
#define TSIZE 45 /*存放片名数组的大小*/
#define FMAX 5 /*最多的影片数*/

struct film {
    char title[TSIZE];
    int rating;
};

int main(void)
{
    struct film movies[FMAX];
    int i = 0;
    int j;

    puts("enter first movie title: ");
    while (i < FMAX && fgets (movies[i].title,TSIZE,stdin) != NULL &&
            movies[i].title[0] != '\0')
    {
        puts("Enter your rating <0-10>: ");
        scanf("%d", &movies[i++].rating);
        while(getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop): ");
    }
    if (i == 0)
        printf("No date entered.");
    else
        printf("Here is the movie list: \n");

    for (j=0; j<i;j++)
        printf("Movie: %s Rating : %d\n", movies[j].title,
                movies[j].rating);
    printf("Bye\n");
    return 0;
}
