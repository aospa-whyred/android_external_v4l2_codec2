// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ANDROID_C2_ALLOCATOR_CROS_GRALLOC_NYC_H
#define ANDROID_C2_ALLOCATOR_CROS_GRALLOC_NYC_H

#include <C2Buffer.h>

#include <gui/ISurfaceComposer.h>
#include <gui/Surface.h>
#include <private/gui/ComposerService.h>

namespace android {

class C2AllocatorCrosGralloc : public C2Allocator {
public:
    virtual id_t getId() const override;

    virtual C2String getName() const override;

    virtual std::shared_ptr<const Traits> getTraits() const override;

    virtual c2_status_t newGraphicAllocation(
            uint32_t width, uint32_t height, uint32_t format, C2MemoryUsage usage,
            std::shared_ptr<C2GraphicAllocation>* allocation) override;

    C2AllocatorCrosGralloc(id_t id);
    virtual ~C2AllocatorCrosGralloc();

private:
    sp<ISurfaceComposer> mComposer;
    sp<IGraphicBufferAlloc> mAllocator;
    std::shared_ptr<const Traits> mTraits;
};

}  // namespace android

#endif  // ANDROID_C2_ALLOCATOR_CROS_GRALLOC_NYC_H
