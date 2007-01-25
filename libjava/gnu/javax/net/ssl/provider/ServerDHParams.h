
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_ServerDHParams__
#define __gnu_javax_net_ssl_provider_ServerDHParams__

#pragma interface

#include <java/lang/Object.h>
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
              class KeyExchangeAlgorithm;
              class ServerDHParams;
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
    namespace nio
    {
        class ByteBuffer;
    }
  }
}

class gnu::javax::net::ssl::provider::ServerDHParams : public ::java::lang::Object
{

public:
  ServerDHParams(::java::nio::ByteBuffer *);
  ServerDHParams(::java::math::BigInteger *, ::java::math::BigInteger *, ::java::math::BigInteger *);
  virtual ::gnu::javax::net::ssl::provider::KeyExchangeAlgorithm * algorithm();
  virtual jint length();
  virtual ::java::nio::ByteBuffer * buffer();
  virtual ::java::math::BigInteger * p();
  virtual ::java::math::BigInteger * g();
  virtual ::java::math::BigInteger * y();
  virtual void setP(::java::math::BigInteger *);
  virtual void setG(::java::math::BigInteger *);
  virtual void setY(::java::math::BigInteger *);
  virtual ::java::lang::String * toString();
  virtual ::java::lang::String * toString(::java::lang::String *);
private:
  ::java::nio::ByteBuffer * __attribute__((aligned(__alignof__( ::java::lang::Object)))) buffer__;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_ServerDHParams__
