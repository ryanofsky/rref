
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_concurrent_SynchronousQueue$TransferQueue$QNode__
#define __java_util_concurrent_SynchronousQueue$TransferQueue$QNode__

#pragma interface

#include <java/lang/Object.h>

class java::util::concurrent::SynchronousQueue$TransferQueue$QNode : public ::java::lang::Object
{

public: // actually package-private
  SynchronousQueue$TransferQueue$QNode(::java::lang::Object *, jboolean);
  jboolean casNext(::java::util::concurrent::SynchronousQueue$TransferQueue$QNode *, ::java::util::concurrent::SynchronousQueue$TransferQueue$QNode *);
  jboolean casItem(::java::lang::Object *, ::java::lang::Object *);
  void tryCancel(::java::lang::Object *);
  jboolean isCancelled();
  jboolean isOffList();
  volatile ::java::util::concurrent::SynchronousQueue$TransferQueue$QNode * __attribute__((aligned(__alignof__( ::java::lang::Object)))) next;
  volatile ::java::lang::Object * item;
  volatile ::java::lang::Thread * waiter;
  jboolean isData;
  static ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater * nextUpdater;
  static ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater * itemUpdater;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_concurrent_SynchronousQueue$TransferQueue$QNode__