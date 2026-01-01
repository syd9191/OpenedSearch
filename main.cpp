#include <iostream>
#include <string>
#include <vector> 
#include <cstdint>
#include <unordered_map>
#include <cctype>
#include "tokeniser.hpp"

using ChunkId=uint32_t;

struct ChunkMeta{
    std::string source;
    std::string external_id;
    std::unordered_map<std::string, std::string> metadata;
};

struct ChunkInfo{
    ChunkId id;
    uint32_t chunkLength;
    ChunkMeta metadata;
    std::string content;
};
 
struct Posting{
    ChunkId id;
    uint32_t freq; 
};

using PostingList = std::vector<Posting>;
using InvertedIndex = std::unordered_map<std::string, PostingList>; 

struct Index{
    std::unordered_map<ChunkId, ChunkInfo> chunks;
    InvertedIndex inverted;
    
    uint32_t numChunks=0;
    uint64_t totalLength=0; //sum of all chunk lengths

    double avg_length() const{ //const here is a promise not to modify the obj
        if (numChunks==0){
            return 0;
        }
        return static_cast<double>(totalLength)/static_cast<double>(numChunks);
    };

    ChunkId add_chunk(const ChunkInfo &chunk){
        uint32_t chunkID=chunk.id; 
    
        chunks[chunkID]=chunk;
        numChunks+=1;
        totalLength+=chunk.chunkLength;

        return chunkID;
    }
};

int main(){
    std::string testString1= "Hello World 123";
    std::string testString2= " ";
    std::string testString3= "123!:dfgdfg134#!:";

    std::vector<std::string> tokensVec;

    tokensVec=tokenise(testString3);

    std::cout<<"Test Starts Here"<<"\n";

    for (const std::string&tokenString:tokensVec){
        std::cout<<tokenString<<"\n";
    }
    return 0;
}