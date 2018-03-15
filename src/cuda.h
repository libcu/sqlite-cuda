/*
** 2015 January 12
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
******************************************************************************
**
** This file contains code that is specific to CUDA.
*/
#ifndef SQLITE_CUDA_H
#define SQLITE_CUDA_H
#if __CUDACC__
#ifdef __cplusplus
}

#ifdef __CUDA_ARCH__
#define SQLITE_OS_OTHER 1
#define SQLITE_FIELD __device__
#define SQLITE_CONSTANT __constant__
#endif
#define SQLITE_METHOD __host__ __device__

#include <crtdefscu.h>
#include <stdiocu.h>
#include <stdlibcu.h>
#include <stringcu.h>

//From: hash.h
//#include <ext/hash.h>
//#define SQLITE_HASH_H
//#define Hash hash_t
//#define HashElem hashElem_t
//#define sqlite3HashInit(H) hashInit(H)
//#define sqlite3HashInsert(H, Key, Data) hashInsert(H, Key, Data)
//#define sqlite3HashFind(H, Key) hashFind(H, Key)
//#define sqlite3HashClear(H) hashClear(H)
//#undef sqliteHashFirst
//#undef sqliteHashNext
//#undef sqliteHashData
//#define sqliteHashFirst(H) hashFirst(H)
//#define sqliteHashNext(E) hashNext(E)
//#define sqliteHashData(E) hashData(E)

//From: malloc.c
//#define sqlite3MemdebugSetType(X, Y) memdbg_settype(X, Y)
//#define sqlite3MemdebugHasType(X, Y) memdbg_hastype(X, Y)
//#define sqlite3MemdebugNotType(X, Y) memdbg_nottype(X, Y)
////
//#define sqlite3_release_memory(n) alloc_releasememory(n)
//#define sqlite3MallocMutex() allocMutex()
//#define sqlite3_memory_alarm(xCallback, pArg, iThreshold) panic("DEPRECATED")
//#define sqlite3_soft_heap_limit64(n) alloc_softheaplimit64()
//#define sqlite3_soft_heap_limit(n) alloc_softheaplimit()
//#define sqlite3MallocInit() allocInitialize()
//#define sqlite3HeapNearlyFull() allocHeapNearlyFull()
//#define sqlite3MallocEnd() allocShutdown()
//#define sqlite3_memory_used() alloc_memoryused()
//#define sqlite3_memory_highwater(resetFlag) alloc_memoryhighwater(resetFlag)
//#define sqlite3Malloc(n) alloc(n)
//#define sqlite3_malloc(n) alloc32(n)
//#define sqlite3_malloc64(n) alloc64(n)
//#define sqlite3MallocSize(p) allocSize(p)
//#define sqlite3DbMallocSize(db, p) tagallocSize(db, p)
//#define sqlite3_msize(p) alloc_msize(p)
//#define sqlite3_free(p) mfree(p)
//#define sqlite3DbFreeNN(db, p) tagfreeNN(db, p)
//#define sqlite3DbFree(db, p) tagfree(db, p)
//#define sqlite3Realloc(pOld, nBytes) allocRealloc(pOld, nBytes)
//#define sqlite3_realloc(pOld, n) alloc_realloc32(pOld, n)
//#define sqlite3_realloc64(pOld, n) alloc_realloc64(pOld, n)
//#define sqlite3MallocZero(n) allocZero(n)
//#define sqlite3DbMallocZero(db, n) tagallocZero(db, n)
//#define sqlite3DbMallocRaw(db, n) tagallocRaw(db, n)
//#define sqlite3DbMallocRawNN(db, n) tagallocRawNN(db, n)
//#define sqlite3DbRealloc(db, p, n) tagrealloc(db, p, n)
//#define sqlite3DbReallocOrFree(db, p, n) tagreallocOrFree(db, p, n)
//#define sqlite3DbStrDup(db, z) tagstrdup(db, z)
//#define sqlite3DbStrNDup(db, z, n) tagstrndup(db, z, n)
//#define sqlite3SetString(pz, db, zNew) tagstrset(pz, db, zNew)
//#define sqlite3OomFault(db) tagOomFault(db)
//#define sqlite3OomClear(db) tagOomClear(db)
//#define sqlite3ApiExit(db, rc) tagApiExit(db, rc)

//From: mem0.c, mem1.c
//#define sqlite3MemSetDefault() __allocsystemSetDefault()

//From: memjournal.c
//#define sqlite3_file vsysfile
//#define sqlite3JournalOpen(pVfs, zName, pJfd, flags, nSpill)
//#define sqlite3MemJournalOpen(pJfd) memfileOpen
//#define sqlite3JournalCreate(pJfd)
//#define sqlite3JournalIsInMemory(p)
//#define sqlite3JournalSize(pVfs)

//From: mutex.c
//#define sqlite3MemoryBarrier systemMemoryBarrier
////
//#define sqlite3_mutex mutex
//#define sqlite3MutexInit() mutexInitialize()
//#define sqlite3MutexEnd() mutexShutdown()
//#define sqlite3_mutex_alloc(id) mutex_alloc(id)
//#define sqlite3MutexAlloc(id) mutexAlloc(id)
//#define sqlite3_mutex_free(p) mutex_free(p)
//#define sqlite3_mutex_enter(p) mutex_enter(p)
//#define sqlite3_mutex_try(p) mutex_tryenter(p)
//#define sqlite3_mutex_leave(p) mutex_leave(p)
//#define sqlite3_mutex_held(p) mutex_held(p)
//#define sqlite3_mutex_notheld(p) mutex_notheld(p)

//From: mutex_noop.c, mutex_unix.c, mutex_w32.c
//#define sqlite3DefaultMutex() __mutexsystemDefault()

//From: os.c
//#define _SQLITE_OS_H_
//#define SQLITE_DEFAULT_SECTOR_SIZE LIBCU_DEFAULT_SECTOR_SIZE
//#define SQLITE_TEMP_FILE_PREFIX LIBCU_TEMP_FILE_PREFIX
//#define SQLITE_FCNTL_DB_UNCHANGED LIBCU_FCNTL_DB_UNCHANGED
////
//#define sqlite3_io_error_hit libcu_io_error_hit
//#define sqlite3_io_error_hardhit libcu_io_error_hardhit
//#define sqlite3_io_error_pending libcu_io_error_pending
//#define sqlite3_io_error_persist libcu_io_error_persist
//#define sqlite3_io_error_benign libcu_io_error_benign
//#define sqlite3_diskfull_pending libcu_diskfull_pending
//#define sqlite3_diskfull libcu_diskfull
//#define sqlite3_open_file_count libcu_open_file_count
//#define sqlite3_memdebug_vfs_oom_test libcu_memdebug_vfs_oom_test
//#define sqlite3OsClose(pId) vsys_close(pId)
//#define sqlite3OsRead(id, pBuf, amt, offset) vsys_read(id, pBuf, amt, offset)
//#define sqlite3OsWrite(id, pBuf, amt, offset) vsys_write(id, pBuf, amt, offset)
//#define sqlite3OsTruncate(id, size) vsys_truncate(id, size)
//#define sqlite3OsSync(id, flags) vsys_sync(id, flags)
//#define sqlite3OsFileSize(id, pSize) vsys_fileSize(id, pSize)
//#define sqlite3OsLock(id, lockType) vsys_lock(id, lockType)
//#define sqlite3OsUnlock(id, lockType) vsys_unlock(id, lockType)
//#define sqlite3OsCheckReservedLock(id, pResOut) vsys_checkReservedLock(id, pResOut)
//#define sqlite3OsFileControl(id, op, pArg) vsys_fileControl(id, op, pArg)
//#define sqlite3OsFileControlHint(id, op, pArg) vsys_fileControlHint(id, op, pArg)
//#define sqlite3OsSectorSize(id) vsys_sectorSize(id)
//#define sqlite3OsDeviceCharacteristics(id) vsys_deviceCharacteristics(id)
//#define sqlite3OsShmLock(id, offset, n, flags) vsys_shmLock(id, offset, n, flags)
//#define sqlite3OsShmBarrier(id) vsys_shmBarrier(id)
//#define sqlite3OsShmUnmap(id, deleteFlag) vsys_shmUnmap(id, deleteFlag)
//#define sqlite3OsShmMap(id, iPage, pgsz, bExtend, pp) vsys_shmMap(id, iPage, pgsz, bExtend, pp)
//#define sqlite3OsFetch(id, iOff, iAmt, pp) vsys_fetch(id, iOff, iAmt, pp)
//#define sqlite3OsUnfetch(id, iOff, p) vsys_unfetch(id, iOff, p)
//#define sqlite3OsOpen(pVfs, zPath, pFile, flags, pFlagsOut) vsys_open(pVfs, zPath, pFile, flags, pFlagsOut)
//#define sqlite3OsDelete(pVfs, zPath, dirSync) vsys_delete(pVfs, zPath, dirSync)
//#define sqlite3OsAccess(pVfs, zPath, flags, pResOut) vsys_access(pVfs, zPath, flags, pResOut)
//#define sqlite3OsFullPathname(pVfs, zPath, nPathOut, zPathOut) vsys_fullPathname(pVfs, zPath, nPathOut, zPathOut)
//#define sqlite3OsDlOpen(pVfs, zPath) vsys_dlOpen(pVfs, zPath)
//#define sqlite3OsDlError(pVfs, nByte, zBufOut) vsys_dlError(pVfs, nByte, zBufOut)
//#define sqlite3OsDlSym(pVfs, pHdle, zSym) vsys_dlSym(pVfs, pHdle, zSym)
//#define sqlite3OsDlClose(pVfs, pHandle) vsys_dlClose(pVfs, pHandle)
//#define sqlite3OsRandomness(pVfs, nByte, zBufOut) vsys_randomness(pVfs, nByte, zBufOut)
//#define sqlite3OsSleep(pVfs, nMicro) vsys_sleep(pVfs, nMicro)
//#define sqlite3OsGetLastError(pVfs) vsys_getLastError(pVfs)
//#define sqlite3OsCurrentTimeInt64(pVfs, pTimeOut) vsys_currentTimeInt64(pVfs, pTimeOut)
//#define sqlite3OsOpenMalloc(pVfs, zFile, ppFile, flags, pOutFlags) vsys_openMalloc(pVfs, zFile, ppFile, flags, pOutFlags)
//#define sqlite3OsCloseFree(pFile) vsys_closeAndFree(pFile)
//#define sqlite3OsInit() vsystemFakeInit()
//#define sqlite3_vfs_find(zVfs) vsystemFind(zVfs)
//#define sqlite3_vfs_register(pVfs, makeDflt) vsystemRegister(pVfs, makeDflt)
//#define sqlite3_vfs_unregister(pVfs) vsystemUnregister(pVfs)

extern "C" {
#endif
#endif /* __cplusplus */
#endif /* SQLITE_CUDA_H */