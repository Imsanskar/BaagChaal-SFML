#pragma once
#include <inttypes.h>

struct Node {
    uint64_t state = 0;
    Node *parent = nullptr;
    Node *child = nullptr;
};