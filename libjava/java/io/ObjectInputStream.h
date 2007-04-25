
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_io_ObjectInputStream__
#define __java_io_ObjectInputStream__

#pragma interface

#include <java/io/InputStream.h>
#include <gcj/array.h>


class java::io::ObjectInputStream : public ::java::io::InputStream
{

public:
  ObjectInputStream(::java::io::InputStream *);
  virtual ::java::lang::Object * readObject();
private:
  ::java::lang::Object * parseContent(jbyte);
  void checkTypeConsistency(::java::lang::String *, JArray< ::java::io::ObjectStreamField * > *, JArray< ::java::io::ObjectStreamField * > *);
public: // actually protected
  virtual ::java::io::ObjectStreamClass * readClassDescriptor();
public:
  virtual void defaultReadObject();
  virtual void registerValidation(::java::io::ObjectInputValidation *, jint);
public: // actually protected
  virtual ::java::lang::Class * resolveClass(::java::io::ObjectStreamClass *);
private:
  ::java::lang::ClassLoader * currentLoader();
  ::java::io::ObjectStreamClass * lookupClass(::java::lang::Class *);
  JArray< ::java::io::ObjectStreamClass * > * hierarchy(::java::lang::Class *);
public: // actually protected
  virtual ::java::lang::Object * resolveObject(::java::lang::Object *);
  virtual ::java::lang::Class * resolveProxyClass(JArray< ::java::lang::String * > *);
  virtual jboolean enableResolveObject(jboolean);
  virtual void readStreamHeader();
public:
  virtual jint read();
  virtual jint read(JArray< jbyte > *, jint, jint);
  virtual jint available();
  virtual void close();
  virtual jboolean readBoolean();
  virtual jbyte readByte();
  virtual jint readUnsignedByte();
  virtual jshort readShort();
  virtual jint readUnsignedShort();
  virtual jchar readChar();
  virtual jint readInt();
  virtual jlong readLong();
  virtual jfloat readFloat();
  virtual jdouble readDouble();
  virtual void readFully(JArray< jbyte > *);
  virtual void readFully(JArray< jbyte > *, jint, jint);
  virtual jint skipBytes(jint);
  virtual ::java::lang::String * readLine();
  virtual ::java::lang::String * readUTF();
  virtual ::java::io::ObjectInputStream$GetField * readFields();
public: // actually protected
  ObjectInputStream();
  virtual ::java::lang::Object * readObjectOverride();
private:
  jint assignNewHandle(::java::lang::Object *);
  void rememberHandle(::java::lang::Object *, jint);
  ::java::lang::Object * lookupHandle(jint);
  ::java::lang::Object * processResolution(::java::io::ObjectStreamClass *, ::java::lang::Object *, jint);
  void clearHandles();
  void readNextBlock();
  void readNextBlock(jbyte);
  void readArrayElements(::java::lang::Object *, ::java::lang::Class *);
  void readFields(::java::lang::Object *, ::java::io::ObjectStreamClass *);
  jboolean setBlockDataMode(jboolean);
  ::java::lang::Object * newObject(::java::lang::Class *, ::java::lang::reflect::Constructor *);
  void invokeValidators();
  void callReadMethod(::java::lang::reflect::Method *, ::java::lang::Class *, ::java::lang::Object *);
  void dumpElement(::java::lang::String *);
  void dumpElementln(::java::lang::String *);
  void dumpElementln(::java::lang::String *, ::java::lang::Object *);
  static const jint BUFFER_SIZE = 1024;
  ::java::io::DataInputStream * __attribute__((aligned(__alignof__( ::java::io::InputStream)))) realInputStream;
  ::java::io::DataInputStream * dataInputStream;
  ::java::io::DataInputStream * blockDataInput;
  jint blockDataPosition;
  jint blockDataBytes;
  JArray< jbyte > * blockData;
  jboolean useSubclassMethod;
  jint nextOID;
  jboolean resolveEnabled;
  ::java::util::Vector * objectLookupTable;
  ::java::lang::Object * currentObject;
  ::java::io::ObjectStreamClass * currentObjectStreamClass;
  ::java::util::TreeSet * currentObjectValidators;
  jboolean readDataFromBlock;
  jboolean fieldsAlreadyRead;
  ::java::util::Hashtable * classLookupTable;
  ::java::io::ObjectInputStream$GetField * prereadFields;
  static jboolean dump;
  jint depth;
  static const jboolean DEBUG = 0;
public:
  static ::java::lang::Class class$;
};

#endif // __java_io_ObjectInputStream__
