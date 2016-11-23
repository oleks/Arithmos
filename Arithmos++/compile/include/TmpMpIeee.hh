/******************************************************************************
 **
 ** Arithmos class library
 ** 
 ** MpIeee : Multiprecision floating-point software library
 **
 ** Copyright (C) 2000
 ** Research Group Computer Arithmetic & Numerical Techniques (CANT)
 ** Department of Mathematics & Computer Science
 ** University of Antwerp
 ** Universiteitsplein 1
 ** B-2610 Wilrijk
 ** BELGIUM
 **
 ** contact : cant@uia.ua.ac.be
 **
 ******************************************************************************/


/**
 ** @file     TmpMpIeee.hh
 ** @brief    Temporary class for MpIeee
 **
 ** $Id: TmpMpIeee.hh,v 1.9 2001/08/23 13:30:39 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:39 $
 ** $Author: sbecuwe $
 **/
 
#ifndef _ARITHMOS_TMPMPIEEE_H_
#define _ARITHMOS_TMPMPIEEE_H_

#include <MpIeee.hh>

/**
 ** @brief Class used for storage of temporary multiprecision
 **        floats.
 **
 ** The TmpMpIeee class.
 **
 ** The TmpMpIeee class is used to store temporary MpIeee results.
 **/   
class TmpMpIeee: public MpIeee
{
public:
  /**
   ** @name constructors
   **/
  /*@{*/
  TmpMpIeee();
  TmpMpIeee( unsigned int prec, unsigned int expSize );
  TmpMpIeee( unsigned int prec, int l, int u );
  TmpMpIeee( int i );
  TmpMpIeee( int i, unsigned int prec, int l, int u );
  TmpMpIeee( long li );
  TmpMpIeee( long li, unsigned int prec, int l, int u );
  TmpMpIeee( unsigned int ui );
  TmpMpIeee( unsigned int ui, unsigned int prec, int l, int u );
  TmpMpIeee( unsigned long ul );
  TmpMpIeee( unsigned long ul, unsigned int prec, int l, int u );
  TmpMpIeee( float f );
  TmpMpIeee( float f, unsigned int prec, int l, int u );
  TmpMpIeee( double d );
  TmpMpIeee( double d, unsigned int prec, int l, int u );
  TmpMpIeee( long double ld );
  TmpMpIeee( long double ld, unsigned int prec, int l, int u );
  TmpMpIeee( const char *s );
  TmpMpIeee( const char *s, unsigned int prec, int l, int u );
  TmpMpIeee( SpecialValue s );
  TmpMpIeee( SpecialValue s, unsigned int prec, int l, int u );
  TmpMpIeee( SpecialRounded s );
  TmpMpIeee( SpecialRounded s, unsigned int prec, int l, int u );
  TmpMpIeee( const MpIeee& R );
  TmpMpIeee( const TmpMpIeee& T );
  /*@}*/
  
  /// destructor
  ~TmpMpIeee() {}
		
  /**
   ** @name assignment operators
   **/
  /*@{*/
  void operator=(const MpIeee &R);
  void operator=(TmpMpIeee &T);
  /*@}*/

  // auxiliary routines
  /// conversion from integer
  void TmpMpIeee::fromInt(int *decimal,int size);
};


#endif /* _ARITHMOS_TMPMPIEEE_H_ */



