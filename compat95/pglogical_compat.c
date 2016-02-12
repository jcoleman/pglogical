/*-------------------------------------------------------------------------
 *
 * pglogical_compat.c
 *              compatibility functions (mainly with different PG versions)
 *
 * Copyright (c) 2015, PostgreSQL Global Development Group
 *
 * IDENTIFICATION
 *              pglogical_compat.c
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include "pglogical_compat.h"

LWLockPadded tmplock;

LWLockPadded *
GetNamedLWLockTranche(const char *tranche_name)
{
	LWLock	   *lock = LWLockAssign();

	tmplock.lock = lock;

	return &tmplock;
}

void
RequestNamedLWLockTranche(const char *tranche_name, int num_lwlocks)
{
	Assert(num_lwlocks == 1);

	RequestAddinLWLocks(num_lwlocks);
}

