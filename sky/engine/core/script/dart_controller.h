// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_ENGINE_CORE_SCRIPT_DART_CONTROLLER_H_
#define SKY_ENGINE_CORE_SCRIPT_DART_CONTROLLER_H_

#include <memory>

#include "dart/runtime/include/dart_api.h"
#include "lib/ftl/macros.h"
#include "mojo/public/cpp/system/data_pipe.h"

namespace blink {
class UIDartState;
class DartLibraryProvider;
class DartSnapshotLoader;

class DartController {
 public:
  DartController();
  ~DartController();

  static void InitVM();

  void RunFromLibrary(std::string name, DartLibraryProvider* library_provider);
  void RunFromPrecompiledSnapshot();
  void RunFromSnapshot(mojo::ScopedDataPipeConsumerHandle snapshot);
  void RunFromSnapshotBuffer(const uint8_t* buffer, size_t size);

  void CreateIsolateFor(std::unique_ptr<UIDartState> ui_dart_state);
  void Shutdown();

  UIDartState* dart_state() const { return ui_dart_state_; }

 private:
  void DidLoadMainLibrary(std::string url);
  void DidLoadSnapshot();
  bool SendStartMessage(Dart_Handle root_library);

  // The DartState associated with the main isolate.  This will be deleted
  // during isolate shutdown.
  UIDartState* ui_dart_state_;

  std::unique_ptr<DartSnapshotLoader> snapshot_loader_;

  FTL_DISALLOW_COPY_AND_ASSIGN(DartController);
};
}

#endif  // SKY_ENGINE_CORE_SCRIPT_DART_CONTROLLER_H_
