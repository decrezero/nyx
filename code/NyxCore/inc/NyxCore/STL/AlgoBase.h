#ifndef NyxCore_STL_AlgoBase_h
#define NyxCore_STL_AlgoBase_h

namespace Nyx
{

template <class T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
const T& min(const T& a, const T& b)
{
    return b < a ? b : a;
}

template <class T>
const T& max(const T& a, const T& b)
{
    return a < b ? b : a;
}

} // namespace Nyx

#endif // NyxCore_STL_AlgoBase_h
