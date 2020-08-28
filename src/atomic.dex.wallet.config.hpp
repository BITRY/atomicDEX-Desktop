/******************************************************************************
 * Copyright © 2013-2019 The Komodo Platform Developers.                      *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * Komodo Platform software, including this file may be copied, modified,     *
 * propagated or distributed except according to the terms contained in the   *
 * LICENSE file                                                               *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#pragma once

#include "atomic.dex.pch.hpp"

namespace atomic_dex
{
    struct contact_contents
    {
        std::string type;
        std::string address;
    };

    void to_json(nlohmann::json& j, const contact_contents& cfg);

    struct contact
    {
        std::string                   name;
        std::vector<contact_contents> contents;
    };

    void to_json(nlohmann::json& j, const contact& cfg);

    struct wallet_cfg
    {
        std::string          name;
        std::string          protection_pass{"default_protection_pass"};
        std::vector<contact> address_book;
    };

    void from_json(const nlohmann::json& j, wallet_cfg& cfg);
    void to_json(nlohmann::json& j, const wallet_cfg& cfg);
} // namespace atomic_dex
