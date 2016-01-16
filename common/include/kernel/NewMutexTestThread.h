/* 
 * File:   NewMutexTestThread.h
 * Author: alex
 *
 * Created on 10. November 2015, 17:29
 */

#ifndef NEWMUTEXTESTTHREAD_H
#define	NEWMUTEXTESTTHREAD_H

#include "Mutex.h"
#include "Scheduler.h"

class NewMutexTestThread : public Thread
{
public:
  NewMutexTestThread();
  virtual ~NewMutexTestThread();
private:
  NewMutexTestThread(const NewMutexTestThread& orig);
  void Run();
  static Mutex mtest_;
  static Thread* previously_held_by_;
  static int counter;
  static int counterref;
};

#endif	/* NEWMUTEXTESTTHREAD_H */

