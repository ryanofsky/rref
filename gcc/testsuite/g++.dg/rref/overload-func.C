// { dg-do link }

struct S{};
S & lvalue() { return *static_cast<S*>(0); }
S rvalue() { return S(); }

void f(const S&) {}
void f(S&&);
void g(const S&);
void g(S&&) {}

int main()
{
  f(lvalue());
  g(rvalue());
}
