// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_ENGINE_PUBLIC_PLATFORM_SKY_SETTINGS_H_
#define SKY_ENGINE_PUBLIC_PLATFORM_SKY_SETTINGS_H_

namespace blink {

struct SkySettings {
  bool enable_observatory = false;
  bool enable_dart_checked_mode = false;

  static const SkySettings& Get();
  static void Set(const SkySettings& settings);
};

} // namespace blink

#endif  // SKY_ENGINE_PUBLIC_PLATFORM_SKY_SETTINGS_H_