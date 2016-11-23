/******************************************************************************
 **
 ** Arithmos class library
 **
 ** SpecialExact : Special Value support for exact arithmetic
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
 ** @file	SpecialExact.hh
 ** @brief	Special Value support for exact arithmetic.
 **
 ** $Id: SpecialExact.hh,v 1.2 2001/08/23 13:30:39 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:39 $
 ** $Author: sbecuwe $
 **/

#include "ExactCS.hh"
#include "SpecialValue.hh"

class SpecialExact : public SpecialValue
{
	public:
		/**
		 ** @name	Constructors
		 ** @see	SpecialValue
		 ** @see	ExactCS
		 **
		 ** These functions create a new special value, with control and
		 ** status word for exact arithmetic.
		 **/
		/*@{*/
		SpecialExact() : SpecialValue( spExactCS ){}
		SpecialExact( int i ) : SpecialValue( i, spExactCS ){}
		SpecialExact( long l ) : SpecialValue( l, spExactCS ){}
		SpecialExact( unsigned long ul ) : SpecialValue( ul, spExactCS ){}
		SpecialExact( const char* s ) : SpecialValue( s, spExactCS ){}
		/*@}*/

		/**
		 ** @name	Assignations
		 **
		 ** What's in a name...
		 **/
		/*@{*/
		SpecialExact& operator=( SpecialValue sv );
		/*@}*/
};

#ifndef OUTLINE
#include "SpecialExact.icc"
#endif

