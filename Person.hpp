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
 * @remark: files include header (Person.h) and Implementation (Person.cpp) *
 *                                                                          *
 * @remark  Uncomment main program in implementation file for unit testing  *
 *                                                                          *
 * @author Henry M. Walker                                                  *
 * @date September 12, 2024                                                 *
 *                                                                          *
 ****************************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {

public:
  // constructors
/** *************************************************************************
 * @remark Default constructor (with no parameters)                         *
 *                                                                          *
 *  all fields set to empty string or 0                                     *
 *                                                                          *
 ****************************************************************************/

  Person ( ) ;

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
  Person (const char * first, const char * last,
          const char * cityNme, const char * stateTerritory, long int telephone) ;

  // deconstructors
/** *************************************************************************
 * @remark standard deconstructor (with no parameters)                      *
 ****************************************************************************/

  ~Person ( ) ;


/** *************************************************************************
 *  Standard Getters                                                        *
 *     (but no setters, as not needed in Project simulations)               *
 *                                                                          *
 ****************************************************************************/

  std::string getFirstName ( );
  std::string getSurame ( );
  std::string getCity ( );
  std::string getStateTerritory ( );
  long getTelephone ( ) ;

/** *************************************************************************
 *  equals methods                                                          *
 *     for equalFirstName, equalSurname (same string fields                 *
 *     for name comparisos     (same first name and surname)                *
 *     for equalcity, equalStateTerritory (same string fields               *
 *     for location comparison (same city and state/territory)              *
 *     for telephone number comparisons (same phone number)                 *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true if associated strings or long for first matches second,   *
 *       and false otherwise                                                *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************
 *  @remark although likely not relevant in uses of this class,             *
 *      private method fields stored as strings or long integers            *
 *                                                                          *
 ****************************************************************************/

  bool static equalFirstName (const Person first, const Person second);
  bool static equalSurname (const Person first, const Person second);
  bool static equalName (const Person first, const Person second);
  bool static equalCity (const Person first, const Person second);
  bool static equalStateTerritory (const Person first, const Person second);
  bool static equalLocation (const Person first, const Person second);
  bool static equalTelephone (const Person first, const Person second);

/** *************************************************************************
 *  @remark determines if first name of the first object preceeds           *
 *     corresponding string in second object in lexiographic order          *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true                                                           *
 *       if first firstName comes before firstName of second object         *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeFirstName (Person first, Person second);

/** *************************************************************************
 *  @remark determines if surname of first object preceeds                  *
 *     corresponding string in second object in lexiographic order          *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true                                                           *
 *       if first surname comes before surname of second object             *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeSurname (Person first, Person second);

/** *************************************************************************
 *  @remark determines if surname, then first name of the first object      *
 *     preceeds corresponding string in second object in lexiographic order *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true                                                           *
 *       if first surname comes before surname of second or                 *
 *          if surnames match and first firstName precedes that of second   *
 *   and returns false otherwise                                            *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeName (Person first, Person second);

/** *************************************************************************
 *  @remark determines if city of the first object preceeds                 *
 *     corresponding string within second object in lexiographic order      *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true                                                           *
 *      if first city comes before that of second                           *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeCity (Person first, Person second);

/** *************************************************************************
 *  @remark determines if stateTerritory of the first object preceeds       *
 *     corresponding string within second object in lexiographic order      *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true                                                           *
 *      if first stateTerritory comes before that of second                 *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeStateTerritory (Person first, Person second);

/** *************************************************************************
 *  @remark determines if stateTerritory, then first city of this object    *
 *     preceeds corresponding data in second object in lexiographic order   *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true                                                           *
 *       if first stateTerritory comes before stateTerritory of second or   *
 *          if stateTerritory match and *this city precedes that of second  *
 *   and returns false otherwise                                            *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeLocation (Person first, Person second);

/** *************************************************************************
 *  @remark determines if telephone number of the first object              *
 *    is less than the telephone number of the second object                *
 *                                                                          *
 *  @param first   the first Person in the comparison                       *
 *  @param second  the second Person in the comparison                      *
 *                                                                          *
 * @post  neither the first or second objects are changed during execution  *
 *                                                                          *
 *  @returns true                                                           *
 *       if first telephone number less than telephone number of second     *
 *    and returns false otherwise                                           *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeTelephone (Person first, Person second);

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

  friend std::ostream& operator<< (std::ostream &os, const Person &pers) ;

  public:
    std::string firstName;        // a Person's first name
    std::string surname;          // a Person's surname (or last name)
    std::string city;             // city location where Person lives
    std::string stateTerritory;   // state or territory where Person lives
    long phone;                   // a Person's telephone number (no dashes)
  };

#endif