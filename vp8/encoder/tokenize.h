/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#ifndef tokenize_h
#define tokenize_h

#include "entropy.h"
#include "block.h"

void vp8_tokenize_initialize();

typedef struct
{
    int Token;
    int Extra;
    const vp8_prob *context_tree;
    int skip_eob_node;
    int section;
} TOKENEXTRA;

int rd_cost_mby(MACROBLOCKD *);

#ifdef ENTROPY_STATS
void init_context_counters();
void print_context_counters();

extern _int64 context_counters[BLOCK_TYPES] [COEF_BANDS] [PREV_COEF_CONTEXTS] [vp8_coef_tokens];
#endif

extern const int *vp8_dct_value_cost_ptr;
/* TODO: The Token field should be broken out into a separate char array to
 *  improve cache locality, since it's needed for costing when the rest of the
 *  fields are not.
 */
extern const TOKENEXTRA *vp8_dct_value_tokens_ptr;

#endif  /* tokenize_h */
