#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {

   int key;
   int info[30];
   int array[20];

};

struct node heapStructs[20];                                            // Global declaration of struct array
int array[20][10];


void CreateNode();
void HeapSort();
void Print();

int main() {



	FILE* fp = fopen("f.dat", "r");                // Opens file


      int i, j = 0;

      for (i=0; i<20; ++i) {


      	for (j=0; j<10; ++j) {                                  //Prints out the array
            char* s = malloc(5);
            fscanf(fp, " %s", s);
            array[i][j] = atoi(s);

            printf("%02d ", array[i][j]);


         }
               printf("\n");

      	}



   CreateNode();
   HeapSort();                                                 // Two calls: One for initial iteration
   HeapSort();                                                  // Second call goes over and fixes any irregularities and mismatches
   Print();


	fclose(fp);

	return 0;
}


void CreateNode(){

   int i = 0;

   for (i = 0; i<20; ++i) {                                                         // Stores the information for each of the 20 struct nodes

      struct node heapNode;
      heapNode.key = 0;

      int sum = array[i][0] + array[i][1] + array[i][2];
      heapNode.key = sum;                                                  //Stores the sum

      printf("THE KEY IS: %d", heapNode.key);

      int j;
      printf("  THE INFORMATION CONTENTS ARE: ");
      int x = 0;
      for (j=3; j<10; ++j) {

      heapNode.info[x] = array[i][j];
      printf("%02d ", heapNode.info[x]);
      ++x;

      }

      int y = 0;

      for (y=0; y<10; ++y) {

         heapNode.array[y] = array[i][y];                                        // Assigns the array of numbers for each struct object

       }

      printf("\n");
      printf("VALUE OF I: %d\n", i);
      heapStructs[i] = heapNode;

   }

}


void Print(){


      int i, j = 0;

      for (i=0; i<20; ++i) {



         for (j=0; j<10; ++j) {                                  //Prints out the array

            printf("%02d ",  heapStructs[i].array[j]);

         }
           printf("\n");

}

}

void HeapSort() {

   int i = 0;
   int n = 0;


  for (i = 19; i>=1; --i) {

      n = i;

      while (heapStructs[n].key < heapStructs[(n-1)/2].key) {                             // Starts at the bottom of the heap and swaps if parent key is greater than child's


               struct node temp;
               temp = heapStructs[(i-1)/2];
               heapStructs[(i-1)/2] = heapStructs[i];
               heapStructs[i] = temp;

               n = (i-1)/2;
               break;
     }

      }



   }
