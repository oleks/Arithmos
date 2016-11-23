/******************************************************************************
 **
 ** Arithmos class library
 **
 ** Rational : Rational software library
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
 *****************************************************************************/

/**
 ** @file     Rational.hh
 ** @brief    exact rational arithmetic
 **
 ** $Id: Rational.hh,v 1.28 2001/08/23 13:30:38 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:38 $
 ** $Author: sbecuwe $
 **
 ** The Arithmos Rational Library has to be linked with the GNU GMP
 ** library, which is available under the GNU lesser general public
 ** license (http://www.swox.com/gmp/lgpl.html)
 **
 **/


#ifndef RATIONAL_HH
#define RATIONAL_HH

#include <gmp.h>
#include "RefBigInt.hh"

/*
 * Foreward declarations
 */
class MpIeee;
class TmpMpIeee;
class TmpRational;

/**
 ** @brief Class for exact rational arithmetic.
 **
 ** The Rational class.
 **
 ** The Rational class is a C++ wrapper around the GNU MP rationals
 ** (mpq_t).
 **/

class Rational : public ControlStatus
{
  public:
      /**
       ** @name Constructors
       **
       ** These functions create a new Rational.  The default
       ** constructor assigns zero to the new Rational.
       **/
      /*@{*/
      Rational();
      Rational( SpecialExact s );
      Rational( int i );
      Rational( long l );
      Rational( unsigned long ul );
      Rational( const char *s );
      Rational( const MpIeee& m );
      Rational( const BigInt& b );
      Rational( const TmpBigInt& t );
      Rational( const Rational& r );
      Rational( const TmpRational& t );
      /*@}*/
      ~Rational();

  /**
   ** @name Assignations
   **
   ** These functions assign a value to a Rational.
   **/
  /*@{*/
  Rational& operator=( SpecialExact s );
  Rational& operator=( SpecialValue s );
  Rational& operator=( int i );
  Rational& operator=( long l );
  Rational& operator=( unsigned long ul );
  Rational& operator=( const char *s );
  Rational& operator=( const MpIeee& m );
  Rational& operator=( const BigInt& b );
  Rational& operator=( const TmpBigInt& t );
  Rational& operator=( const Rational& b );
  Rational& operator=( const TmpRational& t );
  Rational& set( const TmpBigInt& num, const TmpBigInt& den );
  /*@}*/

      /**
       ** @name Conversions to other data types.
       **
       ** These conversions to other data types are supported :
       **/
      /*@{*/
      long toLong() const;
#ifndef _NO_MPIEEE_
      float toFloat() const;
      double toDouble() const;
#endif
      void toString( char* string, unsigned long strLen ) const;
      TmpBigInt toBigInt() const;
      SpecialExact toSpecialExact() const;
      TmpMpIeee toMpIeee( unsigned int prec = 0, int l = 0, int u = 0 ) const;
      /*@}*/

      /**
       ** @name Extracting components.
       **
       ** These functions give access to the numerator and denominator
       ** of the rational.
       **/
      /*@{*/
      TmpBigInt num() const;
      TmpBigInt den() const;
      const RefBigInt numRef() const;
      const RefBigInt denRef() const;
      /*@}*/

      /**
       ** @name Setting components
       **
       ** These functions allow to set the numerator and denominator
       ** individually.
       **
       ** @warning  The Rational is always canonicalized after a
       **           setNum() or setDen call.  So there's no guarantee
       **     	    that after setNum( a ) the numerator is a.  It's
       **     	    not impossible that it has become a divisor of a.
       **     	    If you have to set both the numerator and
       **     	    denominator, you' d better use the Rational#set()
       **     	    function.
       ** @see	    Rational#set()
       **/
      /*@{*/
      Rational& setNum( const TmpBigInt& b );
      Rational& setDen( const TmpBigInt& b );
      /*@}*/

      /**
       ** @name Setting special values.
       **
       ** These functions assign a special value to a BigInt, and
       ** return a reference to themselves.
       **/
      /*@{*/
      Rational& setNan();
      Rational& setInf( SignBitsType sign = spUnsigned );
      Rational& setZero( SignBitsType sign = spUnsigned );
      /*@}*/

      /**
       ** @name Testing for special values.
       **
       ** These functions check for special values.
       **/
      /*@{*/
      unsigned int isSpecial() const;
      unsigned int isZero() const;
      unsigned int isInf() const;
      unsigned int isNan() const;
      /*@}*/

      /**
       ** @name Basic operations and square root
       **
       ** Addition, subtraction, multiplication, division,...
       **/
      /*@{*/

  Rational& operator+= ( const Rational& b );
  friend TmpRational operator+( const Rational& a, const
				Rational& b );
  Rational& operator-= ( const Rational& b );
  friend TmpRational operator-( const Rational& a, const
				Rational& b );
  friend TmpRational operator-( const Rational& b );
  Rational& operator*= ( const Rational& b );
  friend TmpRational operator*( const Rational& a, const
				Rational& b );
  Rational& operator/= ( const Rational& b );
  friend TmpRational operator/( const Rational& a, const
				Rational& b );
  TmpRational sqrt() const;
  TmpRational inv() const;
  
  friend void neg( Rational& c, const Rational& a );
  friend void add( Rational& c, const Rational& a, const Rational&
		   b );
  friend void sub( Rational& c, const Rational& a, const Rational&
		   b );
  friend void mul( Rational& c, const Rational& a, const Rational&
		   b );
  friend void div( Rational& c, const Rational& a, const Rational&
		   b );
  friend void sqrt( Rational& c, const Rational& a );
  friend void inv( Rational& c, const Rational& a );
  
  /*@}*/

      /**
       ** @name Relational operators.
       **
       ** These functions compare two Rationals
       **/
      /*@{*/
      friend unsigned int operator==( const Rational& a, const
	      	      	      	      Rational& b );
      friend unsigned int operator!=( const Rational& a, const
	      	      	      	      Rational& b );
      friend unsigned int operator<( const Rational& a, const
	      	      	      	      Rational& b );
      friend unsigned int operator>=( const Rational& a, const
	      	      	      	      Rational& b );
      friend unsigned int operator>( const Rational& a, const
	      	      	      	      Rational& b );
      friend unsigned int operator<=( const Rational& a, const
	      	      	      	      Rational& b );
      friend unsigned int unordered( const Rational& a, const
	      	      	      	     Rational& b );
      /*@}*/

      /**
       ** @name Elementary functions
       **/
      /*@{*/
      TmpRational pow( const Rational& s ) const;
      TmpRational exp2() const;
      TmpRational exp10() const;
      TmpBigInt floor() const;
      TmpBigInt ceil() const;
      TmpRational abs() const;
      /*@}*/

      /**
       ** @name miscellaneous
       **/
      /*@{*/
  int sgn() const;
  unsigned int perfectSquare() const;
  /*@}*/
  
      /**
       ** @name I/O
       **
       ** Input and output of rationals.
       ** I/O of rationalss is done using streams.
       **/
      /*@{*/
      friend istream& operator>>( istream& stream, Rational& b );
      friend ostream& operator<<( ostream& stream, const Rational& b );
      friend ostream& outputRational( ostream& os, const Rational& b );
      /*@}*/

#ifndef _WINDOWS_MSVC_
  private:
#else
  public:
#endif
      mpq_t mValue;
      SpecialExact mProperties;
};

#include "TmpRational.hh"

#ifndef OUTLINE
#include "Rational.icc"
#endif
#endif
