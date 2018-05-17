// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2010-2018 The Bitcoin developers
// Original code was distributed under the MIT software license.
// Copyright (c) 2014-2018 TEDLab Sciences Ltd
// Gamechain code distributed under the GPLv3 license, see COPYING file.

#ifndef _SECP256K1_ECMULT_
#define _SECP256K1_ECMULT_

#include "num.h"
#include "group.h"

typedef struct {
    /* For accelerating the computation of a*P + b*G: */
    secp256k1_ge_storage (*pre_g)[];    /* odd multiples of the generator */
#ifdef USE_ENDOMORPHISM
    secp256k1_ge_storage (*pre_g_128)[]; /* odd multiples of 2^128*generator */
#endif
} secp256k1_ecmult_context;

static void secp256k1_ecmult_context_init(secp256k1_ecmult_context *ctx);
static void secp256k1_ecmult_context_build(secp256k1_ecmult_context *ctx, const secp256k1_callback *cb);
static void secp256k1_ecmult_context_clone(secp256k1_ecmult_context *dst,
                                           const secp256k1_ecmult_context *src, const secp256k1_callback *cb);
static void secp256k1_ecmult_context_clear(secp256k1_ecmult_context *ctx);
static int secp256k1_ecmult_context_is_built(const secp256k1_ecmult_context *ctx);

/** Double multiply: R = na*A + ng*G */
static void secp256k1_ecmult(const secp256k1_ecmult_context *ctx, secp256k1_gej *r, const secp256k1_gej *a, const secp256k1_scalar *na, const secp256k1_scalar *ng);

#endif
