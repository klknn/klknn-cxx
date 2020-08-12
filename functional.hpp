#pragma once

#include <utility>

namespace klknn {
namespace functional {

template <class>
class FPtr;

template <class R, class ... Args>
class FPtr<R(Args...)> {
 public:
  using F = R(*)(Args ...);
  F f;

  // Implicit ctor from fptr.
  FPtr(F f) : f(f) {}

  // For lambda without captures (convertible to fptr)
  template <class T>
  FPtr(T t) : FPtr(static_cast<F>(t)) {}

  auto operator()(Args&& ... args) {
    return this->f(std::forward<Args...>(args...));
  }
};

// Deduction guide for fptr
template <class R, class ... Args>
FPtr(R (&)(Args ...)) -> FPtr<R(Args ...)>;

} // namespace functional
} // namespace klknn
