
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_SecurityParameters__
#define __gnu_javax_net_ssl_provider_SecurityParameters__

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
              class ContentType;
              class ProtocolVersion;
              class SecurityParameters;
          }
        }
      }
    }
  }
}

class gnu::javax::net::ssl::provider::SecurityParameters : public ::java::lang::Object
{

public:
  virtual JArray< jbyte > * decrypt(JArray< jbyte > *, ::gnu::javax::net::ssl::provider::ProtocolVersion *, ::gnu::javax::net::ssl::provider::ContentType *) = 0;
  virtual JArray< jbyte > * encrypt(JArray< jbyte > *, jint, jint, ::gnu::javax::net::ssl::provider::ContentType *) = 0;
  virtual void reset() = 0;
  virtual ::gnu::javax::net::ssl::provider::ProtocolVersion * getVersion() = 0;
  virtual void setVersion(::gnu::javax::net::ssl::provider::ProtocolVersion *) = 0;
  virtual void setDeflating(jboolean) = 0;
  virtual void setInflating(jboolean) = 0;
  virtual jint getFragmentLength() = 0;
  virtual void setFragmentLength(jint) = 0;
  virtual void setInCipher(::java::lang::Object *) = 0;
  virtual void setOutCipher(::java::lang::Object *) = 0;
  virtual void setInMac(::java::lang::Object *) = 0;
  virtual void setOutMac(::java::lang::Object *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __gnu_javax_net_ssl_provider_SecurityParameters__