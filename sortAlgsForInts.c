/** **************************************************************888888***********
 * @remark This program provides implementation and testing                       *
 *    for versions of four common sorting algorithms                              *
 *    of integer arrays                                                           *
 *                                                                                *
 * @author Henry M. Walker                                                        *
 * @remark Assignment  Comparison of Sorting Algorithms                           *
 * @file  sort-comparisons-complete.c                                             *
 * @date  March 13. 2023                                                          *
 *                                                                                *
 * @remark  Sorting algorithms included:                                          *
 *    Straight Selection Sort (mostly traditional swap of maximum)                *
 *    Straight Selection Sort (with insert rather than swap of maximum)           *
 *    Insertion Sort (mostly traditional insertion process)                       *
 *    Recursive Merge Sort (mostly traditional)                                   *
 *    Irerative Merge Sort (replacing recursion with equivalent iteration)        *
 *                                                                                *
 * @remark Some versions may be somewhat different from traditional ones          *
 *                                                                                *
 * @remark Although all versions pass tests of sorting correctness,               *
 *    for asending, random, and descending data                                   *
 *                                                                                *
 * to compile as a C program                                                      *
 *     gcc -o sortAlgsForInts sortAlgsForInts.c                                   *
 *                                                                                *
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>   // for malloc, free, srand, rand
#include <time.h>     // for time
#include <limits.h>   // for INT_MAX, the largest value of type int

/** *******************************************************************************
 * structure to identify both the name of a sorting algorithm and                 *
 * a pointer to the function that performs the sort                               *
 * the main function utilizes this struct to define an array of                   *
 * the sorting algorithms to be timed by this program.                            *
 **********************************************************************************/

typedef struct sorts {
  const char * name;
  void (*sortProc) (int [ ], int);
} sorts;

/* * * * * * * * * * * * sorting procedures, with helperss  * * * * * * * * * * * */

/** *******************************************************************************
 * straight selection sort                                                        *
 *    (slight variation that does not impact correctness)                         *
 *                                                                                *
 * as the traditional sort, once max foound, it is swapped with last array element*
 *                                                                                *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
 *                                                                                *
 **********************************************************************************/

void tradSelectionSort (int a [ ], int n) {
   int i, j, smallIndex;
   int temp;

   // put largest remaining element in a[i]
   for (i = n-1; i >= 1; i--) {
      // find largest in a[i..i]
      smallIndex = i;
      for (j = i-1; j >= 0; j--) {
         if (a[smallIndex] < a[j])
            smallIndex = j;
     }
     // swap smallest to a[i]
     temp = a[smallIndex];
     a[smallIndex] = a[i];
     a[i] = temp;
   }
}

/** *******************************************************************************
 * straight selection sort                                                        *
 *    (slight variation that does not impact correctness)                         *
 *                                                                                *
 * in this variation of the selection sort, once max is found,                    *
 *   the element being moved with max is inserted into array, not swapped         *
 *                                                                                *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
 *                                                                                *
 **********************************************************************************/

void SelSortWInsertion (int a [ ], int n) {
   int i, j, smallIndex;
   int temp;
   // put largest remaining element in a[i]
   for (i = n-1; i >= 0; i--) {
      // find largest in a[i..n-1]
      smallIndex = i;
      for (j = i-1; j >= 0; j--) {
         if (a[smallIndex] < a[j])
            smallIndex = j;
     }
     // insert max element into last position by sliding other elements down
     temp = a[smallIndex];
     for (j = smallIndex; j < i; j++) {
       a[j] = a[j+1];
     }
     a[i] = temp;
   }
}
// 1 2 3 4
//
/** *******************************************************************************
 * insertion sort                                                                 *
 *    (slight variation that does not impact correctness)                         *
 *                                                                                *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * @post  the first n elements of a are sorted in non-descending order            *
 *                                                                                *
 **********************************************************************************/

void insertionSort (int a [], int n) {
// method to sort using the insertion sort
// parameters:  a, the array to be sorted
//              length, the size of the a array
   for (int k = 1; k < n; k++) {
      int item = a[k];
      int i = k-1;
      while ((i >= 0) && a[i] >= item){
         a[i+1] = a[i];
         i--;
      }
      a[i+1] = item;
   }
}

/** *********************************************************************************
 * tradtional merge Sort procedure                                                  *
 * based on tutorialpoint.com:                                                      *
 *      https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort    *
 *      See URL for parameters, etc.                                                *
 *                                                                                  *
 * with slight variation that does not impact correctness                           *
 *                                                                                  *
 * this procedure merges segment [left, mid] with [mid, right] in array             *
 *                                                                                  *
 * @param   left    left endpoint of array segment to be merged                     *
 * @param   mid     midpoint of array segment to be merged                          *
 * @param   right  right endpoint of array segment to be merged                     *
 *                                                                                  *
 * @pre  segments [left, mid] and [mid+1, right] are ordered                        *
 * @post segment [left, right] is ordered                                           *
 *                                                                                  *
 * @remark dynamic memory allocation to avoid segmentation fault                    *
 * for moderately large array size                                                  *
 *                                                                                  *
 ************************************************************************************/
void traditionalMerge (int *array, int left, int mid, int right) {
  int i, j, k;
  int lsize = mid-left+1;     //size of left and right sub-arrays
  int rsize =  right-mid;

  // use malloc to avoid segmentation fault for size >= 2560000
  int * larr = (int *) malloc (lsize * sizeof (int));
  int * rarr = (int *) malloc (rsize * sizeof (int));

  //fill left and right sub-arrays
  for(i = 0; i<lsize; i++)
    larr[i] = array[left+i];
  for(j = 0; j<rsize; j++)
    rarr[j] = array[mid+j+1];
  i = 0;
  j = 0;
  k = left;

  //marge temp arrays to real array
  while(i < lsize && j<rsize) {
    if(larr[i] < rarr[j]) {
      array[k] = larr[i];
      i++;
    }else{
      array[k] = rarr[j];
      j++;
    }
    k++;
  }
  while(i<lsize) {       //extra element(s) in left array
    array[k] = larr[i];
    i++;
    k++;
  }
  while(j<rsize) {       //extra element(s) in right array
    array[k] = rarr[j];
    j++;
    k++;
  }
}

/** **************************************************************************************
 * tradtional merge Sort procedure, with left/right (start/end)parameters, renamed from  *
 * source:  tutorialpoint.com:                                                           *
 * https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort              *
 *                                                                                       *
 * this procedure oversees sorting of the segment [left, right] within array             *
 *                                                                                       *
 * @param   left    left endpoint of array segment to be sorted                          *
 * @param   rightt  right endpoint of array segment to be sorted                         *
 *                                                                                       *
 *****************************************************************************************/

void traditionalMergeSort(int *array, int start, int end) {
   int mid;
   if (start < end) {
      int mid = start+(end-start)/2;
      // Sort first and second arrays
      traditionalMergeSort(array, start, mid);
      traditionalMergeSort(array, mid+1, end);
      traditionalMerge(array, start, mid, end);
   }
}

/** **************************************************************************************
 * traditional recursive merge Sort procedure                                            *
 *                                                                                       *
 * @param  arr  the array to be sorted                                                   *
 * @param  n  the size of the array                                                      *
 * @post  the first n elements of a are sorted in non-descending order                   *
 * @remark segmentation fault for n-1 >= 256000 or so                                    *
  ****************************************************************************************/
void tradRecMergeSort  (int arr [ ], int n) {
traditionalMergeSort (arr, 0, n-1);
}


/** **************************************************************************************
 * iterative merge Sort procedure                                                        *
 *    simply translating the recursive algorithm to iteration                            *
 *    (same logical steps as recursion, but in a different order)                        *
 *                                                                                       *
 * @param  a  the array to be sorted                                                     *
 * @param  n  the size of the array                                                      *
 * @post  the first n elements of a are sorted in non-descending order                   *
 * @remark segmentation fault for n-1 >= 256000 or so                                    *
  ****************************************************************************************/
void tradIterMergeSort  (int a [ ], int n) {

  int mergeSize = 1;

  // array segments to be merged will be [start1, end1] and [end1+1, end2]

  int start1, end1, end2;
  while (mergeSize < n)
    {
      int end2;
      for (start1 = 0;        // start merge process for this mergeSize at start of array
           start1 < n-1;      // if first index of segment is >=n-1, then segment already sorted
           start1 = end2+1) { // since merging done forsegments in a[0..end2] , next segment starts at end2+1
        int end1 = start1 + mergeSize - 1;
        // check sorting does not access elements outside array
        // last valid index is n-1
        if (end1 > n-1) {
          end1 = n-1;
        }
        end2 = end1 + mergeSize;
        if (end2 > n-1) {
          end2 = n-1;
        }

        traditionalMerge (a, start1, end1, end2);
      }
      mergeSize *=2;
    }
}


/* * * * * * * * * * * * procedures to check sorting correctness  * * * * * * * * * */

/** *******************************************************************************
 * check all array elements have values 0, 2, 4, . . ., 2(n-1)                    *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * returns  "ok" if array contains required elements; "NO" if not                 *
 ****************************************************************************(*****/

const char * checkAscValues (int a [ ], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] != 2*i) {
      printf ("%4d %4d", i, a[i]);
      return "NO";
    }
  }
  return "ok";
}

/** *******************************************************************************
 * check all array elements are in non-descending order                           *
 * @param  a  the array to be sorted                                              *
 * @param  n  the size of the array                                               *
 * returns  "ok" if array elements in non-descending order; "NO" otherwise        *
 **********************************************************************************/

const char * checkAscending (int a [ ], int n) {
  for (int i = 0; i < n-1; i++) {
    if (a[i] > a[i+1])
      return "NO";
  }
  return "ok";
}

/** *******************************************************************************
 * driver program for testing and timing sorting algorithms                       *
 **********************************************************************************/

int main ( ) {
  const int numAlgs = 5;
  sorts sortProcs [numAlgs] = {
                               {"trad. selection sort ", tradSelectionSort     },
                               {"sel. sort w/insert   ", SelSortWInsertion     },
                               {"insertion sort       ", insertionSort         },
                               {"rec. merge sort      ", tradRecMergeSort      },
                               {"iter. merge sort     ", tradIterMergeSort     }
                              };

  //size variables
  int maxDataSetSize = 40000;
  //int maxDataSetSize = 40960000;
  //int maxDataSetSize = 81920000;
  //int maxDataSetSize = 327680000;
  int algTimeLimit = 15; // do not print results after algorithm taks this long (in seconds)

  //arrays to determine which algorithms are to be run
  //   1 = run algorithm; 0 = do not run (alg has taken too long in past
  int algAscActive [numAlgs];
  int algRanActive [numAlgs];
  int algDesActive [numAlgs];

  // initially all algorithms active for ascending, random, and descendind data
  int numSort;
;
 for (numSort = 0; numSort < numAlgs; numSort++) {
      algAscActive[numSort] = 1;
      algRanActive[numSort] = 1;
      algDesActive[numSort] = 1;
    }

  // randomize random number generator's seed
  srand (time ((time_t *) 0) );

  // print headings
  printf ("                        Data Set                                Times\n");
  printf ("Algorithm                 Size        Ascending Order       Random Order   Descending Order\n");

  int size;
  for (size = 10000; size <= maxDataSetSize; size *= 2) {
    //for (size = 10; size <= maxDataSetSize; size *= 2) {
      // create and initialize control data set arrays
     int * asc = (int *) malloc (size * sizeof(int));   //array with ascending data
     int * ran = (int *) malloc (size * sizeof(int));   //array with random data
     int * des = (int *) malloc (size * sizeof(int));   // array with descending data

     int i;
     for (i = 0; i< size; i++) {
        asc[i] = 2*i;
        ran[i] = rand();
        des[i] = 2*(size - i - 1);
     }

     // timing variables
     clock_t start_time, end_time;
     double elapsed_time;

     /* loop to test successive sorting procedures */
     // copy to test arrays
     int * tempAsc = malloc (size * sizeof(int));
     int * tempRan = malloc (size * sizeof(int));
     int * tempDes = malloc (size * sizeof(int));

     // break output for this array sze
     printf ("\n");

     /* iterate through sorting algorithms */
     for (numSort = 0; numSort < numAlgs; numSort++) {

       // set up copies of arrays to sort
       for (i = 0; i< size; i++) {
         tempAsc[i] = asc[i];
         tempRan[i] = ran[i];
         tempDes[i] = des[i];
       }

       // timing for sorting algorithm
       printf ("%4s %9d", sortProcs[numSort].name, size);
       // run-time stack exceeded for qicksort for large ordered arrays
       if (!algAscActive[numSort]) {
         printf ("             > %2d ", algTimeLimit);
       } else {
         // ascending data
         start_time = clock ();
         sortProcs[numSort].sortProc (tempAsc, size);
         end_time = clock();
         elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
         printf ("%14.1lf", elapsed_time);
         printf ("  %2s", checkAscValues (tempAsc, size));
         algAscActive[numSort] = (elapsed_time <= algTimeLimit);
       }

      if (!algRanActive[numSort]) {
          printf ("             > %2d  ", algTimeLimit);
      } else {
        // random data
        start_time = clock ();
        sortProcs[numSort].sortProc (tempRan, size);
        end_time = clock();
        elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
        printf ("%15.1lf", elapsed_time);
        printf ("  %2s", checkAscending (tempRan, size));
        algRanActive[numSort] = (elapsed_time <= algTimeLimit);
      }

       // run-time stack exceeded for qicksort for large ordered arrays
      if (!algDesActive[numSort]) {
         printf ("             > %2d  ", algTimeLimit);
       } else {
         // descending data
         start_time = clock ();
         sortProcs[numSort].sortProc (tempDes, size);
         end_time = clock();
         elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
         printf ("%15.1lf", elapsed_time);
         printf ("  %2s", checkAscValues (tempDes, size));
         algDesActive[numSort] = (elapsed_time <= algTimeLimit);
       }

      printf ("\n");
     }

      printf ("\n---------------------------------------------------------------------------------------\n");

      // clean up copies of test arrays
     free (tempAsc);
     free (tempRan);
     free (tempDes);



     // clean up original test arrays
     free (asc);
     free (ran);
     free (des);

  } // end of loop for testing procedures with different array sizes

  return 0;
}
