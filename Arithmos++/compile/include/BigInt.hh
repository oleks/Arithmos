/******************************************************************************
 **
 ** Arithmos class library
 **
 ** BigInt : BigInt software library
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
 ** @file     BigInt.hh
 ** @brief    exact BigInt arithmetic
 **
 ** $Id: BigInt.hh,v 1.24 2001/08/23 13:30:37 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:37 $
 ** $Author: sbecuwe $
 **
 ** The Arithmos Rational Library has to be linked with the GNU GMP
 ** library, which is available under the GNU lesser general public
 ** license (http://www.swox.com/gmp/lgpl.html)
 **/

#ifndef BIGINT_HH
#define BIGINT_HH

#include <gmp.h>
#include "SpecialExact.hh"

#ifndef _WINDOWS_MSVC_
#define LONGLONG long long    ///< 64 bit integer
#define ULONGLONG unsigned long long  ///< unsigned 64 bit integer
#else
#define LONGLONG __int64      ///< 64 bit integer
#define ULONGLONG unsigned __int64    ///< unsigned 64 bit integer
#endif

#ifndef ULLONG_MAX
/// max. value of unsigned 64 bit integer
#define ULLONG_MAX (~(ULONGLONG)0)
#endif

#define LIMB_MAX (~(mp_limb_t)0)  ///< max. value of a (gnu) mp limb
#define LIMB_BITS nBits( LIMB_MAX ) ///< no. of bits in a (gnu) mp limb

/*
 * I hope these functions will some day be part of GMP...
 */
#ifndef mpz_odd
unsigned int mpz_odd( const mpz_t a );	///< check for odd gnu mpz
#endif
#ifndef mpz_even
unsigned int mpz_even( const mpz_t a ); ///< check for even gnu mpz
#endif

/*
 * Foreward declarations
 */

class TmpBigInt;
class TmpMpIeee;
class MpIeee;

/**
 ** @brief Class for multiprecision integer arithmetic.
 **
 ** The Arithmos BigInt class.
 **
 ** The BigInt class is a C++ wrapper around the GNU MP multiprecision
 ** integers (mpz_t).
 **/
class BigInt : public ControlStatus
{
  friend class Rational;

  public:
      /**
       ** @name Constructors
       **
       ** These functions create a new BigInt.  The default
       ** constructor assigns zero to the new bigint.
       **/
      /*@{*/
      BigInt();
	  BigInt( SpecialValue s );
      BigInt( SpecialExact s );
      BigInt( int i );
      BigInt( long l );
      BigInt( unsigned long ul );
      BigInt( const char *s );
      BigInt( const BigInt& b );
      BigInt( const TmpBigInt& t );
      BigInt( const MpIeee& m );
      /*@}*/

      ~BigInt();

      /**
       ** @name Assignations
       **
       ** These functions assign a value to a BigInt.
       **/
      /*@{*/
	  BigInt& operator=( SpecialValue s );
      BigInt& operator=( SpecialExact s );
      BigInt& operator=( int i );
      BigInt& operator=( long l );
      BigInt& operator=( unsigned long ul );
      BigInt& operator=( const char *s );
      BigInt& operator=( const BigInt& b );
      BigInt& operator=( const TmpBigInt& t );
      BigInt& operator=( const MpIeee& m );
      /*@}*/

      /**
       ** @name Conversions to other data types.
       **
       ** To convert a BigInt to one of these data types, one should
       ** use these explicit conversions.
       **/
      /*@{*/
      SpecialExact toSpecialExact() const;
      int toInt() const;
      long toLong() const;
      unsigned long toUnsignedLong() const;
      void toString( char* string, unsigned long strLen ) const;
      TmpMpIeee toMpIeee( unsigned int prec = 0 ) const;
      /*@}*/

      /**
       ** @name Setting special values.
       **
       ** These functions assign a special value to a BigInt, and
       ** return a reference to themselves.
       **/
      /*@{*/
      BigInt& setPhi();
      BigInt& setNan();
      BigInt& setInf( SignBitsType sign = spUnsigned );
      BigInt& setZero( SignBitsType sign = spUnsigned );
      /*@}*/

      /**
       ** @name Checking for special values.
       **
       ** These functions check whether a BigInt represents a special
       ** value.
       **/
      /*@{*/
      unsigned int isSpecial() const;
      unsigned int isPhi() const;
      unsigned int isNan() const;
      unsigned int isInf() const;
      unsigned int isZero() const;
      /*@}*/

      /**
       ** @name Basic operations and square root
       **
       ** Addition, subtraction, multiplication, division,...
       **/
      /*@{*/

      TmpBigInt operator-() const;
      BigInt& operator++();
      TmpBigInt operator++( int dummy );
      BigInt& operator--();
      TmpBigInt operator--( int dummy );

      BigInt& operator+=( const BigInt& b );
      friend TmpBigInt operator+( const BigInt& a, const BigInt& b );
      friend TmpBigInt operator+( const TmpBigInt& a, const BigInt& b );
      friend TmpBigInt operator+( const BigInt& a, const TmpBigInt& b );
      friend TmpBigInt operator+( const TmpBigInt& a, const TmpBigInt& b );
      BigInt& operator-=( const BigInt& b );
      friend TmpBigInt operator-( const BigInt& a, const BigInt& b );
      friend TmpBigInt operator-( const TmpBigInt& a, const BigInt& b );
      friend TmpBigInt operator-( const BigInt& a, const TmpBigInt& b );
      friend TmpBigInt operator-( const TmpBigInt& a, const TmpBigInt& b );
      BigInt& operator*=( const BigInt& b );
      friend TmpBigInt operator*( const BigInt& a, const BigInt& b );
      BigInt& operator/=( const BigInt& b );
      friend TmpBigInt operator/( const BigInt& a, const BigInt& b );
      BigInt& operator%=( const BigInt& b );
      friend TmpBigInt operator%( const BigInt& a, const BigInt& b );

      TmpBigInt inv() const;
      TmpBigInt sqrt() const;

      friend void neg( BigInt& c, const BigInt& a );
      friend void inv( BigInt& c, const BigInt& a );

      friend void add( BigInt& c, const BigInt& a, const BigInt& b );
      friend void sub( BigInt& c, const BigInt& a, const BigInt& b );
      friend void mul( BigInt& c, const BigInt& a, const BigInt& b );
      friend void div( BigInt& c, const BigInt& a, const BigInt& b );
      friend void mod( BigInt& c, const BigInt& a, const BigInt& b );
      friend void sqrt( BigInt& c, const BigInt& a );
      /*@}*/

      /**
       ** @name Relational operators
       **
       ** Functions to compare two Bigints.
       **/
      /**@{*/
      friend unsigned int operator==( const BigInt& a, const
	      	      	      	      BigInt& b );
      friend unsigned int operator!=( const BigInt& a, const
	      	      	      	      BigInt& b );
      friend unsigned int operator<( const BigInt& a, const
	      	      	      	      BigInt& b );
      friend unsigned int operator>=( const BigInt& a, const
	      	      	      	      BigInt& b );
      friend unsigned int operator>( const BigInt& a, const
	      	      	      	      BigInt& b );
      friend unsigned int operator<=( const BigInt& a, const
	      	      	      	      BigInt& b );
      friend unsigned int unordered( const BigInt& a, const
	      	      	      	     BigInt& b );
      /**@}*/

      /**
       ** @name Elementary functions
       **/
      /*@{*/
      TmpBigInt pow( unsigned long b ) const;
      TmpBigInt pow( const BigInt& b ) const;
      TmpBigInt root( unsigned long b ) const;
      TmpBigInt root( const BigInt& b ) const;

      TmpBigInt operator>>( unsigned long l ) const;
      TmpBigInt operator<<( unsigned long l ) const;
      BigInt& operator>>=( unsigned long l );
      BigInt& operator<<=( unsigned long l );

      friend void pow( BigInt& c, const BigInt& a, unsigned long b );
      friend void pow( BigInt& c, const BigInt& a, const BigInt& b );
      friend void root( BigInt& c, const BigInt& a, unsigned long b );
      friend void root( BigInt& c, const BigInt& a, const BigInt& b );
      friend void rshift( BigInt& c, const BigInt& a, unsigned long l );
      friend void lshift( BigInt& c, const BigInt& a, unsigned long l );
      /*@}*/

      /**
       ** @name Miscellaneous
       **/
      /*@{*/
      int sgn() const;
      SignBitsType getSignBits() const;
      unsigned int odd() const;
      unsigned int even() const;
      unsigned int perfectSquare() const;
      unsigned int hasZero() const;
      /*@}*/

      /**
       ** @name I/O
       **
       ** Input and output of big integers.
       ** I/O of big integers is done using streams.
       **/
      /*@{*/
      friend istream& operator>>( istream& stream, BigInt& b );
      friend ostream& operator<<( ostream& stream, const BigInt& b );
      friend ostream& outputRational( ostream& os, const BigInt& b );
      /*@}*/

      /*
       * protected instead of private; otherwise RefBigInt hasn't the
       * access it needs.
       */
  protected:
      /**
       ** @brief Value of the BigInt.
       **
       ** Actual value of the BigInt, stored as gnu mpq.  If the
       ** BigInt is a special value; mValue should be zero.
       **/
      mpz_t mValue;
      /**
       ** @brief Properties of the BigInt if it's a special value.
       **
       ** If mValue is zero, mProperties indicates which special value
       ** is represented by the BigInt.
       **/
      SpecialExact mProperties;
};

#include "TmpBigInt.hh"


#ifndef OUTLINE
#include "BigInt.icc"
#endif
#endif
