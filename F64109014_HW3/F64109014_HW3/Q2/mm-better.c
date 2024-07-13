void matrix_multiplication(int *a, int *b, int *output, int i,
                           int k, int j) {
	for(int m=0; m<i; m++){
		for(int n=0; n<k; n++){
			int r = a[m*k+n];
			for(int l=0; l<j; l++){
				output[m*j+l] += r * b[n*j+l];
			}
		}
	}
    return;
}
