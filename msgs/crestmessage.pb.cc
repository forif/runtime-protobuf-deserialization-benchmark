// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: crestmessage.proto

#include "crestmessage.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_crestmessage_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CrestMessage_HashEntry_DoNotUse_crestmessage_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_crestmessage_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_NestMessage_crestmessage_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_test_2ftopmessage_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TopMessage_test_2ftopmessage_2eproto;
class CrestMessage_HashEntry_DoNotUseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CrestMessage_HashEntry_DoNotUse> _instance;
} _CrestMessage_HashEntry_DoNotUse_default_instance_;
class CrestMessageDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CrestMessage> _instance;
  bool red_;
  bool blue_;
} _CrestMessage_default_instance_;
class NestMessageDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<NestMessage> _instance;
} _NestMessage_default_instance_;
static void InitDefaultsscc_info_CrestMessage_crestmessage_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_CrestMessage_default_instance_;
    new (ptr) ::CrestMessage();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::CrestMessage::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<3> scc_info_CrestMessage_crestmessage_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 3, 0, InitDefaultsscc_info_CrestMessage_crestmessage_2eproto}, {
      &scc_info_CrestMessage_HashEntry_DoNotUse_crestmessage_2eproto.base,
      &scc_info_TopMessage_test_2ftopmessage_2eproto.base,
      &scc_info_NestMessage_crestmessage_2eproto.base,}};

static void InitDefaultsscc_info_CrestMessage_HashEntry_DoNotUse_crestmessage_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_CrestMessage_HashEntry_DoNotUse_default_instance_;
    new (ptr) ::CrestMessage_HashEntry_DoNotUse();
  }
  ::CrestMessage_HashEntry_DoNotUse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CrestMessage_HashEntry_DoNotUse_crestmessage_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_CrestMessage_HashEntry_DoNotUse_crestmessage_2eproto}, {}};

static void InitDefaultsscc_info_NestMessage_crestmessage_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_NestMessage_default_instance_;
    new (ptr) ::NestMessage();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::NestMessage::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_NestMessage_crestmessage_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_NestMessage_crestmessage_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_crestmessage_2eproto[3];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_crestmessage_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_crestmessage_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_crestmessage_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::CrestMessage_HashEntry_DoNotUse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage_HashEntry_DoNotUse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::CrestMessage_HashEntry_DoNotUse, key_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage_HashEntry_DoNotUse, value_),
  0,
  1,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::CrestMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::CrestMessage, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::CrestMessage, id_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage, name_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage, hash_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage, topm_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage, nestm_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage, fruit_),
  offsetof(::CrestMessageDefaultTypeInternal, red_),
  offsetof(::CrestMessageDefaultTypeInternal, blue_),
  PROTOBUF_FIELD_OFFSET(::CrestMessage, PickOne_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::NestMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::NestMessage, id_),
  PROTOBUF_FIELD_OFFSET(::NestMessage, name_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 7, sizeof(::CrestMessage_HashEntry_DoNotUse)},
  { 9, -1, sizeof(::CrestMessage)},
  { 23, -1, sizeof(::NestMessage)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_CrestMessage_HashEntry_DoNotUse_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_CrestMessage_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_NestMessage_default_instance_),
};

const char descriptor_table_protodef_crestmessage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022crestmessage.proto\032\025test/topmessage.pr"
  "oto\"\340\002\n\014CrestMessage\022\n\n\002id\030\001 \001(\005\022\014\n\004name"
  "\030\002 \003(\t\022%\n\004hash\030\003 \003(\0132\027.CrestMessage.Hash"
  "Entry\022\031\n\004topM\030\004 \001(\0132\013.TopMessage\022\033\n\005nest"
  "M\030\005 \001(\0132\014.NestMessage\022\'\n\005fruit\030\025 \001(\0162\030.C"
  "restMessage.EnumFruits\022\r\n\003red\030\027 \001(\010H\000\022\016\n"
  "\004blue\030\030 \001(\010H\000\032+\n\tHashEntry\022\013\n\003key\030\001 \001(\005\022"
  "\r\n\005value\030\002 \001(\t:\0028\001\"W\n\nEnumFruits\022\t\n\005APPL"
  "E\020\000\022\010\n\004PEAR\020\001\022\t\n\005PEACH\020\002\022\n\n\006BANANA\020\003\022\016\n\n"
  "STRAWBERRY\020\004\022\r\n\tCHOCOLATE\020\005B\t\n\007PickOne\"\'"
  "\n\013NestMessage\022\n\n\002id\030\001 \001(\005\022\014\n\004name\030\002 \001(\tb"
  "\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_crestmessage_2eproto_deps[1] = {
  &::descriptor_table_test_2ftopmessage_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_crestmessage_2eproto_sccs[3] = {
  &scc_info_CrestMessage_crestmessage_2eproto.base,
  &scc_info_CrestMessage_HashEntry_DoNotUse_crestmessage_2eproto.base,
  &scc_info_NestMessage_crestmessage_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_crestmessage_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_crestmessage_2eproto = {
  false, false, descriptor_table_protodef_crestmessage_2eproto, "crestmessage.proto", 447,
  &descriptor_table_crestmessage_2eproto_once, descriptor_table_crestmessage_2eproto_sccs, descriptor_table_crestmessage_2eproto_deps, 3, 1,
  schemas, file_default_instances, TableStruct_crestmessage_2eproto::offsets,
  file_level_metadata_crestmessage_2eproto, 3, file_level_enum_descriptors_crestmessage_2eproto, file_level_service_descriptors_crestmessage_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_crestmessage_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_crestmessage_2eproto)), true);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* CrestMessage_EnumFruits_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_crestmessage_2eproto);
  return file_level_enum_descriptors_crestmessage_2eproto[0];
}
bool CrestMessage_EnumFruits_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr CrestMessage_EnumFruits CrestMessage::APPLE;
constexpr CrestMessage_EnumFruits CrestMessage::PEAR;
constexpr CrestMessage_EnumFruits CrestMessage::PEACH;
constexpr CrestMessage_EnumFruits CrestMessage::BANANA;
constexpr CrestMessage_EnumFruits CrestMessage::STRAWBERRY;
constexpr CrestMessage_EnumFruits CrestMessage::CHOCOLATE;
constexpr CrestMessage_EnumFruits CrestMessage::EnumFruits_MIN;
constexpr CrestMessage_EnumFruits CrestMessage::EnumFruits_MAX;
constexpr int CrestMessage::EnumFruits_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)

// ===================================================================

CrestMessage_HashEntry_DoNotUse::CrestMessage_HashEntry_DoNotUse() {}
CrestMessage_HashEntry_DoNotUse::CrestMessage_HashEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void CrestMessage_HashEntry_DoNotUse::MergeFrom(const CrestMessage_HashEntry_DoNotUse& other) {
  MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata CrestMessage_HashEntry_DoNotUse::GetMetadata() const {
  return GetMetadataStatic();
}
void CrestMessage_HashEntry_DoNotUse::MergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::Message& other) {
  ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom(other);
}


// ===================================================================

void CrestMessage::InitAsDefaultInstance() {
  ::_CrestMessage_default_instance_._instance.get_mutable()->topm_ = const_cast< ::TopMessage*>(
      ::TopMessage::internal_default_instance());
  ::_CrestMessage_default_instance_._instance.get_mutable()->nestm_ = const_cast< ::NestMessage*>(
      ::NestMessage::internal_default_instance());
  ::_CrestMessage_default_instance_.red_ = false;
  ::_CrestMessage_default_instance_.blue_ = false;
}
class CrestMessage::_Internal {
 public:
  static const ::TopMessage& topm(const CrestMessage* msg);
  static const ::NestMessage& nestm(const CrestMessage* msg);
};

const ::TopMessage&
CrestMessage::_Internal::topm(const CrestMessage* msg) {
  return *msg->topm_;
}
const ::NestMessage&
CrestMessage::_Internal::nestm(const CrestMessage* msg) {
  return *msg->nestm_;
}
void CrestMessage::clear_topm() {
  if (GetArena() == nullptr && topm_ != nullptr) {
    delete topm_;
  }
  topm_ = nullptr;
}
CrestMessage::CrestMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  name_(arena),
  hash_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:CrestMessage)
}
CrestMessage::CrestMessage(const CrestMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      name_(from.name_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  hash_.MergeFrom(from.hash_);
  if (from._internal_has_topm()) {
    topm_ = new ::TopMessage(*from.topm_);
  } else {
    topm_ = nullptr;
  }
  if (from._internal_has_nestm()) {
    nestm_ = new ::NestMessage(*from.nestm_);
  } else {
    nestm_ = nullptr;
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&fruit_) -
    reinterpret_cast<char*>(&id_)) + sizeof(fruit_));
  clear_has_PickOne();
  switch (from.PickOne_case()) {
    case kRed: {
      _internal_set_red(from._internal_red());
      break;
    }
    case kBlue: {
      _internal_set_blue(from._internal_blue());
      break;
    }
    case PICKONE_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:CrestMessage)
}

void CrestMessage::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CrestMessage_crestmessage_2eproto.base);
  ::memset(&topm_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&fruit_) -
      reinterpret_cast<char*>(&topm_)) + sizeof(fruit_));
  clear_has_PickOne();
}

CrestMessage::~CrestMessage() {
  // @@protoc_insertion_point(destructor:CrestMessage)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void CrestMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete topm_;
  if (this != internal_default_instance()) delete nestm_;
  if (has_PickOne()) {
    clear_PickOne();
  }
}

void CrestMessage::ArenaDtor(void* object) {
  CrestMessage* _this = reinterpret_cast< CrestMessage* >(object);
  (void)_this;
}
void CrestMessage::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CrestMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CrestMessage& CrestMessage::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CrestMessage_crestmessage_2eproto.base);
  return *internal_default_instance();
}


void CrestMessage::clear_PickOne() {
// @@protoc_insertion_point(one_of_clear_start:CrestMessage)
  switch (PickOne_case()) {
    case kRed: {
      // No need to clear
      break;
    }
    case kBlue: {
      // No need to clear
      break;
    }
    case PICKONE_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = PICKONE_NOT_SET;
}


void CrestMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:CrestMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.Clear();
  hash_.Clear();
  if (GetArena() == nullptr && topm_ != nullptr) {
    delete topm_;
  }
  topm_ = nullptr;
  if (GetArena() == nullptr && nestm_ != nullptr) {
    delete nestm_;
  }
  nestm_ = nullptr;
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&fruit_) -
      reinterpret_cast<char*>(&id_)) + sizeof(fruit_));
  clear_PickOne();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CrestMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_name();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "CrestMessage.name"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      // map<int32, string> hash = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(&hash_, ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else goto handle_unusual;
        continue;
      // .TopMessage topM = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_topm(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .NestMessage nestM = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_nestm(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .CrestMessage.EnumFruits fruit = 21;
      case 21:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 168)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_fruit(static_cast<::CrestMessage_EnumFruits>(val));
        } else goto handle_unusual;
        continue;
      // bool red = 23;
      case 23:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 184)) {
          _internal_set_red(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool blue = 24;
      case 24:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 192)) {
          _internal_set_blue(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CrestMessage::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CrestMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 id = 1;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_id(), target);
  }

  // repeated string name = 2;
  for (int i = 0, n = this->_internal_name_size(); i < n; i++) {
    const auto& s = this->_internal_name(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "CrestMessage.name");
    target = stream->WriteString(2, s, target);
  }

  // map<int32, string> hash = 3;
  if (!this->_internal_hash().empty()) {
    typedef ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_pointer
        ConstPtr;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::SortItem< ::PROTOBUF_NAMESPACE_ID::int32, ConstPtr > SortItem;
    typedef ::PROTOBUF_NAMESPACE_ID::internal::CompareByFirstField<SortItem> Less;
    struct Utf8Check {
      static void Check(ConstPtr p) {
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
          p->second.data(), static_cast<int>(p->second.length()),
          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
          "CrestMessage.HashEntry.value");
      }
    };

    if (stream->IsSerializationDeterministic() &&
        this->_internal_hash().size() > 1) {
      ::std::unique_ptr<SortItem[]> items(
          new SortItem[this->_internal_hash().size()]);
      typedef ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::size_type size_type;
      size_type n = 0;
      for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
          it = this->_internal_hash().begin();
          it != this->_internal_hash().end(); ++it, ++n) {
        items[static_cast<ptrdiff_t>(n)] = SortItem(&*it);
      }
      ::std::sort(&items[0], &items[static_cast<ptrdiff_t>(n)], Less());
      for (size_type i = 0; i < n; i++) {
        target = CrestMessage_HashEntry_DoNotUse::Funcs::InternalSerialize(3, items[static_cast<ptrdiff_t>(i)].second->first, items[static_cast<ptrdiff_t>(i)].second->second, target, stream);
        Utf8Check::Check(&(*items[static_cast<ptrdiff_t>(i)].second));
      }
    } else {
      for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
          it = this->_internal_hash().begin();
          it != this->_internal_hash().end(); ++it) {
        target = CrestMessage_HashEntry_DoNotUse::Funcs::InternalSerialize(3, it->first, it->second, target, stream);
        Utf8Check::Check(&(*it));
      }
    }
  }

  // .TopMessage topM = 4;
  if (this->has_topm()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::topm(this), target, stream);
  }

  // .NestMessage nestM = 5;
  if (this->has_nestm()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        5, _Internal::nestm(this), target, stream);
  }

  // .CrestMessage.EnumFruits fruit = 21;
  if (this->fruit() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      21, this->_internal_fruit(), target);
  }

  // bool red = 23;
  if (_internal_has_red()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(23, this->_internal_red(), target);
  }

  // bool blue = 24;
  if (_internal_has_blue()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(24, this->_internal_blue(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CrestMessage)
  return target;
}

size_t CrestMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CrestMessage)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string name = 2;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(name_.size());
  for (int i = 0, n = name_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      name_.Get(i));
  }

  // map<int32, string> hash = 3;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->_internal_hash_size());
  for (::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::int32, std::string >::const_iterator
      it = this->_internal_hash().begin();
      it != this->_internal_hash().end(); ++it) {
    total_size += CrestMessage_HashEntry_DoNotUse::Funcs::ByteSizeLong(it->first, it->second);
  }

  // .TopMessage topM = 4;
  if (this->has_topm()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *topm_);
  }

  // .NestMessage nestM = 5;
  if (this->has_nestm()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *nestm_);
  }

  // int32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_id());
  }

  // .CrestMessage.EnumFruits fruit = 21;
  if (this->fruit() != 0) {
    total_size += 2 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_fruit());
  }

  switch (PickOne_case()) {
    // bool red = 23;
    case kRed: {
      total_size += 2 + 1;
      break;
    }
    // bool blue = 24;
    case kBlue: {
      total_size += 2 + 1;
      break;
    }
    case PICKONE_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CrestMessage::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:CrestMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const CrestMessage* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CrestMessage>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:CrestMessage)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:CrestMessage)
    MergeFrom(*source);
  }
}

void CrestMessage::MergeFrom(const CrestMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CrestMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  name_.MergeFrom(from.name_);
  hash_.MergeFrom(from.hash_);
  if (from.has_topm()) {
    _internal_mutable_topm()->::TopMessage::MergeFrom(from._internal_topm());
  }
  if (from.has_nestm()) {
    _internal_mutable_nestm()->::NestMessage::MergeFrom(from._internal_nestm());
  }
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.fruit() != 0) {
    _internal_set_fruit(from._internal_fruit());
  }
  switch (from.PickOne_case()) {
    case kRed: {
      _internal_set_red(from._internal_red());
      break;
    }
    case kBlue: {
      _internal_set_blue(from._internal_blue());
      break;
    }
    case PICKONE_NOT_SET: {
      break;
    }
  }
}

void CrestMessage::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:CrestMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CrestMessage::CopyFrom(const CrestMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CrestMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CrestMessage::IsInitialized() const {
  return true;
}

void CrestMessage::InternalSwap(CrestMessage* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.InternalSwap(&other->name_);
  hash_.Swap(&other->hash_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(CrestMessage, fruit_)
      + sizeof(CrestMessage::fruit_)
      - PROTOBUF_FIELD_OFFSET(CrestMessage, topm_)>(
          reinterpret_cast<char*>(&topm_),
          reinterpret_cast<char*>(&other->topm_));
  swap(PickOne_, other->PickOne_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata CrestMessage::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void NestMessage::InitAsDefaultInstance() {
}
class NestMessage::_Internal {
 public:
};

NestMessage::NestMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:NestMessage)
}
NestMessage::NestMessage(const NestMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:NestMessage)
}

void NestMessage::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_NestMessage_crestmessage_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  id_ = 0;
}

NestMessage::~NestMessage() {
  // @@protoc_insertion_point(destructor:NestMessage)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void NestMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void NestMessage::ArenaDtor(void* object) {
  NestMessage* _this = reinterpret_cast< NestMessage* >(object);
  (void)_this;
}
void NestMessage::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void NestMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const NestMessage& NestMessage::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_NestMessage_crestmessage_2eproto.base);
  return *internal_default_instance();
}


void NestMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:NestMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  id_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* NestMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "NestMessage.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* NestMessage::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:NestMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 id = 1;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_id(), target);
  }

  // string name = 2;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "NestMessage.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:NestMessage)
  return target;
}

size_t NestMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:NestMessage)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 2;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // int32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void NestMessage::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:NestMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const NestMessage* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<NestMessage>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:NestMessage)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:NestMessage)
    MergeFrom(*source);
  }
}

void NestMessage::MergeFrom(const NestMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:NestMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
}

void NestMessage::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:NestMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NestMessage::CopyFrom(const NestMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:NestMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NestMessage::IsInitialized() const {
  return true;
}

void NestMessage::InternalSwap(NestMessage* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata NestMessage::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::CrestMessage_HashEntry_DoNotUse* Arena::CreateMaybeMessage< ::CrestMessage_HashEntry_DoNotUse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CrestMessage_HashEntry_DoNotUse >(arena);
}
template<> PROTOBUF_NOINLINE ::CrestMessage* Arena::CreateMaybeMessage< ::CrestMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CrestMessage >(arena);
}
template<> PROTOBUF_NOINLINE ::NestMessage* Arena::CreateMaybeMessage< ::NestMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::NestMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
