#pragma once

#include <string>
#include <unordered_map>
#include <cstdint>

using ChunkId = uint32_t;

struct ChunkMeta {
    std::string source;
    std::string external_id;
    std::unordered_map<std::string, std::string> metadata;
};

struct ChunkInfo {
    ChunkId id;
    uint32_t chunkLength;
    std::string content;
    ChunkMeta metadata;
};