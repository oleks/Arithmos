/******************************************************************************
 **
 ** Arithmos class library
 **
 ** ControlStatus : Control word and status word for exact arithmetic
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
 ** @file	ExactCS.hh
 ** @brief	Control word and status word functionality for exact
 **		arithmetic
 ** @warning	In previous version the control and status bits were
 **		stored in static data members.  This is'nt the case
 **		any more.  If you want to use this class as control and
 **		status word of another class, you should make it
 **		a static member or keep it outside the class.
 **
 ** $Id: ExactCS.hh,v 1.6 2001/08/23 13:30:37 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:37 $
 ** $Author: sbecuwe $
 **/

#ifndef EXACTCS_HH
#define EXACTCS_HH

#include <ControlStatus.hh>

/**
 ** @name Rational rounding modes.
 **
 ** These rounding modes are added for rational arithmetic support.
 **/
/*@{*/
const RoundingModeType ecsMediantRounding = 0x0000;
const RoundingModeType ecsRoundToFloat = 0x0400;
const RoundingModeType ecsIntRoundingMask = csRoundingMask;
const RoundingModeType ecsRatRoundingMask =
    (ecsMediantRounding|ecsRoundToFloat);
const RoundingModeType ecsRoundingMask =
				csRoundingMask|ecsRatRoundingMask;
/*@}*/

/**
 ** @name Precision control
 **
 ** The bits in the control word which aren't used for exceptions and
 ** rounding modes, are used for precision control for rational
 ** rounding.
 **/
/*@{*/
const unsigned int ecsControlBitsUsed = 11;
const unsigned int ecsPrecisionControlMask =
    (0xffff << ecsControlBitsUsed);
/*@}*/

/**
 ** The ExactCS class.
 **
 ** This class implements the virtual functions of ControlStatus for
 ** Exact Arithmetic.  Some typical `exact arithmetic' extensions are
 ** added.
 **/
class ExactCS : public ControlStatus
{
public:

  ExactCS();

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

  /**
   ** @name I/O control
   **
   ** These functions controls the I/O of (rational) numbers.
   **/
  /*@{*/
  void setBaseForIO( unsigned int base );
  unsigned int getBaseForIO() const;
  void setRationalOutputPrecision( unsigned int precision );
  unsigned int getRationalOutputPrecision() const;
  /*@}*/

  /**
   ** @name	Some default settings
   **/
  /*@{*/
  const static unsigned int defaultRoundingPrecision;
  const static ExceptionsType  defaultControlBits;
  const static RoundingModeType  defaultRoundingMode;
  const static unsigned int defaultBaseForIO;
  const static unsigned int defaultRationalOutputPrecision;
  /*
   * precision 0 -> output in rationaal formaat met teller en noemer
   */
  /*@}*/

private:
  ControlBitsType mControlWord;
  StatusBitsType mStatusWord;
  unsigned int mBaseForIO;
  unsigned int mRationalOutputPrecision;
};

/* THE control and status word for exact and rounded arithmetic */
extern ExactCS theExactCS; 
#ifdef _NO_MPIEEE_
extern ExactCS theRoundedCS;
#endif

#ifndef OUTLINE
#include "ExactCS.icc"
#endif

#endif

