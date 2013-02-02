require 'mkmf'

dir_config('puzzle')
if have_header('puzzle.h') and have_library('puzzle', 'puzzle_init_context')
  create_makefile('rpuzzle/rpuzzle')
end
