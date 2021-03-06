// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/sky/shell/platform/linux/platform_view_linux.h"

namespace sky {
namespace shell {

PlatformViewLinux::PlatformViewLinux(const Config& config,
                                     SurfaceConfig surface_config)
    : weak_factory_(this) {}

PlatformViewLinux::~PlatformViewLinux() {}

ftl::WeakPtr<PlatformView> PlatformViewLinux::GetWeakViewPtr() {
  return weak_factory_.GetWeakPtr();
}

uint64_t PlatformViewLinux::DefaultFramebuffer() const {
  return 0;
}

bool PlatformViewLinux::ContextMakeCurrent() {
  return false;
}

bool PlatformViewLinux::SwapBuffers() {
  return false;
}

}  // namespace shell
}  // namespace sky
