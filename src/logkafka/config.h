///////////////////////////////////////////////////////////////////////////
//
// logkafka - Collect logs and send lines to Apache Kafka v0.8+
//
///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2015 Qihoo 360 Technology Co., Ltd. All rights reserved.
//
// Licensed under the MIT License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////
#ifndef LOGKAFKA_CONFIG_H_
#define LOGKAFKA_CONFIG_H_

#include <inttypes.h>
#include <limits.h>
#include <sys/types.h>

#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>

#include "logkafka/common.h"

#include "confuse.h"

using namespace std;

namespace logkafka {

class Config {
    public:
        Config();
        ~Config();
        bool init(const char* filename);

    public:
        string zk_urls;
        string gdbm_path;
        string pos_path;
        unsigned long line_max_bytes;
        unsigned long zookeeper_upload_interval;
        unsigned long refresh_interval;
        unsigned long message_send_max_retries;
        unsigned long stat_silent_max_ms;

    private:
        Config(const Config &config);

    private:
        cfg_t *m_cfg;
};

} // namespace logkafka

#endif // LOGKAFKA_CONF_H
