#include "wv.hpp"

namespace W
{
wv::wv() : _mem(std::make_unique<int[]>(2))
{
}
} // namespace W