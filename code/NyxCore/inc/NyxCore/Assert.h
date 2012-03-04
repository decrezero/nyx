#ifndef NyxCore_Assert_h
#define NyxCore_Assert_h

#include <cassert>

#define NYX_ASSERT(expr) assert(expr)

#define NYX_FAIL() NYX_ASSERT(0)

#endif // NyxCore_Assert_h
