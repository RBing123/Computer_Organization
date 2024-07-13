#include<stdio.h>
int main()
{ 
    int i = 0;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/4.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    
    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];
    
    asm volatile(
    	"li t6, 3\n\t"
    	"loop_i:\n\t"
    		"li t1, 3\n\t"
    		"loop_f:\n\t"
    			"lw t2, 0(%[p_h])\n\t"
        		"lw t3, 0(%[p_x])\n\t"
        		"lw t4, 0(%[p_y])\n\t"
    			"mul t5, t2, t3\n\t"
    			"add t4, t4, t5\n\t"
    			"sw t4, 0(%[p_y])\n\t"
    			"lw t2, 0(%[p_h])\n\t"//
        		"lw t3, 4(%[p_x])\n\t"
        		"lw t4, 4(%[p_y])\n\t"
    			"mul t5, t2, t3\n\t"
    			"add t4, t4, t5\n\t"
    			"sw t4, 4(%[p_y])\n\t"
    			"addi %[p_h], %[p_h], 4\n\t"
    			"addi %[p_x], %[p_x], 8\n\t"
    			"addi t1, t1, -1\n\t"
    		"bnez t1, loop_f\n\t"
    		"addi %[p_y], %[p_y], 8\n\t"
    		"addi %[p_x], %[p_x], -24\n\t"
    		
    		"addi t6, t6, -1\n\t"
    	"bnez t6, loop_i\n\t"
    	:[p_y] "+r"(p_y)
    	:[p_h] "r"(p_h), [p_x] "r"(p_x)
    );

    p_y = &y[0];
    for(i = 0; i < 6; i++)
        printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}
