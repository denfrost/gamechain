// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#ifndef BITCOIN_CRYPTO_SHA1_H
#define BITCOIN_CRYPTO_SHA1_H

#include <stdint.h>
#include <stdlib.h>

/** A hasher class for SHA1. */
class CSHA1
{
private:
    uint32_t s[5];
    unsigned char buf[64];
    size_t bytes;

public:
    static const size_t OUTPUT_SIZE = 20;

    CSHA1();
    CSHA1& Write(const unsigned char* data, size_t len);
    void Finalize(unsigned char hash[OUTPUT_SIZE]);
    CSHA1& Reset();
};

#endif // BITCOIN_CRYPTO_SHA1_H
