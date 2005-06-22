template<typename T, typename U> struct same_type;
template<typename T> struct same_type<T, T> {};

void f()
{
  same_type<int & &, int &>();
  same_type<int & &&, int &>();
  same_type<int && &, int &>();
  same_type<int && &&, int &&>();

  same_type<int && const &, int const &>();
  same_type<int volatile && const &&, int volatile const &&>();
  same_type<int const && const &, int const &>();
}
