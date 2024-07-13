"li t4, 0\n\t" // i
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"for_loop:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"bge t4, %[N], exit\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
// under
"li t1, 2\n\t" // set t4 as 2 , t4 to t1
"addi %[lw_cnt], %[lw_cnt], 1\n\t"
"mul t1, t1, t4\n\t" // 2*i
"addi %[mul_cnt], %[mul_cnt], 1\n\t"
"addi t1, t1, 1\n\t" // 2*i+1
"addi %[add_cnt], %[add_cnt], 1\n\t"
"FCVT.D.W f2, t1\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"li t2, 1\n\t" // set power init value(base)
"li t3, -1\n\t" // set self-mul
"addi %[lw_cnt], %[lw_cnt], 2\n\t"

"mv t1, t4\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"pow:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"beqz t1, continue\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"mul t2, t2, t3\n\t"
"addi %[mul_cnt], %[mul_cnt], 1\n\t"
"addi t1, t1, -1\n\t" // i-1
"addi %[add_cnt], %[add_cnt], 1\n\t"
"j pow\n\t"

"continue:\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"FCVT.D.W f1, t2\n\t"
"addi %[others_cnt], %[others_cnt], 1\n\t"
"fdiv.d f1, f1, f2\n\t" // divide
"addi %[div_cnt], %[div_cnt], 1\n\t"

"fadd.d %[pi], %[pi], f1\n\t" // pi+=term
"addi %[add_cnt], %[add_cnt], 1\n\t"
"addi t4, t4, 1\n\t"
"addi %[add_cnt], %[add_cnt], 1\n\t"
"j for_loop\n\t"

"exit:\n\t"
