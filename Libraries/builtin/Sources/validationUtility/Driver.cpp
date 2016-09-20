/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#include <builtin/validationUtility/Driver.h>
#include <builtin/validationUtility/Options.h>
#include <libutil/Filesystem.h>
#include <libutil/ProcessContext.h>

using builtin::validationUtility::Driver;
using builtin::validationUtility::Options;
using libutil::Filesystem;
using libutil::ProcessContext;

Driver::
Driver()
{
}

Driver::
~Driver()
{
}

std::string Driver::
name()
{
    return "builtin-validationUtility";
}

int Driver::
run(libutil::ProcessContext const *processContext, libutil::Filesystem *filesystem)
{
    Options options;
    std::pair<bool, std::string> result = libutil::Options::Parse<Options>(&options, processContext->commandLineArguments());
    if (!result.first) {
        fprintf(stderr, "error: %s\n", result.second.c_str());
        return 1;
    }

    // TODO(grp): Implement validation builtin.
    fprintf(stderr, "error: validation not supported\n");
    return 1;
}
