
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_XMLSessionContext$SAXHandler__
#define __gnu_javax_net_ssl_provider_XMLSessionContext$SAXHandler__

#pragma interface

#include <org/xml/sax/helpers/DefaultHandler.h>
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
              class Session;
              class SessionContext;
              class XMLSessionContext;
              class XMLSessionContext$SAXHandler;
          }
        }
      }
    }
  }
  namespace org
  {
    namespace xml
    {
      namespace sax
      {
          class Attributes;
      }
    }
  }
}

class gnu::javax::net::ssl::provider::XMLSessionContext$SAXHandler : public ::org::xml::sax::helpers::DefaultHandler
{

public: // actually package-private
  XMLSessionContext$SAXHandler(::gnu::javax::net::ssl::provider::XMLSessionContext *, ::gnu::javax::net::ssl::provider::SessionContext *, ::gnu::java::security::prng::IRandom *);
public:
  virtual void startElement(::java::lang::String *, ::java::lang::String *, ::java::lang::String *, ::org::xml::sax::Attributes *);
  virtual void endElement(::java::lang::String *, ::java::lang::String *, ::java::lang::String *);
  virtual void characters(JArray< jchar > *, jint, jint);
private:
  ::gnu::javax::net::ssl::provider::SessionContext * __attribute__((aligned(__alignof__( ::org::xml::sax::helpers::DefaultHandler)))) context;
  ::gnu::javax::net::ssl::provider::Session * current;
  ::gnu::java::security::prng::IRandom * pbekdf;
  ::java::lang::StringBuffer * buf;
  ::java::lang::String * certType;
  jint state;
  ::gnu::javax::crypto::mode::IMode * cipher;
  ::java::util::HashMap * cipherAttr;
  ::gnu::javax::crypto::mac::IMac * mac;
  ::java::util::HashMap * macAttr;
  JArray< jbyte > * key;
  JArray< jbyte > * iv;
  JArray< jbyte > * mackey;
  static const jint START = 0;
  static const jint SESSIONS = 1;
  static const jint SESSION = 2;
  static const jint PEER = 3;
  static const jint PEER_CERTS = 4;
  static const jint CERTS = 5;
  static const jint SECRET = 6;
public: // actually package-private
  ::gnu::javax::net::ssl::provider::XMLSessionContext * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_XMLSessionContext$SAXHandler__
