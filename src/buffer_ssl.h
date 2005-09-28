/*
 * lftp and utils
 *
 * Copyright (c) 1998 by Alexander V. Lukyanov (lav@yars.free.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* $Id$ */

#ifndef BUFFER_SSL_H
#define BUFFER_SSL_H

#include "buffer.h"

#if USE_SSL
#include "lftp_ssl.h"
class IOBufferSSL : public IOBuffer
{
   lftp_ssl *ssl;
   bool close_later;

   int Get_LL(int size);
   int Put_LL(const char *buf,int size);

protected:
   ~IOBufferSSL();

public:
   IOBufferSSL(lftp_ssl *s,dir_t m);
   void CloseLater()	{ close_later=true; }
   int Do();
   bool Done() { return IOBuffer::Done() && ssl->handshake_done; }
};
#endif

#endif//BUFFER_SSL_H
