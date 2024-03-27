#ifndef HEARTBEAT_BUILDER_H
#define HEARTBEAT_BUILDER_H

/* Generated by flatcc 0.6.1-dev FlatBuffers schema compiler for C by dvide.com */

#ifndef HEARTBEAT_READER_H
#include "heartbeat_reader.h"
#endif
#ifndef FLATBUFFERS_COMMON_BUILDER_H
#include "flatbuffers_common_builder.h"
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension ".bin"
#endif

static const flatbuffers_voffset_t __AzureIoTSecurity_Heartbeat_required[] = { 0 };
typedef flatbuffers_ref_t AzureIoTSecurity_Heartbeat_ref_t;
static AzureIoTSecurity_Heartbeat_ref_t AzureIoTSecurity_Heartbeat_clone(flatbuffers_builder_t *B, AzureIoTSecurity_Heartbeat_table_t t);
__flatbuffers_build_table(flatbuffers_, AzureIoTSecurity_Heartbeat, 0)

#define __AzureIoTSecurity_Heartbeat_formal_args 
#define __AzureIoTSecurity_Heartbeat_call_args 
static inline AzureIoTSecurity_Heartbeat_ref_t AzureIoTSecurity_Heartbeat_create(flatbuffers_builder_t *B __AzureIoTSecurity_Heartbeat_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, AzureIoTSecurity_Heartbeat, AzureIoTSecurity_Heartbeat_file_identifier, AzureIoTSecurity_Heartbeat_type_identifier)


static inline AzureIoTSecurity_Heartbeat_ref_t AzureIoTSecurity_Heartbeat_create(flatbuffers_builder_t *B __AzureIoTSecurity_Heartbeat_formal_args)
{
    if (AzureIoTSecurity_Heartbeat_start(B)) {
        return 0;
    }
    return AzureIoTSecurity_Heartbeat_end(B);
}

static AzureIoTSecurity_Heartbeat_ref_t AzureIoTSecurity_Heartbeat_clone(flatbuffers_builder_t *B, AzureIoTSecurity_Heartbeat_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (AzureIoTSecurity_Heartbeat_start(B)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, AzureIoTSecurity_Heartbeat_end(B));
}

#include "flatcc/flatcc_epilogue.h"
#endif /* HEARTBEAT_BUILDER_H */
