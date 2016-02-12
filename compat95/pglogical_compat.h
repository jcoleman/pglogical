#ifndef PG_LOGICAL_COMPAT_H
#define PG_LOGICAL_COMPAT_H

extern LWLockPadded *GetNamedLWLockTranche(const char *tranche_name);
extern void RequestNamedLWLockTranche(const char *tranche_name, int num_lwlocks);

#endif
