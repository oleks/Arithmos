/******************************************************************************
 **
 ** Arithmos class library
 **
 ** SpecialValue : SpecialValue software library
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
 ** @file    SpecialValue.hh
 ** @brief   Declaration of the SpecialValue class.
 **
 ** $Id: SpecialValue.hh,v 1.16 2001/08/23 13:30:39 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:39 $
 ** $Author: sbecuwe $
 **
 ** The SpecialValue class is used to represent special values, and to
 ** use them in calculations.  Detailed documentation of this class
 ** can be found in the CVS repository :
 **
 ** cvs/ArithmosDevelopment/Arithmos/doc/special_doc.tex
 **
 **/

#ifndef SPECIALVALUE_HH
#define SPECIALVALUE_HH

#include "ControlStatus.hh"

/**
 ** @brief Some template functions.
 ** Some stupid functions like max, min,...
 **/
/*@{*/

/**
 ** @brief  Minimum function
 ** @param  x first number
 ** @param  y second number
 ** @return smallest number
 **/
template <class T>
inline T min( T x, T y )
{
  return (x < y) ? x : y;
}

/**
 ** @brief  Maximum function
 ** @param  x first number
 ** @param  y second number
 ** @return largest number
 **/
template <class T>
inline T max( T x, T y )
{
  return (x > y) ? x : y;
}

/**
 ** @brief  returns the number of bits of a.
 ** @param  a number of which the bits will be counted.
 ** @return number of bits of a.
 **/
template <class T>
inline unsigned int nBits(T a)
{
  if (!a) return 0;
  else
  {
    int totBits = 8*sizeof(T);
    int i = totBits;
    while (!(a & ((T)1 << (totBits - 1)))) a <<= 1, --i;
    return i;
  }
}
/*@}*/

/*
 * Since version 3 of the gcc compiler, you can't `foreward declare'
 * istream and ostream like this anymore.
 * (amai what a dragon of a sentence)
 *
 * class istream;
 * class ostream;
 */

#include <iostream.h>

/**
 ** Bit pattern containing the mProperties of a special value.
 **
 ** A bit pattern consists of two sign bits, a zero and an infinity
 ** bit, and three IaX bits.  One bit is still unused.
 **
 ** @see SignBitsType
 ** @see IaxBitsType
 **/
typedef unsigned char BitPatternType;

 /**
  ** Zero bit of a special value.
  **
  ** The zero bit is set iff the set which is represented by the
  ** special value contains zero.
  **/
const BitPatternType spZeroBit = 0x20;

 /**
  ** Infinity bit of a special value.
  **
  ** The infinity bit is set iff the set which is represented by the
  ** special value contains infinity.
  **/
const BitPatternType spInfinityBit = 0x10;

/**
 ** Type to represent the sign of a special value.
 **
 ** The sign bits determine whether a special value has a positive
 ** sign, a negative sign, no sign at all, or whether the special
 ** value is NaN (not a number).
 **/
typedef unsigned char SignBitsType;

/**
 ** @name Sign bits of a special value.
 **
 ** The combinations of the sign bits of a special value are
 ** interpreted as follows :
 **/
 /*@{*/
 const SignBitsType spSignMask = 0xc0;
 const SignBitsType spUnsigned = 0x00;
 const SignBitsType spPlus = 0x40;
 const SignBitsType spMinus = 0x80;
 const SignBitsType spNanBits = 0xc0;
 /*@}*/

/**
 ** Type to represent different `IaX'es.
 **
 ** These bits indicate whether a number set (Z, Q, R, C) is
 ** included in the set represented by the special value.
 **/
typedef unsigned char IaxBitsType;

/**
 ** @name Iax bits of a special value.
 **
 ** These combinations are used to represent the different IaX values.
 **/
/*@{*/
const IaxBitsType spIaxMask = 0x07;
const IaxBitsType spIaz = 0x04;
const IaxBitsType spIaq = 0x05;
const IaxBitsType spIar = 0x06;
const IaxBitsType spIac = 0x07;
/*@}*/


/**
 ** Type to select a control-status pair.
 **
 ** @remark	It's important that the SpecialValue::pairs array (in
 **		sp_SpecialValue.cpp) is initialized according to
 **		these values.
 **/
typedef char ControlStatusPair;

/** @name       Available ControlStatusPair constants.
 ** @remark	    It's important that the SpecialValue::pairs array (in
 **	            sp_SpecialValue.cpp) is initialized according to
 **	            these values.
 **/
/*@{*/
const ControlStatusPair spGenericCS = 0;
const ControlStatusPair spRoundedCS = 1;
const ControlStatusPair spExactCS = 2;
/*@}*/

/**
 ** @brief Class for special value support.
 **
 ** The SpecialValue class
 **
 ** The SpecialValue class is an implementation of the special values
 ** described in special_doc.tex, which can be found in the cvs
 ** repository :
 **
 ** cvs/ArithmosDevelopment/Arithmos/doc/special_doc.tex
 **/
class SpecialValue
{
public:
  /**
   ** @name Constructors
   **
   ** These functions create a new special value.
   ** When a special value is constructed from another value,
   ** the result will be the smallest superset of that value which
   ** can be represented as a SpecialValue.  The implementation of
   ** these functions can be found in sp_SpecialValue.cpp
   **/
  /*@{*/
  SpecialValue( ControlStatusPair cs = spGenericCS );
  SpecialValue( int i, ControlStatusPair cs = spGenericCS );
  SpecialValue( long l, ControlStatusPair cs = spGenericCS );
  SpecialValue( unsigned long ul, ControlStatusPair cs = spGenericCS );
  SpecialValue( const char* s, ControlStatusPair cs = spGenericCS );
  /*@}*/

  /**
   ** @name Setting particular special values.
   **
   ** These functions are used to assign a particular value to an
   ** instance of SpecialValue.  When creating an infinity or a
   ** zero, one can give them a sign.  If no sign is specified,
   ** the infinity or zero will be unsigned by default.
   **
   ** @see SignBitsType
   **/
  /*@{*/
  void setPhi();
  void setNan();
  void setZero( SignBitsType sign = spUnsigned );
  void setInf( SignBitsType sign = spUnsigned );
  /*@}*/

  /**
   ** @name Testing for particular special values.
   **
   ** Use these functions to test whether a special value is Phi,
   ** NaN, zero or infinity.
   **/
  /*@{*/
  unsigned int isPhi() const;
  unsigned int isNan() const;
  unsigned int isZero() const;
  unsigned int isInf() const;
  /*@}*/

  /**
   ** @name Generating particular special values.
   **
   ** These functions return instances of particular special
   ** values.
   **/
  /*@{*/
  static SpecialValue phi();
  static SpecialValue nan();
  static SpecialValue iac();
  static SpecialValue iar();
  static SpecialValue iaq();
  static SpecialValue iaz();
  static SpecialValue zero( SignBitsType sign = spUnsigned );
  /*@}*/

  /**
   ** @name Adding elements to a special value.
   **
   ** These functions make a special value `bigger' by adding
   ** elements to its set.
   **/
  /*@{*/
  SpecialValue& addZero();
  SpecialValue& addInf();
  /*@}*/

  /**
   ** @name Removing elements from a special value.
   **
   ** These functions make a special value `smaller' by removing
   ** elements from its set.
   **/
  /*@{*/
  SpecialValue& removeZero();
  SpecialValue& removeInf();
  SpecialValue& removeReals();
  /*@}*/

  /**
   ** @name Checking for elements in a special value.
   **
   ** These functions check the contents of a special value.
   **/
  /*@{*/
  unsigned int hasZero() const;
  unsigned int hasInf() const;
  unsigned int isReal() const;
  unsigned int isPositive() const;
  unsigned int isNegative() const;
  /*@}*/

  /**
   ** @name Basic operations and square root.
   **
   ** Addition, subtraction, multiplication, division, sqrt
   **/
  /*@{*/
  SpecialValue operator-() const;
  SpecialValue inv() const;

  SpecialValue& operator++();
  SpecialValue operator++( int dummy );
  SpecialValue& operator--();
  SpecialValue operator--( int dummy );

  friend SpecialValue operator+( SpecialValue a, SpecialValue b );
  friend SpecialValue operator-( SpecialValue a, SpecialValue b );
  friend SpecialValue operator*( SpecialValue a, SpecialValue b );
  friend SpecialValue operator/( SpecialValue a, SpecialValue b );

  SpecialValue& operator+=( SpecialValue b );
  SpecialValue& operator-=( SpecialValue b );

  SpecialValue sqrt() const;
  SpecialValue square() const;
  /*@}*/

  /**
   ** @name Relational operators
   **
   ** These functions compare two special values.
   **/
  /*@{*/
  friend unsigned int ceq( SpecialValue a, SpecialValue b );
  friend unsigned int peq( SpecialValue a, SpecialValue b );
  friend unsigned int cneq( SpecialValue a, SpecialValue b );
  friend unsigned int pneq( SpecialValue a, SpecialValue b );
  friend unsigned int cles( SpecialValue a, SpecialValue b );
  friend unsigned int ples( SpecialValue a, SpecialValue b );
  friend unsigned int cgeq( SpecialValue a, SpecialValue b );
  friend unsigned int pgeq( SpecialValue a, SpecialValue b );
  friend unsigned int cgtr( SpecialValue a, SpecialValue b );
  friend unsigned int pgtr( SpecialValue a, SpecialValue b );
  friend unsigned int cleq( SpecialValue a, SpecialValue b );
  friend unsigned int pleq( SpecialValue a, SpecialValue b );

  friend unsigned operator==( SpecialValue a, SpecialValue b );
  friend unsigned operator!=( SpecialValue a, SpecialValue b );
  friend unsigned operator<( SpecialValue a, SpecialValue b );
  friend unsigned operator>=( SpecialValue a, SpecialValue b );
  friend unsigned operator>( SpecialValue a, SpecialValue b );
  friend unsigned operator<=( SpecialValue a, SpecialValue b );

  friend unsigned int unordered( SpecialValue a, SpecialValue b );
  friend unsigned int disjoint( SpecialValue a, SpecialValue b );
  /*@}*/

  /**
   ** @name Elementary functions.
   **/
  /*@{*/
  SpecialValue abs() const;
  SpecialValue acos() const;
  SpecialValue acosh() const;
  SpecialValue acotan() const;
  SpecialValue acotanh() const;

  friend SpecialValue hull( SpecialValue a, SpecialValue b );
  friend SpecialValue hull( SpecialValue a, SpecialValue b,
			    SpecialValue c );
  friend SpecialValue hull( SpecialValue a, SpecialValue b,
			    SpecialValue c, SpecialValue d );
  friend SpecialValue intersection( SpecialValue a, SpecialValue b
				    );
  SpecialValue num() const;
  SpecialValue den() const;
  SpecialValue floor() const;
  SpecialValue ceil() const;
  SpecialValue pow( unsigned long b ) const;
  SpecialValue pow( SpecialValue b ) const;
  SpecialValue root( unsigned long b ) const;
  SpecialValue root( SpecialValue b ) const;
  /*@}*/

  /**
   ** @name Miscellaneous
   **/
  /*@{*/
  int sgn() const;
  unsigned int odd() const;
  unsigned int even() const;
  /*@}*/

  /**
   ** @name I/O
   **
   ** Input and output of special values.
   ** I/O of special values is done using streams.  The implementation
   ** of these functions can be found in sp_get.cpp and sp_put.cpp
   **/
  /*@{*/
  friend istream& operator>>( istream& stream, SpecialValue& value );
  friend ostream& operator<<( ostream& stream, SpecialValue value );
  /*@}*/

  /**
   ** @name monitoring components of a special value.
   **
   ** These functions directly read from the bits of a
   ** special value.
   **
   ** @see SignBitsType
   ** @see IaxBitsType
   **/
  /*@{*/
  SignBitsType getSignBits() const;
  IaxBitsType getIaxBits() const;
  unsigned int getZeroBit() const;
  unsigned int getInfBit() const;
  BitPatternType getBitPattern() const;
  /*@}*/

  /**
   ** @name	Control word and status word.
   **
   ** You can set the control word - status word pair of this special value
   ** using these functions.
   **
   ** @see	ControlStatusPair
   **/
  /*@{*/
  ControlStatusPair getCSP() const;
  void setCSP( ControlStatusPair csp );
  /*@}*/

protected:
  /**
   ** @name setting components of a special value.
   **
   ** These functions directly write into the bits of a
   ** special value.
   **
   ** @see SignBitsType
   ** @see IaxBitsType
   **/
  /*@{*/
  void setSignBits( SignBitsType sign );
  void setIaxBits( IaxBitsType iax );
  void setZeroBit( unsigned int state = 1 );
  void setInfBit( unsigned int state = 1 );
public:
  void setBitPattern( BitPatternType bits );
  /*@}*/

#ifndef _NO_PROTECTED_
protected:
#else
public:
#endif
  static ControlStatus* pairs[];
  BitPatternType mProperties;
  ControlStatusPair mcs;
};

#ifndef OUTLINE
#include "SpecialValue.icc"
#endif

#endif


