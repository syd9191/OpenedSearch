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
    
    uint64_t totalLength=0; 

    double avg_length() const;
    ChunkId add_chunk(const ChunkInfo &chunk);
    void clear_chunks();
    uint32_t get_num_chunks() const;
    uint64_t get_total_length() const;
};