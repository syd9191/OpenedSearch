#include "index.hpp"

double Index::avg_length() const {
    uint32_t numChunks = get_num_chunks();
    if (numChunks == 0) {
        return 0.0;
    }
    return static_cast<double>(totalLength) /
           static_cast<double>(numChunks);
}

ChunkId Index::add_chunk(const ChunkInfo &chunk) {
    ChunkId chunkID = chunk.id;
    uint32_t newChunkLength = chunk.chunkLength;

    auto it = chunks.find(chunkID);
    if (it != chunks.end()) {
        totalLength -= it->second.chunkLength;
        it->second = chunk;
        totalLength += newChunkLength;
    } else {
        chunks.emplace(chunkID, chunk);
        totalLength += newChunkLength;
    }

    return chunkID;
}

void Index::clear_chunks() {
    chunks.clear();
    totalLength = 0;
}

uint32_t Index::get_num_chunks() const {
    return static_cast<uint32_t>(chunks.size());
}

uint64_t Index::get_total_length() const {
    return totalLength;
}