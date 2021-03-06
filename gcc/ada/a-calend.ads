------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                         A D A . C A L E N D A R                          --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--          Copyright (C) 1992-2006, Free Software Foundation, Inc.         --
--                                                                          --
-- This specification is derived from the Ada Reference Manual for use with --
-- GNAT. The copyright notice above, and the license provisions that follow --
-- apply solely to the  contents of the part following the private keyword. --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNAT;  see file COPYING.  If not, write --
-- to  the  Free Software Foundation,  51  Franklin  Street,  Fifth  Floor, --
-- Boston, MA 02110-1301, USA.                                              --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

package Ada.Calendar is

   type Time is private;

   --  Declarations representing limits of allowed local time values. Note that
   --  these do NOT constrain the possible stored values of time which may well
   --  permit a larger range of times (this is explicitly allowed in Ada 95).

   subtype Year_Number  is Integer range 1901 .. 2399;
   subtype Month_Number is Integer range 1 .. 12;
   subtype Day_Number   is Integer range 1 .. 31;

   --  A Day_Duration value of 86_400.0 designates a new day

   subtype Day_Duration is Duration range 0.0 .. 86_400.0;

   function Clock return Time;
   --  The returned time value is the number of nanoseconds since the start
   --  of Ada time (1901-1-1 0.0 GMT).

   function Year    (Date : Time) return Year_Number;
   function Month   (Date : Time) return Month_Number;
   function Day     (Date : Time) return Day_Number;
   function Seconds (Date : Time) return Day_Duration;

   procedure Split
     (Date    : Time;
      Year    : out Year_Number;
      Month   : out Month_Number;
      Day     : out Day_Number;
      Seconds : out Day_Duration);
   --  Break down a time value into its date components set in the current
   --  time zone. If Split is called on a time value created using Ada 2005
   --  Time_Of in some arbitrary time zone, the input value always will be
   --  interpreted as some point in time relative to the local time zone.

   function Time_Of
     (Year    : Year_Number;
      Month   : Month_Number;
      Day     : Day_Number;
      Seconds : Day_Duration := 0.0) return Time;
   --  GNAT Note: Normally when procedure Split is called on a Time value
   --  result of a call to function Time_Of, the out parameters of procedure
   --  Split are identical to the in parameters of function Time_Of. However,
   --  when a non-existent time of day is specified, the values for Seconds
   --  may or may not be different. This may happen when Daylight Saving Time
   --  (DST) is in effect, on the day when switching to DST, if Seconds
   --  specifies a time of day in the hour that does not exist. For example,
   --  in New York:
   --
   --    Time_Of (Year => 1998, Month => 4, Day => 5, Seconds => 10740.0)
   --
   --  will return a Time value T. If Split is called on T, the resulting
   --  Seconds may be 14340.0 (3:59:00) instead of 10740.0 (2:59:00 being
   --  a time that not exist).

   function "+" (Left : Time;     Right : Duration) return Time;
   function "+" (Left : Duration; Right : Time)     return Time;
   function "-" (Left : Time;     Right : Duration) return Time;
   function "-" (Left : Time;     Right : Time)     return Duration;
   --  The first three functions will raise Time_Error if the resulting time
   --  value is less than the start of Ada time in GMT or greater than the
   --  end of Ada time in GMT. The last function will raise Time_Error if the
   --  resulting difference cannot fit into a duration value.

   function "<"  (Left, Right : Time) return Boolean;
   function "<=" (Left, Right : Time) return Boolean;
   function ">"  (Left, Right : Time) return Boolean;
   function ">=" (Left, Right : Time) return Boolean;

   Time_Error : exception;

private
   pragma Inline (Clock);

   pragma Inline (Year);
   pragma Inline (Month);
   pragma Inline (Day);

   pragma Inline ("+");
   pragma Inline ("-");

   pragma Inline ("<");
   pragma Inline ("<=");
   pragma Inline (">");
   pragma Inline (">=");

   --  The units used in this version of Ada.Calendar are nanoseconds. The
   --  following constants provide values used in conversions of seconds or
   --  days to the underlying units.

   Nano         : constant := 1_000_000_000;
   Nano_F       : constant := 1_000_000_000.0;
   Nanos_In_Day : constant := 86_400_000_000_000;
   Secs_In_Day  : constant := 86_400;

   ----------------------------
   -- Implementation of Time --
   ----------------------------

   --  Time is represented as an unsigned 64 bit integer count of nanoseconds
   --  since the start of Ada time (1901-1-1 0.0 GMT). Time values produced
   --  by Time_Of are internaly normalized to GMT regardless of their local
   --  time zone. This representation ensures correct handling of leap seconds
   --  as well as performing arithmetic. In Ada 95, Split will treat a time
   --  value as being in the local time zone and break it down accordingly.
   --  In Ada 2005, Split will treat a time value as being in the designated
   --  time zone by the corresponding formal parameter or in GMT by default.
   --  The size of the type is large enough to cover the Ada 2005 range of
   --  time (1901-1-1 0.0 GMT - 2399-12-31-86_399.999999999 GMT).

   ------------------
   -- Leap seconds --
   ------------------

   --  Due to Earth's slowdown, the astronomical time is not as precise as the
   --  International Atomic Time. To compensate for this inaccuracy, a single
   --  leap second is added after the last day of June or December. The count
   --  of seconds during those occurences becomes:

   --    ... 58, 59, leap second 60, 1, 2 ...

   --  Unlike leap days, leap seconds occur simultaneously around the world.
   --  In other words, if a leap second occurs at 23:59:60 GMT, it also occurs
   --  on 18:59:60 -5 or 2:59:60 +2 on the next day.
   --  Leap seconds do not follow a formula. The International Earth Rotation
   --  and Reference System Service decides when to add one. Leap seconds are
   --  included in the representation of time in Ada 95 mode. As a result,
   --  the following two time values will conceptually differ by two seconds:

   --    Time_Of (1972, 7, 1, 0.0) - Time_Of (1972, 6, 30, 86_399.0) = 2 secs

   --  When a new leap second is added, the following steps must be carried
   --  out:

   --     1) Increment Leap_Seconds_Count by one
   --     2) Add an entry to the end of table Leap_Second_Dates

   --  The algorithms that build the actual leap second values and discover
   --  how many leap seconds have occured between two dates do not need any
   --  modification.

   ------------------------------
   -- Non-leap centenial years --
   ------------------------------

   --  Over the range of Ada time, centenial years 2100, 2200 and 2300 are
   --  non-leap. As a consequence, seven non-leap years occur over the period
   --  of year - 4 to year + 4. Internaly, routines Split and Time_Of add or
   --  subtract a "fake" February 29 to facilitate the arithmetic involved.
   --  This small "cheat" remains hidden and the following calculations do
   --  produce the correct difference.

   --    Time_Of (2100, 3, 1, 0.0) - Time_Of (2100,  2, 28, 0.0) = 1 day
   --    Time_Of (2101, 1, 1, 0.0) - Time_Of (2100, 12, 31, 0.0) = 1 day

   type Time_Rep is mod 2 ** 64;
   type Time is new Time_Rep;

   --  Due to boundary time values and time zones, two days of buffer space
   --  are set aside at both end points of Ada time:

   --    Abs zero  Hard low     Soft low          Soft high    Hard high
   --    +---------+============+#################+============+----------->
   --                 Buffer 1     Real Ada time     Buffer 2

   --  A time value in a any time zone may not excede the hard bounds of Ada
   --  time, while a value in GMT may not go over the soft bounds.

   Buffer_D : constant Duration := 2.0 * Secs_In_Day;
   Buffer_N : constant Time     := 2   * Nanos_In_Day;

   --  Lower and upper bound of Ada time shifted by two days from the absolute
   --  zero. Note that the upper bound includes the non-leap centenial years.

   Ada_Low  : constant Time := Buffer_N;
   Ada_High : constant Time := (121 * 366 + 378 * 365) * Nanos_In_Day +
                                  Buffer_N;

   --  Both of these hard bounds are 28 hours before and after their regular
   --  counterpart. The value of 28 is taken from Ada.Calendar.Time_Zones.

   Hard_Ada_Low  : constant Time := Ada_Low  - 100_800 * Nano;
   Hard_Ada_High : constant Time := Ada_High + 100_800 * Nano;

   Days_In_Month : constant array (Month_Number) of Day_Number :=
                     (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);

   Invalid_Time_Zone_Offset : Long_Integer;
   pragma Import (C, Invalid_Time_Zone_Offset, "__gnat_invalid_tzoff");

   function Is_Leap (Year : Year_Number) return Boolean;
   --  Determine whether a given year is leap

   --  The following packages provide a target independent interface to the
   --  children of Calendar - Arithmetic, Delays, Formatting and Time_Zones.

   package Arithmetic_Operations is
      function Add (Date : Time; Days : Long_Integer) return Time;
      --  Add X number of days to a time value

      procedure Difference
        (Left         : Time;
         Right        : Time;
         Days         : out Long_Integer;
         Seconds      : out Duration;
         Leap_Seconds : out Integer);
      --  Calculate the difference between two time values in terms of days,
      --  seconds and leap seconds elapsed. The leap seconds are not included
      --  in the seconds returned. If Left is greater than Right, the returned
      --  values are positive, negative otherwise.

      function Subtract (Date : Time; Days : Long_Integer) return Time;
      --  Subtract X number of days from a time value
   end Arithmetic_Operations;

   package Delays_Operations is
      function To_Duration (Ada_Time : Time) return Duration;
      --  Given a time value in nanoseconds since 1901, convert it into a
      --  duration value giving the number of nanoseconds since the Unix Epoch.
   end Delays_Operations;

   package Formatting_Operations is
      function Day_Of_Week (Date : Time) return Integer;
      --  Determine which day of week Date falls on. The returned values are
      --  within the range of 0 .. 6 (Monday .. Sunday).

      procedure Split
        (Date       : Time;
         Year       : out Year_Number;
         Month      : out Month_Number;
         Day        : out Day_Number;
         Day_Secs   : out Day_Duration;
         Hour       : out Integer;
         Minute     : out Integer;
         Second     : out Integer;
         Sub_Sec    : out Duration;
         Leap_Sec   : out Boolean;
         Time_Zone  : Long_Integer);
      --  Split a time value into its components

      function Time_Of
        (Year         : Year_Number;
         Month        : Month_Number;
         Day          : Day_Number;
         Day_Secs     : Day_Duration;
         Hour         : Integer;
         Minute       : Integer;
         Second       : Integer;
         Sub_Sec      : Duration;
         Leap_Sec     : Boolean;
         Leap_Checks  : Boolean;
         Use_Day_Secs : Boolean;
         Time_Zone    : Long_Integer) return Time;
      --  Given all the components of a date, return the corresponding time
      --  value. Set Use_Day_Secs to use the value in Day_Secs, otherwise the
      --  day duration will be calculated from Hour, Minute, Second and Sub_
      --  Sec. Set flag Leap_Checks to verify the validity of a leap second.

   end Formatting_Operations;

   package Time_Zones_Operations is
      function UTC_Time_Offset (Date : Time) return Long_Integer;
      --  Return the offset in seconds from GMT
   end Time_Zones_Operations;

end Ada.Calendar;
