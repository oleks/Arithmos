/******************************************************************************
**
** Arithmos class library
** 
** ArithmosIO : class for manipulating I/O in the Arithmos class library
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


#ifndef _ARITHMOS_IO_H_
#define _ARITHMOS_IO_H_

#define ARITHMOS_IO_MPIEEE_PARAM        0x00000001
#define ARITHMOS_IO_MPIEEE_DECIMAL      0x00000002
#define ARITHMOS_IO_MPIEEE_BINARY       0x00000004
#define ARITHMOS_IO_MPIEEE_BINREP       0x00000008
#define ARITHMOS_IO_MPIEEE_HEXREP       0x00000010
#define ARITHMOS_IO_MPIEEE_FLAGS        0x00000020
#define ARITHMOS_IO_MPIEEE_RATIONAL     0x00000040

#define ARITHMOS_IO_IMPIEEE_PARAM       0x00000080
#define ARITHMOS_IO_IMPIEEE_DECIMAL     0x00000100
#define ARITHMOS_IO_IMPIEEE_BINARY      0x00000200
#define ARITHMOS_IO_IMPIEEE_BINREP      0x00000400
#define ARITHMOS_IO_IMPIEEE_HEXREP      0x00000800

#define ARITHMOS_IO_CMPIEEE_PARAM       0x00001000
#define ARITHMOS_IO_CMPIEEE_DECIMAL     0x00002000
#define ARITHMOS_IO_CMPIEEE_BINARY      0x00004000
#define ARITHMOS_IO_CMPIEEE_BINREP      0x00008000
#define ARITHMOS_IO_CMPIEEE_HEXREP      0x00010000

#define ARITHMOS_IO_RATIONAL_DECIMAL    0x00020000
#define ARITHMOS_IO_RATIONAL_BINREP     0x00040000
#define ARITHMOS_IO_RATIONAL_RATIONAL   0x00080000
#define ARITHMOS_IO_RATIONAL_FLAGS      0x00100000

#define ARITHMOS_IO_DEBUG               0x40000000
#define ARITHMOS_IO_VERBOSE             0x80000000

#define ARITHMOS_IO_DEFAULT             ( ARITHMOS_IO_MPIEEE_DECIMAL | \
                                          ARITHMOS_IO_IMPIEEE_DECIMAL | \
                                          ARITHMOS_IO_RATIONAL_RATIONAL )

class ArithmosIO {
 public:
  static void setIoMode(long newMode);
  static long getIoMode(void);
  static void setDefaultMode(void);

  friend void debugInfo(char*);

 protected:
  static long ioMode;
};


#ifndef OUTLINE
#include "ArithmosIO.icc"
#endif


#endif /* _ARITHMOS_IO_H_ */
