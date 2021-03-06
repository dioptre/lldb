//===-- RegisterContext_powerpc.h --------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef liblldb_RegisterContext_powerpc_H_
#define liblldb_RegisterContext_powerpc_H_

// eh_frame and DWARF Register numbers (eRegisterKindEHFrame & eRegisterKindDWARF)
enum
{
    gcc_dwarf_r0_powerpc = 0,
    gcc_dwarf_r1_powerpc,
    gcc_dwarf_r2_powerpc,
    gcc_dwarf_r3_powerpc,
    gcc_dwarf_r4_powerpc,
    gcc_dwarf_r5_powerpc,
    gcc_dwarf_r6_powerpc,
    gcc_dwarf_r7_powerpc,
    gcc_dwarf_r8_powerpc,
    gcc_dwarf_r9_powerpc,
    gcc_dwarf_r10_powerpc,
    gcc_dwarf_r11_powerpc,
    gcc_dwarf_r12_powerpc,
    gcc_dwarf_r13_powerpc,
    gcc_dwarf_r14_powerpc,
    gcc_dwarf_r15_powerpc,
    gcc_dwarf_r16_powerpc,
    gcc_dwarf_r17_powerpc,
    gcc_dwarf_r18_powerpc,
    gcc_dwarf_r19_powerpc,
    gcc_dwarf_r20_powerpc,
    gcc_dwarf_r21_powerpc,
    gcc_dwarf_r22_powerpc,
    gcc_dwarf_r23_powerpc,
    gcc_dwarf_r24_powerpc,
    gcc_dwarf_r25_powerpc,
    gcc_dwarf_r26_powerpc,
    gcc_dwarf_r27_powerpc,
    gcc_dwarf_r28_powerpc,
    gcc_dwarf_r29_powerpc,
    gcc_dwarf_r30_powerpc,
    gcc_dwarf_r31_powerpc,
    gcc_dwarf_f0_powerpc,
    gcc_dwarf_f1_powerpc,
    gcc_dwarf_f2_powerpc,
    gcc_dwarf_f3_powerpc,
    gcc_dwarf_f4_powerpc,
    gcc_dwarf_f5_powerpc,
    gcc_dwarf_f6_powerpc,
    gcc_dwarf_f7_powerpc,
    gcc_dwarf_f8_powerpc,
    gcc_dwarf_f9_powerpc,
    gcc_dwarf_f10_powerpc,
    gcc_dwarf_f11_powerpc,
    gcc_dwarf_f12_powerpc,
    gcc_dwarf_f13_powerpc,
    gcc_dwarf_f14_powerpc,
    gcc_dwarf_f15_powerpc,
    gcc_dwarf_f16_powerpc,
    gcc_dwarf_f17_powerpc,
    gcc_dwarf_f18_powerpc,
    gcc_dwarf_f19_powerpc,
    gcc_dwarf_f20_powerpc,
    gcc_dwarf_f21_powerpc,
    gcc_dwarf_f22_powerpc,
    gcc_dwarf_f23_powerpc,
    gcc_dwarf_f24_powerpc,
    gcc_dwarf_f25_powerpc,
    gcc_dwarf_f26_powerpc,
    gcc_dwarf_f27_powerpc,
    gcc_dwarf_f28_powerpc,
    gcc_dwarf_f29_powerpc,
    gcc_dwarf_f30_powerpc,
    gcc_dwarf_f31_powerpc,
    gcc_dwarf_cr_powerpc,
    gcc_dwarf_fpscr_powerpc,
    gcc_dwarf_msr_powerpc,
    gcc_dwarf_vscr_powerpc,
    gcc_dwarf_xer_powerpc = 101,
    gcc_dwarf_lr_powerpc = 108,
    gcc_dwarf_ctr_powerpc,
    gcc_dwarf_pc_powerpc,
    gcc_dwarf_vrsave_powerpc = 356,
    gcc_dwarf_v0_powerpc = 1124,
    gcc_dwarf_v1_powerpc,
    gcc_dwarf_v2_powerpc,
    gcc_dwarf_v3_powerpc,
    gcc_dwarf_v4_powerpc,
    gcc_dwarf_v5_powerpc,
    gcc_dwarf_v6_powerpc,
    gcc_dwarf_v7_powerpc,
    gcc_dwarf_v8_powerpc,
    gcc_dwarf_v9_powerpc,
    gcc_dwarf_v10_powerpc,
    gcc_dwarf_v11_powerpc,
    gcc_dwarf_v12_powerpc,
    gcc_dwarf_v13_powerpc,
    gcc_dwarf_v14_powerpc,
    gcc_dwarf_v15_powerpc,
    gcc_dwarf_v16_powerpc,
    gcc_dwarf_v17_powerpc,
    gcc_dwarf_v18_powerpc,
    gcc_dwarf_v19_powerpc,
    gcc_dwarf_v20_powerpc,
    gcc_dwarf_v21_powerpc,
    gcc_dwarf_v22_powerpc,
    gcc_dwarf_v23_powerpc,
    gcc_dwarf_v24_powerpc,
    gcc_dwarf_v25_powerpc,
    gcc_dwarf_v26_powerpc,
    gcc_dwarf_v27_powerpc,
    gcc_dwarf_v28_powerpc,
    gcc_dwarf_v29_powerpc,
    gcc_dwarf_v30_powerpc,
    gcc_dwarf_v31_powerpc,
};

// Stabs Register numbers (eRegisterKindStabs)
enum
{
    gdb_r0_powerpc = 0,
    gdb_r1_powerpc,
    gdb_r2_powerpc,
    gdb_r3_powerpc,
    gdb_r4_powerpc,
    gdb_r5_powerpc,
    gdb_r6_powerpc,
    gdb_r7_powerpc,
    gdb_r8_powerpc,
    gdb_r9_powerpc,
    gdb_r10_powerpc,
    gdb_r11_powerpc,
    gdb_r12_powerpc,
    gdb_r13_powerpc,
    gdb_r14_powerpc,
    gdb_r15_powerpc,
    gdb_r16_powerpc,
    gdb_r17_powerpc,
    gdb_r18_powerpc,
    gdb_r19_powerpc,
    gdb_r20_powerpc,
    gdb_r21_powerpc,
    gdb_r22_powerpc,
    gdb_r23_powerpc,
    gdb_r24_powerpc,
    gdb_r25_powerpc,
    gdb_r26_powerpc,
    gdb_r27_powerpc,
    gdb_r28_powerpc,
    gdb_r29_powerpc,
    gdb_r30_powerpc,
    gdb_r31_powerpc,
    gdb_f0_powerpc,
    gdb_f1_powerpc,
    gdb_f2_powerpc,
    gdb_f3_powerpc,
    gdb_f4_powerpc,
    gdb_f5_powerpc,
    gdb_f6_powerpc,
    gdb_f7_powerpc,
    gdb_f8_powerpc,
    gdb_f9_powerpc,
    gdb_f10_powerpc,
    gdb_f11_powerpc,
    gdb_f12_powerpc,
    gdb_f13_powerpc,
    gdb_f14_powerpc,
    gdb_f15_powerpc,
    gdb_f16_powerpc,
    gdb_f17_powerpc,
    gdb_f18_powerpc,
    gdb_f19_powerpc,
    gdb_f20_powerpc,
    gdb_f21_powerpc,
    gdb_f22_powerpc,
    gdb_f23_powerpc,
    gdb_f24_powerpc,
    gdb_f25_powerpc,
    gdb_f26_powerpc,
    gdb_f27_powerpc,
    gdb_f28_powerpc,
    gdb_f29_powerpc,
    gdb_f30_powerpc,
    gdb_f31_powerpc,
    gdb_pc_powerpc,
    gdb_cr_powerpc = 66,
    gdb_lr_powerpc,
    gdb_ctr_powerpc,
    gdb_xer_powerpc,
    gdb_fpscr_powerpc,
    gdb_v0_powerpc = 106,
    gdb_v1_powerpc,
    gdb_v2_powerpc,
    gdb_v3_powerpc,
    gdb_v4_powerpc,
    gdb_v5_powerpc,
    gdb_v6_powerpc,
    gdb_v7_powerpc,
    gdb_v8_powerpc,
    gdb_v9_powerpc,
    gdb_v10_powerpc,
    gdb_v11_powerpc,
    gdb_v12_powerpc,
    gdb_v13_powerpc,
    gdb_v14_powerpc,
    gdb_v15_powerpc,
    gdb_v16_powerpc,
    gdb_v17_powerpc,
    gdb_v18_powerpc,
    gdb_v19_powerpc,
    gdb_v20_powerpc,
    gdb_v21_powerpc,
    gdb_v22_powerpc,
    gdb_v23_powerpc,
    gdb_v24_powerpc,
    gdb_v25_powerpc,
    gdb_v26_powerpc,
    gdb_v27_powerpc,
    gdb_v28_powerpc,
    gdb_v29_powerpc,
    gdb_v30_powerpc,
    gdb_v31_powerpc,
    gdb_vscr_powerpc,
    gdb_vrsave_powerpc,
};

#endif // liblldb_RegisterContext_powerpc_H_
