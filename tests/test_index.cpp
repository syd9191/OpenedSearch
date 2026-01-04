#include <index.hpp>
#include <chunk.hpp>
#include <cassert>
#include <iostream>
#include <string>

void test_add_single_chunk(){
    std::cout<<"---Single Chunks Addition Test---"<<"\n\n";

    Index idx;
    
    ChunkInfo testChunk{
        1,
        3,
        "This is TestChunk",
        {}
    };

    idx.add_chunk(testChunk);

    assert(idx.get_num_chunks()==1);
    assert(idx.get_total_length()==3);
    assert(idx.avg_length()==3.0);

    std::cout<<"---Single Chunks Addition Test PASSED---"<<"\n\n";
};

void test_overwrite_chunk(){
    std::cout<<"---Overide Test---"<<"\n";
    Index idx;

    ChunkInfo chunk1{1, 3, "hello world test", {}};
    ChunkInfo chunk2{1, 5, "hello world again test", {}};

    idx.add_chunk(chunk1);
    idx.add_chunk(chunk2);

    assert(idx.get_num_chunks()==1);      
    assert(idx.get_total_length()==5);  
    assert(idx.avg_length()==5.0);

    std::cout<<"---Override Test PASSED---"<<"\n\n";
};

int main(){
    std::cout<<"---INDEX TESTS START---"<<"\n\n";

    int passed=0;

    test_add_single_chunk();
    passed++;

    test_overwrite_chunk();
    passed++;

    std::cout<<"---INDEX TESTS FINISHED: PASSED "<< passed << "/2 tests";

    return 0;
};