// { dg-do link }

struct S{};
void f(const S&) {};
void f(S&&);
void g(const S&);
void g(S&&) {};

int main()
{
  S s;
  f(s);
  g(S());
}
