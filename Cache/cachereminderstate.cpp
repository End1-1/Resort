#include "cachereminderstate.h"

CacheReminderState::CacheReminderState() :
    CacheBaseStruct()
{
    fCacheId = cid_reminder_state;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_reminder_state";
    fSelectorTitle = QObject::tr("Remind state");
    getSelectorTwoField();
    
}
