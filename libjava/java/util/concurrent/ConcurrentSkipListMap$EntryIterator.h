
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_concurrent_ConcurrentSkipListMap$EntryIterator__
#define __java_util_concurrent_ConcurrentSkipListMap$EntryIterator__

#pragma interface

#include <java/util/concurrent/ConcurrentSkipListMap$Iter.h>

class java::util::concurrent::ConcurrentSkipListMap$EntryIterator : public ::java::util::concurrent::ConcurrentSkipListMap$Iter
{

public: // actually package-private
  ConcurrentSkipListMap$EntryIterator(::java::util::concurrent::ConcurrentSkipListMap *);
public:
  ::java::util::Map$Entry * target$next();
  ::java::lang::Object * next();
public: // actually package-private
  ::java::util::concurrent::ConcurrentSkipListMap * __attribute__((aligned(__alignof__( ::java::util::concurrent::ConcurrentSkipListMap$Iter)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_concurrent_ConcurrentSkipListMap$EntryIterator__
