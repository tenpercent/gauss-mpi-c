int findMainBlock(double *a, int matrix_side, int block_side, int total_pr, int current_pr, 
	int first_row, int current_pr_full_rows, int block_size, int block_string_size){
	min_j = 0;
    min_k_global = 0;

   	in.minnorm = 0.;
   	in.rank = current_pr;
    in.label = 0;
    in.min_k = i;
	temp = 0.;

	for (j=first_row; j<current_pr_full_rows; j++){
   		for (k=i; k<total_full_block_rows; k++){
   	    res = simpleInvert(a + j*block_string_size + k*block_size, buf_1, buf_2, block_side);
        if (!res) {
   			  temp = matrixNorm(buf_1, block_side);
          if (in.label){
            if (temp<in.minnorm){
     	      in.minnorm = temp;
              min_j=j;
              in.min_k = k;
            }
          }
          else{
            in.label = 1;
            in.minnorm = temp;
            min_j=j;
            in.min_k = k;
          }
        }
      }
    }
}
/*
оманъ
int Find_Main_Block_Index(int n, int m, int p, double *ac, double *s_colomn, int iteration, double *main_block_inv, double *main_block_buf, int my_rank)
{
struct {
double nor;
int index; } send, recv;
int min_norm = 100;
int norm;
int min_norm_index = iteration;
int k = n/m;
bool flag;
double *pointer;

if(my_rank == iteration%p )
{
pointer = ac + (iteration/p)*m*n;
}
else
{
pointer = s_colomn;
}
MPI_Bcast(pointer, n*m, MPI_DOUBLE, iteration%p, MPI_COMM_WORLD );

//Find max block norm( min inversed block norm) and nomber of string corresponding to it in each process;

flag = 1;

for(int i = iteration; i < k; i++ )
{
if(my_rank == i%p)
{
if(Matrix_Block_Inversion(pointer + (i/p)*m*m, main_block_buf, main_block_inv, m)!= 0)
continue;

if(flag == 1)
{
min_norm = Matrix_Block_Norm(main_block_inv, m);
min_norm_index = i;
flag = 0;
}
else
{
norm = Matrix_Block_Norm(main_block_inv, m);
if( norm < min_norm)
{
min_norm = norm;
min_norm_index = i;
}
}
}
}
if(flag == 0)
{
send.nor = 1e+100;
send.index = min_norm_index;
}
else
{
send.nor = -1.;
send.index = iteration;
}
MPI_Allreduce(&send, &recv, 1, MPI_DOUBLE_INT, MPI_MINLOC, MPI_COMM_WORLD );

return recv.index;

}
*/