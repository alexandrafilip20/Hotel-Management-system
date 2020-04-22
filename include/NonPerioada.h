#ifndef NONPERIOADA_H
#define NONPERIOADA_H
#include <exception>
using namespace std;

class NonPerioada : public exception
{
   public:
  NonPerioada () noexcept {}
  NonPerioada (const NonPerioada&) noexcept = default;
  NonPerioada& operator= (const NonPerioada&) noexcept = default;
  virtual ~NonPerioada() noexcept = default;
  virtual const char* what() const noexcept
  {
    return "Perioada de sedere trebuie sa fie de minim o noapte, respectiv maxim 10 nopti";
  }
};

#endif // NONPERIOADA_H
