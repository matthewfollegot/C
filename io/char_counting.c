#include <stdio.h>

main() 
{
    double nc;

    // counting # of characters. Simulate EOF with ^+d
    for(nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);

    
    

}