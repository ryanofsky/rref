
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_JCESecurityParameters__
#define __gnu_javax_net_ssl_provider_JCESecurityParameters__

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
              class JCESecurityParameters;
              class ProtocolVersion;
          }
        }
      }
    }
  }
  namespace javax
  {
    namespace crypto
    {
        class Cipher;
        class Mac;
    }
  }
}

class gnu::javax::net::ssl::provider::JCESecurityParameters : public ::java::lang::Object
{

public: // actually package-private
  JCESecurityParameters();
public:
  virtual void reset();
  virtual void setInCipher(::java::lang::Object *);
  virtual void setOutCipher(::java::lang::Object *);
  virtual void setInMac(::java::lang::Object *);
  virtual void setOutMac(::java::lang::Object *);
  virtual void setDeflating(jboolean);
  virtual void setInflating(jboolean);
  virtual jint getFragmentLength();
  virtual void setFragmentLength(jint);
  virtual ::gnu::javax::net::ssl::provider::ProtocolVersion * getVersion();
  virtual void setVersion(::gnu::javax::net::ssl::provider::ProtocolVersion *);
  virtual JArray< jbyte > * decrypt(JArray< jbyte > *, ::gnu::javax::net::ssl::provider::ProtocolVersion *, ::gnu::javax::net::ssl::provider::ContentType *);
  virtual JArray< jbyte > * encrypt(JArray< jbyte > *, jint, jint, ::gnu::javax::net::ssl::provider::ContentType *);
private:
  ::javax::crypto::Cipher * __attribute__((aligned(__alignof__( ::java::lang::Object)))) inCipher;
  ::javax::crypto::Cipher * outCipher;
  ::javax::crypto::Mac * inMac;
  ::javax::crypto::Mac * outMac;
  ::java::util::zip::Inflater * inflater;
  ::java::util::zip::Deflater * deflater;
  jint fragmentLength;
  jlong inSequence;
  jlong outSequence;
  ::gnu::javax::net::ssl::provider::ProtocolVersion * version;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_JCESecurityParameters__
