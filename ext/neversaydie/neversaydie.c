#include <stdio.h>
#include <ruby.h>

VALUE cNeverSayDie;

static VALUE segv(VALUE self)
{
  int *ptr = NULL;
  *ptr = 1;
  return self;
}

void Init_neversaydie()
{
  cNeverSayDie = rb_define_class("NeverSayDie", rb_eRuntimeError);
  rb_define_singleton_method(cNeverSayDie, "segv", segv, 0);
}
