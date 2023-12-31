/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef PSEUDO_M4U_GZ_SEC_H
#define PSEUDO_M4U_GZ_SEC_H

#include <linux/mutex.h>

#include "kree/mem.h"
#include "tz_m4u.h"
#include "trustzone/kree/system.h"
#include <linux/mutex.h>

struct m4u_sec_ty_context {
	KREE_SESSION_HANDLE mem_sn;	/*for mem service */
	KREE_SESSION_HANDLE mem_hd;
	KREE_SHAREDMEM_PARAM shm_param;

	KREE_SESSION_HANDLE m4u_sn;

	struct mutex ctx_lock;
	int init;
};

struct m4u_gz_sec_context {
	const char *name;
	struct gz_m4u_msg *gz_m4u_msg;
	void *imp;
};

int m4u_gz_sec_context_init(void);
int m4u_gz_sec_context_deinit(void);
void m4u_gz_sec_set_context(void);
struct m4u_gz_sec_context *m4u_gz_sec_ctx_get(void);
int m4u_gz_sec_ctx_put(struct m4u_gz_sec_context *ctx);
int m4u_gz_exec_cmd(struct m4u_gz_sec_context *ctx);

#endif
