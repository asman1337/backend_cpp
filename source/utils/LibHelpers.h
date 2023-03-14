//
// Created by asman on 12-03-2023.
//
#ifndef CODINGVEDA_BACKEND_CPP_LIBHELPERS_H
#define CODINGVEDA_BACKEND_CPP_LIBHELPERS_H

#include <iostream>
#include <thread>
#include "../utils/md5/MD5.h"

namespace LibHelpers
{
    // auto getMd5Hash(const std::string &text)
    // {
    //     auto result = MD5(text).hexdigest();
    //     return result;
    //     // return md5(text);
    // }

    auto getThreadsForServer()
    {
        unsigned int mThreads, mUsable;
        mThreads = std::thread::hardware_concurrency();
        if (mThreads >= 16)
        {
            mUsable = mThreads - 2;
        }
        else if (mThreads >= 12)
        {
            mUsable = ((mThreads / 2) + 2);
        }
        else if (mThreads >= 4)
        {
            mUsable = mThreads - 1;
        }
        else
        {
            mUsable = mThreads;
        }

        return mUsable;
    }
}

#endif // CODINGVEDA_BACKEND_CPP_LIBHELPERS_H