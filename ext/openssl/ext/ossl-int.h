/*
 *
 * Copyright (C) 2010 Martin Bosslet <Martin.Bosslet@googlemail.com>
 * All rights reserved.
 */
/*
 * This program is licenced under the same licence as Ruby.
 * (See the file 'LICENCE'.)
 */
#if !defined(_OSSL_INT_H_)
#define _OSSL_INT_H_

#include RUBY_EXTCONF_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <ruby.h>
#include <ruby/io.h>

#include <openssl/opensslv.h>

#ifdef HAVE_ASSERT_H
#  include <assert.h>
#else
#  define assert(condition)
#endif

#if defined(_WIN32)
#  define OSSL_NO_CONF_API 1
#  include <winsock2.h>
#endif
#include <errno.h>
#include <openssl/err.h>
#include <openssl/asn1_mac.h>
#include <openssl/x509v3.h>
#include <openssl/ssl.h>
#include <openssl/pkcs12.h>
#include <openssl/pkcs7.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#include <openssl/ts.h>
#include <openssl/ocsp.h>

/*
 * Main Module
 */
extern VALUE mOSSL;

/*
 * Common Error Classes
 */
extern VALUE eOSSLError;
extern VALUE eASN1Error;
extern VALUE eX509AttrError;

/*
 * OpenSSL classes
 */
extern VALUE cX509Cert;
extern VALUE cPKCS7;


/*
 * CheckTypes
 */
#define OSSL_Check_Kind(obj, klass) do {\
  if (!rb_obj_is_kind_of(obj, klass)) {\
    ossl_raise(rb_eTypeError, "wrong argument (%s)! (Expected kind of %s)",\
               rb_obj_classname(obj), rb_class2name(klass));\
  }\
} while (0)

#define OSSL_Check_Instance(obj, klass) do {\
  if (!rb_obj_is_instance_of(obj, klass)) {\
    ossl_raise(rb_eTypeError, "wrong argument (%s)! (Expected instance of %s)",\
               rb_obj_classname(obj), rb_class2name(klass));\
  }\
} while (0)

#define OSSL_Check_Same_Class(obj1, obj2) do {\
  if (!rb_obj_is_instance_of(obj1, rb_obj_class(obj2))) {\
    ossl_raise(rb_eTypeError, "wrong argument type");\
  }\
} while (0)


#define ossl_str_adjust(str, p) \
do{\
    int len = RSTRING_LEN(str);\
    int newlen = (p) - (unsigned char*)RSTRING_PTR(str);\
    assert(newlen <= len);\
    rb_str_set_len(str, newlen);\
}while(0)

/*
 * Common functions
 */
extern NORETURN(void ossl_raise(VALUE, const char *, ...));
extern VALUE ossl_exc_new(VALUE, const char *, ...);

/*
 * ASN.1 functions
 */

/*
 * ASN1_DATE conversions
 */
extern VALUE asn1time_to_time(ASN1_TIME *);
extern time_t time_to_time_t(VALUE);

/*
 * ASN1_STRING conversions
 */
extern VALUE asn1str_to_str(ASN1_STRING *);

/*
 * ASN1_INTEGER conversions
 */
extern VALUE asn1integer_to_num(ASN1_INTEGER *);
extern ASN1_INTEGER *num_to_asn1integer(VALUE, ASN1_INTEGER *);

/*
 * BIO helper functions
 */
extern BIO *ossl_obj2bio(VALUE);
extern BIO *ossl_protect_obj2bio(VALUE,int*);
extern VALUE ossl_membio2str0(BIO*);
extern VALUE ossl_membio2str(BIO*);
extern VALUE ossl_protect_membio2str(BIO*,int*);

/*
 * X509 functions
 */
extern VALUE ossl_x509_new(X509 *);
extern VALUE ossl_x509_new_from_file(VALUE);
extern X509 *GetX509CertPtr(VALUE);
extern X509 *DupX509CertPtr(VALUE);

/*
 * PKey functions
 */
extern VALUE ossl_pkey_new(EVP_PKEY *);
extern VALUE ossl_pkey_new_from_file(VALUE);
extern EVP_PKEY *GetPKeyPtr(VALUE);
extern EVP_PKEY *DupPKeyPtr(VALUE);
extern EVP_PKEY *GetPrivPKeyPtr(VALUE);
extern EVP_PKEY *DupPrivPKeyPtr(VALUE);

extern VALUE ossl_to_der(VALUE);
extern VALUE ossl_to_der_if_possible(VALUE);

/*
 * Include all parts
 */
#include "ossl_ts.h"

void Init_openssl_ext(void);

#if defined(__cplusplus)
}
#endif

#endif /* _OSSL_INT_H_ */

