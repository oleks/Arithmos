/******************************************************************************
 *
 * Arithmos class library
 * 
 * IMpIeee : Multiprecision interval floating-point software library
 *
 * Copyright (C) 2000
 * Research Group Computer Arithmetic & Numerical Techniques (CANT)
 * Department of Mathematics & Computer Science
 * University of Antwerp
 * Universiteitsplein 1
 * B-2610 Wilrijk
 * BELGIUM
 *
 * contact : cant@uia.ua.ac.be
 *
 ****************************************************************************/


/**
 ** @file     IMpIeee.h
 ** @brief    Declaration of the IMpIeee class
 ** 
 ** $Id: IMpIeee.hh,v 1.17 2001/08/23 13:30:38 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:38 $
 ** $Author: sbecuwe $
 **
 ** The IMpIeee class implements (multiprecision floating point)
 ** interval arithmetic with special value support.  Documentation
 ** about the special values/exceptions can be found in
 ** cvs/ArithmosDevelopment/Arithmos/doc/superval.tex
 **/                        


#ifndef _ARITHMOS_IMPIEEE_H_
#define _ARITHMOS_IMPIEEE_H_

#include <MpIeee.hh>

/**
 ** The IMpIeee class
 **
 ** This class implements (multiprecision floating point) interval
 ** arithmetic, with special value support.
 **/

class TmpIMpIeee;

class IMpIeee {
  friend class TmpIMpIeee;

public:
  /**
   ** @name Constructors
   **
   ** These functions create a new interval.
   **/
  /*@{*/
  IMpIeee();
  IMpIeee( unsigned int prec, unsigned int expSize );
  IMpIeee( unsigned int prec, int l, int u );
  IMpIeee( int i );
  IMpIeee( int i, unsigned int prec, int l, int u );
  IMpIeee( long li );
  IMpIeee( long li, unsigned int prec, int l, int u );
  IMpIeee( unsigned int ui );
  IMpIeee( unsigned int ui, unsigned int prec, int l, int u );
  IMpIeee( unsigned long ul );
  IMpIeee( unsigned long ul, unsigned int prec, int l, int u );
  IMpIeee( float f );
  IMpIeee( float f, unsigned int prec, int l, int u );
  IMpIeee( double d );
  IMpIeee( double d, unsigned int prec, int l, int u );
  IMpIeee( long double ld );
  IMpIeee( long double ld, unsigned int prec, int l, int u );
  IMpIeee( const char *s );
  IMpIeee( const char *s, unsigned int prec, int l, int u );
  IMpIeee( const MpIeee& R );
  IMpIeee( const MpIeee& R, unsigned int prec, int l, int u );
  IMpIeee( const MpIeee& Inf, const MpIeee& Sup );
  IMpIeee( const MpIeee& Inf, const MpIeee& Sup, unsigned int prec, int l,
	   int u );
  IMpIeee( const IMpIeee& R );
  IMpIeee( TmpIMpIeee& T );
  IMpIeee( SpecialValue s );
  /*@}*/

  ~IMpIeee( );

  void operator= ( const IMpIeee& R );
  void operator= ( TmpIMpIeee& T );

  /**
   ** @name Properties of the interval.
   **/
  /*@{*/
  unsigned int prec() const;
  int getL() const;
  int getU() const;
  /*@}*/

  /**
   ** @name Setting special values
   **/
  /*@{*/
  IMpIeee& setNan();
  /*@}*/

  /**
   ** @name Checking for special values
   **/
  /*{@*/
  int isPhi() const;
  int isZero() const; 
  int isInf() const;
  int iisPhi() const;
  /*@}*/
  
  IMpIeee withoutInf() const;
    
  MpIeee getInf() const;
  MpIeee getSup() const;
  MpIeee mid() const;
  MpIeee diam() const;

  /** 
   ** @name Basic operations and square root
   **/
  /*@{*/
  friend IMpIeee operator+ ( const IMpIeee& X, const IMpIeee& Y );
  friend IMpIeee operator- ( const IMpIeee& X, const IMpIeee& Y );
  friend IMpIeee operator* ( const IMpIeee& X, const IMpIeee& Y );
  friend IMpIeee operator/ ( const IMpIeee& X, const IMpIeee& Y );
  IMpIeee sqrt();
  /*@}*/
  
  /**
   ** @name Relations
   **
   ** These functions are used to compare two intervals.  Be careful
   ** when you use these, because there's a difference between the 
   ** `certain', `possibly', `interval certain' and `interval
   ** possibly' versions of the operations.
   **/
  /*@{*/
  
  friend int ceq   ( const IMpIeee& A, const IMpIeee& B );
  friend int peq   ( const IMpIeee& A, const IMpIeee& B );
  friend int iceq  ( const IMpIeee& A, const IMpIeee& B );
  friend int ipeq  ( const IMpIeee& A, const IMpIeee& B );
  
  friend int cneq  ( const IMpIeee& A, const IMpIeee& B );
  friend int pneq  ( const IMpIeee& A, const IMpIeee& B );
  friend int icneq ( const IMpIeee& A, const IMpIeee& B );
  friend int ipneq ( const IMpIeee& A, const IMpIeee& B );
  
  friend int cles  ( const IMpIeee& A, const IMpIeee& B );
  friend int ples  ( const IMpIeee& A, const IMpIeee& B );
  friend int icles ( const IMpIeee& A, const IMpIeee& B );
  friend int iples ( const IMpIeee& A, const IMpIeee& B );
  
  friend int cleq  ( const IMpIeee& A, const IMpIeee& B );
  friend int pleq  ( const IMpIeee& A, const IMpIeee& B );
  friend int icleq ( const IMpIeee& A, const IMpIeee& B );
  friend int ipleq ( const IMpIeee& A, const IMpIeee& B );
  
  friend int cgtr  ( const IMpIeee& A, const IMpIeee& B );
  friend int pgtr  ( const IMpIeee& A, const IMpIeee& B );
  friend int icgtr ( const IMpIeee& A, const IMpIeee& B );
  friend int ipgtr ( const IMpIeee& A, const IMpIeee& B );
  
  friend int cgeq  ( const IMpIeee& A, const IMpIeee& B );
  friend int pgeq  ( const IMpIeee& A, const IMpIeee& B );
  friend int icgeq ( const IMpIeee& A, const IMpIeee& B );
  friend int ipgeq ( const IMpIeee& A, const IMpIeee& B );
  
  /// certainly equal
  friend int operator== ( const IMpIeee& A, const IMpIeee& B );
  /// possibly not equal
  friend int operator!= ( const IMpIeee& A, const IMpIeee& B );
  /// certainly less
  friend int operator<  ( const IMpIeee& A, const IMpIeee& B );
  /// certainly less or equal
  friend int operator<= ( const IMpIeee& A, const IMpIeee& B );
  /// certainly greater
  friend int operator>  ( const IMpIeee& A, const IMpIeee& B );
  /// certainly greater or equal
  friend int operator>= ( const IMpIeee& A, const IMpIeee& B );
  /// unordered
  friend int unordered  ( const IMpIeee& A, const IMpIeee& B );
   /*@}*/

  IMpIeee rint();

  void fromDecimal (char *decimal);
  void toDecimal(char *decimal, unsigned int prec);

  void fromBinary         ( char* binStr    );
  void fromBinaryRep      ( char* binRepStr );
  void fromHexadecimalRep ( char* hexRepStr );

  void scaleTo2Pi(MpIeee &Inf, MpIeee &Sup);

  /**
   ** @name	Elementary functions
   **/
  /*@{*/
  IMpIeee sin();
  IMpIeee cos();
  IMpIeee tan();
  IMpIeee cotan();
  IMpIeee atan();
  IMpIeee asin();
  IMpIeee acos();
  IMpIeee acotan();
  IMpIeee exp();
  IMpIeee exp2();
  IMpIeee exp10();
  IMpIeee sinh();
  IMpIeee cosh();
  IMpIeee tanh();
  IMpIeee asinh();
  IMpIeee acosh();
  IMpIeee atanh();
  IMpIeee ln();
  IMpIeee log10();
  IMpIeee log2();

  IMpIeee pow( unsigned long e );
  /*@}*/

  friend SpecialRounded toSpecial( const MpIeee& inf, const MpIeee& sup );

  /*
   * De implementatie van de operatoren << en >> vind je terug in
   * imp_output.cpp en imp_get.cpp 
   */
  friend ostream& operator<<       ( ostream& o,const IMpIeee& s );
  friend istream& operator>>       ( istream& i, IMpIeee& s );
  friend void outputParameters     ( ostream& o, const IMpIeee& s );
  friend void outputDecimal        ( ostream& o, const IMpIeee& s );
  friend void outputBinary         ( ostream& o, const IMpIeee& s );
  friend void outputBinaryRep      ( ostream& o, const IMpIeee& s );
  friend void outputHexadecimalRep ( ostream& o, const IMpIeee& s );

  /*
   * `_NO_PRIVATE_' should only be used for debugging purposes !
   */
#ifndef _NO_PRIVATE_
#ifndef _WINDOWS_MSVC_
private:
#else
protected:
#endif
#endif
  MpIeee *inf, *sup;
  SpecialRounded properties;

  static int quadrant(MpIeee &mp);
  static void splitInterval ( char *str, char *&sep, char *&inf, char *&sup );
};

#include "TmpIMpIeee.hh"

#ifndef OUTLINE
#include "IMpIeee.icc"
#endif

#endif /* _ARITHMOS_IMPIEEE_H */


