/******************************************************************************
 **
 ** Arithmos class library
 **
 ** ControlStatus : Control word and status word
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
 ** @file    ControlStatus.hh
 ** @brief   Interface for control and status word functionality
 **
 ** $Author: sbecuwe $
 **
 ** This class provides an interface for control and status word
 ** functionality.
 **/

#ifndef CONTROLSTATUS_HH
#define CONTROLSTATUS_HH

// 't is tegen mijn goesting, maar ik zal de foreward declaratie dan
// maar weglaten...

#include <iostream.h>

/**
 ** Type to represent the bits in the control word.
 **
 ** The control word contains a bit for each exception.  When an
 ** exception bit in the control word is cleared, a trap handler
 ** should be activated when the exception occurs.  (Trapping isn't
 ** supported yet.)
 **
 ** If an exception bit is set and the exception occurs, the
 ** corresponding flag will be set in the status word, and the
 ** program will continue it's execution.
 **
 ** Next to this, the control word specifies the active rounding
 ** mode, and the precision of rational rounding.  Rounding is
 ** only done when the csInexactResult control bit is set.
 **
 ** @see ExceptionsType
 ** @see RoundingModeType
 ** @see StatusBitsType
 **/
typedef unsigned int ControlBitsType;

/**
 ** Type to represent the bits in the status word.
 **
 ** The status word contains the flags which can be used to monitor
 ** which exceptions have occured.
 **
 ** @see ExceptionsType
 **/
typedef unsigned int StatusBitsType;

/**
 ** Type to represent (combinations of) exceptions.
 **
 ** Each possible exception is represented by a bit.  To represent a
 ** combination of exceptions, just take the bitwise or of the single
 ** exceptions.
 **/
typedef unsigned int ExceptionsType;

/**
 ** @name Individual exceptions.
 **
 ** These are the exceptions which can be handled.  The
 ** individual exceptions can be combined using a bitwise or
 ** operation.
 **/
/*@{*/
const ExceptionsType csUndefinedResult = 0x0001;
const ExceptionsType csIrrepresentableResult = 0x0002;
const ExceptionsType csInvalidOperation =
    (csUndefinedResult|csIrrepresentableResult);
const ExceptionsType csMemoryOverflow = 0x0004;
const ExceptionsType csOverflow = 0x0008;
const ExceptionsType csUnderflow = 0x0010;
const ExceptionsType csDivisionByZero = 0x0020;
const ExceptionsType csInexactResult = 0x0040;
const ExceptionsType csAllExceptions =
    (csInvalidOperation|csMemoryOverflow|csOverflow|
     csUnderflow|csDivisionByZero|csInexactResult);
/*@}*/

/**
 ** Type to represent rounding modes.
 **
 ** Bits 3-6 are reserved for rounding modes, but only 3-5 are used
 ** here.  Bit 6 will be used for rational rounding.
 **/
typedef unsigned int RoundingModeType;

/**
 ** @name Integer rounding modes.
 **
 ** These rounding modes are supported for integer arithmetic.
 **/
/*@{*/
const RoundingModeType csRoundToNearest = 0x0000;
const RoundingModeType csRoundToZero = 0x0080;
const RoundingModeType csRoundToInfinity = 0x0100;
const RoundingModeType csRoundDown = 0x0280;
const RoundingModeType csRoundUp = 0x0300;
const RoundingModeType csRoundingMask = (csRoundToNearest|
					 csRoundToZero|csRoundToInfinity|
					 csRoundDown|csRoundUp);
/*@}*/

/**
 ** @brief Class for control and status word management.
 **
 ** The ControlStatus class.
 **
 ** This class provides an interface to manage a control word and a
 ** status word.  If you want to use it in your own classes, you
 ** should make it a static class member, because the virtual
 ** functions consume a lot of memory.
 **/
class ControlStatus
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
   ** These functions set and test the rounding bits of the
   ** control word.
   **
   ** @see RoundingModeType
   **/
  /*@{*/
  virtual void setRoundingMode( RoundingModeType roundingmode );
  virtual RoundingModeType getRoundingMode() const;
  /*@}*/

  /**
   ** Output of the status word.
   **/
  /*@{*/
  ostream& outputStatusFlags( ostream& stream ) const;
  ostream& outputControlFlags( ostream& stream ) const;
  /*@}*/
  
  /**
   ** Some default settings
   **/
  /*@{*/
  static const unsigned int defaultPrecision;
  static const ExceptionsType defaultControlBits;
  static const RoundingModeType defaultRoundingMode;
  /*@}*/
  
private:
  void warning() const;
};

extern ControlStatus theCS;	/* THE generic control/status word */

#ifndef OUTLINE
#include "ControlStatus.icc"
#endif

#endif
