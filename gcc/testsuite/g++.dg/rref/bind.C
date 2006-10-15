// { dg-options "" }
struct S{};
void f(S&&);

int main()
{
  f(S());
}
