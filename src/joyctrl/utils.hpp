#pragma once

#include <vector>
#include <string>
#include <array>

namespace joyctrl
{
namespace utils
{
template <size_t N_DELIMS>
static inline std::vector<std::string> splitStringByDelimiters(const std::string &str,
                                                               std::array<char, N_DELIMS> delims)
{
    size_t curr_index = 0;
    size_t last_index = 0;
    std::vector<std::string> tokens;

    auto is_delimiter = [&delims](char c) {
        for (auto iter : delims)
        {
            if (iter == c)
            {
                return true;
            }
        }
        return false;
    };

    for (; curr_index < str.size(); curr_index++)
    {
        if (is_delimiter(str[curr_index]))
        {
            if (curr_index - last_index > 0)
            {
                tokens.push_back(str.substr(last_index, curr_index - last_index));
                tokens.push_back(std::string(1, str[curr_index]));
            }
            last_index = curr_index + 1;
        }
    }

    if (curr_index - last_index)
    {
        tokens.push_back(str.substr(last_index, curr_index - last_index));
    }

    return tokens;
}
} // namespace utils
} // namespace joyctrl