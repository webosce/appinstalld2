// Copyright (c) 2017-2020 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef APP_CLOSE_STEP_H
#define APP_CLOSE_STEP_H

#include "Step.h"
#include "installer/InstallHistory.h"
#include "base/Logging.h"
#include "base/CallChain.h"
#include "installer/CallChainEventHandler.h"

using namespace std;

class Task;
class AppCloseStep : public Step
{
public:
    //! Constructor
    AppCloseStep();

    //! Destructor
    ~AppCloseStep();

    virtual bool proceed(Task *task);

protected:

    void onAppClosed(pbnjson::JValue result, void *user_data);

    bool checkPriviligedApp();

    void addCallItems(const char *sessionId, const string& packageId, CallChain& callchain);
};

#endif
