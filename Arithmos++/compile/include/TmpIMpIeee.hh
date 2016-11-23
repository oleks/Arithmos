/******************************************************************************
**
** Arithmos class library
** 
** IMpIeee : Multiprecision interval floating-point software library
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
 ** @file     IMpIeee.h
 ** @brief    Temporary class fo IMpIeee
 ** 
 ** $Id: TmpIMpIeee.hh,v 1.3 2001/08/23 13:30:39 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:39 $
 ** $Author: sbecuwe $
 **/                        


#ifndef _ARITHMOS_TMPIMPIEEE_H_
#define _ARITHMOS_TMPIMPIEEE_H_

#include <IMpIeee.hh>

class TmpIMpIeee : public IMpIeee {
 public:
  TmpIMpIeee( );
  TmpIMpIeee( unsigned int prec, unsigned int expSize );
  TmpIMpIeee( unsigned int prec, int l, int u );
  TmpIMpIeee( int i );
  TmpIMpIeee( int i, unsigned int prec, int l, int u );
  TmpIMpIeee( long li );
  TmpIMpIeee( long li, unsigned int prec, int l, int u );
  TmpIMpIeee( unsigned int ui );
  TmpIMpIeee( unsigned int ui, unsigned int prec, int l, int u );
  TmpIMpIeee( unsigned long ul );
  TmpIMpIeee( unsigned long ul, unsigned int prec, int l, int u );
  TmpIMpIeee( float f );
  TmpIMpIeee( float f, unsigned int prec, int l, int u );
  TmpIMpIeee( double d );
  TmpIMpIeee( double d, unsigned int prec, int l, int u );
  TmpIMpIeee( long double ld );
  TmpIMpIeee( long double ld, unsigned int prec, int l, int u );
  TmpIMpIeee( const char *s );
  TmpIMpIeee( const char *s, unsigned int prec, int l, int u );
  TmpIMpIeee( const MpIeee& R );
  TmpIMpIeee( const MpIeee& R, unsigned int prec, int l, int u );
  TmpIMpIeee( const MpIeee& Inf, const MpIeee& Sup );
  TmpIMpIeee( const MpIeee& Inf, const MpIeee& Sup, unsigned int prec,
	      int l, int u );
  TmpIMpIeee( const IMpIeee& R );
  TmpIMpIeee( const TmpIMpIeee& T );
  TmpIMpIeee( SpecialValue s );

  ~TmpIMpIeee() {}
  void operator= ( const IMpIeee& R );
  void operator= ( TmpIMpIeee& T );
};


#endif /* _ARITHMOS_TMPIMPIEEE_H */


