/******************************************************************************
 **
 ** Arithmos class library
 ** 
 ** MpIeee : Multiprecision floating-point software library
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
 ** @file     MpIeee.hh
 ** @brief    Multiprecision floating-point software library
 **
 ** $Id: MpIeee.hh,v 1.40 2001/08/23 13:30:38 sbecuwe Exp $
 ** $Date: 2001/08/23 13:30:38 $
 ** $Author: sbecuwe $
 **/

/*
 * Some notes on the handling of special values.
 *
 * +0, -0, +inf and -inf are represented as in the IEEE 754 standard.
 * All other special values are represented as NaN, with in the second
 * digit the special value bit pattern.
 *
 */
 
#ifndef _ARITHMOS_MPIEEE_H_
#define _ARITHMOS_MPIEEE_H_

#include <iostream.h>
#include <limits.h>
#include <math.h>
#include <FPEnv.hh>
#include <SpecialRounded.hh>

#ifndef _WINDOWS_MSVC_
#define longlong long long
#define ulonglong unsigned long long
#else
#define longlong __int64
#define ulonglong unsigned __int64
#endif

#if defined log2
#undef log2
#endif

#define EXP_BIAS(size)  ((1L<<((unsigned long)(size)-1L))-1L)
#define EXP_U(size)     EXP_BIAS(size)
#define EXP_L(size)     (-(EXP_BIAS(size)-1))


const unsigned int mpBitsPerULong = 8*sizeof( unsigned long );
			/// <number of bits in unsigned long integer.

/** 
 ** @brief  Type for storing the MpIeee sign bit.
 ** @remark The MpIeee sign bit is only used for `standard' floating point 
 **   	    values, i.e. the values described by the IEEE 754 standard.
 **   	    (normals, denormals, +0, -0, +inf, -inf, nan).  If the MpIeee
 **   	    represents another special value (which can be unsigned), the
 **   	    sign bit is ignored.
 **/
typedef enum signs {plus = 0,minus = 1} sign;

/**
 ** @brief   max. nr. of chars for decimal input strings
 ** @remark  also max. decimal exponent 10^e
 **/
#define maxstr 5000

// foreward declarations of four :-) stand-alone inline functions

int PrecisionMismatch();
Digit log2( Digit x );
unsigned int validChar( char c );
unsigned int mpLeadingZeros( unsigned long a );

class TmpMpIeee; // forward declaration

/**
 ** @brief The MpIeee class.
 **
 ** Class for multiprecision floating-point arithmetic.
 **/
class MpIeee {
  friend class TmpMpIeee;

public:
  static class FPEnv fpEnv; ///< floating-point environment

  /**
   ** @name Constructors
   **
   ** These functions create a new MpIeee.  The default
   ** constructor assigns zero to the new MpIeee.
   **/
  /*@{*/
  MpIeee();
  MpIeee( unsigned int prec, unsigned int expSize );
  MpIeee( unsigned int prec, int l, int u );
  MpIeee( int i );
  MpIeee( int i, unsigned int prec, int l, int u );
  MpIeee( long li );
  MpIeee( long li, unsigned int prec, int l, int u );
  MpIeee( unsigned int ui );
  MpIeee( unsigned int ui, unsigned int prec, int l, int u );
  MpIeee( unsigned long ul );
  MpIeee( unsigned long ul, unsigned int prec, int l, int u );
  MpIeee( float f );
  MpIeee( float f, unsigned int prec, int l, int u );
  MpIeee( double d );
  MpIeee( double d, unsigned int prec, int l, int u );
  MpIeee( long double ld );
  MpIeee( long double ld, unsigned int prec, int l, int u );
  MpIeee( const char *s );
  MpIeee( const char *s, unsigned int prec, int l, int u );
  MpIeee( SpecialRounded s );
  MpIeee( SpecialRounded s, unsigned int prec, int l, int u );
  MpIeee( SpecialValue s );
  MpIeee( SpecialValue s, unsigned int prec, int l, int u );
  MpIeee( const MpIeee& R );
  MpIeee( TmpMpIeee& T );
  /*@}*/
  
  /// destructor

  ~MpIeee();

  /**
   ** @name Assignment operators
   **
   ** These functions assign a value to a MpIeee.
   **/
  /*@{*/
  void operator= ( const MpIeee& R );
  void operator= ( TmpMpIeee& T );
  void operator= ( int i );
  void operator= ( unsigned int i );
  void operator= ( long i );
  void operator= ( unsigned long i );
  void operator= ( longlong i );
#ifndef _WINDOWS_MSVC_
  void operator= ( ulonglong i );
#endif
  void operator= ( double d );
  void operator= ( long double l );
  void operator= ( SpecialValue s );
  /*@}*/

  /// MpIeee resize.
  void resize(const unsigned int new_prec); // new precision

  /**
   ** @name Nondestructive arithmetic
   **
   ** Addition, subtraction, multiplication, division,...
   **/
  /*@{*/ 
  friend TmpMpIeee operator+ ( const MpIeee& X, const MpIeee& Y);
  friend TmpMpIeee operator- ( const MpIeee& X, const MpIeee& Y);
  friend TmpMpIeee operator* ( const MpIeee& X, const MpIeee& Y);
  friend TmpMpIeee operator* ( const MpIeee& X, const int i );
  friend TmpMpIeee operator/ ( const MpIeee& X, const MpIeee& Y );
  friend TmpMpIeee operator% ( const MpIeee& X, const MpIeee& Y );
  TmpMpIeee operator-() const;
  TmpMpIeee sqrt() const;

  
  static MpIeee& fastAssign ( const MpIeee& source, MpIeee& destination );
  static MpIeee& add ( const MpIeee& op1, const MpIeee& op2, MpIeee& result );
  static MpIeee& sub ( const MpIeee& op1, const MpIeee& op2, MpIeee& result );
  static MpIeee& mul ( const MpIeee& op1, const MpIeee& op2, MpIeee& result );
  static MpIeee& div ( const MpIeee& op1, const MpIeee& op2, MpIeee& result );


  friend void divJohan( MpIeee& c, const MpIeee& a, const MpIeee& b );
  /*@}*/

  /**
   ** @name Destructive arithmetic
   **
   ** Addition, subtraction, multiplication, division
   **/
  /*@{*/
  void operator+= ( const MpIeee& Y );
  void operator-= ( const MpIeee& Y );
  void operator*= ( const MpIeee& Y );
  void operator/= ( const MpIeee& Y );
  /*@}*/

  /**
   ** @name Relational operators
   **
   ** Functions to compare two MpIeees.
   **/
  /*@{*/
  friend int operator== ( const MpIeee& X, const MpIeee& Y );
  friend int operator!= ( const MpIeee& X, const MpIeee& Y );
  friend int operator>  ( const MpIeee& X, const MpIeee& Y );
  friend int operator<  ( const MpIeee& X, const MpIeee& Y );
  friend int operator>= ( const MpIeee& X, const MpIeee& Y );
  friend int operator<= ( const MpIeee& X, const MpIeee& Y );
  friend int unordered  ( const MpIeee& X, const MpIeee& Y );
  /*@}*/

  /**
   ** @name Elementary functions
   **/
  /*@{*/
  TmpMpIeee sin();
  TmpMpIeee cos();
  TmpMpIeee tan();
  TmpMpIeee cotan();
  TmpMpIeee atan();
  TmpMpIeee acotan();
  TmpMpIeee asin();
  TmpMpIeee acos();
  TmpMpIeee exp();
  TmpMpIeee exp2();
  TmpMpIeee exp10();
  TmpMpIeee sinh();
  TmpMpIeee cosh();
  TmpMpIeee tanh();
  TmpMpIeee cotanh();
  TmpMpIeee arsinh();
  TmpMpIeee arcosh();
  TmpMpIeee artanh();
  TmpMpIeee arcotanh();
  TmpMpIeee ln();
  TmpMpIeee log10();
  TmpMpIeee log2();
  TmpMpIeee pow( unsigned long e ) const;
  TmpMpIeee pow( const MpIeee& Y );
  /*@}*/

  /**
   ** @name Miscellaneous
   **/
  /*@{*/
  void pi();
  void pi2();
  void neg();
  TmpMpIeee abs();
  TmpMpIeee floor() const; 
  TmpMpIeee ceil() const;

  friend void swap( MpIeee& A, MpIeee& B );

  /*@}*/

  /**
   ** @name Conversions
   **/
  /*@{*/
  void fromBinary        ( char* binStr );
  void fromBinaryRep     ( char* binRepStr );
  void fromHexadecimalRep( char* hexRepStr );

  void fromInt   ( int i );
  void fromUint  ( unsigned int ui );
  void fromLong  ( long l );
  void fromUlong ( unsigned long ul );
  void fromLlong ( longlong ll );
#ifndef _WINDOWS_MSVC_
  void fromUllong( ulonglong ull );
#endif
  void fromDouble(long double d);      ///< Actually long double
  float to_float();   	      	       ///< Only in base 2
  double to_double() const;    	       ///< Only in base 2
  void from_double(double d); 	       ///< Only in base 2
  // void frombigint(const bigint&b);
  // void fromrational(const rational&r);
  long toInt32();
  unsigned long toUint32() const;
  longlong toInt64();
  ulonglong toUint64();
  void rint();
  SpecialRounded toSpecial () const;
  /*@}*/

  /**
   ** @name String operations
   **/
  /*@{*/
  void fromDecimal ( const char *decimal ); 
  void toDecimal   ( char *decimal, unsigned int prec );
  /*@}*/

  /// Input from a stream
  friend istream& operator>> ( istream& i, MpIeee& s );

  /**
   ** @name Output operations
   **/
  /*@{*/
  friend ostream& operator<<       ( ostream& o, const MpIeee& s );
  friend void outputParameters     ( ostream& o, const MpIeee& s );
  friend void outputDecimal        ( ostream& o, const MpIeee& s );
  friend void outputBinary         ( ostream& o, const MpIeee& s );
  friend void outputBinaryRep      ( ostream& o, const MpIeee& s );
  friend void outputHexadecimalRep ( ostream& o, const MpIeee& s );
  friend void outputFlags          ( ostream& o, const MpIeee& s );
  /*@}*/

  /**
   ** @name Special representations
   **/
  /*@{*/
  int isZero() const;
  void setZero(sign newsign);
  int isInf() const;
  void setInf(sign newsign);
  int isNan() const;
  int isIeeeNan() const;
  void setNan();
  int isSpecial() const;
  void setSpecial( SpecialValue sv );
  void setMax( sign s );
  /*@}*/

  /**
   ** @name Sign, mantissa and exponent manipulation
   **/
  /*@{*/
  sign getSign() const;
  void setSign(sign newsign);
  int getExp() const;
  void setExp(long int e);
  unsigned int prec() const;
  int getL() const;
  int getU() const;

  Digit& operator[](unsigned int i);
  Digit  operator[](unsigned int i) const;
  /*@}*/

  void round(Digit g, Digit s);
  int isAbsGreater(const MpIeee &Y) const;
  
#ifndef _WINDOWS_MSVC_
private:
#else
protected:
#endif
  int L;			///< minimal exponent
  int U;			///< maximal exponent
  sign          mpSign;         // sign
  int           mpExponent;     // exponent value
  Digit        *mpSignificand;  // pointer to significand digits
  unsigned int  mpPrecision;    // number of digits

  static void iCopy(const Digit *src, Digit *dst, int n);
  unsigned int fillPrecStack(unsigned int prec,unsigned int *nstack);

  // void pow(const MpIeee &X,long unsigned int e); // X^e
  long int log(const MpIeee &X) const; // logX

  void add(const MpIeee &X, const MpIeee &Y, sign newsign);
  void add(MpIeee &Y, unsigned int prec, Digit &extrax1, Digit &extrax2, 
	   Digit &extray1,Digit &extray2);
  void sub(const MpIeee &X, const MpIeee &Y, sign newsign);
  void shortProduct(const MpIeee &X, const MpIeee &Y);
  void mulBy2();
  void mulByShort(const MpIeee &Y);
  void div(const MpIeee &X, const MpIeee &Y);
  unsigned int div2(const MpIeee &X, const MpIeee &Y, unsigned int prec, 
		    Digit &extra1, Digit &extra2);
  void divBy2(unsigned int prec, Digit &extra1, Digit &extra2);

  void dRound(unsigned int precision, Digit ulps);

  double toDigit() const;

  void sqroot(const MpIeee &X);
  void remainder(const MpIeee &X, const MpIeee &Y);

  void sine(const MpIeee &X);
  void cosine(const MpIeee &X);
  void tangent(const MpIeee &X);
  void cotangent(const MpIeee &X);
  void arctangent(const MpIeee &X);
  void arcsine(const MpIeee &X);
  void arccosine(const MpIeee &X);
  void exponential(const MpIeee &X);
  void hyperbolicsine(const MpIeee &X);
  void hyperboliccosine(const MpIeee &X);
  void hyperbolictangent(const MpIeee &X);
  void naturallog(const MpIeee &X);
  void naturallog1(const MpIeee &X); // ln(1+x)
  
  Digit setSticky(const MpIeee &X, unsigned int from);
  
  friend double testMpIeee();	/* Debugging purposes */
};


TmpMpIeee abs(MpIeee &X);
TmpMpIeee acos(MpIeee &X);
TmpMpIeee acotan(MpIeee &X);
TmpMpIeee arcosh(MpIeee &X);
TmpMpIeee arcotanh(MpIeee &X);
TmpMpIeee arsinh(MpIeee &X);
TmpMpIeee artanh(MpIeee &X);
TmpMpIeee asin(MpIeee &X);
TmpMpIeee atan(MpIeee &X);
TmpMpIeee ceil(const MpIeee &X); 
TmpMpIeee cos(MpIeee &X);
TmpMpIeee cosh(MpIeee &X);
TmpMpIeee cotan(MpIeee &X);
TmpMpIeee exp(MpIeee &X);
TmpMpIeee exp2(MpIeee &X);
TmpMpIeee exp10(MpIeee &X);
TmpMpIeee floor(const MpIeee &X); 
TmpMpIeee ln(MpIeee &X);
TmpMpIeee log2(MpIeee &X);
TmpMpIeee log10(MpIeee &X);
TmpMpIeee pow(MpIeee &X,const MpIeee &Y);
TmpMpIeee sin(MpIeee &X);
TmpMpIeee sinh(MpIeee &X);
TmpMpIeee sqrt(MpIeee &X);
TmpMpIeee tan(MpIeee &X);
TmpMpIeee tanh(MpIeee &X);

TmpMpIeee prev(MpIeee &X);
TmpMpIeee next(MpIeee &X);

TmpMpIeee poweri(const MpIeee &X,int i);
TmpMpIeee neg(MpIeee &X);

MpIeee e(unsigned int newprec);  // return e
MpIeee one(unsigned int newprec); // return 1
MpIeee ln10(unsigned int newprec);
MpIeee lnradix();

#include "TmpMpIeee.hh"

#ifndef OUTLINE
#include "MpIeee.icc"
#endif

#endif /* _ARITHMOS_MPIEEE_H_ */
