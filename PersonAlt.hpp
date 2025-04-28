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
 * @date September 29, 2024                                                 *
 *                                                                          *
 ****************************************************************************
 *  @remark although likely not relevant in uses of this class,             *
 *      private method fields stored as const char * or long integers       *
 *                                                                          *
 ****************************************************************************/

#ifndef PERSONALT_H
#define PERSONALT_H

#include <iostream>

class PersonAlt {

public:
  // constructors
/** *************************************************************************
 * @remark Default constructor (with no parameters)                         *
 *                                                                          *
 *  all fields set to empty string or 0                                     *
 *                                                                          *
 ****************************************************************************/

  PersonAlt ( ) ;

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
  PersonAlt (const char * first, const char * last,
          const char * cityNme, const char * stateTerritory, long int telephone) ;

  // deconstructors
/** *************************************************************************
 * @remark standard deconstructor (with no parameters)                      *
 ****************************************************************************/

  ~PersonAlt ( ) ;


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
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true if associated strings or long for first matches second,   *
 *       and false otherwise                                                *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static equalFirstName (PersonAlt first, PersonAlt second);
  bool static equalSurname (PersonAlt first, PersonAlt second);
  bool static equalName (PersonAlt first, PersonAlt second);
  bool static equalCity (PersonAlt first, PersonAlt second);
  bool static equalStateTerritory (PersonAlt first, PersonAlt second);
  bool static equalLocation (PersonAlt first, PersonAlt second);
  bool static equalTelephone (PersonAlt first, PersonAlt second);

/** *************************************************************************
 *  @remark determines if first name of the first object preceeds           *
 *     corresponding string in second object in lexiographic order          *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true                                                           *
 *       if first firstName comes before firstName of second object         *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeFirstName (PersonAlt first, PersonAlt second);

/** *************************************************************************
 *  @remark determines if surname of first object preceeds                  *
 *     corresponding string in second object in lexiographic order          *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true                                                           *
 *       if first surname comes before surname of second object             *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeSurname (PersonAlt first, PersonAlt second);

/** *************************************************************************
 *  @remark determines if surname, then first name of the first object      *
 *     preceeds corresponding string in second object in lexiographic order *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true                                                           *
 *       if first surname comes before surname of second or                 *
 *          if surnames match and first firstName precedes that of second   *
 *   and returns false otherwise                                            *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeName (PersonAlt first, PersonAlt second);

/** *************************************************************************
 *  @remark determines if city of the first object preceeds                 *
 *     corresponding string within second object in lexiographic order      *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true                                                           *
 *      if first city comes before that of second                           *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeCity (PersonAlt first, PersonAlt second);

/** *************************************************************************
 *  @remark determines if stateTerritory of the first object preceeds       *
 *     corresponding string within second object in lexiographic order      *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true                                                           *
 *      if first stateTerritory comes before that of second                 *
 *    and returns false otherwise                                           *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeStateTerritory (PersonAlt first, PersonAlt second);

/** *************************************************************************
 *  @remark determines if stateTerritory, then first city of this object    *
 *     preceeds corresponding data in second object in lexiographic order   *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true                                                           *
 *       if first stateTerritory comes before stateTerritory of second or   *
 *          if stateTerritory match and *this city precedes that of second  *
 *   and returns false otherwise                                            *
 *                                                                          *
 *  @remark  the comparison of strings is case sensitive                    *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeLocation (PersonAlt first, PersonAlt second);

/** *************************************************************************
 *  @remark determines if telephone number of the first object              *
 *    is less than the telephone number of the second object                *
 *                                                                          *
 *  @param first   the first PersonAlt in the comparison                       *
 *  @param second  the second PersonAlt in the comparison                      *
 *                                                                          *
 *  @returns true                                                           *
 *       if first telephone number less than telephone number of second     *
 *    and returns false otherwise                                           *
 *                                                                          *
 ****************************************************************************/

  bool static comesBeforeTelephone (PersonAlt first, PersonAlt second);

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

  friend std::ostream& operator<< (std::ostream &os, const PersonAlt &pers) ;

  public:
    const char * firstName;        // a PersonAlt's first name
    const char * surname;          // a PersonAlt's surname (or last name)
    const char * city;             // city location where PersonAlt lives
    const char * stateTerritory;   // state or territory where PersonAlt lives
    long phone;                    // a PersonAlt's telephone number (no dashes)
  };

#endif