#include<ruby.h>
#include<puzzle.h>

VALUE          cRPuzzle;
PuzzleContext  puzzleContext;

static void finish_libpuzzle(VALUE data)
{
    puzzle_free_context(&puzzleContext);
}

static VALUE rb_puzzle_vector_normalized_distance(VALUE self, VALUE file1, VALUE file2)
{
    PuzzleCvec    cVec1, cVec2;
    double        d;
    int           ret1, ret2;

    puzzle_init_cvec(&puzzleContext, &cVec1);
    puzzle_init_cvec(&puzzleContext, &cVec2);

    ret1 = puzzle_fill_cvec_from_file(&puzzleContext, &cVec1, StringValuePtr(file1)); 
    ret2 = puzzle_fill_cvec_from_file(&puzzleContext, &cVec2, StringValuePtr(file2));
    
    if(ret1 == 0 && ret2 == 0){
        d = puzzle_vector_normalized_distance(&puzzleContext, &cVec1, &cVec2, 1);
    }

    if(ret1 == 0){ puzzle_free_cvec(&puzzleContext, &cVec1);}
    if(ret2 == 0){ puzzle_free_cvec(&puzzleContext, &cVec2);}
    
    if(ret1 != 0){rb_raise(rb_eStandardError, "Unable to read [%s]",StringValuePtr(file1));}
    if(ret2 != 0){rb_raise(rb_eStandardError, "Unable to read [%s]",StringValuePtr(file2));}

    return DBL2NUM(d);
}

void Init_rpuzzle(void)
{
    puzzle_init_context(&puzzleContext);

    cRPuzzle = rb_define_class("RPuzzle", rb_cObject);
    rb_set_end_proc(finish_libpuzzle, Qnil);
    rb_define_method(cRPuzzle, "vector_normalized_distance", rb_puzzle_vector_normalized_distance, 2);
}
