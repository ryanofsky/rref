
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_net_URLClassLoader$FileURLLoader__
#define __java_net_URLClassLoader$FileURLLoader__

#pragma interface

#include <java/net/URLClassLoader$URLLoader.h>
extern "Java"
{
  namespace java
  {
    namespace net
    {
        class URL;
        class URLClassLoader;
        class URLClassLoader$FileURLLoader;
        class URLClassLoader$Resource;
    }
  }
}

class java::net::URLClassLoader$FileURLLoader : public ::java::net::URLClassLoader$URLLoader
{

public: // actually package-private
  URLClassLoader$FileURLLoader(::java::net::URLClassLoader *, ::java::net::URL *, ::java::net::URL *);
  ::java::net::URLClassLoader$Resource * getResource(::java::lang::String *);
  ::java::io::File * __attribute__((aligned(__alignof__( ::java::net::URLClassLoader$URLLoader)))) dir;
public:
  static ::java::lang::Class class$;
};

#endif // __java_net_URLClassLoader$FileURLLoader__
