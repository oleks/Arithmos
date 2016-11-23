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
 ** @file     TmpBigInt.hh
 ** @brief    exact BigInt arithmetic -- class for temporary results
 **
 ** $Id: TmpBigInt.hh,v 1.12 2001/08/23 13:30:39 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:39 $
 ** $Author: sbecuwe $
 **
 ** The Arithmos Rational Library has to be linked with the GNU GMP
 ** library, which is available under the GNU lesser general public
 ** license (http://www.swox.com/gmp/lgpl.html)
 **/

#ifndef TMPBIGINT_HH
#define TMPBIGINT_HH

#include "BigInt.hh"


/*
 * There is no TmpBigInt.icc, so the inline functions are declared
 * here.  I don't think this is a big problem, since a normal user
 * doesn't need anything of this class.
 */

/**
 ** @brief Class used for storage of temporary multiprecision
 **   	   integers.
 **
 ** The TmpBigInt class.
 **
 ** The TmpBigInt class is used to store temporary BigInt results.
 **/
class TmpBigInt : public BigInt
{
  public:
      /**
       ** @name Constructors
       **
       ** These functions create a new TmpBigInt.  The default
       ** constructor assigns zero to the new TmpBigInt.
       **/
      /*@{*/
      TmpBigInt() : BigInt() {}
	  TmpBigInt( SpecialValue s ) : BigInt( s ) {}
      TmpBigInt( SpecialExact s ) : BigInt( s ) {}
      TmpBigInt( int i ) : BigInt( i ) {}
      TmpBigInt( long l ) : BigInt( l ) {}
      TmpBigInt( unsigned long ul ) : BigInt( ul ) {}
      TmpBigInt( const char *s ) : BigInt( s ) {}
      TmpBigInt( const BigInt& b ) : BigInt( b ) {}
      TmpBigInt( const TmpBigInt& t ) : BigInt( t ) {}
      TmpBigInt( const MpIeee& m ) : BigInt( m ) {}
      /*@}*/

      /**
       ** @name Arithmetic shifts
       **
       ** Shifting is a fast operation on temporary BigInts.
       **/
      /*@{*/
      /// Shift to the right
      TmpBigInt operator>>( unsigned long l ){return (*this >>= l), *this;}
      /// Shift to the left
      TmpBigInt operator<<( unsigned long l ){return (*this >>= l), *this;}
      /*@}*/

      /**
       ** @name Some unary operators
       **
       ** These operations can be performed very fast on temporary
       ** multiprecision integers.
       **/
      /*@{*/
      /// Unary minus
      TmpBigInt operator-() {return neg(*this, *this), *this;}
      /*@}*/

      /// Destructor
      ~TmpBigInt() {}
};

// #ifndef OUTLINE
// #include "TmpBigInt.icc"
// #endif
#endif
