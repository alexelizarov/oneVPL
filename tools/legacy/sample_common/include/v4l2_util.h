/*############################################################################
  # Copyright (C) Intel Corporation
  #
  # SPDX-License-Identifier: MIT
  ############################################################################*/

#ifndef __V4L2_UTIL_H__
#define __V4L2_UTIL_H__

#include <errno.h>
#include <fcntl.h>
#include <linux/videodev2.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <va/va.h>
#include "sample_defs.h"

/* MIPI DRIVER Configurations*/
#define _ISP_MODE_NONE       0x0000
#define _ISP_MODE_CONTINUOUS 0x1000
#define _ISP_MODE_STILL      0x2000
#define _ISP_MODE_VIDEO      0x4000
#define _ISP_MODE_PREVIEW    0x8000

#define CLEAR(x) memset(&(x), 0, sizeof(x))
#define ERRSTR   strerror(errno)

#define BYE_ON(cond, ...)                                               \
    do {                                                                \
        if (cond) {                                                     \
            int errsv = errno;                                          \
            fprintf(stderr, "ERROR(%s:%d) : ", __FILENAME__, __LINE__); \
            errno = errsv;                                              \
            fprintf(stderr, __VA_ARGS__);                               \
            abort();                                                    \
        }                                                               \
    } while (0)

enum AtomISPMode { NONE = 0, PREVIEW, STILL, VIDEO, CONTINUOUS };

enum V4L2PixelFormat { NO_FORMAT = 0, UYVY, YUY2 };

typedef struct _Buffer {
    int fd, index;
} Buffer;

extern Buffer* buffers;
void* PollingThread(void* data);

class v4l2Device {
public:
    v4l2Device(const char* devname               = "/dev/video0",
               uint32_t width                    = 1920,
               uint32_t height                   = 1080,
               uint32_t num_buffer               = 4,
               enum AtomISPMode MipiMode         = NONE,
               enum V4L2PixelFormat m_v4l2Format = NO_FORMAT);

    ~v4l2Device();

    void Init(const char* devname,
              uint32_t width,
              uint32_t height,
              uint32_t num_buffer,
              enum V4L2PixelFormat v4l2Format,
              enum AtomISPMode MipiMode,
              int m_MipiPort);

    void V4L2Init();
    void V4L2Alloc();
    int blockIOCTL(int handle, int request, void* args);
    int GetAtomISPModes(enum AtomISPMode mode);
    void V4L2QueueBuffer(Buffer* buffer);
    Buffer* V4L2DeQueueBuffer(Buffer* buffer);
    void V4L2StartCapture();
    void V4L2StopCapture();
    int GetV4L2TerminationSignal();
    void PutOnQ(int x);
    int GetOffQ();
    int ConvertToMFXFourCC(enum V4L2PixelFormat v4l2Format);
    int ConvertToV4L2FourCC();
    int GetV4L2DisplayID() {
        return m_fd;
    }
    bool ISV4L2Enabled() {
        return (m_fd > 0) ? true : false;
    }

protected:
    const char* m_devname;
    uint32_t m_height;
    uint32_t m_width;
    uint32_t m_num_buffers;
    struct v4l2_pix_format m_format;
    int m_MipiPort;
    enum AtomISPMode m_MipiMode;
    enum V4L2PixelFormat m_v4l2Format;
    int m_fd;
};

#endif // ifdef __V4L2_UTIL_H__
