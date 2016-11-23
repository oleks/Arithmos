/******************************************************************************
 **
 ** Arithmos class library
 **
 ** SpecialExact : Special Value support for rounded arithmetic
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
 ** @file	SpecialRounded.hh
 ** @brief	Special Value support for rounded arithmetic.
 **
 ** $Id: SpecialRounded.hh,v 1.2 2001/08/23 13:30:39 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:39 $
 ** $Author: sbecuwe $
 **/

#include "RoundedCS.hh"
#include "SpecialValue.hh"

class SpecialRounded : public SpecialValue
{
	public:
		/**
		 ** @name	Constructors
		 ** @see	SpecialValue
		 ** @see	RoundedCS
		 **
		 ** These functions create a new special value, with
		 ** control and status word for rounded arithmetic.
		 **/
		/*@{*/
		SpecialRounded() : SpecialValue( spRoundedCS ){}
		SpecialRounded( int i ) : SpecialValue( i, spRoundedCS ){}
		SpecialRounded( long l ) : SpecialValue( l, spRoundedCS ){}
		SpecialRounded( unsigned long ul ) : SpecialValue( ul, spRoundedCS ){}
		SpecialRounded( const char* s ) : SpecialValue( s, spRoundedCS ){}
		/*@}*/

		/**
		 ** @name	Assignations
		 **
		 ** What's in a name...
		 **/
		/*@{*/
		SpecialRounded& operator=( SpecialValue sv );
		/*@}*/
};

#ifndef OUTLINE
#include "SpecialRounded.icc"
#endif

