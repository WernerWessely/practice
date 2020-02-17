#ifndef _WV_H_
#define _WV_H_

#include <memory>

namespace W
{
class wv
{
public:
    wv();

private:
    wv(const wv &other);
    wv operator=(const wv &other);
    std::unique_ptr<int[]> _mem;
};
} // namespace W

#endif