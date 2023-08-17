//
// Created by Administrator on 2023/8/17.
//

#include "linear-structure/sequence-list/SequenceList.h"

int main() {
    SequenceList sequenceList = sequenceListConstructor();
    try {
        sequenceListInsert(sequenceList, 11, 1);
    } catch(OUT_RANGE_ERROR) {
        stdErr();
    }

    return 0;
}
