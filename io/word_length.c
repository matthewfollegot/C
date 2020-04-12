#include <stdio.h>

/* this program calculates a histogram of word lengths */

main()
{
    int wlengths[15];
    int i, c, wl;

    for (i = 0; i < 15; ++i)
        wlengths[i] = 0;

    wl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++wlengths[wl];
            wl = 0;
        }
        else
            ++wl;
    }
    
    printf("histogram:\n");
    for (i = 1; i < 15; ++i)
        if (wlengths[i] != 0)
            printf("word length of %d has %d occurences\n", i, wlengths[i]);
    printf("all word lengths not mentioned have a frequency of 0"); // cleaning up output
                
}
