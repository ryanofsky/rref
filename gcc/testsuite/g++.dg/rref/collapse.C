// { dg-options "" }
template<typename T, typename U> struct same_type;
template<typename T> struct same_type<T, T> {};

typedef int & lref;
typedef int const & clref;
typedef int && rref;
typedef int const && crref;

template<typename T>
struct S
{
  typedef T & lref;
  typedef T const & clref;
  typedef T && rref;
  typedef T const && crref;
};

void f()
{
  same_type<lref &, int &>();
  same_type<lref &&, int &>();
  same_type<rref &, int &>();
  same_type<rref &&, int &&>();

  same_type<rref const &, int const &>();
  same_type<crref volatile &&, int volatile const &&>();
  same_type<clref const &&, int const &>();

  same_type<S<int &>::lref &, int &>();
  same_type<S<int &&>::lref &&, int &>();
  same_type<S<int &>::rref &, int &>();
  same_type<S<int &&>::rref &&, int &&>();

  same_type<S<int const &>::rref, int const &>();
  same_type<S<int volatile &&>::crref, int volatile const &&>();
  same_type<S<int const &&>::clref, int const &>();
}
