// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2020, The Ionize Developers
// Copyright (c) 2018, The DeroGold Association
// Copyright (c) 2020 The Ionize Developers.
//
// Please see the included LICENSE file for more information.

#include <stdint.h>
#include <vector>

uint64_t nextDifficulty(std::vector<uint64_t> timestamps, std::vector<uint64_t> cumulativeDifficulties, const uint64_t blockHeight);
