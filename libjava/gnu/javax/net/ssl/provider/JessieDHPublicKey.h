
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_JessieDHPublicKey__
#define __gnu_javax_net_ssl_provider_JessieDHPublicKey__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace net
      {
        namespace ssl
        {
          namespace provider
          {
              class JessieDHPublicKey;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace math
    {
        class BigInteger;
    }
  }
  namespace javax
  {
    namespace crypto
    {
      namespace spec
      {
          class DHParameterSpec;
      }
    }
  }
}

class gnu::javax::net::ssl::provider::JessieDHPublicKey : public ::java::lang::Object
{

public: // actually package-private
  JessieDHPublicKey(::javax::crypto::spec::DHParameterSpec *, ::java::math::BigInteger *);
public:
  virtual ::java::lang::String * getAlgorithm();
  virtual ::java::lang::String * getFormat();
  virtual JArray< jbyte > * getEncoded();
  virtual ::javax::crypto::spec::DHParameterSpec * getParams();
  virtual ::java::math::BigInteger * getY();
  virtual ::java::lang::String * toString();
private:
  ::javax::crypto::spec::DHParameterSpec * __attribute__((aligned(__alignof__( ::java::lang::Object)))) params;
  ::java::math::BigInteger * y;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_JessieDHPublicKey__
