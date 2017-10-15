#ifndef __FS_UTILS_H_
#define __FS_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <gctypes.h>

int MountFS(void *pClient, void *pCmd, char **mount_path);
int UmountFS(void *pClient, void *pCmd, const char *mountPath);

int LoadFileToMem(const char *filepath, u8 **inbuffer, u32 *size);

//! todo: C++ class
int CreateSubfolder(const char * fullpath);
int CheckFile(const char * filepath);

int is_gamefile(const char *path);
char * getPathWithNewBase(const char * inPath, const char * newBase);
char * getRelativePath(const char *path);

#ifdef __cplusplus
}
#endif

#endif // __FS_UTILS_H_
