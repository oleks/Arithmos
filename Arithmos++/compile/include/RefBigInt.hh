/******************************************************************************
 **
 ** Arithmos class library
 **
 ** RefBigInt : class to provide a BigInt interface for existing mpz
 **   	      	integers.
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
 ** @file     RefBigInt.hh
 ** @brief    Class to provide a BigInt interface for existing mpz
 **   	      integers.
 **
 ** $Id: RefBigInt.hh,v 1.7 2001/08/23 13:30:38 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:38 $
 ** $Author: sbecuwe $
 **
 ** The Arithmos Rational Library has to be linked with the GNU GMP
 ** library, which is available under the GNU lesser general public
 ** license (http://www.swox.com/gmp/lgpl.html)
 **/

#ifndef REFBIGINT_HH
#define REFBIGINT_HH

#include "BigInt.hh"

/**
 ** @brief BigInt interface around existing GNU mpz_t
 **
 ** BigInt interface around GNU mpz_t.
 **
 ** This class is only meant to be used by the rational class, to
 ** create a BigInt interface around the numerator and denominator
 ** of a Rational (which is in fact an mpq_t).
 **
 ** When a RefBigInt is deleted, the mpz it is referring to is left
 ** unchanged, an will not be cleared.
 **
 ** It's forbidden to change the integer the RefBigInt object refers
 ** to.  So when a function returns a RefBigInt, this RefBigInt should
 ** ALWAYS be declared as CONST !!
 **/
class RefBigInt : public BigInt
{
  friend class Rational;

  public:
      RefBigInt( const RefBigInt& r );
      ~RefBigInt();

  private:
      /*
       * Only a Rational can create a RefBigInt.
       */
      RefBigInt( mpz_srcptr z );
	  RefBigInt( SpecialValue s );
      RefBigInt( SpecialExact s );
};

#endif
