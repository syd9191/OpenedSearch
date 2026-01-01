#pragma once

#include <unordered_map>
#include "chunk.hpp"
#include "posting.hpp"


using ChunkId = uint32_t;
using PostingList = std::vector<Posting>;
using InvertedIndex = std::unordered_map<std::string, PostingList>; 

struct Index{
    std::unordered_map<ChunkId, ChunkInfo> chunks;
    InvertedIndex inverted;
    
    uint32_t numChunks=0;
    uint64_t totalLength=0; 

    double avg_length() const{};
    ChunkId add_chunk(const ChunkInfo &chunk){};
};