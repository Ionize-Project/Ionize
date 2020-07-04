// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2018-2019, The DeroGold Association
// Copyright (c) 2020, The Ionize Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <limits>
#include <initializer_list>
#include <boost/uuid/uuid.hpp>

namespace CryptoNote {
    namespace parameters {
        const uint64_t DIFFICULTY_TARGET                             = 300;
        const uint64_t DIFFICULTY_TARGET_V2                          = 300;

        const uint64_t DIFFICULTY_TARGET_V2_HEIGHT                   = 1051200;

        const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 1'000'000'000;
        const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 1'000'000'000;
        const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1'000'000'000;
        const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 31097;
        const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 5;
        const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 6 * DIFFICULTY_TARGET;

        const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 11;

        const uint64_t MONEY_SUPPLY                                  = UINT64_C(20'000'000'00000000);

        const uint32_t EMISSION_SPEED_FACTOR                         = 23;
        const uint32_t EMISSION_SPEED_FACTOR_V2                      = 24;

        static_assert(EMISSION_SPEED_FACTOR    <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");
        static_assert(EMISSION_SPEED_FACTOR_V2 <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

        const uint64_t EMISSION_SPEED_FACTOR_V2_HEIGHT               = 1051200;

        const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(200'000'00000000);

        /* PREMINE
           ================================
           Development Coins:   200,000 INZ
           ================================ */

        const char GENESIS_COINBASE_TX_HEX[] = "010501ff0001808095e789c6040298f2317799dbc655184026c4f453a28fae2c1274daf2ec6d1296f90c292f07fb21010742cc0c3e12f5ddccf9fcae2911c1c7b4f8b7ff4728ee67238c2190e040d12f";
        static_assert(sizeof(GENESIS_COINBASE_TX_HEX)/sizeof(*GENESIS_COINBASE_TX_HEX) != 1, "GENESIS_COINBASE_TX_HEX must not be empty.");

        const uint64_t GENESIS_BLOCK_TIMESTAMP                       = 1593266607;

        const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
        const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000;
        const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 20000;
        const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 10000;
        const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
        const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;

        const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;

        const uint64_t MINIMUM_FEE                                   = UINT64_C(1000);

        const uint64_t MINIMUM_MIXIN_V0                              = 0;
        const uint64_t MAXIMUM_MIXIN_V0                              = 3;

        const uint64_t DEFAULT_MIXIN_V0                              = 3;

        const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(0);

        const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;

        const uint64_t DIFFICULTY_WINDOW                             = 60;
        const uint64_t DIFFICULTY_BLOCKS_COUNT                       = DIFFICULTY_WINDOW + 1;

        const size_t   MAX_BLOCK_SIZE_INITIAL                        = 100000;
        const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
        const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
        const uint64_t MAX_EXTRA_SIZE                                = 140000;
        const uint64_t MAX_EXTRA_SIZE_V2                             = 1024;
        const uint64_t MAX_EXTRA_SIZE_V2_HEIGHT                      = 0;

        const uint64_t TRANSACTION_SIGNATURE_COUNT_VALIDATION_HEIGHT = 0;

        const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
        const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

        const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;
        const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7;
        const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;

        const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
        const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
        const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

        const uint32_t UPGRADE_HEIGHT_V2                             = 1;
        const uint32_t UPGRADE_HEIGHT_V3                             = 2;
        const uint32_t UPGRADE_HEIGHT_V4                             = 3;
        const uint32_t UPGRADE_HEIGHT_V5                             = 4;
        const uint32_t UPGRADE_HEIGHT_CURRENT                        = UPGRADE_HEIGHT_V5;

        const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;
        const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; 
        const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;
        static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
        static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

        const uint64_t FORK_HEIGHTS[] =
        {
            1051200,
        };

        const uint64_t SOFTWARE_SUPPORTED_FORK_INDEX                 = 0;

        const uint64_t FORK_HEIGHTS_SIZE = sizeof(FORK_HEIGHTS) / sizeof(*FORK_HEIGHTS);

        const uint8_t CURRENT_FORK_INDEX = FORK_HEIGHTS_SIZE == 0 ? 0 : SOFTWARE_SUPPORTED_FORK_INDEX;

        static_assert(CURRENT_FORK_INDEX >= 0, "CURRENT FORK INDEX must be >= 0");
        static_assert(FORK_HEIGHTS_SIZE == 0 || CURRENT_FORK_INDEX < FORK_HEIGHTS_SIZE, "CURRENT_FORK_INDEX out of range of FORK_HEIGHTS!");

        const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
        const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
        const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
        const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
        const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
    }

    const char     CRYPTONOTE_NAME[]                             = "Ionize";

    const uint8_t  TRANSACTION_VERSION_1                         =  1;
    const uint8_t  TRANSACTION_VERSION_2                         =  2;
    const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;

    const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
    const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
    const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
    const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
    const uint8_t  BLOCK_MAJOR_VERSION_5                         =  5;

    const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
    const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

    const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;
    const uint64_t BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  100;
    const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

    const int      P2P_DEFAULT_PORT                              =  23230;
    const int      RPC_DEFAULT_PORT                              =  23231;
    const int      SERVICE_DEFAULT_PORT                          =  23232;

    const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
    const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

    const uint8_t  P2P_CURRENT_VERSION                           = 1;
    const uint8_t  P2P_MINIMUM_VERSION                           = 0;

    const uint8_t P2P_LITE_BLOCKS_PROPOGATION_VERSION            = 0;

    const uint8_t  P2P_UPGRADE_WINDOW                            = 2;

    const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 32 * 1024 * 1024;
    const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
    const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
    const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;
    const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;
    const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
    const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;
    const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;
    const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000;
    const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;
    const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

    const uint64_t DATABASE_WRITE_BUFFER_MB_DEFAULT_SIZE         = 256;
    const uint64_t DATABASE_READ_BUFFER_MB_DEFAULT_SIZE          = 128;
    const uint32_t DATABASE_DEFAULT_MAX_OPEN_FILES               = 125;
    const uint16_t DATABASE_DEFAULT_BACKGROUND_THREADS_COUNT     = 4;

    const char     LATEST_VERSION_URL[]                          = "https://github.com/Ionize-Project/Ionize/releases";
    const std::string LICENSE_URL                                = "https://github.com/Ionize-Project/Ionize/blob/master/LICENSE";
    const static   boost::uuids::uuid CRYPTONOTE_NETWORK         =
    {
        {  0xaa, 0xbb, 0xcc, 0x11, 0x45, 0x33, 0x5b, 0xcd, 0x10, 0x11, 0x23, 0x3d, 0x28, 0x5d, 0x54, 0x10  }
    };

    const char* const SEED_NODES[] = {
        "178.238.226.229:23230", // Seed Node 1
        "178.238.226.229:24240", // Seed Node 2
        "45.77.57.130:23230", // ML
        "95.111.246.231:23230", // Eskal
        "164.68.100.209:23230", // Galapagos
        "87.197.119.149:23230" // PeterNagy
    };
}
