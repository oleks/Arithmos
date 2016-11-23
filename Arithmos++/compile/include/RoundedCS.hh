/******************************************************************************
 **
 ** Arithmos class library
 **
 ** ControlStatus : Control word and status word for rounded arithmetic
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
 ** @file	RoundedCS.hh
 ** @brief	Control word and status word functionality for rounded
 **		arithmetic
 ** @warning	In previous version the control and status bits were
 **		stored in static data members.  This is'nt the case
 **		any more.  If you want to use this class as control and
 **		status word of another class, you should make it
 **		a static member or keep it outside the class.
 **
 ** $Id: RoundedCS.hh,v 1.2 2001/08/23 13:30:38 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:38 $
 ** $Author: sbecuwe $
 **/

#ifndef ROUNDEDCS_HH
#define ROUNDEDCS_HH

#include <ControlStatus.hh>

/**
 ** @brief Control and status word management for exact arithmetic.
 **
 ** The RoundedCS class.
 **
 ** This class implements the virtual functions of ControlStatus for
 ** Exact Arithmetic.  Some typical `exact arithmetic' extensions are
 ** added.
 **/
class RoundedCS : public ControlStatus
{
public:

  /**
   ** @name Manipulation of the exception control bits
   **
   ** If an exception control bit is set, and its exception
   ** occurs, a standard action will be executed, and the
   ** exception will be signaled in the status word.  If
   ** an exception for which the control bit isn't set occurs,
   ** something else will happen (trapping, which isn't
   ** implemented yet, or generation of a `set result' for the
   ** inexact exception).
   **
   ** @see ExceptionsType
   **/
  /*@{*/
  virtual void controlSet( ExceptionsType exceptions );
  virtual void controlClr( ExceptionsType exceptions );
  virtual ExceptionsType controlTst( ExceptionsType exceptions ) const;
  /*@}*/

  /**
   ** @name Manipulation of the exception status bits
   **
   ** These functions are used to set, check and clear the
   ** exception bits in the status word.  They don't care about
   ** the control bits (yet).
   **
   ** @see ExceptionsType
   **/
  /*@{*/
  virtual void exceptionSet( ExceptionsType exceptions );
  virtual void exceptionClr( ExceptionsType exceptions );
  virtual ExceptionsType exceptionTst( ExceptionsType exceptions ) const;
  /*@}*/

  /**
   ** @name Rounding control.
   **
   ** In addition to the `global' rounding mode manipulation
   ** functions, some functions are added to manipulate only the
   ** `rational rounding bits' and only the `integer rounding bits'
   **
   ** @see RoundingModeType
   **/
  /*@{*/
  virtual void setRoundingMode( RoundingModeType roundingmode );
  virtual RoundingModeType getRoundingMode() const;
  void setIntRoundingMode( RoundingModeType roundingmode );
  RoundingModeType getIntRoundingMode() const;
  void setRatRoundingMode( RoundingModeType roundingmode );
  RoundingModeType getRatRoundingMode() const;
  void setRoundingPrecision( unsigned int precision );
  unsigned int getRoundingPrecision() const;
  /*@}*/
};

extern RoundedCS theRoundedCS; /* THE control and status word for rounded arithmetic */

#ifndef OUTLINE
#include "RoundedCS.icc"
#endif

#endif

