// SPDX-License-Identifier: GPL-2.0
/*
 * Support for Intel Camera Imaging ISP subsystem.
 * Copyright (c) 2010-2015, Intel Corporation.
 */

/* The name "mmu.h is already taken" */
#include "mmu_device.h"

void mmu_set_page_table_base_index(
    const mmu_ID_t		ID,
    const hrt_data		base_index)
{
	mmu_reg_store(ID, _HRT_MMU_PAGE_TABLE_BASE_ADDRESS_REG_IDX, base_index);
	return;
}

hrt_data mmu_get_page_table_base_index(
    const mmu_ID_t		ID)
{
	return mmu_reg_load(ID, _HRT_MMU_PAGE_TABLE_BASE_ADDRESS_REG_IDX);
}

void mmu_invalidate_cache(
    const mmu_ID_t		ID)
{
	mmu_reg_store(ID, _HRT_MMU_INVALIDATE_TLB_REG_IDX, 1);
	return;
}

void mmu_invalidate_cache_all(void)
{
	mmu_ID_t	mmu_id;

	for (mmu_id = (mmu_ID_t)0; mmu_id < N_MMU_ID; mmu_id++) {
		mmu_invalidate_cache(mmu_id);
	}
}
