/******************************************************************************
 **
 ** Arithmos class library
 **
 ** Rational : Temporary Rational
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
 ** @file     TmpRational.hh
 ** @brief    exact Rational arithmetic -- class for temporary results
 **
 ** $Id: TmpRational.hh,v 1.10 2001/08/23 13:30:39 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:39 $
 ** $Author: sbecuwe $
 **
 ** The Arithmos Rational Library has to be linked with the GNU GMP
 ** library, which is available under the GNU lesser general public
 ** license (http://www.swox.com/gmp/lgpl.html)
 **/

#ifndef TMPRational_HH
#define TMPRational_HH

#include "Rational.hh"


/*
 * The constructors of this class are all declared inline, because
 * they don't contain any code.
 */

/**
 ** @brief Class used for storage of temporary rationals.
 **
 ** The TmpRational class.
 **
 ** The TmpRational class is used to store temporary Rational results.
 **/
class TmpRational : public Rational
{
  public:
      /**
       ** @name Constructors
       **
       ** These functions create a new TmpRational.  The default
       ** constructor assigns zero to the new TmpRational.
       **/
      /*@{*/
      TmpRational() : Rational() {}
      TmpRational( SpecialExact s ) : Rational( s ) {}
      TmpRational( int i ) : Rational( i ) {}
      TmpRational( long l ) : Rational( l ) {}
      TmpRational( unsigned long ul ) : Rational( ul ) {}
      TmpRational( const char *s ) : Rational( s ) {}
      TmpRational( const MpIeee& m ) : Rational( m ) {}
      TmpRational( const BigInt& b ) : Rational( b ) {}
      TmpRational( const TmpBigInt& t ) : Rational( t ) {}
      TmpRational( const Rational& r ) : Rational( r ) {}
      TmpRational( const TmpRational& t ) : Rational( t ) {}
      /*@}*/

      /**
       ** @name Some operations
       **
       ** These operations are more performant on temporary Rationals.
       **/
      /*@{*/
      TmpRational operator-() { return ::neg( *this, *this ), *this; }
      TmpRational inv() { return ::inv( *this, *this ), *this; }
      /*@}*/

      /// Destructor
      ~TmpRational() {}
};

// #ifndef OUTLINE
// #include "TmpRational.icc"
// #endif
#endif
