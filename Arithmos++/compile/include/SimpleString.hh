/******************************************************************************
 **
 ** Arithmos class library
 **
 ** SimpleString : stupid string class
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
 ** @file     SimpleString.hh
 ** @brief    A simple string class
 ** @version  $Id: SimpleString.hh,v 1.4 2001/08/23 13:30:39 sbecuwe Exp $
 ** @date     $Date: 2001/08/23 13:30:39 $
 ** @author   $Author: sbecuwe $
 **
 ** This class is used for the input of the IMpIeee class.  In the
 ** future, it will be used for BigInt input too.
 **/

#ifndef SIMPLESTRING_HH
#define SIMPLESTRING_HH

#include <malloc.h>

#include <iostream.h>


/**
 ** @brief A (very) simple string class.
 **
 ** This class is used for the input of the IMpIeee class.  In the
 ** future, it will be used for BigInt input too.
 **/

class SimpleString
{
public:
    SimpleString( unsigned int size = 30 );
    ~SimpleString();
    unsigned char operator[]( unsigned int i ) const;
    unsigned char& operator[]( unsigned int i );
    operator const char*() const;
    
    void extractNumberFromStream( istream& is );    
    
    static unsigned char mMemoryOverflow;
    
private:
    void resize( unsigned int size );
    unsigned char* mBuffer;
    unsigned int mBufferSize;
};

#ifndef OUTLINE
#include "SimpleString.icc"
#endif
#endif
