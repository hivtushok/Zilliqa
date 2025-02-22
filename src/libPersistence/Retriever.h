/*
 * Copyright (C) 2019 Zilliqa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ZILLIQA_SRC_LIBPERSISTENCE_RETRIEVER_H_
#define ZILLIQA_SRC_LIBPERSISTENCE_RETRIEVER_H_

#include <list>
#include <map>
#include <unordered_map>

#include "libData/AccountData/Account.h"
#include "libData/AccountData/Address.h"
#include "libMediator/Mediator.h"

class Retriever {
 public:
  Retriever(Mediator& mediator);

  bool RetrieveTxBlocks();
  bool RetrieveBlockLink();
  bool RetrieveStates();
  bool ValidateStates();
  bool MigrateContractStates(
      bool ignore_checker, bool disambiguation,
      const std::string& contract_address_output_filename,
      const std::string& normal_address_output_filename);
  void CleanAll();

 private:
  Mediator& m_mediator;
};

#endif  // ZILLIQA_SRC_LIBPERSISTENCE_RETRIEVER_H_
