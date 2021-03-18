/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <stdint.h>

#define BIONIC_DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) = delete;             \
  void operator=(const TypeName&) = delete

#define BIONIC_DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
  TypeName() = delete;                                  \
  BIONIC_DISALLOW_COPY_AND_ASSIGN(TypeName)

#define BIONIC_ROUND_UP_POWER_OF_2(value) \
  ((sizeof(value) == 8) \
    ? (1UL << (64 - __builtin_clzl(static_cast<unsigned long>(value)))) \
    : (1UL << (32 - __builtin_clz(static_cast<unsigned int>(value)))))

static constexpr uintptr_t align_down(uintptr_t p, size_t align) {
  return p & ~(align - 1);
}

static constexpr uintptr_t align_up(uintptr_t p, size_t align) {
  return (p + align - 1) & ~(align - 1);
}

template <typename T>
static inline T* align_down(T* p, size_t align) {
  return reinterpret_cast<T*>(align_down(reinterpret_cast<uintptr_t>(p), align));
}

template <typename T>
static inline T* align_up(T* p, size_t align) {
  return reinterpret_cast<T*>(align_up(reinterpret_cast<uintptr_t>(p), align));
}