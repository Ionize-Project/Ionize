// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2020, The Ionize Developers
// Copyright (c) 2020, The Ionize Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <sstream>
#include <config/CryptoNoteConfig.h>
#include <config/Ascii.h>
#include <version.h>

namespace CryptoNote
{
  inline std::string getProjectCLIHeader()
  {
    std::stringstream programHeader;
    programHeader << std::endl
      << asciiArt << std::endl
      << " " << CryptoNote::CRYPTONOTE_NAME << " v" << PROJECT_VERSION_LONG << std::endl
      << " This software is distributed under the General Public License v3.0"
      << std::endl << std::endl
      << " " << PROJECT_COPYRIGHT
      << std::endl;

    return programHeader.str();
  }
}
