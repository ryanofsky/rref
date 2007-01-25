
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_GNUSecurityParameters__
#define __gnu_javax_net_ssl_provider_GNUSecurityParameters__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace security
      {
        namespace prng
        {
            class IRandom;
        }
      }
    }
    namespace javax
    {
      namespace crypto
      {
        namespace mac
        {
            class IMac;
        }
        namespace mode
        {
            class IMode;
        }
      }
      namespace net
      {
        namespace ssl
        {
          namespace provider
          {
              class ContentType;
              class GNUSecurityParameters;
              class ProtocolVersion;
              class Session;
          }
        }
      }
    }
  }
}

class gnu::javax::net::ssl::provider::GNUSecurityParameters : public ::java::lang::Object
{

public: // actually package-private
  GNUSecurityParameters(::gnu::javax::net::ssl::provider::Session *);
public:
  virtual void reset();
  virtual ::gnu::javax::net::ssl::provider::ProtocolVersion * getVersion();
  virtual void setVersion(::gnu::javax::net::ssl::provider::ProtocolVersion *);
  virtual void setInCipher(::java::lang::Object *);
  virtual void setOutCipher(::java::lang::Object *);
  virtual void setInMac(::java::lang::Object *);
  virtual void setOutMac(::java::lang::Object *);
  virtual void setDeflating(jboolean);
  virtual void setInflating(jboolean);
  virtual jint getFragmentLength();
  virtual void setFragmentLength(jint);
  virtual JArray< jbyte > * decrypt(JArray< jbyte > *, ::gnu::javax::net::ssl::provider::ProtocolVersion *, ::gnu::javax::net::ssl::provider::ContentType *);
  virtual JArray< jbyte > * encrypt(JArray< jbyte > *, jint, jint, ::gnu::javax::net::ssl::provider::ContentType *);
private:
  static void transformRC4(JArray< jbyte > *, jint, jint, JArray< jbyte > *, jint, ::gnu::java::security::prng::IRandom *);
  static const jboolean DEBUG_RECORD_LAYER = 0;
  static ::java::io::PrintWriter * debug;
public: // actually package-private
  ::gnu::javax::crypto::mode::IMode * __attribute__((aligned(__alignof__( ::java::lang::Object)))) inCipher;
  ::gnu::javax::crypto::mode::IMode * outCipher;
  ::gnu::java::security::prng::IRandom * inRandom;
  ::gnu::java::security::prng::IRandom * outRandom;
  ::gnu::javax::crypto::mac::IMac * inMac;
  ::gnu::javax::crypto::mac::IMac * outMac;
  jlong inSequence;
  jlong outSequence;
  ::gnu::javax::net::ssl::provider::Session * session;
  ::gnu::javax::net::ssl::provider::ProtocolVersion * version;
  jint fragmentLength;
private:
  ::java::util::zip::Inflater * inflater;
  ::java::util::zip::Deflater * deflater;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_GNUSecurityParameters__
