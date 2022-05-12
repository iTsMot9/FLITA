#include <stdlib.h>
#include <stdio.h>
int main() {
	FILE *f_mat, *f_graph;
	int mat_arr[1001][1001];
	int c;	
	int i = 0;
	int j = 0;
	int creb = 0;
	int tmpi = 0, tmpj = 0;
	f_mat = fopen("matrix_of_incedence161_2.txt", "r");
	while (!feof(f_mat)) {
		c = getc(f_mat);
		if (c == '\n') {
			tmpj = j;
			j = 0;
			i++;
			tmpi = i;
		}	
		else if (c != ' ') {
			mat_arr[i][j] = c - '0';
			j++;
		} 
  	}
	fclose(f_mat);
       	f_graph = fopen("out.dot", "w");
	fprintf(f_graph, "graph mat {\n");  
	for (int f_i = 1; f_i <= tmpi; f_i++) {
		fprintf(f_graph, "%d\n", f_i);
		printf("%d\n", f_i);
	}
	for (int f_j = 0; f_j < tmpj; f_j++) { 
   		for (int f_i = 0; f_i < tmpi - 1; f_i++) {
			for (int f_k = f_i + 1; f_k < tmpi; f_k++) {
     				if (mat_arr[f_i][f_j] == 1 && mat_arr[f_k][f_j] == 1) {
         				fprintf(f_graph, "%d -- %d;\n", f_i+1, f_k+1);
					printf("%d -- %d;\n", f_i+1, f_k+1);
					creb++;
				}
			}
	 	}
       	}
       	fprintf(f_graph, "}");
	fclose(f_graph);
	if (((tmpi-1)*(tmpi-2)/2) < creb) {
		printf("Connect\n");
	} else {
		printf("Not connect\n");
	}
	system("dot out.dot -Tpng -o out.png"); 
	system("gwenview ~/Desktop/fl3/out.png");
}
