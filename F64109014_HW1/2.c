#include <stdio.h>
int main ()
{
    int a[10] = {0}, b[10] = {0}, c[10] = {0}; 
    int i, arr_size = 10;
    FILE *input = fopen("../input/2.txt", "r");
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &a[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &b[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &c[i]);
    fclose(input);
    int *p_a = &a[0];
    int *p_b = &b[0];
    int *p_c = &c[0];
    /* Original C code segment
    for (int i = 0; i < arr_size; i++){
    *p_c++ = *p_a++ - *p_b++;
    }
    */
    for (int i = 0; i < arr_size; i++){
    	asm volatile(
    		"sub %[c], %[a], %[b]\n\t"
    		:[c] "+r"(*(p_c+i))
    		:[a] "r"(*(p_a+i)), [b] "r"(*(p_b+i))
    	);
    }
    p_c = &c[0];
    for (int i = 0; i < arr_size; i++)
    printf("%d ", *p_c++);
    printf("\n");
    return 0;
}
