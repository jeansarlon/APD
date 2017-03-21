#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



#define TAM 800
int A[TAM][TAM]={0}, B[TAM][TAM]={0}, C[TAM][TAM]={0}, r1,r2;

int main() {
   omp_set_num_threads(300);

   
   srand(time(NULL));


   for (int i = 0; i < TAM; i++) {
      for (int j = 0; j < TAM; j++) {
         A[i][j] = rand()%999999+1;
         B[i][j] = rand()%999999+1;
      }
   }

#pragma omp parallel for
   for (int i = 0; i < TAM; i++) {
     #pragma omp parallel for
      for (int j = 0; j < TAM; j++) {
         // printf("%i\n", A[i][j] );
         C[i][j] = A[i][j] * B[i][j];
      }
   }

   // for (int i = 0; i < TAM; i++) {
   //    printf("\n");
   //    for (int j = 0; j < TAM; j++) {
   //       if (C[i][j] > 99 && C[i][j] < 1000) {
   //          printf(" %i  - ", C[i][j] );
   //       }else if (C[i][j] > 9 && C[i][j] < 100) {
   //          printf(" %i   - ", C[i][j] );
   //       }else if (C[i][j] > 0 && C[i][j] < 10) {
   //          printf(" %i    - ", C[i][j] );
   //       }else{
   //          printf(" %i - ", C[i][j] );
   //       }
   //    }
   // }

   printf("\n");
   printf("\n");

   //  printf("Hello %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
}
