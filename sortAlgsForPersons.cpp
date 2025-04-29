/** **************************************************************************************
 * @remark    This file provides a framework for two software development tasks          *
 *      traisitioning in from arrays of simple data types to arrays of objects           *
 *      experimenting with the impact of separate procedures                             *
 *           (e.g., for readability, maintenance) on efficiency                          *
 *                                                                                       *
 * To ilustrate some types of work using sorting arrays of objects, this program         *
 *         iniital an array of random objects (using 2 distinct random number generators *
 *         implements and tests an insertion sort, based on different object fields      *
 *                                                                                       *
 * Insertion sort is based on the C program contained in sortAlgsForInts.c               *
 *                                                                                       *
 * @author of program shell: Henry M. Walker                                             *
 * @date of framework:  September 22, 2024                                               *
 *                                                                                       *
 * @remark  Focus for experiments for this program                                       *
 *                                                                                       *
 * @author                                                                               *
 * @date                                                                                 *
 *                                                                                       *
 * This file demonstrates the use of two approaches to generate random numbers in C++    *
 *    srand, rand    the traditional library functions for random number genration       *
 *                                                                                       *
 * to compile and run:                                                                   *
 *  1. compile complete implementation for Person class (perhaps called Person.cpp)      *
 *        omitting main in compilation                                                   *
 *      g++ -c -o Person Person.cpp                                                      *
 *  2.  compile and link this program, sortAlgsForPerson.cpp                             *
 *      g++ -o sortAlgsForPersons sortAlgsForPersons.cpp Person.o                        *
 *                                                                                       *
 *****************************************************************************************/

#include <stdio.h>  // for formatted output printf

// C++ libraries for output

// no need to include <stdlib.h> library for creating arrays dynamically in C++;
//     part of std in C++
#include <stdlib.h>   // for malloc, free; also for srand, rand

// libraries needed with srand/rand
#include <ctime>     // for time  (this is the C++ library corresponding to <time.h> in C
#include <limits.h>   // for INT_MAX, the largest value of type int

// library needed for C++ random_device
#include <random>     // for random_device random number generator

// header file for Person class of objects
#include "Person.hpp"

// files with strings for creating Person fields
#include <string.h>

#include "first-names.h"    // 2000 first names, common in the United States
#include "surnames.h"       // 1000 surnames, common in the United States
#include "states.h"         // names of 57 U. S. states and territories

/*****************************************************************************************
 *                                 Global Constantsnn                                    *
 *****************************************************************************************/
//size variables

// range of simulations
const int minDataSetSize = 40;
const int maxDataSetSize = 640;
//int maxDataSetSize = 40960000;
//int maxDataSetSize = 81920000;
//int maxDataSetSize = 327680000;

// expression for incrementing size variable in simulation outer loop
#define sizeIncrement  size *= 2

// number of iterations for simulation/timing of each sorting size
const int numSimIterations = 1500;

/** *******************************************************************************
 * structure to identify both the name of a sorting algorithm and                 *
 * a pointer to the function that performs the sort                               *
 * the main function utilizes this struct to define an array of                   *
 * the sorting algorithms to be timed by this program.                            *
 *********************************************************************************/

typedef struct sorts {
  const char * name;
  void (*sortProc) (std::vector<Person *> &,
                    bool comesBefore (Person, Person),
                    bool equals (Person, Person) );
} sorts;


/*****************************************************************************************
 *                                 Sorting Procedures                                    *
 *****************************************************************************************/

/** **************************************************************************************
 * @remark one version of the common insertion sort algorithm,                           *
 *     adjusted for arrays of objects                                                    *
 *                                                                                       *
 * @param  vec            vector to be sorted, containing Person objects                 *
 * @param  comesBefore    comparison operator to determine when first object < second    *
 * @param  equals         comparison operator to determine when 2 objects are ==         *
 *                                                                                       *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *         with ordering based on the comesBefore, equals operators                      *
 *                                                                                       *
  *****************************************************************************************/

void insertionSort (std::vector<Person *> & vec ,
                    bool comesBefore (Person, Person),
                    bool equals (Person, Person)
                    ) {
  for (int k = 1; k < vec.size ( ) ; k++) {
     Person *item = vec.at(k);
      int i = k-1;
      while ((i >= 0) && !(comesBefore(*(vec.at(i)), *item))){
        vec.at(i+1) = vec.at(i);
         i--;
      }
      vec.at(i+1) = item;
   }
}

/**
 * @param vec             vector for the max element to be placed last
 * @param smallIndex      the index of the smallest value found in vec
 * @param int i           The index where the max element (from smallIndex) should be placed after shifting other elements.
 *
 * @post                  max element placed at the end of vec at i
 *
*/
void insertMaxToLast(std::vector<Person *> & vec, int smallIndex, int i) {
  Person *temp = vec[smallIndex];
  for (int j = smallIndex; j < i; j++) {
    vec[j] = vec[j+1];
  }
  vec[i] = temp;
}


/** **************************************************************************************
 * @remark one version of a sorting algorithm (to be determined) for an array of objects *
 *                                                                                       *
 * @param  vec            vector to be sorted, containing Person objects                 *
 * @param  comesBefore    comparison operator to determine when first object < second    *
 * @param  equals         comparison operator to determine when 2 objects are ==         *
 *                                                                                       *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *         with ordering based on the comesBefore, equals operators                      *
 *                                                                                       *
  *****************************************************************************************/
void sortAlgA ( std::vector<Person *> & vec,
                bool (comesBefore (Person, Person)),
                bool (equals (Person, Person))
              ) {
  int i, j, smallIndex;
  Person* temp;
  // put largest remaining element in a[i]
  for (i = vec.size()-1; i >= 0; i--) {
    // find largest in a[i..n-1]
    smallIndex = i;
    for (j = i-1; j >= 0; j--) {
      if (comesBefore(*vec[smallIndex], *vec[j]))
        smallIndex = j;
    }
    // insert max element into last position by sliding other elements down
    insertMaxToLast(vec, smallIndex, i);
  }
}




/**
 * @remark          helper function for recursive version of sortAlgBHelper
 *
 * @param  vec            vector to be sorted, containing Person objects                 *
 * @param  comesBefore    comparison operator to determine when one object < another     *
 * @param  equals         comparison operator to determine when 2 objects are ==         *
 * @param   i             index that represents where the largest element must be placed *
 *
 * @post                  if there are no more elements to consider, return. otherwise.
 *                        keep sorting recursively
 **/
void sortAlgBHelper(std::vector<Person *> &vec,
                    bool (comesBefore)(Person, Person),
                    bool (equals)(Person, Person),
                    int i) {
  if (i < 0) {
    return; // Base case: done
  }

  int smallIndex = i;
  for (int j = i - 1; j >= 0; j--) {
    if (comesBefore(*vec[smallIndex], *vec[j])) {
      smallIndex = j;
    }
  }

  Person* temp = vec[smallIndex];
  for (int j = smallIndex; j < i; j++) {
    vec[j] = vec[j + 1];
  }
  vec[i] = temp;

  // Recursive call on next smaller i
  sortAlgBHelper(vec, comesBefore, equals, i - 1);
}

/** **************************************************************************************
 * @remark alternative recursive version of a sorting algorithm sortAlgA using           *
 *                                                                                       *
 * @param  vec            vector to be sorted, containing Person objects                 *
 * @param  comesBefore    comparison operator to determine when one object < another     *
 * @param  equals         comparison operator to determine when 2 objects are ==         *
 *                                                                                       *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *         with ordering based on the comesBefore, equals operators                      *
 *                                                                                       *
  *****************************************************************************************/
// Husk
void sortAlgB(std::vector<Person *> &vec,
              bool (comesBefore)(Person, Person),
              bool (equals)(Person, Person)) {
  sortAlgBHelper(vec, comesBefore, equals, static_cast<int>(vec.size()) - 1);
}


/** **************************************************************************************
 * @remark sorting sub to help approximate time for sorting simulation overhead          *
 *                                                                                       *
 * @param  vec            vector to be sorted, containing Person objects                 *
 * @param  comesBefore    comparison operator to determine when one object < another     *
 * @param  equals         comparison operator to determine when 2 objects are ==         *
 *                                                                                       *
 * @post  the first n elements of a are sorted in non-descending order                   *
 *         with ordering based on the comesBefore, equals operators                      *
 *                                                                                       *
  *****************************************************************************************/

void sortStub ( std::vector<Person *> & vec ,
                bool comesBefore (Person, Person),
                bool equals (Person, Person)
              ) {
  // trivial procedure body to simulate basic procedure call
  int i;
  i = 5;
}

/* * * * * * * * * * * * procedure to check sorting correctness  * * * * * * * * * */

/** *******************************************************************************
 * check all array elements are in non-descending order                           *
 * @param  vec  the vector to be sorted                                           *
 * returns  "ok" if array elements in non-descending order; "NO" otherwise        *
 *********************************************************************************/

const char * checkAscending (std::vector<Person *> vec,
                       bool comesBefore (Person, Person),
                       bool equals (Person, Person)
                      ) {
  for (int i = 0; i < vec.size () - 1; i++) {
    if (comesBefore ((*(vec.at(i+1))), (*(vec.at(i))))) {
      return "NO";
    }
  }
  return "OK";
}

/* * * * * * * * * * * Procedure  to oversee testing with timing * * * * * * * * */

/** *******************************************************************************
 * procedure to conduct simulation test of procedure and time overall work        *
 * @param sortProc      sorting procedure to be tested and timed                  *
 * @param                vec  the vector to be sorted                             *
 * @param  comesBefore  boolean function returning when 1 Persome < another       *
 * @param  equals       boolean function returning when 1 Persome == another      *
 * returns  time in secords for the simulation                                    *
 *                                                                                *
*********************************************************************************/

double  conductSimulation (std::vector<Person *> vec,
                           void (*sortProc) ( std::vector<Person *> &,
                                              bool comesBefore (Person, Person),
                                              bool equals (Person, Person)
                                            ),
                           bool comesBefore (Person, Person),
                           bool equals (Person, Person),
                           bool *sortCorrect
                      ) {
  // declare new vector to be copied during simulation and testing
  std::vector<Person *> tempRan  = std::vector<Person *> (vec.size ( ) ) ;

  // timing variables
  clock_t start_time, end_time;
  start_time = clock ();

  for (int iteration = 0; iteration < numSimIterations; iteration++) {
    // declear and initialize copy of vector to be sorted
    // copy to test arrays

    for (int i = 0; i< vec.size ( ); i++) {
      tempRan[i] = vec[i];
    }

    // sort vector with prescribed sorting algorithm
    sortProc (tempRan, comesBefore, equals);

  }
  end_time = clock();
  double elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;

  *sortCorrect = (strcmp ("OK", checkAscending (tempRan, comesBefore, equals)) == 0);

  return elapsed_time ;
}

/** *******************************************************************************
 * driver program for testing and timing sorting algorithms                       *
 **********************************************************************************/

int main ( ) {

  const int numAlgs = 3;

  sorts sortProcs [numAlgs] = {{"Insertion Sort       ", insertionSort },
                               {"Assigned Sort Alg    ", sortAlgA      },
                               {"Assigned Alt. Alg    ", sortAlgB      }
                              };
  // initially all algorithms active for ascending, random, and descendind data
  int numSort;

  // randomize random number generator's seed
  // rand, the traditional C random number generator, can work fine, but has limitations

  srand (time ((time_t *) 0) );          // intialize C's traditional random number gener


  // random_device, in the C++ 11 library, allows more control of number distributions
  // see https://stackoverflow.com/questions/18726102/what-difference-between-rand-and-random-functions
  //  for details and an example
  std::random_device rd;
  std::mt19937 e2(rd());
  std::uniform_int_distribution<> distState(0, 56);         // range for indices [0, 56] element arrays
  std::uniform_int_distribution<> dist1000(0, 1000);        // range for indices of 1000 element arrays

  // to accommodate 10-digit numbers need to declare a long random number generator
  std::uniform_int_distribution<long> dist10digit((long)1000000000, (long)9999999999); // range for 10-digit long integer

  // print headings
  printf ("                        Data Set                            Sort by\n");
  printf ("Algorithm                 Size            Name             Location            Phone\n ");


  int size;
  for (size = minDataSetSize; size <= maxDataSetSize; sizeIncrement) {
    //std::vector<Person> randomVec = std::vector<Person> (size) ;
    std::vector<Person *> randomVec ;
    int i;
    for (i = 0; i< size; i++) {
      // create and initialize control data array of random Person elements
      char city [20];
      snprintf (city, 20, "city-%d", dist1000(e2));  // generate number in [0, 1000], place in city label
      randomVec.push_back (new Person ( firstNames [rand ( ) % 2000],        //  use arrays included for random data
                                        surnames [rand ( ) % 1000],          //     with rand random number generator
                                        city,
                                        statesTerritories [distState(e2)],   // generator for [0, 56] states/territories
                                        dist10digit(e2)                      // get 10 non-zero digits
                                       )
                           );
      // std::cout << "main program:  "<< i << ": "  << *(randomVec.at(i)) << std::endl;
    }

     // timing variables
    double  base_elapsed_time, elapsed_time;

      // break output for this array sze
     printf ("\n");


     /* loop to test successive sorting procedures */
     /* iterate through sorting algorithms */
     for (numSort = 0; numSort < numAlgs; numSort++) {
       // determine if result of sort algorithm yielded elements in non-decreasing order
       bool sortCorrect;

       // record algorithm and vector size
       printf ("%4s %9d", sortProcs[numSort].name, size);

       // determine approximate time of overhead (e.g., vector initialization, sort alg call)
       double base_elapsed_time = conductSimulation (randomVec,
                                                     sortStub,
                                                     Person::comesBeforeName,
                                                     Person::equalName,
                                                     &sortCorrect
                                                     );

       /****************************** sorting by name  ******************************/


       // time overall simulation of sorting algorithm
       elapsed_time = conductSimulation (randomVec,
                                         sortProcs[numSort].sortProc,
                                         Person::comesBeforeName,
                                         Person::equalName,
                                         &sortCorrect
                                        );

       // remove time of overhead from overall simulation
       if (elapsed_time < base_elapsed_time) {
         elapsed_time = 0;
       } else {
         elapsed_time -= base_elapsed_time;
       }
       printf ("%15.1lf", elapsed_time);

       // print check of correctness
       if (sortCorrect) {
         printf (" OK");
           } else {
         printf (" NO");
       }

       // for (i = 0; i< size; i++) {
       //  std::cout << "name sort:  "<< i << ": "  << *(tempRan.at(i)) << std::endl;
       //}

       /**************************** sorting bylocation  ****************************/

       // time overall simulation of sorting algorithm
       elapsed_time = conductSimulation (randomVec,
                                         sortProcs[numSort].sortProc,
                                         Person::comesBeforeLocation,
                                         Person::equalLocation,
                                         &sortCorrect
                                        );

       // remove time of overhead from overall simulation
       if (elapsed_time < base_elapsed_time) {
         elapsed_time = 0;
       } else {
         elapsed_time -= base_elapsed_time;
       }
       printf ("%15.1lf", elapsed_time);

       // print check of correctness
       if (sortCorrect) {
         printf (" OK");
           } else {
         printf (" NO");
       }

       // for (i = 0; i< size; i++) {
       //  std::cout << "location sort:  "<< i << ": "  << *(tempRan.at(i)) << std::endl;
       //}

       /**************************** sorting by telephone  ****************************/

       // time overall simulation of sorting algorithm
       elapsed_time = conductSimulation (randomVec,
                                         sortProcs[numSort].sortProc,
                                         Person::comesBeforeLocation,
                                         Person::equalLocation,
                                         &sortCorrect
                                        );

       // remove time of overhead from overall simulation
       if (elapsed_time < base_elapsed_time) {
         elapsed_time = 0;
       } else {
         elapsed_time -= base_elapsed_time;
       }
       printf ("%15.1lf", elapsed_time);

       // print check of correctness
       if (sortCorrect) {
         printf (" OK");
           } else {
         printf (" NO");
       }

       //for (i = 0; i< size; i++) {
       //  std::cout << "phone sort:  "<< i << ": "  << *(tempRan.at(i)) << std::endl;
       //}

       printf ("\n");
     } // end of test for specific algorithm

     printf ("\n---------------------------------------------------------------------------------------\n");

     // free objects in  ran vector
     for (int i= 0; i < size; i++) {
       delete randomVec.at(i);
     }

  } // end of loop for testing procedures with different array sizes

    return 0;
}
