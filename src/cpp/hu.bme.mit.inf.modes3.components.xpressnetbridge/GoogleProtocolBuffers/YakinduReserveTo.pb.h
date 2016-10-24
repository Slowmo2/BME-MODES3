// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: YakinduReserveTo.proto

#ifndef PROTOBUF_YakinduReserveTo_2eproto__INCLUDED
#define PROTOBUF_YakinduReserveTo_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "Enums.pb.h"
// @@protoc_insertion_point(includes)

namespace modes3 {
namespace protobuf {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_YakinduReserveTo_2eproto();
void protobuf_InitDefaults_YakinduReserveTo_2eproto();
void protobuf_AssignDesc_YakinduReserveTo_2eproto();
void protobuf_ShutdownFile_YakinduReserveTo_2eproto();

class YakinduReserveTo;

// ===================================================================

class YakinduReserveTo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:modes3.protobuf.YakinduReserveTo) */ {
 public:
  YakinduReserveTo();
  virtual ~YakinduReserveTo();

  YakinduReserveTo(const YakinduReserveTo& from);

  inline YakinduReserveTo& operator=(const YakinduReserveTo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const YakinduReserveTo& default_instance();

  static const YakinduReserveTo* internal_default_instance();

  void Swap(YakinduReserveTo* other);

  // implements Message ----------------------------------------------

  inline YakinduReserveTo* New() const { return New(NULL); }

  YakinduReserveTo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const YakinduReserveTo& from);
  void MergeFrom(const YakinduReserveTo& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(YakinduReserveTo* other);
  void UnsafeMergeFrom(const YakinduReserveTo& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 targetID = 1;
  void clear_targetid();
  static const int kTargetIDFieldNumber = 1;
  ::google::protobuf::uint32 targetid() const;
  void set_targetid(::google::protobuf::uint32 value);

  // optional .modes3.protobuf.YakinduConnectionDirection direction = 2;
  void clear_direction();
  static const int kDirectionFieldNumber = 2;
  ::modes3::protobuf::YakinduConnectionDirection direction() const;
  void set_direction(::modes3::protobuf::YakinduConnectionDirection value);

  // @@protoc_insertion_point(class_scope:modes3.protobuf.YakinduReserveTo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 targetid_;
  int direction_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_YakinduReserveTo_2eproto_impl();
  friend void  protobuf_AddDesc_YakinduReserveTo_2eproto_impl();
  friend void protobuf_AssignDesc_YakinduReserveTo_2eproto();
  friend void protobuf_ShutdownFile_YakinduReserveTo_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<YakinduReserveTo> YakinduReserveTo_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// YakinduReserveTo

// optional uint32 targetID = 1;
inline void YakinduReserveTo::clear_targetid() {
  targetid_ = 0u;
}
inline ::google::protobuf::uint32 YakinduReserveTo::targetid() const {
  // @@protoc_insertion_point(field_get:modes3.protobuf.YakinduReserveTo.targetID)
  return targetid_;
}
inline void YakinduReserveTo::set_targetid(::google::protobuf::uint32 value) {
  
  targetid_ = value;
  // @@protoc_insertion_point(field_set:modes3.protobuf.YakinduReserveTo.targetID)
}

// optional .modes3.protobuf.YakinduConnectionDirection direction = 2;
inline void YakinduReserveTo::clear_direction() {
  direction_ = 0;
}
inline ::modes3::protobuf::YakinduConnectionDirection YakinduReserveTo::direction() const {
  // @@protoc_insertion_point(field_get:modes3.protobuf.YakinduReserveTo.direction)
  return static_cast< ::modes3::protobuf::YakinduConnectionDirection >(direction_);
}
inline void YakinduReserveTo::set_direction(::modes3::protobuf::YakinduConnectionDirection value) {
  
  direction_ = value;
  // @@protoc_insertion_point(field_set:modes3.protobuf.YakinduReserveTo.direction)
}

inline const YakinduReserveTo* YakinduReserveTo::internal_default_instance() {
  return &YakinduReserveTo_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf
}  // namespace modes3

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_YakinduReserveTo_2eproto__INCLUDED