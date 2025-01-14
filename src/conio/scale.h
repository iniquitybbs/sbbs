#include "bitmap_con.h"

struct graphics_buffer {
	uint32_t* data;
	size_t    sz;
	size_t    w;
	size_t    h;
	struct graphics_buffer *next;
};

extern uint32_t r2y[1<<24];
extern uint32_t y2r[1<<24];

struct graphics_buffer * get_buffer(void);
void release_buffer(struct graphics_buffer *);
void init_r2y(void);

struct graphics_buffer * do_scale(struct rectlist* rect, int xscale, int yscale, int aspect_width, int aspect_height);
void aspect_correct(int *x, int *y, int aspect_width, int aspect_height);
void aspect_reverse(int *x, int *y, int scrnwidth, int scrnheight, int aspect_width, int aspect_height);
void aspect_fix(int *x, int *y, int aspect_width, int aspect_height);
void aspect_fix_low(int *x, int *y, int aspect_width, int aspect_height);
