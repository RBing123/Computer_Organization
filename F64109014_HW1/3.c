#include<stdio.h>
int main()
{ 
    int f, i, j;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/3.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
    for (i = 0; i < 3; i++){ 
        for (j = 0; j < 2; j++){        	
            for (f = 0; f < 3; f++){
                asm volatile(
                	"li t5, 2\n\t"
                	"lw t2, 0(%[p_h])\n\t"
                	"lw t3, 0(%[p_x])\n\t"
                	"lw t4, 0(%[p_y])\n\t"
                	"bne %[f], t5, ptr\n\t"
                	"mul t1, t2, t3\n\t"
                	"add t4, t4, t1\n\t"
                	"sw t4, (%[p_y])\n\t"
                	"addi %[p_y], %[p_y], 4\n\t"
                	"j space\n\t"
                	"ptr:\n\t"
                	"mul t1, t2, t3\n\t"
                	"add t4, t4, t1\n\t"
                	"sw t4, 0(%[p_y])\n\t"
                	"space:\n\t"
                	:[p_y] "+r"(p_y)
                	:[p_h] "r"(p_h+(i*3)+f), [p_x] "r"(p_x+j+(f*2)), [f] "r"(f)
                );
            }
	}
    }
    p_y = &y[0];
    for(i = 0; i < 6; i++)
    printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}
