/*
 * This file is part of the flashrom project.
 *
 * Copyright 2022 Google LLC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef WRAPS_H
#define WRAPS_H

#include <stdio.h>
#include "flash.h"

char *__wrap_strdup(const char *s);
void __wrap_physunmap(void *virt_addr, size_t len);
void *__wrap_physmap(const char *descr, uintptr_t phys_addr, size_t len);
struct pci_dev *__wrap_pcidev_init(void *devs, int bar);
uintptr_t __wrap_pcidev_readbar(void *dev, int bar);
void __wrap_sio_write(uint16_t port, uint8_t reg, uint8_t data);
uint8_t __wrap_sio_read(uint16_t port, uint8_t reg);
int __wrap_open(const char *pathname, int flags);
int __wrap_open64(const char *pathname, int flags);
int __wrap___open64_2(const char *pathname, int flags);
int __wrap_ioctl(int fd, unsigned long int request, ...);
int __wrap_write(int fd, const void *buf, size_t sz);
int __wrap_read(int fd, void *buf, size_t sz);
FILE *__wrap_fopen(const char *pathname, const char *mode);
FILE *__wrap_fopen64(const char *pathname, const char *mode);
FILE *__wrap_fdopen(int fd, const char *mode);
int __wrap_stat(const char *path, void *buf);
int __wrap_stat64(const char *path, void *buf);
int __wrap___xstat(const char *path, void *buf);
int __wrap___xstat64(const char *path, void *buf);
int __wrap_fstat(int fd, void *buf);
int __wrap_fstat64(int fd, void *buf);
int __wrap___fxstat(int fd, void *buf);
int __wrap___fxstat64(int fd, void *buf);
char *__wrap_fgets(char *buf, int len, FILE *fp);
char *__wrap___fgets_chk(char *buf, int len, FILE *fp);
size_t __wrap_fread(void *ptr, size_t size, size_t nmemb, FILE *fp);
size_t __wrap_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *fp);
int __wrap_fflush(FILE *fp);
int __wrap_fileno(FILE *fp);
int __wrap_fsync(int fd);
int __wrap_setvbuf(FILE *fp, char *buf, int type, size_t size);
int __wrap_fprintf(FILE *fp, const char *fmt, ...);
int __wrap___vfprintf_chk(FILE *fp, const char *fmt, va_list args);
int __wrap_fclose(FILE *fp);
int __wrap_feof(FILE *fp);
int __wrap_ferror(FILE *fp);
void __wrap_clearerr(FILE *fp);
int __wrap_rget_io_perms(void);
void __wrap_test_outb(unsigned char value, unsigned short port);
unsigned char __wrap_test_inb(unsigned short port);
void __wrap_test_outw(unsigned short value, unsigned short port);
unsigned short __wrap_test_inw(unsigned short port);
void __wrap_test_outl(unsigned int value, unsigned short port);
unsigned int __wrap_test_inl(unsigned short port);
int __wrap_spi_send_command(const struct flashctx *flash,
		unsigned int writecnt, unsigned int readcnt,
		const unsigned char *writearr, unsigned char *readarr);

#endif /* WRAPS_H */
