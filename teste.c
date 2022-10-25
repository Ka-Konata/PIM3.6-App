#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main () {

   /* an array with 5 rows and 2 columns*/
   int a[2][5][2] = {{ {0,0}, {1,2}, {2,4}, {3,6},{4,8}}, { {0,0}, {1,2}, {2,4}, {3,6},{4,8}}};
   int i, j, k;
 
   /* output each array element's value */
   for ( i = 0; i < 2; i++ ) {

      for ( j = 0; j < 5; j++ ) {

        for (k = 0; k < 2; k++) {
            printf("a[%d][%d][%d] = %d\n", i,j,k, a[i][j][k] );
        }
      }
   }
   printf("\n%d\n", (int) (sizeof(a[0]) / sizeof(a[0][0])));
   system("pause");
}
 