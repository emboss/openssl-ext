/*
 * $Id: ossl.c 30174 2010-12-10 23:13:47Z drbrain $
 * 'OpenSSL for Ruby' project
 * Copyright (C) 2001-2002  Michal Rokos <m.rokos@sh.cvut.cz>
 * All rights reserved.
 */
/*
 * This program is licenced under the same licence as Ruby.
 * (See the file 'LICENCE'.)
 */
#include "ossl-int.h"
#include <stdarg.h> /* for ossl_raise */

void Init_ext(void)
{
    /*
     * Init components
     */
    Init_ossl_ts();

}
