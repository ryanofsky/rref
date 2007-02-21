
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_text_DateFormat__
#define __java_text_DateFormat__

#pragma interface

#include <java/text/Format.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace text
    {
        class DateFormat;
        class FieldPosition;
        class NumberFormat;
        class ParsePosition;
    }
  }
}

class java::text::DateFormat : public ::java::text::Format
{

public: // actually protected
  DateFormat();
public:
  virtual jboolean equals(::java::lang::Object *);
  virtual ::java::lang::Object * clone();
  virtual ::java::lang::StringBuffer * format(::java::lang::Object *, ::java::lang::StringBuffer *, ::java::text::FieldPosition *);
  virtual ::java::lang::String * format(::java::util::Date *);
  virtual ::java::lang::StringBuffer * format(::java::util::Date *, ::java::lang::StringBuffer *, ::java::text::FieldPosition *) = 0;
  static JArray< ::java::util::Locale * > * getAvailableLocales();
  virtual ::java::util::Calendar * getCalendar();
private:
  static ::java::text::DateFormat * computeInstance(jint, ::java::util::Locale *, jboolean, jboolean);
  static ::java::text::DateFormat * computeInstance(jint, jint, ::java::util::Locale *, jboolean, jboolean);
public:
  static ::java::text::DateFormat * getDateInstance();
  static ::java::text::DateFormat * getDateInstance(jint);
  static ::java::text::DateFormat * getDateInstance(jint, ::java::util::Locale *);
  static ::java::text::DateFormat * getDateTimeInstance();
  static ::java::text::DateFormat * getDateTimeInstance(jint, jint);
  static ::java::text::DateFormat * getDateTimeInstance(jint, jint, ::java::util::Locale *);
  static ::java::text::DateFormat * getInstance();
  virtual ::java::text::NumberFormat * getNumberFormat();
  static ::java::text::DateFormat * getTimeInstance();
  static ::java::text::DateFormat * getTimeInstance(jint);
  static ::java::text::DateFormat * getTimeInstance(jint, ::java::util::Locale *);
  virtual ::java::util::TimeZone * getTimeZone();
  virtual jint hashCode();
  virtual jboolean isLenient();
  virtual ::java::util::Date * parse(::java::lang::String *);
  virtual ::java::util::Date * parse(::java::lang::String *, ::java::text::ParsePosition *) = 0;
  virtual ::java::lang::Object * parseObject(::java::lang::String *, ::java::text::ParsePosition *);
  virtual void setCalendar(::java::util::Calendar *);
  virtual void setLenient(jboolean);
  virtual void setNumberFormat(::java::text::NumberFormat *);
  virtual void setTimeZone(::java::util::TimeZone *);
private:
  static const jlong serialVersionUID = 7218322306649953788LL;
public: // actually protected
  ::java::util::Calendar * __attribute__((aligned(__alignof__( ::java::text::Format)))) calendar;
  ::java::text::NumberFormat * numberFormat;
public:
  static const jint FULL = 0;
  static const jint LONG = 1;
  static const jint MEDIUM = 2;
  static const jint SHORT = 3;
  static const jint DEFAULT = 2;
  static const jint ERA_FIELD = 0;
  static const jint YEAR_FIELD = 1;
  static const jint MONTH_FIELD = 2;
  static const jint DATE_FIELD = 3;
  static const jint HOUR_OF_DAY1_FIELD = 4;
  static const jint HOUR_OF_DAY0_FIELD = 5;
  static const jint MINUTE_FIELD = 6;
  static const jint SECOND_FIELD = 7;
  static const jint MILLISECOND_FIELD = 8;
  static const jint DAY_OF_WEEK_FIELD = 9;
  static const jint DAY_OF_YEAR_FIELD = 10;
  static const jint DAY_OF_WEEK_IN_MONTH_FIELD = 11;
  static const jint WEEK_OF_YEAR_FIELD = 12;
  static const jint WEEK_OF_MONTH_FIELD = 13;
  static const jint AM_PM_FIELD = 14;
  static const jint HOUR1_FIELD = 15;
  static const jint HOUR0_FIELD = 16;
  static const jint TIMEZONE_FIELD = 17;
  static const jint ISO_YEAR_FIELD = 18;
  static const jint LOCALIZED_DAY_OF_WEEK_FIELD = 19;
  static const jint EXTENDED_YEAR_FIELD = 20;
  static const jint MODIFIED_JULIAN_DAY_FIELD = 21;
  static const jint MILLISECOND_IN_DAY_FIELD = 22;
  static const jint RFC822_TIMEZONE_FIELD = 23;
  static ::java::lang::Class class$;
};

#endif // __java_text_DateFormat__