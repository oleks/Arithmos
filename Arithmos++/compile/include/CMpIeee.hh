/**
 ** @file     CMpIeee.hh
 ** @brief    Multiprecision complex floating-point software library
 **
 ** $Id: CMpIeee.hh,v 1.4 2001/04/30 07:32:56 backelj Exp $
 ** $Date: 2001/04/30 07:32:56 $
 ** $Author: backelj $
 **/

#ifndef _ARITHMOS_CMPIEEE_H_
#define _ARITHMOS_CMPIEEE_H_

#include <MpIeee.hh>
#include <IMpIeee.hh>

class TmpCMpIeee; // forward declaration

/**
 ** @brief    The CMpIeee class
 **/
 
class CMpIeee
{
  friend class TmpCMpIeee;
  
public:
  
  /**
   ** @name    Constructors
   **/
  /*@{*/
  CMpIeee ();

  CMpIeee ( unsigned int prec, unsigned int expSize );
  CMpIeee ( unsigned int prec, int l, int u );
  
  CMpIeee ( const MpIeee &a, const MpIeee &b );
  /*@}*/
  
  /**
   ** @name    Copy constructors
   **/
  /*@{*/
  CMpIeee ( const CMpIeee &y ); // verbatim copy
  CMpIeee ( const TmpCMpIeee &t ); // assumption initializer
  /*@}*/
  
  // destructor
  ~CMpIeee();
  
  /**
   ** @name    Assignment operators
   **/
  /*@{*/
  void operator = ( const CMpIeee& y ); // verbatim assignment
  void operator = ( const TmpCMpIeee& t ); // copy-by-assumption
  /*@}*/
  
  /**
   ** @name    Unary arithmetical operators
   **/
  /*@{*/
  void operator += ( const CMpIeee& y );
  void operator -= ( const CMpIeee& y );
  void operator *= ( const CMpIeee& y );
  void operator /= ( const CMpIeee& y );
  /*@{*/
  
  /**
   ** @name    Basic arithmetical operations
   **/
  /*@{*/
  friend void cadd ( CMpIeee& z, const CMpIeee& x, const CMpIeee& y );
  friend void csub ( CMpIeee& z, const CMpIeee& x, const CMpIeee& y );
  friend void cmul ( CMpIeee& z, const CMpIeee& x, const CMpIeee& y );
  friend void cdiv ( CMpIeee& z, const CMpIeee& x, const CMpIeee& y );
  /*@}*/

  /**
   ** @name    Relational operators
   **/
  /*{@*/
  int operator == ( const CMpIeee& y ) const;
  int operator != ( const CMpIeee& y ) const;
  /*@}*/

  /**
   ** @name    String operations
   **/
  /*@{*/
  void fromDecimal ( const char *decimal ); 
  void toDecimal ( char *decimal, unsigned int prec );
  /*@}*/

  /**
   ** @name    Output operations
   **/
  /*@{*/
  friend ostream& operator << ( ostream& o, const CMpIeee& x );
  friend void outputParameters ( ostream& o, const CMpIeee& x );
  friend void outputDecimal ( ostream& o, const CMpIeee& x );
  friend void outputBinary ( ostream& o, const CMpIeee& x );
  friend void outputBinaryRep ( ostream& o, const CMpIeee& x );
  friend void outputHexadecimalRep ( ostream& o, const CMpIeee& x );
  /*@}*/
  
  /**
   ** @name    Special representations
   **/
  /*@{*/
  int isZero () const;
  int isInf () const;
  int isNan () const;
  /*@}*/
    
  /**
   ** @name    Auxiliary member functions
   **/
  /*{@*/
  friend void creal ( MpIeee &c, const CMpIeee& x );
  TmpMpIeee creal() const;
  
  friend void cimag ( MpIeee &c, const CMpIeee& x );
  TmpMpIeee cimag() const;

  unsigned int prec() const;
  /*@}*/
#ifndef _WINDOWS_MSVC_    
private:
#else
protected:
#endif

  MpIeee *re; // real part
  MpIeee *im; // imaginary part

  // auxiliary functions for cmul and cdiv
  
  static void mulAdd ( MpIeee& c, Digit sticky, MpIeee& a, MpIeee& b, unsigned int prec );
  static void mulSub ( MpIeee& c, Digit sticky, MpIeee& a, MpIeee& b, unsigned int prec );
  static void mulRound ( MpIeee& c, const MpIeee& a, Digit sticky, unsigned int prec );
  static void mulRecover ( CMpIeee& z, const CMpIeee& x, const CMpIeee& y );
  static void divRound ( const IMpIeee& i, MpIeee& result, bool ok );

}; // CMpIeee

/**
 ** @name    Binary arithmetical operators
 **/
/*@{*/
TmpCMpIeee operator + ( const CMpIeee& x, const CMpIeee& y );
TmpCMpIeee operator + ( const CMpIeee& x, const TmpCMpIeee& t );
TmpCMpIeee operator + ( const TmpCMpIeee& s, const CMpIeee& y );
TmpCMpIeee operator + ( const TmpCMpIeee& s, const TmpCMpIeee& t );

TmpCMpIeee operator - ( const CMpIeee& x, const CMpIeee& y );
TmpCMpIeee operator - ( const CMpIeee& x, const TmpCMpIeee& t );
TmpCMpIeee operator - ( const TmpCMpIeee& s, const CMpIeee& y );
TmpCMpIeee operator - ( const TmpCMpIeee& s, const TmpCMpIeee& t );

TmpCMpIeee operator * ( const CMpIeee& x, const CMpIeee& y );
TmpCMpIeee operator * ( const CMpIeee& x, const TmpCMpIeee& t );
TmpCMpIeee operator * ( const TmpCMpIeee& s, const CMpIeee& y );
TmpCMpIeee operator * ( const TmpCMpIeee& s, const TmpCMpIeee& t );

TmpCMpIeee operator / ( const CMpIeee& x, const CMpIeee& y );
TmpCMpIeee operator / ( const CMpIeee& x, const TmpCMpIeee& t );
TmpCMpIeee operator / ( const TmpCMpIeee& s, const CMpIeee& y );
TmpCMpIeee operator / ( const TmpCMpIeee& s, const TmpCMpIeee& t );
/*@}*/

/**
 ** @name    Auxiliary functions
 **/
/*@{*/
TmpMpIeee creal( const CMpIeee& x );
TmpMpIeee cimag( const CMpIeee& x );

unsigned int prec ( const CMpIeee& x );
/*@}*/

#include "TmpCMpIeee.hh"

#ifndef OUTLINE
#include "CMpIeee.icc"
#endif

#endif /* _ARITHMOS_CMPIEEE_H_ */
