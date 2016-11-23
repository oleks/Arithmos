/**
 ** @file     TmpCMpIeee.hh
 ** @brief    Temporary class for CMpIeee
 **
 ** $Id: TmpCMpIeee.hh,v 1.3 2001/04/13 09:24:38 backelj Exp $
 ** $Date: 2001/04/13 09:24:38 $
 ** $Author: backelj $
 **/

#ifndef _ARITHMOS_TMPCMPIEEE_H_
#define _ARITHMOS_TMPCMPIEEE_H_

#include <CMpIeee.hh>

/**
 ** @brief    The TmpCMpIeee class
 **/
 
class TmpCMpIeee : public CMpIeee
{  
public:
  
  /**
   ** @name    Constructors
   **/
  /*@{*/
  TmpCMpIeee ();

  TmpCMpIeee ( unsigned int prec, unsigned int expSize );
  TmpCMpIeee ( unsigned int prec, int l, int u );
  /*@}*/

  /**
   ** @name    Copy constructors
   **/
  /*@{*/
  TmpCMpIeee ( const TmpCMpIeee& t ); // assumption initializer
  TmpCMpIeee ( const CMpIeee& y ); // verbatim copy
  /*@}*/

  // destructor
  ~TmpCMpIeee() {}
  
  /**
   ** @name    Assignment operators
   **/
  /*@{*/
  void operator = ( const TmpCMpIeee& t ); // copy-by-assumption
  void operator = ( const CMpIeee& y ); // verbatim assignment
  /*@}*/
  
}; // TmpCMpIeee

#endif /* _ARITHMOS_TMPCMPIEEE_H_ */
