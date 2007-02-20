// { dg-do compile }
// { dg-options "--std=c++0x" }

struct S
{
  S() {}
  S(S&) {}
};

S f()
{
  S s;
  return s;
}

void g()
{
  S s;
  throw s;
}
