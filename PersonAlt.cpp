/** *************************************************************************
 * @remark  Person:  an underlying class for entries                        *
 *   within several simulations for a CS SSU  Signature Project             *
 *                                                                          *
 * @remark  Person Class fields include:                                    *
 *    pointers to a Person's first name and surname (as strings)            *
 *    pointers to a Person's city and U.S. state or territory (as strings)  *
 *    a Person's telephone number (as a long integer)                       *
 *                                                                          *
 * @ remark  Person Class capabilities include:                             *
 *    Constructors                                                          *
 *    Getters (but no setters, as not needed in Project simulations)        *
 *    Comparison operations, based on surnames names, then first names      *
 *    Comparison operations, based on states/territories, then cities       *
 *    Comparison operations, based on telephone numbers                     *
 *    Overloaded << operator for formatted output                           *
 *                                                                          *
 * @remark: files include header (Person.hpp) and Implementation (Person.cpp) *
 *                                                                          *
 * @remark  Uncomment main program in implementation file for unit testing  *
 *                                                                          *
 * @author Henry M. Walker                                                  *
 * @date September 12, 2024                                                 *
 *                                                                          *
 * compile using                                                            *
 * for testing:  g++ -DTEST -o PersonAlt PersonAlt.cpp                      *
 * to link for applicaitons: g++ -c PersonAlt.cpp                           *
 *                                                                          *
****************************************************************************/

#include "PersonAlt.hpp"
#include <cstring>
#include <stdio.h>    //with C++2023 standard, could use <cstdio> with std::print below

// constructors
/** *************************************************************************
 * @remark Default constructor (with no parameters)                         *
 *                                                                          *
 *  all fields set to empty string or 0                                     *
 *                                                                          *
 ****************************************************************************/
PersonAlt::PersonAlt ( ) {
  firstName      = "";
  surname        = "";
  city           = "";
  stateTerritory = "";
  phone          = 0;
};

/** *************************************************************************
 * @remark Full-parameter constructor                                       *
 *                                                                          *
 * @param first    a person's first name                                    *
 * @param last     a person's last name                                     *
 * @param cityName                                                          *
 * @param stateOrTerritory                                                  *
 * @param telephoneNumber                                                   *
 *                                                                          *
 ****************************************************************************/
PersonAlt::PersonAlt (const char * first, const char * last,
                const char * cityName, const char * stateOrTerritory, long telephoneNumber) {
  firstName = first;
  surname = last;
  city = cityName;
  stateTerritory = stateOrTerritory;
  phone     = telephoneNumber;

  // std::cout << "constructor:  " <<  *this << std::endl;

};

// deconstructors
/** *************************************************************************
 * @remark standard deconstructor (with no parameters)                      *
 ****************************************************************************/
PersonAlt::~PersonAlt () {
  // as all string variables reference external strings, no work needed here
};


/** *************************************************************************
 *  Standard Getters                                                        *
 *     (but no setters, as not needed in Project simulations)               *
 *                                                                          *
 ****************************************************************************/

std::string PersonAlt::getFirstName ( ) {
  return firstName;
};

std::string PersonAlt::getSurame ( ){
  return surname;
};

std::string PersonAlt::getCity ( ){
  return city;
};

std::string PersonAlt::getStateTerritory ( ){
  return stateTerritory;
};

long PersonAlt::getTelephone ( ) {
  return phone;
};

/** *************************************************************************
 *  equals methods                                                          *
 *     for equalFirstName, equalSurname (same string fields                 *
 *     for name comparisos     (same first name and surname)                *
 *     for equalcity, equalStateTerritory (same string fields               *
 *     for location comparison (same city and state/territory)              *
 *     for telephone number comparisons (same phone number)                 *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true if associated strings or long for first matches second,   *x(x)xs
 *       and false otherwise                                                *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

bool PersonAlt::equalFirstName (const PersonAlt first, const PersonAlt second) {
  if (strcmp(first.firstName, second.firstName) == 0) {
    return true;
  }
  return false;
};

bool PersonAlt::equalSurname (const PersonAlt first, const PersonAlt second) {
  if (strcmp(first.surname, second.surname) == 0) {
    return true;
  }
  return false;
};

bool PersonAlt::equalName (const PersonAlt first, const PersonAlt second) {
  return (strcmp (first.firstName, second.firstName) == 0)
    && (strcmp (first.surname, second.surname) == 0);
};

bool PersonAlt::equalCity (const PersonAlt first, const PersonAlt second) {
  if (strcmp (first.city, second.city) == 0) {
    return true;
  }
  return false;
};
bool PersonAlt::equalStateTerritory (const PersonAlt first, const PersonAlt second) {
  if (strcmp (first.stateTerritory, second.stateTerritory) == 0) {
    return true;
  }
  return false;
};

bool PersonAlt::equalLocation (const PersonAlt first, const PersonAlt second) {
  if ((strcmp(first.city, second.city) == 0) && (strcmp(first.stateTerritory, second.stateTerritory) == 0)) {
    return true;
  }
  return false;
};

bool PersonAlt::equalTelephone (const PersonAlt first, const PersonAlt second){
  if (first.phone == second.phone) {
    return true;
  }
  return false;
};

/** *************************************************************************
 *  @remark determines if first name of the first object preceeds           *
 *     corresponding string in second object in lexiographic order          *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true                                                           *
 *       if first firstName comes before firstName of second object         *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

bool PersonAlt::comesBeforeFirstName (const PersonAlt first, const PersonAlt second) {
  if (strcmp(first.firstName, second.firstName) < 0) {
    return true;
  }
  return false;
};

/** *************************************************************************
 *  @remark determines if surname of first object preceeds                  *
 *     corresponding string in second object in lexiographic order          *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true                                                           *
 *       if first surname comes before surname of second object             *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

bool PersonAlt::comesBeforeSurname (const PersonAlt first, const PersonAlt second) {
   if (strcmp(first.surname, second.surname) < 0) {
    return true;
  }
  return false;
};

/** *************************************************************************
 *  @remark determines if surname, then first name of the first object      *
 *     preceeds corresponding string in second object in lexiographic order *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true                                                           *
 *       if first surname comes before surname of second or                 *
 *          if surnames match and first firstName precedes that of second   *
 *   and returns false otherwise                                            *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/


bool PersonAlt::comesBeforeName (const PersonAlt first, const PersonAlt second) {
  if (strcmp(first.surname, second.surname) < 0) {
    return true;
  } else if (strcmp(first.surname, second.surname) == 0 && strcmp(first.firstName, second.firstName) < 0) {
    return true;
  } else {
    return false;
  }
};

/** *************************************************************************
 *  @remark determines if city of the first object preceeds                 *
 *     corresponding string within second object in lexiographic order      *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true                                                           *
 *      if first city comes before that of second                           *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/


bool comesBeforeCity (const PersonAlt first, const PersonAlt second){
  if (strcmp(first.city, second.city) == 0) {
    return true;
  }
  return false;
};

/** *************************************************************************
 *  @remark determines if stateTerritory of the first object preceeds       *
 *     corresponding string within second object in lexiographic order      *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true                                                           *
 *      if first stateTerritory comes before that of second                 *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

bool comesBeforeStateTerritory (const PersonAlt first, const PersonAlt second){
  if (strcmp(first.stateTerritory, second.stateTerritory) == 0) {
    return true;
  }
  return false;
};

/** *************************************************************************
 *  @remark determines if stateTerritory, then first city of this object    *
 *     preceeds corresponding data in second object in lexiographic order   *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true                                                           *
 *       if first stateTerritory comes before stateTerritory of second or   *
 *          if stateTerritory match and *this city precedes that of second  *
 *   and returns false otherwise                                            *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

bool PersonAlt:: comesBeforeLocation (const PersonAlt first, const PersonAlt second) {
  if (strcmp(first.stateTerritory, second.stateTerritory) < 0) {
    return true;
  } else if ((strcmp(first.stateTerritory, second.stateTerritory) == 0) && (strcmp(first.city, second.city) < 0)) {
    return true;
  } else {
    return false;
  }
};

/** *************************************************************************
 *  @remark determines if telephone number of the first object              *
 *    is less than the telephone number of the second object                *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                    *
 *  @param second  the second PersonAlt in the comparison                   *
 *                                                                          *
 *  @returns true                                                           *
 *       if first telephone number less than telephone number of second     *
 *    and returns false otherwise                                           *
 *                                                                          *
 ****************************************************************************/

bool PersonAlt::comesBeforeTelephone (const PersonAlt first, const PersonAlt second) {
  return first.phone < second.phone;
};

/** *************************************************************************
 *  Formatted string with labeled field data                                *
 *       achieved by overloading the << operator                            *
 *       and creating a toString method                                     *
 *                                                                          *
 *  @param os  output stream which will receive the formatted Entry data    *
 *                                                                          *
 *  @returns formatted string on the given output stream                    *
 *                                                                          *
 *  @remark use of a toString function with a string return type            *
 *          could require allocating space for a long string,               *
 *          yielding a potential memory leak                                *
 *                                                                          *
 *  @remark  overloaded operator<< requires access to private data fields   *
 *                                                                          *
 ****************************************************************************/

std::ostream& operator<< (std::ostream &os, const PersonAlt &pers) {
  return (os << "Name: " << pers.firstName << " " << pers.surname << std::endl
          << "Location: " << pers.city << ", " << pers.stateTerritory << std::endl
          << "Telephone number: " << pers.phone  << std::endl);
};

/** *************************************************************************
 * output formatting procedure to draw line across output                   *
 *  @param label      title (<= 22 characgers expected) printed in center   *
 &  @param lineToken  2 character string to be repeated to make up line     *
****************************************************************************/

void drawAndLabelLine (std::string lineToken, std::string label) {
  int i;
  printf ("\n");
  for (i = 0; i < 15; i++)
    std::cout << lineToken;
  std::cout << " " << label << " ";
  for (i = 0; i < 15; i++)
    std::cout << lineToken;
  std::cout << std::endl << std::endl;
}

/** *************************************************************************
 ****************************************************************************
 *                                                                          *
 * Use -DTEST flag in compilation for testing                               *
 * Omit this flag to use this implemention within another application       *
 *                                                                          *
 ****************************************************************************
 ****************************************************************************/

/** *************************************************************************
 * basic testing of PersonAlt methods                                       *
 *       constructor                                                        *
 *       output: overloaded << operator                                     *
 *       comparison methods                                                 *
 *                                                                          *
 * altogether, 8 objects (obj1, obj2, ... , obj8) will be created           *
 *                                                                          *
 *   after creation, objects are printed to check output overloading        *
 *                                                                          *
 *   testing organized into groups for names, for locations, and for phones *
 *      for each cell in the table,                                         *
 *          the first line shows name comparisons                           *
 *          the second line shows location comparisons                      *
 *          the third line shows phone comparisons                          *
 *                                                                          *
 *  tests for ordering of names must consider                               *
 *     identidal ffrst naes and surname                                     *
 *     identical surnames, but both smaller and larger first names          *
 &     identical first names, but larger and smaller surnames               *
 *                                                                          *
 *  similar sections test ordering for locations and phones                 *
 *                                                                          *
 ****************************************************************************/

int main ( ) {

  /* initialize objects, in accordance with the above comments */\
  const int numObjs = 8;
  PersonAlt pers [numObjs] = {
    PersonAlt ("first-3", "surname-3", "city-1", "New Jersey", 55555),
    PersonAlt ("first-3", "surname-3", "city-5", "New Jersey", 11111),
    PersonAlt ("first-1", "surname-3", "city-1", "New Mexico", 55555),
    PersonAlt ("first-5", "surname-3", "city-3", "New Mexico", 99999),
    PersonAlt ("first-1", "surname-2", "city-3", "New Mexico", 11111),
    PersonAlt ("first-1", "surname-4", "city-5", "New Mexico", 55555),
    PersonAlt ("first-5", "surname-2", "city-1", "New York"  , 99999),
    PersonAlt ("first-5", "surname-4", "city-5", "New York"  , 55555)
  };

  std::cout << "Program to test methods of PersonAlt Class" << std::endl;

  drawAndLabelLine ("--", "Initialized Objects");

  // printing objects
  std::cout << "printing fields for each PersonAlt object:"   << std::endl << std::endl;
  int i, j;
  for (i = 0; i < numObjs; i++) {
    std::cout << "Object " << i << ":" << std::endl << pers[i] << std::endl;

  }

  /** *************************************************************************
   * test equality methods                                                    *
   ****************************************************************************/
  drawAndLabelLine ("--", "Equality Tests");

  // record number of errors
  int numErrors = 0;
  int numNameErr = 0;
  int numLocationErr = 0;
  int numPhoneErr = 0;

  int tableEntryWidth = 4;

  /***************************************************************************/

  // first name test
  // expected results array for the various comparisons

  // first name test: 0,1 and 2,4,5 and 3,6,7  have equal first names, others just equal to themselves
  bool testResult;
  int numWrong = 0;  // count number of errors for an individual field test
  int equalFirstNameResults [numObjs][numObjs] =
    {  { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 1,  0 , 1 , 1 , 0 , 0 },
       { 0 , 0 , 0,  1 , 0 , 0 , 1 , 1 },
       { 0 , 0 , 1,  0 , 1 , 1 , 0 , 0 },
       { 0 , 0 , 1,  0 , 1 , 1 , 0 , 0 },
       { 0 , 0 , 0,  1 , 0 , 0 , 1 , 1 },
       { 0 , 0 , 0,  1 , 0 , 0 , 1 , 1 }
    } ;

  drawAndLabelLine ("% ", "Test First Name Equality");

  printf ("Testing objects for first name equality\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::equalFirstName (pers[i], pers[j]) ;
      numWrong += testResult != equalFirstNameResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", equalFirstNameResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for first name equality:  %d\n\n", numWrong) ;
  numNameErr += numWrong;
  numErrors+= numWrong;


 /***************************************************************************/

   // surname test: 0,1,2,3 and 4,6 and 5,7 have equal surnames, others just equal to themselves
  numWrong = 0;
  int equalSurnameResults [numObjs][numObjs] =
    {  { 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 1,  1 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 1,  1 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 0,  0 , 1 , 0 , 1 , 0 },
       { 0 , 0 , 0,  0 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0,  0 , 1 , 0 , 1 , 0 },
       { 0 , 0 , 0,  0 , 0 , 1 , 0 , 1 }
    } ;

  drawAndLabelLine ("% ", "Test Surname Equality");

  printf ("Testing objects for surname equality\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult= PersonAlt::equalSurname (pers[i], pers[j]) ;
      numWrong += testResult != equalSurnameResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", equalSurnameResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for surname equality:  %d\n\n", numWrong) ;
  numNameErr += numWrong;
  numErrors+= numWrong;

 /***************************************************************************/

   // name test: 0 and 1 have equal names, others just equal to themselves
  numWrong = 0;
  int equalNameResults [numObjs][numObjs] =
    {  { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 1,  0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 0,  1 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 0,  0 , 1 , 0 , 0 , 0 },
       { 0 , 0 , 0,  0 , 0 , 1 , 0 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 1 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 1 }
    } ;

  drawAndLabelLine ("% ", "Test Name Equality");

  printf ("Testing objects for name equality\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::equalName (pers[i], pers[j]) ;
      numWrong += testResult != equalNameResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", equalNameResults[i][j]) ;
    }

    printf ("\n\n");
  }

  printf ("total errors for name equality:  %d\n\n", numWrong) ;
  numNameErr += numWrong;
  numErrors+= numWrong;

  drawAndLabelLine ("- ", "Summary of Name-related Equality Tests");

  printf ("total errors for all name-related equality methods:  %d\n\n", numNameErr) ;


 /***************************************************************************/
 /***************************************************************************/

   drawAndLabelLine ("% ", "Test City Equality");

  // city test: 0,2,6 and 1,5,7 and 3,4 have equal cities, others just equal to themselves
  numWrong = 0;
  int equalCityResults [numObjs][numObjs] =
    {  { 1 , 0 , 1 , 0 , 0 , 0 , 1 , 0 },
       { 0 , 1 , 0 , 0 , 0 , 1 , 0 , 1 },
       { 1 , 0 , 1,  0 , 0 , 0 , 1 , 0 },
       { 0 , 0 , 0,  1 , 1 , 0 , 0 , 0 },
       { 0 , 0 , 0,  1 , 1 , 0 , 0 , 0 },
       { 0 , 1 , 0,  0 , 0 , 1 , 0 , 1 },
       { 1 , 0 , 1,  0 , 0 , 0 , 1 , 0 },
       { 0 , 1 , 0,  0 , 0 , 1 , 0 , 1 }
    };

  printf ("Testing objects for city equality\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::equalCity (pers[i], pers[j]) ;
      numWrong += testResult != equalCityResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", equalCityResults[i][j]) ;
    }

    printf ("\n\n");
  }

  printf ("total errors for city equality:  %d\n\n", numWrong) ;
  numLocationErr += numWrong;
  numErrors+= numWrong;

/***************************************************************************/

   drawAndLabelLine ("% ", "Test state/territory Equality");

  // state/territory test: 0,1 and 2,3,4,5 and 6,7 have equal state/territories, others just equal to themselves
  numWrong = 0;
  int equalStateTerritoryResults [numObjs][numObjs] =
    {  { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 1,  1 , 1 , 1 , 0 , 0 },
       { 0 , 0 , 1,  1 , 1 , 1 , 0 , 0 },
       { 0 , 0 , 1,  1 , 1 , 1 , 0 , 0 },
       { 0 , 0 , 1,  1 , 1 , 1 , 0 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 1 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 1 , 1 }
    };

  printf ("Testing objects for state/territory equality\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::equalStateTerritory (pers[i], pers[j]) ;
      numWrong += testResult != equalStateTerritoryResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", equalStateTerritoryResults[i][j]) ;
    }

    printf ("\n\n");
  }

  printf ("total errors for state/territory equality:  %d\n\n", numLocationErr) ;
  numLocationErr += numWrong;
  numErrors+= numWrong;

/***************************************************************************/

   drawAndLabelLine ("% ", "Test Location Equality");

  // location test: 3 and 4 have equal locations, others just equal to themselves
  numWrong = 0;
  int equalLocationResults [numObjs][numObjs] =
    {  { 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 1,  0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 0,  1 , 1 , 0 , 0 , 0 },
       { 0 , 0 , 0,  1 , 1 , 0 , 0 , 0 },
       { 0 , 0 , 0,  0 , 0 , 1 , 0 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 1 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 1 }
    };

  printf ("Testing objects for location equality\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::equalLocation (pers[i], pers[j]) ;
      numWrong += testResult != equalLocationResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", equalLocationResults[i][j]) ;
    }

    printf ("\n\n");
  }

  printf ("total errors for location equality:  %d\n\n", numWrong) ;
  numLocationErr += numWrong;
  numErrors+= numWrong;

  drawAndLabelLine ("- ", "Summary of Location-related Equality Tests");

  printf ("total errors for all location-related equality methods:  %d\n\n", numLocationErr) ;


  drawAndLabelLine ("% ", "Test Phone Equality");

 /***************************************************************************/

   // phone test: 0,2,5,5 have same phone, 1,4 same, and 3,6 same
  int equalPhoneResults [numObjs][numObjs] =
    {  { 1 , 0 , 1 , 0 , 0 , 1 , 0 , 1 },
       { 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 },
       { 1 , 0 , 1,  0 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0,  1 , 0 , 0 , 1 , 0 },
       { 0 , 1 , 0,  0 , 1 , 0 , 0 , 0 },
       { 1 , 0 , 1,  0 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0,  1 , 0 , 0 , 1 , 0 },
       { 1 , 0 , 1,  0 , 0 , 1 , 0 , 1 }
    };

  printf ("Testing objects for phone equality\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::equalTelephone (pers[i], pers[j]) ;
      numPhoneErr += testResult != equalPhoneResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", equalPhoneResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for phone equality:  %d\n\n", numPhoneErr) ;
  numErrors+= numPhoneErr;

  drawAndLabelLine ("%%", "Equality Test Conclusion");

  printf ("====>>  total errors for equality testing:  %d\n\n", numErrors) ;


  /** *************************************************************************
   * test comesBefore methods                                                 *
   ****************************************************************************/
  drawAndLabelLine ("--", "ComesBefore Tests");

 /***************************************************************************/

 // expected results array for the various comparisons

  // reset error variables
  numNameErr = 0;
  numLocationErr = 0;
  numPhoneErr = 0;


/***************************************************************************/

  // first name test:
  //            0,1 come before 3,6,7
  //            2,4,5 come before 0,1,3,6,7,

  numWrong = 0;
  int comesBeforeFirstNameResults [numObjs][numObjs] =
    {  { 0 , 0 , 0 , 1 , 0 , 0 , 1 , 1 },
       { 0 , 0 , 0 , 1 , 0 , 0 , 1 , 1 },
       { 1 , 1 , 0,  1 , 0 , 0 , 1 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 0,  1 , 0 , 0 , 1 , 1 },
       { 1 , 1 , 0,  1 , 0 , 0 , 1 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 },
    } ;

  drawAndLabelLine ("% ", "Test ComesBefore for First Name");

  printf ("Testing objects for comesBefore for first name\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::comesBeforeFirstName (pers[i], pers[j]) ;
      numWrong += testResult != comesBeforeFirstNameResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", comesBeforeFirstNameResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for comesBefore for first name:  %d\n\n", numWrong) ;
  numNameErr += numWrong;
  numErrors+= numWrong;

/***************************************************************************/

  // surname test:
  //         4,6 come before 0,1,2,3,5,7
  //         0,1,2,3 come before 5,7
  //
  numWrong = 0;
  int comesBeforeSurnameResults [numObjs][numObjs] =
    {  { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0 , 0 , 0 , 1 , 0 , 1 },
       { 1 , 1 , 1,  1 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 },
       { 1 , 1 , 1,  1 , 0 , 1 , 0 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 }
    } ;


  drawAndLabelLine ("% ", "Test ComesBefore for Surname");

  printf ("Testing objects for comesBefore for Surname\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::comesBeforeSurname (pers[i], pers[j]) ;
      numWrong += testResult != comesBeforeSurnameResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", comesBeforeSurnameResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for comesBefore for surname:  %d\n\n", numWrong) ;
  numNameErr += numWrong;
  numErrors+= numWrong;

/***************************************************************************/


  numWrong = 0;
  int comesBeforeNameResults[numObjs][numObjs] =
  {  { 0, 0, 0, 1, 0, 1, 0, 1 },
     { 0, 0, 0, 1, 0, 1, 0, 1 },
     { 1, 1, 0, 1, 0, 1, 0, 1 },
     { 0, 0, 0, 0, 0, 1, 0, 1 },
     { 1, 1, 1, 1, 0, 1, 1, 1 },
     { 0, 0, 0, 0, 0, 0, 0, 1 },
     { 1, 1, 1, 1, 0, 1, 0, 1 },
     { 0, 0, 0, 0, 0, 0, 0, 0 }
  };


   drawAndLabelLine ("% ", "Test ComesBefore for Name");

  printf ("Testing objects for comesBefore for name\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::comesBeforeName (pers[i], pers[j]) ;
      numWrong += testResult != comesBeforeNameResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", comesBeforeNameResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for comesBefore for name:  %d\n\n", numWrong) ;
  numNameErr += numWrong;
  numErrors+= numWrong;



  drawAndLabelLine ("- ", "Summary of Name-related ComesBefore Tests");

  printf ("total errors for all name-related ComesBefore methods:  %d\n\n", numNameErr) ;


/***************************************************************************/
/***************************************************************************/

  drawAndLabelLine ("% ", "Test ComesBefore for Location");

  // location test: 0,1 comesBefore 2,3,4,5,6,7 by state
  //                0 comesBefore 1 by city (same sate)
  //                2,3,4,5 comesBefore 6,7 by state
  //                2 comesBefore 3.4.5 by city (same state)
  //                3,4 comesBefore 5  by city (same state)
  //                6 comesBefore 7  by city (same state)
  int comesBeforeLocationResults [numObjs][numObjs] =
    {  { 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
       { 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 },
       { 0 , 0 , 0,  1 , 1 , 1 , 1 , 1 },
       { 0 , 0 , 0,  0 , 0 , 1 , 1 , 1 },
       { 0 , 0 , 0,  0 , 0 , 1 , 1 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 1 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 1 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 }
     };

  printf ("Testing objects for comesBefore for location\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::comesBeforeLocation (pers[i], pers[j]) ;
      numLocationErr += testResult != comesBeforeLocationResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", comesBeforeLocationResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for comesBefore for location:  %d\n\n", numLocationErr) ;
  numErrors+= numLocationErr;


  drawAndLabelLine ("% ", "Test ComesBefore for Phone");

  // phone test: 1,4 comesbefore 0,2,3,5,6,7
  //             0,2,4,6 comesbefore 3,6
  int comesBeforePhoneResults [numObjs][numObjs] =
    {  { 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 },
       { 1 , 0 , 1 , 1 , 0 , 1 , 1 , 1 },
       { 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 },
       { 1 , 0 , 1 , 1 , 0 , 1 , 1 , 1 },
       { 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 },
       { 0 , 0 , 0,  0 , 0 , 0 , 0 , 0 },
       { 0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 }
     };

  printf ("Testing objects for comesBefore for phone\n") ;

  for (i = 0; i < numObjs; i++) {
    // start new row of test
    printf ("pers[ %d ]: ", i);
    for (j = 0; j < numObjs; j++) {
      testResult = PersonAlt::comesBeforeTelephone (pers[i], pers[j]) ;
      numPhoneErr += testResult != comesBeforePhoneResults[i][j];
      printf ("%3d  ", testResult) ;
    }

    printf ("\nExpected : ");
    for (j = 0; j < numObjs; j++) {
      printf ("%3d  ", comesBeforePhoneResults[i][j]) ;
    }

    printf ("\n\n");
  }
  printf ("total errors for comesBefore for phone:  %d\n\n", numPhoneErr) ;
  numErrors+= numPhoneErr;



  drawAndLabelLine ("%%", "ComesBefore Test Conclusion");

    printf ("total errors for comesBefore testing:  %d\n\n", numNameErr + numLocationErr + numPhoneErr) ;


 drawAndLabelLine ("--", "Comparison Operator Conclusion");

  printf ("\nTotal number of errors detected for all comparison operators:  %d\n\n", numErrors);


  return 0;

}