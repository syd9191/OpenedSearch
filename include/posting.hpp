#pragma once

#include <cstdint>
#include <vector>
#include <chunk.hpp>

struct Posting{
    ChunkId id;
    uint32_t freq; 
};

using PostingList = std::vector<Posting>;

