/* Copyright (C) 2003-2013 Runtime Revolution Ltd.

This file is part of LiveCode.

LiveCode is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License v3 as published by the Free
Software Foundation.

LiveCode is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with LiveCode.  If not see <http://www.gnu.org/licenses/>.  */

//
// utility functions
//

#ifndef UTIL_H
#define UTIL_H

typedef struct
{
	uint2 lockscreen;
	uint2 errorlock;
	Boolean watchcursor;
	Boolean lockerrors;
	Boolean lockmessages;
	Boolean lockmoves;
	Boolean lockrecent;
	Boolean lockmenus;
	Boolean interrupt;
	uint2 dragspeed;
	MCCard *dynamiccard;
	MCObject *errorptr;
	MCObject *errorlockptr;
	Boolean exitall;
}
MCSaveprops;

struct MCSortnode
{
	union
	{
		MCStringRef svalue;
		MCNumberRef nvalue;
	};
	
	const void *data;
	
	MCSortnode()
	: svalue(nil) {}
	
	~MCSortnode()
	{
		if (svalue != nil)
			MCValueRelease(svalue);
	}
	
	MCSortnode& operator= (const MCSortnode& s)
	{
		MCValueAssign(svalue, s.svalue);
		data = s.data;
		return *this;
	}
};

extern void MCU_play();
extern void MCU_play_stop();
extern void MCU_init();
extern void MCU_watchcursor(MCStack *sptr, Boolean force);
extern void MCU_unwatchcursor(MCStack *sptr, Boolean force);
extern void MCU_resetprops(Boolean update);
extern void MCU_saveprops(MCSaveprops &sp);
extern void MCU_restoreprops(MCSaveprops &sp);
extern int4 MCU_any(int4 max);
extern void MCU_getnumberformat(MCExecPoint &, uint2, uint2, uint2);
extern bool MCU_getnumberformat(uint2 fw, uint2 trail, uint2 force, MCStringRef& r_string);
extern void MCU_setnumberformat(MCStringRef p_input, uint2 &fw, uint2 &trailing, uint2 &force);
extern real8 MCU_stoIEEE(const char *bytes);
extern real8 MCU_i4tor8(int4 in);
extern real8 MCU_fwrap(real8 p_x, real8 p_y);
extern int4 MCU_r8toi4(real8 in);
extern void MCU_srand();
extern real8 MCU_drand();
extern Boolean MCU_comparechar(const char *sptr, char target,
	                               Boolean isunicode = False);
extern Boolean MCU_strchr(const char *&, uint4 &, char,
	                          Boolean isunicode = False);
inline uint1 MCU_charsize(Boolean isunicode = False);
extern char *MCU_strtok(char *, const char *);
/* WRAPPER */ extern bool MCU_strtol(MCStringRef p_string, int4& r_l);
extern int4 MCU_strtol(const char *&, uint4 &, int1, Boolean &done,
	                       Boolean reals = False, Boolean octals = False);
extern real8 MCU_strtor8(const char *&, uint4 &, int1, Boolean &r_done,
						Boolean convertoctals = False);
extern void MCU_strip(char *sptr, uint2 trailing, uint2 force);
extern uint4 MCU_r8tos(char *&sptr, uint4 &s, real8 n,uint2 fw, uint2 trailing, uint2 force);
extern bool MCU_r8tos(real8 n, uint2 fw, uint2 trailing, uint2 force, MCStringRef &r_string);
extern bool MCU_stor8(MCStringRef, real8& r_d, bool co = false);
extern Boolean MCU_stor8(const MCString&, real8& d, Boolean co = False);
extern bool MCU_stoi2(MCStringRef, int2 &r_d);
extern Boolean MCU_stoi2(const MCString&, int2 &d);
extern bool MCU_stoui2(MCStringRef p_string, uint2 &r_d);
extern Boolean MCU_stoui2(const MCString&, uint2 &d);
extern bool MCU_stoi2x2(MCStringRef p_string, int16_t& r_d1, int16_t& r_d2);
extern Boolean MCU_stoi2x2(const MCString&, int2 &d1, int2 &d2);
extern bool MCU_stoi2x4(MCStringRef p_string, int16_t& r_d1, int16_t& r_d2, int16_t& r_d3, int16_t& r_d4);
extern Boolean MCU_stoi2x4(const MCString&, int2 &d1, int2 &d2, int2 &d3, int2 &d4);
extern bool MCU_stoi4x4(MCStringRef p_string, int32_t& r_d1, int32_t& r_d2, int32_t& r_d3, int32_t& r_d4);
extern Boolean MCU_stoi4x4(const MCString&, int32_t &d1, int32_t &d2, int32_t &d3, int32_t &d4);
extern Boolean MCU_stoi4x2(const MCString &s, int32_t &d1, int32_t &d2);
extern Boolean MCU_stobxb(const MCString& p_string, Boolean &r_left, Boolean& r_right);
extern bool MCU_stoi4(MCStringRef p_string, int4& r_d);
extern Boolean MCU_stoi4(const MCString&, int4& d);
extern bool MCU_stoui4(MCStringRef p_string, uint4 &r_d);
extern Boolean MCU_stoui4(const MCString&, uint4& d);
extern bool MCU_stoui4x2(MCStringRef p_string, uint4 &r_d1, uint4 &r_d2);
extern bool MCU_stob(MCStringRef p_string, bool& r_condition);
extern Boolean MCU_stob(const MCString&, Boolean& condition);
extern void MCU_lower(char *sptr, const MCString& s);
extern int4 MCU_strncasecmp(const char *one, const char *two, size_t n);
extern Boolean MCU_offset(const MCString &p, const MCString &w,
	                          uint4 &offset, Boolean casesensitive = False);
void MCU_chunk_offset(MCExecPoint &ep, MCString &w,
                      Boolean whole, Chunk_term delimiter);
extern void MCU_additem(char *&dptr, const char *sptr, Boolean first);
extern void MCU_addline(char *&dptr, const char *sptr, Boolean first);
extern void MCU_break_string(const MCString &s, MCString *&ptrs, uint2 &nptrs,
	                             Boolean isunicode = False);
extern void MCU_sort(MCSortnode *items, uint4 nitems,
                       Sort_type dir, Sort_type form);
#ifndef _DEBUG_MEMORY
extern void MCU_realloc(char **data, uint4 osize, uint4 nsize, uint4 csize);
#endif
extern bool MCU_matchname(MCNameRef p_name, Chunk_term type, MCNameRef name);
extern Boolean MCU_matchname(const MCString &, Chunk_term type, MCNameRef name);
extern void MCU_snap(int2 &p);
extern void MCU_roundrect(MCPoint *&, uint2 &npoints,
	                          const MCRectangle &, uint2 radius);
extern void MCU_unparsepoints(MCPoint *points, uint2 npoints, MCExecPoint &);
extern Boolean MCU_parsepoints(MCPoint *&oldpoints, uindex_t &n, MCStringRef p_data);
extern Boolean MCU_parsepoint(MCPoint &r_point, MCStringRef);
extern void MCU_querymouse(int2 &x, int2 &y);
extern void MCU_resetcursors();
extern void MCU_set_rect(MCRectangle &rect, int2 x, int2 y, uint2 w, uint2 h);
extern void MCU_set_rect(MCRectangle32 &rect, int32_t x, int32_t y, int32_t w, int32_t h);
extern Boolean MCU_point_in_rect(const MCRectangle &srect, int2 x, int2 y);
extern Boolean MCU_rect_in_rect(const MCRectangle &p, const MCRectangle &w);
extern Boolean MCU_point_on_line(MCPoint *points, uint2 npoints,
	                                 int2 x, int2 y, uint2 linesize);
extern Boolean MCU_point_in_polygon(MCPoint *points, uint2 npoints,
	                                    int2 x, int2 y);
extern void MCU_offset_points(MCPoint *points, uint2 npoints,
	                              int2 xoff, int2 yoff);

extern MCRectangle MCU_compute_rect(int2 x1, int2 y1, int2 x2, int2 y2);
extern MCRectangle MCU_center_rect(const MCRectangle &, const MCRectangle &);
extern MCRectangle MCU_bound_rect(const MCRectangle &, int2, int2, uint2, uint2);
extern MCRectangle MCU_clip_rect(const MCRectangle &, int2, int2, uint2, uint2);
extern MCRectangle MCU_intersect_rect(const MCRectangle &one, const MCRectangle &two);
extern MCRectangle MCU_union_rect(const MCRectangle &one, const MCRectangle &two);
extern MCRectangle MCU_subtract_rect(const MCRectangle &one, const MCRectangle &two);
extern MCRectangle MCU_reduce_rect(const MCRectangle &rect, int2 amount);
extern MCRectangle MCU_scale_rect(const MCRectangle &rect, int2 factor);
extern MCRectangle MCU_offset_rect(const MCRectangle& r, int2 ox, int2 oy);

extern MCRectangle MCU_recttoroot(MCStack *sptr, const MCRectangle &o);
extern void MCU_getshift(uint4 mask, uint2 &shift, uint2 &outmask);
extern void MCU_choose_tool(MCExecContext& ctxt, MCStringRef p_string, Tool p_tool);
extern Exec_stat MCU_choose_tool(MCExecPoint &ep, Tool littool,
	                                 uint2 line, uint2 pos);
extern Exec_stat MCU_dofrontscripts(Handler_type htype, MCNameRef message, MCParameter *params);
//extern bool MCU_path2std(MCStringRef p_path, MCStringRef& r_std_path);
//extern void MCU_path2std(char *dptr);
//extern bool MCU_path2native(MCStringRef p_path, MCStringRef& r_native_path);
//extern void MCU_path2native(char *dptr);
extern void MCU_fix_path(MCStringRef in, MCStringRef& r_out);
extern void MCU_base64encode(MCExecPoint &ep);
extern void MCU_base64decode(MCExecPoint &ep);
extern void MCU_urlencode(MCExecPoint &ep);
extern void MCU_urldecode(MCExecPoint &ep);
extern Boolean MCU_freeinserted(MCObjectList *&l);
extern void MCU_cleaninserted();
//extern Exec_stat MCU_change_color(MCColor &c, char *&n, MCExecPoint &ep, uint2 line, uint2 pos);
extern Exec_stat MCU_change_color(MCColor &c, MCStringRef&n, MCExecPoint &ep, uint2 line, uint2 pos);
//extern void MCU_get_color(MCExecPoint &ep, const char *name, MCColor &c);
extern void MCU_get_color(MCExecPoint &ep, MCStringRef name, MCColor &c);
extern void MCU_geturl(MCExecContext& ctxt, MCStringRef p_target, MCStringRef &r_output);
extern void MCU_geturl(MCExecPoint &ep);
extern void MCU_puturl(MCExecPoint &ep, MCExecPoint &data);
extern uint1 MCU_unicodetocharset(uint2 uchar);
extern uint1 MCU_languagetocharset(MCNameRef langname);
extern MCNameRef MCU_charsettolanguage(uint1 charset);
/* LEGACY */ extern uint1 MCU_languagetocharset(MCStringRef langname);
extern uint1 MCU_wincharsettocharset(uint2 wincharset);
extern uint1 MCU_charsettowincharset(uint1 charset);
extern bool MCU_multibytetounicode(MCDataRef p_input, MCDataRef &r_output);
extern bool MCU_unicodetomultibyte(MCDataRef p_input, MCDataRef& r_output);
extern bool MCU_multibytetounicode(MCStringRef p_src, uinteger_t p_charset, MCStringRef& r_unicode);
extern bool MCU_unicodetomultibyte(MCStringRef p_src, uinteger_t p_charset, MCStringRef& r_multibyte);
extern bool MCU_multibytetounicode(const MCString& p_src, uinteger_t p_charset, MCStringRef& r_unicode);
extern bool MCU_unicodetomultibyte(const MCString& p_src, uinteger_t p_charset, MCStringRef& r_multibyte);
extern void MCU_multibytetounicode(const char *s, uint4 len, char *d,
	                                   uint4 destbufferlength, uint4 &destlen,
	                                   uint1 charset);
extern void MCU_unicodetomultibyte(const char *s, uint4 len, char *d,
	                                   uint4 destbufferlength, uint4 &destlen,
	                                   uint1 charset);

extern bool MCU_nativetoutf8(MCStringRef p_native, MCStringRef& r_utf8);
extern bool MCU_utf8tonative(MCStringRef p_utf8, MCStringRef& r_native);

extern bool MCU_mapunicode(const MCString& p_src, bool is_unicode, bool to_unicode, MCStringRef& r_string);

extern bool MCU_compare_strings_native(const char *p_a, bool p_a_isunicode, const char *p_b, bool p_b_isunicode);
extern double MCU_squared_distance_from_line(int4 sx, int4 sy, int4 ex, int4 ey, int4 x, int4 y);

// 

struct MCInterval
{
	int from;
	int to;
};

extern bool MCU_disjointrangeinclude(MCInterval*& p_ranges, int& p_count, int p_from, int p_to);
extern bool MCU_disjointrangecontains(MCInterval* p_ranges, int p_count, int p_element);

//

IO_stat MCU_dofakewrite(char*& x_buffer, uint4& x_length, const void *p_data, uint4 p_size, uint4 p_count);

//

inline bool MCU_empty_rect(const MCRectangle& a)
{
	return a . width == 0 || a . height == 0;
}

inline bool MCU_equal_rect(const MCRectangle& a, const MCRectangle& b)
{
	return a . x == b . x && a . y == b . y &&  a . width == b . width && a . height == b . height;
}

inline MCRectangle MCU_make_rect(int2 x, int2 y, uint2 w, uint2 h)
{
	MCRectangle r;
	r . x = x;
	r . y = y;
	r . width = w;
	r . height = h;
	return r;
}

#endif
