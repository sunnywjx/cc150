/*
cc12.1: Find the mistakes in the following code:

            unsigned int i;
            for(i=100; i>=0; --i)
                printf("%d\n", i);


Solution: 1. Use %u instead of %d;
          2. Unsigned int is always >=0, the for will loop 
             infinitely; thus, change it to i>0.

*/