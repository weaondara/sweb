/* 
 * File:   NewMutexTestThread.cpp
 * Author: alex
 * 
 * Created on 10. November 2015, 17:29
 */

#include "NewMutexTestThread.h"
#include "kprintf.h"
#include "debug.h"
#include "assert.h"
#include "ArchThreads.h"

Mutex NewMutexTestThread::mtest_("mtest_");
Thread* NewMutexTestThread::previously_held_by_(0);
int NewMutexTestThread::counter(0);
int NewMutexTestThread::counterref(0);

NewMutexTestThread::NewMutexTestThread() : Thread(0, "NewMutexTestThread")
{
}

NewMutexTestThread::~NewMutexTestThread()
{
  if (mtest_.isHeldBy(currentThread))
    mtest_.release();
}

void NewMutexTestThread::Run()
{
  while (1)
  {
    mtest_.acquire();
    if (previously_held_by_ != this)
    {
//      Scheduler::instance()->printLockingInformation();
      debug(SYSCALL, "holder changed; current %p; previous %p\n", this, previously_held_by_);
    }
    previously_held_by_ = this;
    
    assert(counter == counterref);
    
    counter++;
    ArchThreads::atomic_add(counterref, 1);
    
    assert(counter == counterref);
    
//    for (int i = 0; i < 1000000;)
//      i++;
    mtest_.release();
//    for (int i = 0; i < 1000000;)
//      i++;
//    Scheduler::instance()->yield();
  }
}

