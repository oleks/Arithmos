/******************************************************************************
**
** Arithmos class library
** 
** fpenv : Class which represents the floating-point environment
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
******************************************************************************/

/**
 ** @file	FPEnv.hh
 ** @brief	Floating Point Environment
 **
 ** $Author: sbecuwe $
 **
 ** This class controls the rounding mode and the exception handling
 ** of the MpIeee floating point environment.
 **/

#ifndef _ARITHMOS_FPENV_H_
#define _ARITHMOS_FPENV_H_

#include <iostream.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

/**
 ** MpIeee floating-point environment
 **
 ** This class implements the MpIeee floating-point environment.  It
 ** controls the rounding mode and exception handling of the MpIeee
 ** class.
 **/

/**
 ** Type to represent the MpIeee floating-point rounding modes.
 **/
typedef enum    FP_Rnd {
  FP_RN = 0, ///< round to nearest representable number
  FP_RZ = 1, ///< round toward zero (truncate)
  FP_RP = 2, ///< round toward plus infinity
  FP_RM = 3  ///< round toward minus infinity
} fp_rnd;

/**
 ** Type to represent MpIeee floating-point exceptions.
 **/
#define FP_Excep int

/**
 ** @name	MpIeee floating-point exceptions
 **
 ** These exceptions are supported for MpIeee floating point arithmetic.
 **/
/*@{*/
#define FP_IRP	 0x20    ///< irrepresentable result
#define FP_INV   0x10    ///< invalid operation exception
#define FP_OFL   0x08    ///< overflow exception
#define FP_UFL   0x04    ///< underflow exception
#define FP_DZ    0x02    ///< divide-by-zero exception
#define FP_INX   0x01    ///< inexact
#define FP_ALLEX   0x3f  ///< all exceptions
/*@}*/

/**
 ** @name	Hardware type to store MpIeee digits
 **
 ** The user can choose which hardware type is used to store MpIeee digits.
 **/
/*@{*/
// typedef float Digit;
// #define MAX_BITS 24
// #define MAX_RADIX 4096 // Maximum Radix is 2^12 for IEEE single

typedef double Digit;		///< Type to store digits
#define MAX_BITS 53		///< Max. bits that can be stored in a Digit
#define MAX_RADIX 16777216      ///< Maximum Radix is 2^24 for IEEE double

// typedef long double Digit;
// #define MAX_BITS 113
// #define MAX_RADIX pow(2,50)  // Maximum Radix is 2^50 for SUN quadruple

// #define INTTYPE
// typedef long long int Digit;
// #define MAX_BITS 63
// #define MAX_RADIX 2147483647 // Maximum Radix 2^31 for 64-bit signed 
//                              // integer arithmetic
/*@}*/

/// MpIeee floating-point environment
/**
 ** This class takes care of the rounding mode, exception handling,
 ** and misc. settings of the MpIeee floating-point implementation.
 **/
class FPEnv {

public:
  FPEnv();			///< default constructor


  /**
   ** @name	Rounding Control.
   ** @see	FP_Rnd
   ** 
   ** These functions take care of the rounding bits in the control
   ** word.
   **/
  /*@{*/
  void setRound(FP_Rnd rounding);  ///< set rounding mode
  FP_Rnd getRound(void) const;     ///< return current rounding mode
  void switchRound(void);          ///< switches rounding direction
  /*@}*/
  
  /**
   ** @name	Control bit manipulation
   ** @see	FP_Excep
   **
   ** These functions are used to set and monitor the exception control
   ** bits.
   **/
  /*@{*/
  FP_Excep getMask(void) const;    ///< return current exception mask
  void setMask(FP_Excep mask);     ///< set mask, return previous
  /*@}*/

  /**
   ** @name	Status bit manipulation
   ** @see	FP_Excep
   **
   ** These functions manipulate the exception status bits.
   **/
  /*@{*/
  void signalExcep (FP_Excep e);   ///< signal one or more exceptions
  void setExcep(FP_Excep e);       ///< set exception status bits
  FP_Excep getExcep(void) const;   ///< return exception status bits
  void clearExcep(void);           ///< clear exception status bits
  /*@}*/

  /**
   ** @name	Miscellaneous
   **
   ** These functions are used to alter/monitor misc. settings in the
   ** floating-point environment.
   **/
  /*@{*/
  void setRadix(Digit newRadix);	///< set new floating-point radix
  void setPrecision(unsigned int newPrec);///< set new floating-point precision
  void setExpRange(int newL, int newU);	///< set new floating-point exp. range
  void setExpSize(int expSize);		///< set new exponent size (in bits)

  Digit getRadix() const;		///< return floating-point radix
  unsigned int getPrecision() const;	///< return floating-point precision
  int getGlobalL() const;		///< return min. exponent
  int getGlobalU() const;		///< return max. exponent
  /*@}*/

  static const int fpenvLMIN;               // min_exp + 1
  static const int fpenvUMAX;               // max_exp - 1

private:
  Digit fpenvRadix;
  Digit fpenvRadixDiv2;
  Digit fpenvLog2Radix;
  Digit fpenvMaxNorm;
  int fpenvGlobalL;            // min. exp
  int fpenvGlobalU;            // max. exp
  unsigned int fpenvPrecision; // default precision for MpIeee numbers

  FP_Rnd fpenvRounding;
  FP_Excep fpenvExceptions;
  FP_Excep fpenvMask;

  friend class MpIeee;
};

#ifndef OUTLINE
#include "FPEnv.icc"
#endif

#endif /* ARITHMOS_FPENV_H_ */
