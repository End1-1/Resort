#ifndef CACHEREMINDERSTATE_H
#define CACHEREMINDERSTATE_H

#include "cachebasestruct.h"

#define cid_reminder_state 56

class CacheReminderState : public CacheBaseStruct
{
public:
    CacheReminderState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEREMINDERSTATE_H
